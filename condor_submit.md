# 콘도르(Condor) 작업 제출하기

[README.md](https://github.com/KUNPL/condor/blob/master/README.md)에 내가 원하는 기능이 없다면 이 글을 읽어보자.

콘도르를 사용하기 위해선 파일이 두개 필요하다.

1. 실행파일
1. 제출파일

실행파일을 콘도르로 돌리는 작업은 `condor_submit` 명령어를 사용한다.

    $ condor_submit [제출파일]
  
제출 파일을 매번 만드려면 안의 내용을 수정해야 하기때문에 번거롭다. 따라서 기본적인 내용을 [README.md](https://github.com/KUNPL/condor/blob/master/README.md) 에서 설명한 **condor_executable.sh** 에 적어놓고 사용할 수 있도록 해두었다. **condor_executable.sh** 는 뒤에 오는 매개변수들을 이용해서 제출파일을 1)만들고 2)제출하고 3)지운다. 하지만 기본 내용으로는 부족할 수 있기 때문에 제출파일을 직접 만들어 보도록 하자.

제출파일의 모든 줄은 다음과 같다.

    [옵션] = [값]

그리고 마지막 줄에 "Queue"라고 쓰면 된다. 우린 단지 어떤 [옵션]이 어떤 [값]을 넣었을때 어떻게 작동하는지만 알고있으면 된다. 우리가 쓸만한 옵션을을 나열해 본다. 참고로 제출파일은 대소문자를 구분하지 않으며 주석은 글 앞에 "#"을 기입하여 쓴다.

|옵션|설명|예제|
|:--:|----|----|
|executable|실행파일 이름|executable = example.sh|
|universe|실행 옵션. 우리 서버에서는 vanilla 옵션 밖에 지원하지 않는다. 기본 설정이 vanilla 이지만 혹시 모르니 항상 적도록 하자.|universe = vanilla|
|arguments|실행파일 이후에 오는 매개변수들을 띄어쓰기로 구분하여 적자.|arguments = i love chicken|
|initialdir|[값]의 이름으로 폴더를 만들고 결과파일들을 폴더에 저장한다. 옵션을 지정하지 않았다면 실행한 경로에 결과파일들을 저장한다.| initialdir = data |
|log|콘도르 진행 로그를 [값]의 이름으로 생성한 파일에 저장한다. initialdir가 지정되어 있다면 파일을 initialdir에 저장한다.|log = example.log|
|input|키보드 input을 적어둔 파일을 이용할때 사용한다.|example.in| 
|output|작업이 돌아가면서 나오는 출력들을 [값]의 이름으로 생성한 파일에 저장한다. initialdir가 지정되어 있다면 파일을 initialdir에 저장한다.|output = example.out|
|error|작업이 돌아가면서 나오는 에러를 [값]의 이름으로 생성한 파일에 저장한다. initialdir가 지정되어 있다면 파일을 initialdir에 저장한다.|error = example.err|
|getenv|[값]이 true 라면 유저의 쉘 환경설정을 불러온다. .bash_profile 같은 설정들을 불러온다는 뜻이다.|getenv = true|
|request_cpus|[값]에 해당하는 만큼의 CPU(core)를 요청한다. 기본설정으로는 1이다.|request_cpus = 2|
|request_memory|[값]에 해당하는 만큼의 memory를 요청한다. 숫자 끝에 알파벳을 붙여서 단위를 나타낸다. K: Kbytes, M: Mbytes. G: Gbytes. T: Tbytes.|request_memoty = 1K|
|notify_user|알림을 받아볼 이메일 주소.|notify_user = my@email.address|
|notification|notify_user에서 설정한 메일로 알림을 보낸다. Always: 모든 스텝 마다 알림, Complete: 끝났을 때 알림, Error: 이상이 있을 때마다 알림, Never(기본설정): 알리지 않음.|notification = always|
|priority|자연수인 [값]으로 작업의 중요도를 나타낸다. 중요도가 큰 작업이 중요도가 낮은 작업보다 먼저 돌아간다. 중요도는 한 사용자의 작업들 내에서 작용하며 다른 사용자에게는 영향을 미치지 않는다. 기본 [값]은 0이다.|priority = 1|
|queue|일을 돌린다. queue는 예외로 값을 넣지 않는다.여러번 기입하면 기입한 만큼, 뒤에 숫자를 적으면 그만큼 일이 제출된다. |queue|

***

다음 예제들은 [condor_basic](https://github.com/KUNPL/condor/tree/master/condor_basic) 폴더에서 실행해 볼 수 있다.

[**ilovechicken.sub**](https://github.com/KUNPL/condor/blob/master/condor_basic/ilovechicken.sub) :

    Executable = a.out
    Universe   = vanilla

    Log        = condor_example2.log
    Output     = condor_example2.out
    Error      = condor_example2.error

    Arguments  = i love chicken

    Queue

[**whoami.sub**](https://github.com/KUNPL/condor/blob/master/condor_basic/whoami.sub) :

    Executable = whoami.sh
    Universe   = vanilla

    Queue 10

[**condor_executable**](https://github.com/KUNPL/condor/blob/master/run_executable/condor_executable.sh)의 일부 :

    Executable   = $dir/$2
    Arguments    = $3 $4 $5 $6 $7 $8 $9

    Initialdir   = $dir/$idir
    Log          = $outfile.log
    Error        = $outfile.err
    Output       = $outfile.out
    #Input        = WHEN_YOU_HAVE_INPUT_FILES

    Universe     = vanilla
    GetEnv       = True
    Request_cpus = 1
    Notification = Always
    #Notify_user  = CHANGE_THIS_TO_YOUR_EMAIL

    Queue

##참고자료
+ [condor_submit](http://research.cs.wisc.edu/htcondor/manual/v8.0/condor_submit.html)
