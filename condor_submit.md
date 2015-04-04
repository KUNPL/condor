# 콘도르(Condor) 작업 제출하기

[README.md](https://github.com/KUNPL/condor/blob/master/README.md)에 내가 원하는 기능이 없다면 이 글을 읽어보자.

콘도르를 사용하기 위해선 파일이 두개 필요하다.

1. 실행파일
1. 제출파일

실행파일을 콘도르로 돌리는 작업은 `condor_submit` 명령어를 사용한다.

    $ condor_submit [제출파일]
  
제출 파일을 매번 만드려면 안의 내용을 수정해야 하기때문에 번거롭다. 따라서 기본적인 내용을 [README.md](https://github.com/KUNPL/condor/blob/master/README.md) 에서 설명한 **condor_executable.sh** 에 적어놓고 사용할 수 있도록 해둔 것이다. **condor_executable.sh** 는 뒤에 오는 매개변수들을 이용해서 제출파일을 1)만들고 2)제출하고 3)지운다. 하지만 기본 내용으로는 부족할 수 있기 때문에 제출파일을 직접 만들어 보도록 하자.

제출파일의 내용은 전부 `이름` = `값` 이다. 그리고 마지막 줄에 "Queue"라고 쓰면 된다. 우린 단지 어떤 `이름`이 어떤`값`을 넣었을때 어떻게 작동하는지만 알고있으면 된다.




##참고자료
+ [condor_submit](http://research.cs.wisc.edu/htcondor/manual/v8.0/condor_submit.html)
