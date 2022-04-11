#include <cassert>
#include <iostream>
#include <cstdio>
#include "deadline.h"

void test_deadline() {
    
    //creating deadline task
    DeadlineTask t1("id", "abc", "msdks", 2, 25);
    assert(t1.get_imp() == 2);
    assert(t1.get_time() == 25);

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
    assert(t1.change_time(20));
    //deadline extension with error
    assert(!t1.change_time(-10));
}

void test_periodical() {

    // creating periodical task
    PeriodicalTask p1("id", "task", "name", 2, 60, 60);
    assert(p1.get_imp() == 2);
    assert(p1.get_time() == 60);
    assert(p1.get_period() == 60);

    // skipping execution 
    bool res;
    res = p1.skip_execution();
    assert(res);
    assert(p1.get_time() == 120);

}

    

int main() {
    test_deadline();
    test_periodical();
    return 0;
}
