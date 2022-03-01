#ifndef DEADLINE_H
#define DEADLINE_H
#include <string>
#include <iostream>

using namespace std;

class DeadlineTask{
    std::string id; //string identifier 
    std::string task; //task
    std::string name; //executor
    int imp; // level of importance, on a scale of 1 to 3
    int time; // deadline timestamp 

public:

// creating task with params

DeadlineTask(string id, string task, string name, int imp, int time)
    :id(id), task(task), name(name), imp(imp), time(time){}
    
int get_imp() const {
    return imp;
  }
int get_time() const {
    return time;
  }

//changing importance 

bool change_imp(int NewImp) {
    if ((NewImp <= 3) & (NewImp >= 1)){
    	imp = NewImp;
    return true; 
} else {
    return false;
}
    }

// deadline extension

bool change_time(int dt){
    if (dt > 0) {
        time += dt;
    return true;
} else {
    return false;
}}
    
};

#endif // DEADLINE_H
