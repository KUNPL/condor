
## 사용법
##### README.md 에서 옮김 - 이정우 (2017.7)

깃 저장소를 가져온다. 필요 없다면 패스!

	$ git clone https://github.com/KUNPL/condor.git

지금부터 설명할 매크로들은 모두 [여기](https://github.com/KUNPL/condor/tree/master/run_executable)에 들어있다.

쉘 스크립트, 혹은 컴파일을 해서 나온 실행파일을 이용해서 일을 돌리고 싶다. 간단하게 말해 "./"를 이용해서 돌리는 파일들이다. 루트나 파이썬을 이용하고 싶다면 루트는 [여기](https://github.com/KUNPL/condor/tree/master/run_root), 파이썬은 [여기](https://github.com/KUNPL/condor/tree/master/run_python)를 보자.

[**condor_executable.sh**](https://github.com/KUNPL/condor/blob/master/run_executable/condor_executable.sh)  : 폴더를 생성해서 결과들을 저장한다.

	$ ./condor_executable.sh [폴더 이름] [실행파일] [매개변수1] ... [매개변수7]

[**condor_executable_simple.sh**](https://github.com/KUNPL/condor/blob/master/run_executable/condor_executable_simple.sh) : 현재 경로에 결과들을 저장한다.

	$ ./condor_executabe_simple.sh [실행파일] [매개변수1] ... [매개변수7]

|변수|설명|
|:--:|----|
|폴더 이름| 이 이름을 가진 폴더가 실행파일이 있는 폴더에 자동으로 생성되고, 그 안에 결과물 파일과 log, err, out파일이 생성된다.|
|실행파일|실행시킬 파일 이름.|
|매개변수N|실행시킬 때 매개변수가 필요한 경우 넣어준다. 필요없거나 뭔지 모르겠다면 안쓰면 된다.|

#### 해보자!
ilovechicken.cc 을 실행해보자.

	$ g++ ilovechicken.cc
	$ ./condor_executable_simple.sh a.out i love chicken

실행 결과 : ilovechicken.txt

	i
	love
	chicken

***

## 꼭 알아두어야 할 명령어
|명령어|설명|
|:----:|----|
|condor_q|현재 Condor에 Submit된 작업들의 목록을 보여준다.|
|condor_rm&nbsp;`기준`|`기준`에 따라 Condor에 Submit된 작업을 지운다. <br> `기준`에는 Submitter의 아이디를 사용할 수도 있고, Job ID(번호)를 넣어도 된다. 번호를 넣는 경우에 `-constraint 'ClusterId>시작번호'`를 넣으면 시작번호보다 큰 번호들의 작업들을 다 지운다.|
|condor_status|현재 어떤 서버가 켜져있고, 어떤 서버에 몇개의 코어가 있으며 각각의 코어의 상태를 보여준다.|

`condor_q`를 사용했을 때 나오는 정보들은 다음과 같다.
+ **ID** : 번호
+ **OWNER** : 실행한 사람
+ **SUBMITTED** : 일을 제출한 시간
+ **RUN_TIME** : 돌아간 시간
+ **ST** : 상태
  - **H** : 보류
  - **R** : 돌아가는 중
  - **I** : 대기
  - **C** : 끝남
  - **X** : 제거됨
+ **PRI** : 중요도. 숫자가 높을 수록 중요도가 높다. 설정 하지 않았다면 0.
+ **SIZE** : 이미지 크기. 사용 메모리 크기를 설정하였다면 사용 메모리 크기.
+ **CMD** : 실행 커맨드. [executable] [argument1] [argument2] ...

## 더 알고 싶다면
+ [Condor 작업 제출하기](https://github.com/KUNPL/condor/blob/master/condor_submit.md)
+ [Condor Online Manual](http://research.cs.wisc.edu/htcondor/manual/v8.0/ref.html)
