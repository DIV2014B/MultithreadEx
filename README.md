# MultithreadEx
Visual studio C++를 이용하여 thread priority 설정하여 Function 동작 시작을 확인한 예제.  
* source: [ex3.cpp](MultithreadEx/ex3.cpp)
* 참고: [wiki](wiki.md)

## Test
목적: 실시간성 보장. 동일한 작업을 동일한 사간에 완료

### 시험 내용
1. 우선 순위를 RR로 설정하면 CPU 점유를 100% 보장 받는가? 즉, 동일한 함수를 항상 같은 시간에 처리 하는가?
2. Core를 지정하고 100% load를 유지하면 다른 프로세스가 해당 core로 접근하지 못하는가?

### 관찰 결과
1. 가끔씩 시간이 늘어나는 경우가 보임.  
2. 가끔씩 kernel time이 관찰됨.  
* 낮은 우선 순위 프로세스 보다 CPU를 선점하는 것이 확인됨. 하지만 RR 우선 순위의 kernel job이 발생하는 경우 CPU 시간을 보장 받지 못함. 
