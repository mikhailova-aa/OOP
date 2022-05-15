#include <cassert>
#include <iostream>
#include <cstdio>
#include "deadline.h"

void test_deadline() {
    
    //creating deadline task
    DeadlineTask t1("id", "abc", "msdks", 2, 14);
    assert(t1.get_imp() == 2);
    assert(t1.get_time() == 14);
    assert(t1.is_periodical() == false);

    //changing importance without error
    bool res;
    res = t1.change_imp(3);
    assert(res);
    assert(t1.get_imp() == 3);

    

    //changig importance with error
    res = t1.change_imp(-3);
    assert(!res);
    assert(t1.get_imp() == 3);


    //deadline extension
    assert(t1.change_time(2));
    //deadline extension with error
    assert(!t1.change_time(-10));
}

void test_periodical() {

    // creating periodical task
    PeriodicalTask p1("id", "task", "name", 2, 10, 1);
    assert(p1.get_imp() == 2);
    assert(p1.get_time() == 10);
    assert(p1.get_period() == 1);

    // skipping execution 
    bool res;
    res = p1.change_time();
    assert(res);
    assert(p1.get_time() == 11);

}

void test_list() {

    //creating two tasks
   // PeriodicalTask *t1 = new PeriodicalTask("id1", "text1", "name1", 2, 12, 1, 2);
    //assert(t1->get_imp() == 2);
    //DeadlineTask *t2 = new DeadlineTask("id2", "text2", "name2", 1, 15, 0);
   // assert(t2->get_imp() == 1);
    //add them to the plan
   // Plan *Plan1 = new Plan(t1);
    string day = "day1";
    
printf("i'm here 1 \n");
    PeriodicalTask *t1= new PeriodicalTask("id", "text", "name", 2, 11, 1);
    Planner *Planner1 = new Planner(t1, day);
    printf("i'm here 2 \n");
    PeriodicalTask *t2= new PeriodicalTask("id", "text", "name", 1, 10, 3);   
    printf("i'm here 3 \n");
    Planner1->add_task(t2);
    printf("i'm here 4\n");
    if(Planner1->day != day) printf("Error 1\n");
    
    int i=0;
    Planner *p = Planner1->head;
    while(p!=NULL)
    {
        i++; 
        p=p->next;
        printf(" i = %d \n ", i);
    }
    printf(" i = %d \n ", i);
    
    // Создаём планировщик:

    
	


}    

int main() {
    test_deadline();
    test_periodical();
    test_list();
    return 0;
}
