#include "Course.h"
#include <iomanip>
#include <iostream>
#include <string>
#include "defs.h"
using namespace std;

int Course::nextId = COURSE_ID;

Course::Course(string t, string s, int c, char sec, string i) 
: id(nextId++), term(t), subject(s), code(c), section(sec), instructor(i){}

bool Course::lessThan(Course* course) const {

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

void Course::print() const {
    cout << setw(6) << left << id << "Term:" << term << setw(5) << subject
    << code << setw(4) << section << setw(7) << "Instr:" << setw(10) << instructor;
}

string Course::getTerm() const { return term; }

int Course::getId() const { return id; }

string Course::getFormatString() const {
    return subject + " " + to_string(code) + "-" + section;
}