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
    if ((dt >=0) & (time + dt < 23)) {
	time += dt;
    return true;
} else {
    return false;
}}

//по сути это не нужно, так как можно просто отмечать задание как выполненное, а следующее выполнение этого задания по расписанию останется в списке
bool PeriodicalTask::skip_execution(){
	if (time + period < 23){
		time += period; //task is moved to the next scheduled
	return true;
} else {
	return false;

}}


//task with a deadline is inserted at the right place in an already ordered list
//periodical task is inserted several times, taking into account the period within a day
void Planner::add_task(Plan *T){
	Plan *p = head;
	
	if (T->task->per == 0){
	
		 while(p->next != NULL)
    {
        if(*(T->task) > *(p->next->task))
        {
            p=p->next;
        }
        else
        {   
            break;
        } 
    } 
	}
	else{ while((p->next != NULL) && (T->task->time < 23))
    {
        if(*(T->task) > *(p->next->task))
        {
            T->task->time+=T->task->period;
            p=p->next;
            
        }
        else
        {   
            break;
        } 
    }}
 } 
//Displays information about tasks for one executor				
void Planner::ones_plan(string n){

	Plan *p = head;
	string name = n;
	
       while(p != NULL){
       if(p->task->name == name){
       cout << "Task : " << p->task->text << "\n Importance: " << p->task->imp << "\n Lead time: " << p->task->time << "\n" << endl;
       
       }
       p=p->next;
       
       }
}		
		
	
//delete completed task 		
int Planner::completed_task(Plan *T){

 Plan *p = head;
        while(p->next != NULL)
        {
            if(p->next == T)
            {
                Plan *y = T->next;
                delete(T);
                p->next = y;
                return 0;
            }
        }
        return 1;
}	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	

