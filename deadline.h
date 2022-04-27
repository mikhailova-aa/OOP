#ifndef DEADLINE_H
#define DEADLINE_H
#include <string>
#include <iostream>
#include <list>
using std::list;

void test_deadline();
void test_periodical();

using namespace std;

class DeadlineTask{

public: 

    string id; //string identifier 
    string task; //task
    string name; //executor
    int imp; // level of importance, on a scale of 1 to 3
    int time; // deadline timestamp, on a scale of 0 to 23
    int per; // label 0 or 1 for non-periodic tasks and petiodic


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

const int operator<(const DeadlineTask& other) const{
	return time < other.time;
	}

const int operator==(const DeadlineTask& other) const{
	return per == 0;
	}
    
};



class PeriodicalTask : public DeadlineTask
{

public:
	
int period; // number of hours between nearest execution	

// creating task with params

PeriodicalTask(const string& id, const string& task, const string& name, int imp, int time, int period)
    :id(id), task(task), name(name), imp(imp), time(time), period(period){}
    
int get_period() const{
	return period;
}
// skipping execution

bool skip_execution();
};

// должен быть отсортирован по времени (т.е. в начале стоят те задания, что должны быть выполнены раньше остальных) 
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
public:

string day;
Plan *head;
int count = 0; // amount of tasks


Planner(const string NewDay){
	this->day = NewDay;
	Periodical Task *T = new PeriodicalTask("Нулевой элемент", "none", "none", 1, 0);//null element for ease of use of the list
	head = new Plan(T);
	
}

int add_task();












};





#endif // DEADLINE_H
