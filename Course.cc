#include "Course.h"
#include <iomanip>
#include <iostream>
#include <string>
#include "defs.h"
using namespace std;

int Course::nextId = COURSE_ID;

Course::Course(string t, string s, int c, char sec, string i) 
: id(nextId++), term(t), subject(s), code(c), section(sec), instructor(i){}

bool Course::lessThan(Course* course){

    if (term < course->term){ return true; }
    if (term > course->term){ return false; }

    if (subject < course->subject){ return true; }
    if (subject > course->subject){ return false; }

    if (code < course->code){ return true; }
    if (code > course->code){ return false; }

    if (section < course->section){ return true; }
    if (section > course->section){ return false; }

    return false;
}

void Course::print(){
    cout << setw(6) << left << id << "Term: " << setw(6) << term << setw(5) << subject << setw(5)
    << code << setw(4) << section << setw(7) << "Instr:" << setw(10) << instructor;
}

string Course::getTerm(){ return term; }

int Course::getId(){ return id; }

string Course::getFormatString(){
    return subject + " " + to_string(code) + "-" + section;
}