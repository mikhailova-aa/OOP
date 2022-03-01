#include <cassert>
#include <iostream>
#include <cstdio>
#include"deadline.h"

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

int main() {
    test_deadline();
    return 0;
}
