#include <stdio.h>
#include<pthread.h>

#include "monitor.h"

using namespace std;

class EMonitor : public Monitor{
    Condition isUp;
    Condition isDown;
    Condition request;
    Condition write;
    Condition served;

public:
    EMonitor() : isUp(this), isDown(this), request(this), write(this), served(this){}

    void inIdle(int noServed, int noPeople){
        __synchronized__;
        if(noServed!=noPeople){
            isUp.notify();
            isDown.notify();
        }
    }

    void requestCame(){
        __synchronized__;
        request.notify();
    }

    void requestWait(){
        __synchronized__;
        request.wait();
    }

    void upWait(){
        __synchronized__;
        isUp.wait();
    }

    void downWait(){
        __synchronized__;
        isDown.wait();
    }

    void upSignal(){
        __synchronized__;
        isUp.notify();
    }

    void downSignal(){
        __synchronized__;
        isDown.notify();
    }

    void writeWait(){
        __synchronized__;
        write.wait();
    }

    void writeSignal(){
        __synchronized__;
        write.notify();
    }

    void servedWait(){
        __synchronized__;
        served.wait();
    }

    void servedSignal(){
        __synchronized__;
        served.notify();
    }
/*
    void method1() {
        __synchronized__;
        // implement your monitor method. lock is already acquired
        // thanks to macro call above.
        while ( ...) { // I need to wait for an event
            cv1.wait();
        }
        ...
        cv2.notify();
    }  // no need to unlock here, destructor of macro variable does it*/
};
