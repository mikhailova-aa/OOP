#include<iostream>
#include <cstring>
#include "deadline.h"

extern "C"{
	DeadlineTask* create_deadline(char* id, char* text, char* name, int imp, int time){
		return new DeadlineTask(id, text, name, imp, time);
		}
	
	PeriodicalTask* create_periodical(char* id, char* text, char* name, int imp, int time, int period){
		return new DeadlineTask(id, text, name, imp, time, period);
		}
	Planner* create_planner(char* day){
		return new Planner(day);
		}
	void add_task(Plan *T, Planner *p1){
		p1->add_task(T);
		}
	void print(char *n, Planner *p1){
		p1->ones_plan(n);
		}
	int complete(char *id, Planner *p1){
		p1->completed_task(id);
		return 1;
		}
	}
