#include <iostream>
#include <string>
#include "deadline.h"


bool DeadlineTask::change_imp(int NewImp){
    if ((NewImp <= 3) & (NewImp >= 1)){
	imp = NewImp;
	return true;
} else{
    return false;
}
    }

bool DeadlineTask::change_time(int dt){
    if ((dt >=0) & (time + dt < 23) {
	time += dt;
    return true;
} else {
    return false;
}}


bool PeriodicalTask::skip_execution(){
	if (time + period < 23){
		time += period; //task is moved to the next scheduled
	return true;
} else {
	return false;

}}



int Planner::add_task(Plan *T){
	Plan *p = head;
	
	if (*(T->task) == 0){
	
		 while(p->next != NULL)
    {
        if(*(T->data) > *(p->next->data))
        {
            p=p->next;
        }
        else
        {   
            break;
        } 
    } 
	}
	else{ while((p->next != NULL) & *(T->data < 23))
    {
        if(*(T->data) > *(p->next->data))
        {
            T->data+=;
            p=p->next;
            
        }
        else
        {   
            break;
        } 
    } 
				
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	

