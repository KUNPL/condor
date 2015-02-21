Condor 사용법
===========
장진희 씀
-------
Condor는 똑같은 계산을 여러 번 해야 할 때, 여러개의 컴퓨터에 나눠서 프로그램을 시켜주는 프로그램이다.
사실 이것저것 좋은 기능이 많지만, 내가 생각하기에 우리가 쓸 기능만 적어둔다.

### Condor 이럴 때 사용한다!
시뮬레이션이 필요하다. 양성자를 10\\(^{10}\\)개 쏘는 시뮬레이션이다. 양성자 1개를 쏘는데 0.01초가 걸린다.
단순 계산으로 양성자 10\\(^{10}\\)개를 쏘면 10\\(^8\\)초 = 1.67\\(\times\\)10\\(^6\\)분 = 2.78\\(\times\\)10\\(^4\\)시간 = 1157일 = 3.17년이 걸린다! 말도안돼! 한번 돌려놓고 수료할때까지 기다릴순 없다!

우리 연구실에는 총 72개의 Core가 있으니, 시뮬레이션 코드를 양성자 1.4\\(\times\\)10\\(^6\\)개를 쏘개 만들고, 똑같은 일을 72개의 Core에 시키면, 시간을 1/72로 줄일 수 있다! 1157/72일 = 16일이다! 3년 걸릴 일을 16일만에 끝내고 신나게 그림을 그릴 수 있다!

물론 모든 Core가 성능이 같은 것이 아니기 때문에 16일보다는 더 걸리겠지만, 적어도 3년은 걸리지 않는다.

### 그래서 사용법
콘도르로 돌려야 할 실행파일이 있는 곳으로 스크립트 파일을 복사해온다. 스크립트의 경로는 다음과 같다.

> /home/samba/condor_script_dont_delete_this/condor.sh

스크립트 내용은 이 문서의 마지막에 달아놓지만 별로 볼 필요는 없다.

그래서 스크립트 사용은 이렇게 한다.
> ./condor.sh `폴더 이름` `실행파일 이름` `매개변수1` \\(\cdots\\) `매개변수7`

|변수|설명|
|:-:|-|
|`폴더 이름`| 이 이름을 가진 폴더가 실행파일이 있는 폴더에 자동으로 생성되고, 그 안에 결과물 파일과 log, err, out파일이 생성된다.|
|`실행파일 이름`|실행시킬 파일 이름을 적어주면 된다|
|`매개변수N`|실행시킬 때 매개변수가 필요한 경우 넣어줌|

### 알아둬야 할 다른 명령어
|명령어|설명|
|:-:|-|
|condor_q|현재 Condor에 Submit된 작업들의 목록을 보여준다|
|condor_rm&nbsp;`기준`|`기준`에 따라 Condor에 Submit된 작업을 지운다. <br> `기준`에는 Submitter의 아이디를 사용할 수도 있고, Job ID(번호)를 넣어도 된다. 번호를 넣는 경우에 `-constraint 'ClusterId>시작번호'`를 넣으면 시작번호보다 큰 번호들의 작업들을 다 지운다|
|condor_status|현재 어떤 서버가 켜져있고, 어떤 서버에 몇개의 코어가 있으며 각각의 코어의 상태를 보여준다|

### 스크립트 파일 안

	#!/bin/bash
	# created by Genie
	# email address should be changed into yours. 

	dir=`pwd`
	idir=$1
	outfile=$2_output_`date +"%Y%m%d"`

	subfile=subfile_$outfile

	#echo $subfile
	mkdir -p $idir

	cat > $subfile << EOF
	Universe     = vanilla

	Notification = Always
	Executable   = $dir/$2
	Arguments    = $3 $4 $5 $6 $7 $8 $9
	Request_cpus = 1
	GetEnv       = True

	Initialdir   = $dir/$idir
	#Input        = WHEN_YOU_HAVE_INPUT_FILES
	Output       = $outfile.out
	Error        = $outfile.err
	Log          = $outfile.log
	Notify_user  = CHANGE_THIS_TO_YOUR_EMAIL

	Queue
	EOF

	sleep 0

	echo " "
	echo Executable   = $dir/$2
	echo Arguments    = $3 $4 $5 $6 $7 $8 $9
	echo " "
	condor_submit $subfile
	sleep 0
	rm $subfile