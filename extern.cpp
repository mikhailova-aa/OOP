#include<iostream>
#include <cstring>
#include "deadline.h"
#include <exception>

extern "C"{
	DeadlineTask* create_deadline(char* id, char* text, char* name, int imp, int time){
		return new DeadlineTask(id, text, name, imp, time);
		}
	
	PeriodicalTask* create_periodical(char* id, char* text, char* name, int imp, int time, int period){
		return new PeriodicalTask(id, text, name, imp, time, period);
		}
	Planner* create_planner(char* day){
		return new Planner(day);
		}
	Plan* create_plan(DeadlineTask* d1){
		return new Plan(d1);
		}
	int add_task(Plan *T, Planner *p1){
	try{
		p1->add_task(T); 
		return 0;
		}
	catch(exception){return 1;}
		
		
		}
	void print_plan(char *n, Planner *p1){
		p1->ones_plan(n);
		}
	int complete(char *id, Planner *p1){
		p1->completed_task(id);
		return 1;
		}
	}
