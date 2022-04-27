#ifndef DEADLINE_H
#define DEADLINE_H
#include <string>
#include <iostream>
#include <list>
using std::list;

void test_deadline();
void test_periodical();
int Deadline();
using namespace std;

class DeadlineTask{

public: 

    string id; //string identifier 
    string task; //task
    string name; //executor
    int imp; // level of importance, on a scale of 1 to 3
    int time; // deadline timestamp 


// creating task with params

DeadlineTask(const string& id, const string& task, const string& name, int imp, int time)
    :id(id), task(task), name(name), imp(imp), time(time){}
    
int get_imp() const {
    return imp;
  }
int get_time() const {
    return time;
  }

//changing importance 

bool change_imp(int NewImp);

// deadline extension

bool change_time(int dt);
    
};



class PeriodicalTask : public DeadlineTask
{

public:
	
int period; // number of seconds between nearest execurion	

// creating task with params

PeriodicalTask(const string& id, const string& task, const string& name, int imp, int time, int period)
    :id(id), task(task), name(name), imp(imp), time(time), period(period){}
    
int get_period() const{
	return period;
}
// skipping execution

bool skip_execution();
};

// должен быть отсортирован по времени (т.е. в начале стоят те задания, что должны быть выполнены раньше остальных
class Plan
{
public:

DeadlineTask *task;
Plan *next;

Plan () {this->next = NULL;}
Plan(DeadlineTask *newtask)
{
	this->task = newtask;
	this->next = NULL;
}

};

class Planner
{ 
Plan *head;





















#endif // DEADLINE_H
