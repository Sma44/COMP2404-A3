#include "Student.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;


Student::Student(string num, string n, string pgm) {
    majorPgm = pgm;
    name = n;
    number = num;
}

bool Student::lessThan(Student* stu){
    // cout << "current student name: "<< name << endl;
    // cout << "other student name: "<< stu->name << endl;
    return (name < stu->name) ? true : false;
}

void Student::print(){
    cout << left << setw(10) << number << left << setw(10) <<  name << left << setw(10) << majorPgm;
}

string Student::getNumber(){ return number; }

string Student::getName(){ return name; }

