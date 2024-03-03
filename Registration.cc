#include <iostream>
#include <iomanip>
#include "Registration.h"
using namespace std;

int Registration::nextId = REG_ID;

Registration::Registration(Student* stu, Course* c) 
: id(nextId++), course(c), student(stu) {}

bool Registration::lessThan(Registration* reg) const {
    return (course->lessThan(reg->course));
}

void Registration::print() const {
    cout << setw(7) << left << id << setw(14) << left << student->getName() 
    << setw(5) << left << course->getTerm() << setw(20) << course->getFormatString();
}

Student* Registration::getStu() const { return student; }