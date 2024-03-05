#include "Student.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;


Student::Student(string num, string n, string pgm) 
: number(num), name(n), majorPgm(pgm){}

bool Student::lessThan(Student* stu){
    return (name < stu->getName()) ? true : false;
}

void Student::print(){
    cout << left << setw(10) << number <<  name << majorPgm;
}

string Student::getNumber(){ return number; }

string Student::getName(){ return name; }

