#include <iostream>
#include <string>
#include "deadline.h"

bool DeadlineTask::change_imp(int NewImp){
    if ((NewImp <= 3) & (NewImp >= 1)){
	tmp = NewImp;
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
int Deadline() 
{

return 0;

}
