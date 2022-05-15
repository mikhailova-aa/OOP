#include <iostream>
#include <string>
#include "deadline.h"

//virtual bool DeadlineTask::change_imp(int NewImp){
  //  if ((NewImp <= 3) & (NewImp >= 1)){
	//imp = NewImp;
	//return true;
//} else{
  //  return false;
//}
  //  }

//virtual bool DeadlineTask::change_time(int dt){
  //  if ((dt >=0) & (time + dt < 23)) {
	//time += dt;
   // return true;
//} else {
 //   return false;
//}}

//по сути это не нужно, так как можно просто отмечать задание как выполненное, а следующее выполнение этого задания по расписанию останется в списке
bool PeriodicalTask::change_time(){
	if (time + period < 23){
		time += period; //task is moved to the next scheduled
	return true;
} else {
	return false;

}}


//task with a deadline is inserted at the right place in an already ordered list
//periodical task is inserted several times, taking into account the period within a day
void Planner::add_task(DeadlineTask *T){
	Planner *p = head;
	
	if (!T->is_periodical()){
	
		 while(p->next != NULL)
    {
        if(T > p->next->task)
        {
            p=p->next;
        }
        else
        {   
            break;
        } 
    } 
	}
	else{   int Pd = T->is_periodical();
		while((p->next != NULL) && (T->time < 23))
	    {
	    	printf("time now = %d", T->time);
		if(T > p->next->task)
		{
		    T->time+=Pd;
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

	Planner *p = head;
	string name = n;
	
       while(p != NULL){
       if(p->task->name == name){
       cout << "Task : " << p->task->text << "\n Importance: " << p->task->imp << "\n Lead time: " << p->task->time << "\n" << endl;
       
       }
       p=p->next;
       
       }
}		
		
	
//delete completed task 		
int Planner::completed_task(DeadlineTask *T){

 Planner *p = head;
        while(p->next != NULL)
        {
            if(p->next->task == T)
            {
            	cout << "Task : " << T->text << "\n Importance: " << T->imp << "\n Lead time: " << T->time << "\n" << endl;
                Planner *y = p->next->next;
                delete(T);
                p->next = y;
                return 0;
            }
        }
        return 1;
}	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	

