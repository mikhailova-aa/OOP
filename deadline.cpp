#include <iostream>
#include <string>
#include "deadline.h"


bool DeadlineTask::change_imp(int NewImp){
    int tmp;
    if ((NewImp <= 3) & (NewImp >= 1)){
	imp = NewImp;
	return true;
} else{
    return false;
}
    }

bool DeadlineTask::change_time(int dt){
    if (dt >0) {
	time += dt;
    return true;
} else {
    return false;
}}


bool PeriodicalTask::skip_execution(){
    time += period; //task is moved to the next scheduled
return true;
}


int Deadline() 
{
test_deadline();
test_periodical();
return 0;

}
