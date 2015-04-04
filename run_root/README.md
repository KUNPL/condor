### ROOT 사용하기

ROOT 매크로를 이용해서 일을 돌리고 싶다.

**run_root/condor_root.sh**  : 폴더를 생성해서 결과들을 저장한다.

	$ ./condor_root.sh [폴더 이름] `실행파일 이름`

**condor_root_simple.sh** : 현재 경로에 결과들을 저장한다.

	$ ./condor_root_simple.sh `실행파일 이름`

|변수|설명|
|:--:|----|
|폴더 이름| 이 이름을 가진 폴더가 실행파일이 있는 폴더에 자동으로 생성되고, 그 안에 결과물 파일과 log, err, out파일이 생성된다.|
|실행파일|실행시킬 파일 이름.|
|매개변수N|실행시킬 때 매개변수가 필요한 경우 넣어준다.|

`실행파일` 은 `macro.C`, `macro.C++`, `'macro.C(input_1, ...)'` 등 `root`를 사용할때와 같다.

#### 해보자!
run_root 폴더에 random_gaus.C 을 컴파일 및 실행,

	$ ./condor_root.sh condor_result random_gaus.C+
