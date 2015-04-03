Condor 사용법
===========
##### 장진희 씀, 이정우 붙임 (2015.4)

Condor는 똑같은 계산을 여러 번 해야 할 때, 여러개의 컴퓨터에 나눠서 프로그램을 시켜주는 프로그램이다.
사실 이것저것 좋은 기능이 많지만, 내가 생각하기에 우리가 쓸 기능만 적어둔다.

## Condor 이럴 때 사용한다!

#### 케이스 1 >

시뮬레이션이 필요하다. 양성자를 10^10개 쏘는 시뮬레이션이다. 양성자 1개를 쏘는데 0.01초가 걸린다.
단순 계산으로 양성자 10^10개를 쏘면 10^8초 = 1.67x10^6분 = 2.78x10^4시간 = 1157일 = 3.17년이 걸린다! 말도안돼! 한번 돌려놓고 수료할때까지 기다릴순 없다!

우리 연구실에는 총 72개의 Core가 있으니, 시뮬레이션 코드를 양성자 1.4x10^6개를 쏘개 만들고, 똑같은 일을 72개의 Core에 시키면, 시간을 1/72로 줄일 수 있다! 1157/72일 = 16일이다! 3년 걸릴 일을 16일만에 끝내고 신나게 그림을 그릴 수 있다!

물론 모든 Core가 성능이 같은 것이 아니기 때문에 16일보다는 더 걸리겠지만, 적어도 3년은 걸리지 않는다.

#### 케이스 2 >

내가 컴퓨터에게 시킬 일이 CPU와 메모리를 많이 사용한다. 이 일을 컴퓨터에 시키게 되면 다른 사람들은 타자를 칠 수 없을정도로 컴퓨터가 바빠진다!

Condor는 메인컴퓨터에 연결되어 있는 다른 Core들을 사용하여 일을 시킨다. 따라서 Condor를 이용한다면 다른 사람들을 괴롭히지 않고 일을 시킬 수 있다.

## 그래서 사용법

이 깃 저장소를 내 작업환경으로 가져오자. 

	$ git clone https://github.com/KUNPL/condor.git

성공했다면 condor 폴더가 생겼을 것이다. 지금부터 설명할 메크로들은 모두 여기에 들어있다. 실패했다면 그냥 [여기](https://github.com/KUNPL/condor)에 들어가 직접 보면서 설명을 읽자!

### 1. 실행파일을 이용

실행가능한 파일을 이용해서 Condor를 돌리고 싶다. 실행 가능한 파일이란 쉘 스크립트, 혹은 컴파일을 해서 나온 실행 파일을 의미한다. 간단하게 말해 "./"를 이용해서 돌릴 수 있는 파일들이다.

사용할 메크로 파일은 **run_executable** 폴더의 **condor_executable.sh**와 **condor_executable_simple.sh**이다.

폴더를 생성해서 결과들을 저장하고 싶을 때,

	$ ./condor_executable.sh `폴더 이름` `실행파일 이름` `매개변수1` ... `매개변수7`

현재 경로에 결과들을 저장하고 싶을 때,

	$ ./condor_executabe_simple.sh `실행파일 이름` `매개변수1` ... `매개변수7`

|변수|설명|
|:--:|----|
|`폴더 이름`| 이 이름을 가진 폴더가 실행파일이 있는 폴더에 자동으로 생성되고, 그 안에 결과물 파일과 log, err, out파일이 생성된다.|
|`실행파일 이름`|실행시킬 파일 이름|
|`매개변수N`|실행시킬 때 매개변수가 필요한 경우 넣어준다.|

#### 해보자!
run_executable 폴더에 ilovechicken.cc 을 컴파일 및 실행,

	$ g++ ilovechicken 
	$ ./condor_executable_simple.sh a.out i love chicken

실행 결과 : ilovechicken.txt

	i
	love
	chicken

### 2. ROOT 매크로를 이용
`root` 명령어를 이용해서 돌릴 수 있는 매크로를 이용하고 싶다.

사용할 파일은 **run_root** 폴더의 **condor_root.sh**와 **condor_root_simple.sh**이다.

폴더를 생성해서 결과들을 저장하고 싶을 때,

	$ ./condor_root.sh `폴더 이름` `실행파일 이름`

현재 경로에 결과들을 저장하고 싶을 때,

	$ ./condor_root_simple.sh `실행파일 이름`

`실행파일 이름` 은 평소에 root 이후에 쓰는 이름 그대로 적으면 된다. `macro.C`, `macro.C++`, `'macro.C(input_1, ...)'` 등 모두 가능하다.

#### 해보자!
run_root 폴더에 random_gaus.C 을 컴파일 및 실행,

	$ ./condor_root.sh condor_result random_gaus.C+

condor_result 폴더를 열어보자.

### 3. Python 매크로를 이용
`python` 명령어를 이용해서 돌릴 수 있는 매크로를 이용하고 싶다.

사용할 파일은 **run_python** 폴더의 **condor_python.sh**와 **condor_python_simple.sh**이다.

폴더를 생성해서 결과들을 저장하고 싶을 때,

	$ ./condor_python.sh `폴더 이름` `실행파일 이름` `매개변수1` ... `매개변수7`

현재 경로에 결과들을 저장하고 싶을 때,

	$ ./condor_python_simple.sh `실행파일 이름` `매개변수1` ... `매개변수7`

#### 해보자!
run_python 폴더에 print.py 을 컴파일 및 실행,

	$ ./condor_python_simple.sh print.py

별다른 파이썬 스크립트가 생각나지 않았다...

### 4. Condor 제출 파일 만들기
업데이트 예정.

## 꼭 알아둬야 할 명령어
|명령어|설명|
|:----:|----|
|condor_q|현재 Condor에 Submit된 작업들의 목록을 보여준다|
|condor_rm&nbsp;`기준`|`기준`에 따라 Condor에 Submit된 작업을 지운다. <br> `기준`에는 Submitter의 아이디를 사용할 수도 있고, Job ID(번호)를 넣어도 된다. 번호를 넣는 경우에 `-constraint 'ClusterId>시작번호'`를 넣으면 시작번호보다 큰 번호들의 작업들을 다 지운다|
|condor_status|현재 어떤 서버가 켜져있고, 어떤 서버에 몇개의 코어가 있으며 각각의 코어의 상태를 보여준다|
