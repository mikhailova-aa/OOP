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
    string text; //task
    string name; //executor
    int imp; // level of importance, on a scale of 1 to 3
    int time; // deadline timestamp, on a scale of 0 to 23
    int per; // label 0 or 1 for deadline tasks and petiodical


// creating task with params

DeadlineTask(const string& id, const string& text, const string& name, int imp, int time, int per)
    :id(id), text(text), name(name), imp(imp), time(time), per(per){}
    
virtual int get_imp() const {
    return imp;
  }
virtual int get_time() const {
    return time;
  }

//changing importance 

virtual bool change_imp(int NewImp){
    if ((NewImp <= 3) & (NewImp >= 1)){
	imp = NewImp;
	return true;
} else{
    return false;
}
    }

// deadline extension

virtual bool change_time(int dt){
    if ((dt >=0) & (time + dt < 23)) {
	time += dt;
    return true;
} else {
    return false;
}}


const int operator>(const DeadlineTask& other) const{
	return time > other.time;
	}

const int operator<(const DeadlineTask& other) const{
	return time < other.time;
	}

//const int operator==(const DeadlineTask& other) const{
	//return per == 0;
	//}
//const int operator+=(const DeadlineTask&, int s) const{
	//return (time + s);
	//}
};



class PeriodicalTask : public DeadlineTask
{

public:
	
int period; // number of hours between nearest execution	

// creating task with params

//PeriodicalTask(const string& id, const string& task, const string& name, int imp, int time, int per)
    //:id(id), task(task), name(name), imp(imp), time(time), per(per), period(period){}

PeriodicalTask(const string& id, const string& text, const string& name, int imp, int time, int per, const int period):DeadlineTask(id, text, name, imp, time, per)
{
	this->period = period;
}    
       
int get_period() const{
	return period;
}
// skipping execution

bool change_time();
};

// должен быть отсортирован по времени (т.е. в начале стоят те задания, что должны быть выполнены раньше остальных) 
class Plan
{
public:

PeriodicalTask *task;
Plan *next;

Plan () {this->next = NULL;}
Plan(PeriodicalTask *newtask)
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
	PeriodicalTask *T = new PeriodicalTask("Нулевой элемент", "none", "none", 1, 0, 1,1);//null element for ease of use of the list
	head = new Plan(T);
	
}
void add_task(Plan *T);

void ones_plan(string n);

int completed_task(Plan *T);


};





#endif // DEADLINE_H
