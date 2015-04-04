Condor 사용법
===========
##### 장진희 씀, 이정우 붙임 (2015.4)

Condor는 똑같은 계산을 여러 번 해야 할 때, 여러개의 컴퓨터에 나눠서 프로그램을 시켜주는 프로그램이다.
사실 이것저것 좋은 기능이 많지만, 내가 생각하기에 우리가 쓸 기능만 적어둔다.

## Condor 이럴 때 사용한다!

시뮬레이션이 필요하다. 양성자를 10^10개 쏘는 시뮬레이션이다. 양성자 1개를 쏘는데 0.01초가 걸린다.
단순 계산으로 양성자 10^10개를 쏘면 10^8초 = 1.67x10^6분 = 2.78x10^4시간 = 1157일 = 3.17년이 걸린다! 말도안돼! 한번 돌려놓고 수료할때까지 기다릴순 없다!

우리 연구실에는 총 72개의 Core가 있으니, 시뮬레이션 코드를 양성자 1.4x10^6개를 쏘개 만들고, 똑같은 일을 72개의 Core에 시키면, 시간을 1/72로 줄일 수 있다! 1157/72일 = 16일이다! 3년 걸릴 일을 16일만에 끝내고 신나게 그림을 그릴 수 있다!

물론 모든 Core가 성능이 같은 것이 아니기 때문에 16일보다는 더 걸리겠지만, 적어도 3년은 걸리지 않는다.

## 그래서 사용법

깃 저장소를 가져온다.

	$ git clone https://github.com/KUNPL/condor.git

지금부터 설명할 메크로들은 모두 여기에 들어있다. 실패했거나 귀찮다면 그냥 [여기](https://github.com/KUNPL/condor)에 들어가 직접 보면서 설명을 읽자!

쉘 스크립트, 혹은 컴파일을 해서 나온 실행파일을 이용해서 일을 돌리고 싶다. 간단하게 말해 "./"를 이용해서 돌리는 파일들이다. 루트나 파이썬을 이용하고 싶다면 루트는 [여기](https://github.com/KUNPL/condor/tree/master/run_root), 파이썬은 [여기](https://github.com/KUNPL/condor/tree/master/run_python)를 보자.

**run_executable/condor_executable.sh**  : 폴더를 생성해서 결과들을 저장한다.

	$ ./condor_executable.sh `폴더 이름` `실행파일 이름` `매개변수1` ... `매개변수7`
	
**condor_executable_simple.sh** : 현재 경로에 결과들을 저장한다.

	$ ./condor_executabe_simple.sh `실행파일 이름` `매개변수1` ... `매개변수7`

|변수|설명|
|:--:|----|
|`폴더 이름`| 이 이름을 가진 폴더가 실행파일이 있는 폴더에 자동으로 생성되고, 그 안에 결과물 파일과 log, err, out파일이 생성된다.|
|`실행파일 이름`|실행시킬 파일 이름.|
|`매개변수N`|실행시킬 때 매개변수가 필요한 경우 넣어준다.|

#### 해보자!
run_executable 폴더에 ilovechicken.cc 을 컴파일 및 실행,

	$ g++ ilovechicken 
	$ ./condor_executable_simple.sh a.out i love chicken

실행 결과 : ilovechicken.txt

	i
	love
	chicken

## 꼭 알아두어야 할 명령어
|명령어|설명|
|:----:|----|
|condor_q|현재 Condor에 Submit된 작업들의 목록을 보여준다.|
|condor_rm&nbsp;`기준`|`기준`에 따라 Condor에 Submit된 작업을 지운다. <br> `기준`에는 Submitter의 아이디를 사용할 수도 있고, Job ID(번호)를 넣어도 된다. 번호를 넣는 경우에 `-constraint 'ClusterId>시작번호'`를 넣으면 시작번호보다 큰 번호들의 작업들을 다 지운다.|
|condor_status|현재 어떤 서버가 켜져있고, 어떤 서버에 몇개의 코어가 있으며 각각의 코어의 상태를 보여준다.|
