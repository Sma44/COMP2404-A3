#include "School.h"
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

School::School(string n): name(n){}

School::~School(){
    regList.cleanData();
}

void School::addStudent(Student* stu){
    stuArr.add(stu);
}

void School::addCourse(Course* course){
    courseArr.add(course);
}

void School::addRegistration(Student* stu, Course* course){
    Registration* newReg = new Registration(stu, course);
    regList.add(newReg);
}

bool School::findStudent(string num, Student** stu){
    return stuArr.find(num, stu);
}

bool School::findCourse(int id, Course** course){
    return courseArr.find(id, course);
}

void School::printStudents(){
    cout << "STUDENTS OF " << name << endl;
    stuArr.print();
}

void School::printCourses(){
    cout << "COURSES OF " << name << endl;
    courseArr.print();
}

void School::printCourseByTerm(string term){
    cout << "COURSES OF " << name << " - TERM: " << term << endl;
    courseArr.print(term);
}

void School::printRegistrations(){
    cout << "REGISTRATIONS OF " << name << endl;
    regList.print();
}

void School::printRegistrationsByStu(Student* stu){
    cout << "REGISTRATIONS OF " << name << " - FOR STUDENT: " << stu->getName() << endl;
    RegList stuList(regList, stu);
    stuList.print();
}
