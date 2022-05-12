#include <cassert>
#include <iostream>
#include <cstdio>
#include "deadline.h"

void test_deadline() {
    
    //creating deadline task
    DeadlineTask t1("id", "abc", "msdks", 2, 14, 0);
    assert(t1.get_imp() == 2);
    assert(t1.get_time() == 14);

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
    PeriodicalTask p1("id", "task", "name", 2, 10, 1, 2);
    assert(p1.get_imp() == 2);
    assert(p1.get_time() == 10);
    assert(p1.get_period() == 2);

    // skipping execution 
    bool res;
    res = p1.change_time();
    assert(res);
    assert(p1.get_time() == 12);

}

void test_list() {

    //creating two tasks
    PeriodicalTask *t1 = new PeriodicalTask("id1", "text1", "name1", 2, 12, 1, 2);
    assert(t1->get_imp() == 2);
    DeadlineTask *t2 = new DeadlineTask("id2", "text2", "name2", 1, 15, 0);
    assert(t2->get_imp() == 1);
    //add them to the plan
    Plan *Plan1 = new Plan(t1);
    string day = "day1";
    Planner *Planner1 = new Planner(day);
    
    Planner1->add_task(Plan1);
    assert(Plan1->task->id == "id1");
    
    
    
	


}    

int main() {
    test_deadline();
    test_periodical();
    test_list();
    return 0;
}
