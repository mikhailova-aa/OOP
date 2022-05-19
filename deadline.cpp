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
bool PeriodicalTask::change_time() {
  if (time + period < 23) {
    time += period; //task is moved to the next scheduled
    return true;
  } else {
    return false;

  }
}

//task with a deadline is inserted at the right place in an already ordered list
//periodical task is inserted several times, taking into account the period within a day
void Planner::add_task(Plan * T) {
  Plan * p = head;
  //printf("is periodical = %d\n", T -> task -> is_periodical());
  while (p -> next != NULL) {

    if ( * (T -> task) > * (p -> next -> task)) {

      p = p -> next;
    } else {

      break;
    }
  }
  T -> next = p -> next;
  p -> next = T;
}
//Displays information about tasks for one executor				
void Planner::ones_plan(string n) {

  Plan * p = head;
  string name = n;

  while (p != NULL) {
    if (p -> task -> name == name) {
      cout << "Task : " << p -> task -> text << "\n Importance: " << p -> task -> imp << "\n Lead time: " << p -> task -> time << "\n" << endl;

    }
    p = p -> next;

  }
}

//delete completed task 		
int Planner::completed_task(string identifier) {
  string ct = identifier;
  Plan * p = head;
  cout << "identifier = " << ct << endl;

  while (p != NULL) {
    printf("imhere1\n");
    //находим выполненное задание по идентификатору
    if (p -> task -> id == ct) {
	      cout << "You completed task : " << p -> task -> text << "\n Importance: " << p -> task -> imp << "\n Lead time: " << p -> task -> time << "\n" << endl; //выводим все о нем 

	      Plan * T1 = p;
	      //PERIODICAL TASK CASE

	      if (p -> task -> is_periodical()) { //если оно периодическое, то надо добавить заново
			//увеличиваем время (Добавляем период)
			printf("is periodical = %d\n", p -> task -> is_periodical());
			PeriodicalTask * pp = dynamic_cast < PeriodicalTask * > (p -> task);
			printf("im here\n");
			p -> task -> time += pp -> period;
			printf("new time = %d\n", p -> task -> time);
			//добавляем его в список
			Plan * T = p;
			Plan * p1 = head;
			//printf("is periodical = %d\n", T -> task -> is_periodical());
			while (p1 -> next != NULL) {

			  if ( * (T -> task) > * (p1 -> next -> task)) {

			    	p = p1 -> next;
			  } else {

			    break;
			  }
			}
			T -> next = p -> next;
			p -> next = T;

	      } else {
		break; //если не переодическое переходим сразу к удалению
	      };

	      //Удаляем выполненное задание
		printf("now im deleting\n");
	      Plan * y = p -> next;
	      delete(T1);
	      p -> next = y;
	      return 0;
    } else {
      p = p -> next;
    };
  }
  return 1;
}
