### ROOT 매크로를 이용
`root` 명령어를 이용해서 일을 돌리고 싶다.

사용할 파일은 **run_root** 폴더의 **condor_root.sh**와 **condor_root_simple.sh**이다.

폴더를 생성해서 결과들을 저장하고 싶을 때,

	$ ./condor_root.sh `폴더 이름` `실행파일 이름`

현재 경로에 결과들을 저장하고 싶을 때,

	$ ./condor_root_simple.sh `실행파일 이름`

|변수|설명|
|:--:|----|
|`폴더 이름`| 이 이름을 가진 폴더가 실행파일이 있는 폴더에 자동으로 생성되고, 그 안에 결과물 파일과 log, err, out파일이 생성된다.|
|`실행파일`|실행시킬 파일 이름.|
|`매개변수N`|실행시킬 때 매개변수가 필요한 경우 넣어준다.|

`실행파일` 은 평소에 root 이후에 쓰는 그대로 적으면 된다. `macro.C`, `macro.C++`, `'macro.C(input_1, ...)'` 등 모두 가능하다.

#### 해보자!
run_root 폴더에 random_gaus.C 을 컴파일 및 실행,

	$ ./condor_root.sh condor_result random_gaus.C+

condor_result 폴더를 열어보자.
