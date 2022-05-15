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
    Planner *Planner1 = new Planner(day);
    

    DeadlineTask *t1= new DeadlineTask("id", "text", "name", 3, 11);
        
    Plan *Plan1= new Plan (t1);
    Planner1->add_task(Plan1);
    
    
    if(Planner1->day != day) printf("Error 1\n");
   
    PeriodicalTask *p1 = new PeriodicalTask("id1 ", "text1", "name", 1, 12, 2);
    Plan *Plan2 = new Plan (p1);
    
    Planner1->add_task(Plan2);
   printf("first\n");
    Planner1->ones_plan("name");
    Planner1->completed_task("id1");
    printf("second\n");
    Planner1->ones_plan("name");
    
   
}    



	

int main() {
    test_deadline();
    test_periodical();
    test_list();
    return 0;
}
