#include <iostream>
using namespace std;
#include <string>
#include "Control.h"

Control::Control(){
  school = new School("Carleton U. School of Computer Science");
}

Control::~Control(){
  delete school;
}

void Control::initStudents(School* sch)
{
  sch->addStudent(new Student("100567888", "Matilda", "CS"));
  sch->addStudent(new Student("100333444", "Harold", "Geography"));
  sch->addStudent(new Student("100444555", "Joe", "Physics"));
  sch->addStudent(new Student("100775588", "Timmy", "CS"));
  sch->addStudent(new Student("100111222", "Amy", "Math"));
  sch->addStudent(new Student("100222333", "Stanley", "Art History"));
}

void Control::initCourses(School* sch)
{
  sch->addCourse(new Course("F23", "COMP", 2401, 'A', "Laurendeau"));
  sch->addCourse(new Course("F23", "COMP", 2401, 'B', "Hillen"));
  sch->addCourse(new Course("F23", "COMP", 2401, 'C', "Laurendeau"));
  sch->addCourse(new Course("F23", "COMP", 2401, 'D', "Hillen"));
  sch->addCourse(new Course("F23", "COMP", 2402, 'A', "Shaikhet"));
  sch->addCourse(new Course("F23", "COMP", 2402, 'B', "Shaikhet"));
  sch->addCourse(new Course("F23", "COMP", 2404, 'A', "Hill"));
  sch->addCourse(new Course("F23", "COMP", 2404, 'B', "Hill"));
  sch->addCourse(new Course("F23", "COMP", 2406, 'A', "Nel"));
  sch->addCourse(new Course("F23", "COMP", 2406, 'B', "Shaikhet"));
  sch->addCourse(new Course("F23", "COMP", 2804, 'A', "Morin"));
  sch->addCourse(new Course("F23", "COMP", 2804, 'B', "Hill"));

  sch->addCourse(new Course("W24", "COMP", 2401, 'A', "CI"));
  sch->addCourse(new Course("W24", "COMP", 2401, 'B', "Lanthier"));
  sch->addCourse(new Course("W24", "COMP", 2402, 'A', "Sharp"));
  sch->addCourse(new Course("W24", "COMP", 2402, 'B', "Sharp"));
  sch->addCourse(new Course("W24", "COMP", 2404, 'A', "Hill"));
  sch->addCourse(new Course("W24", "COMP", 2404, 'B', "Laurendeau"));
  sch->addCourse(new Course("W24", "COMP", 2404, 'C', "Laurendeau"));
  sch->addCourse(new Course("W24", "COMP", 2406, 'A', "Nel"));
  sch->addCourse(new Course("W24", "COMP", 2406, 'B', "Nel"));
  sch->addCourse(new Course("W24", "COMP", 2804, 'A', "Hill"));
  sch->addCourse(new Course("W24", "COMP", 2804, 'B', "Hill"));
}

void Control::launch(){
  initStudents(school);
  initCourses(school);
  int userChoice;
  
  do{
    view.showAdminMenu(userChoice);
    switch(userChoice){
      case 1:
        school->printStudents();
        break;
      case 2:
        school->printCourses();
        break;
      case 3: 
        school->printRegistrations();
        break;
      case 4: 
        stuControlFlow();
        break;
      case 0: 
        view.printStr("\nExiting...\n");
        break;
    }      
  } while (userChoice != 0);
}

void Control::stuControlFlow(){
  int stuChoice, cId;
  string stuNum, term;
  bool cFound = false;
  Student* stu = nullptr;
  Course* course = nullptr;
  
  view.printStr("\nPlease enter student number: ");
  view.readStr(stuNum);

  while(!school->findStudent(stuNum, &stu)){
    view.printStr("\nERROR: Student number not found. Try again: ");
    view.readStr(stuNum);
  }
  view.printStr("\n\n");

  do{
    view.showStudentMenu(stu->getName(), stuChoice);
    switch(stuChoice){
      case 1: 
        view.printStr("\nenter a term: ");
        view.readStr(term);
        view.printStr("\n");
        school->printCourseByTerm(term);
        break;
      case 2: 
        school->printRegistrationsByStu(stu);
        break;
      case 3:
        cId = 0;
        view.printStr("\nPlease enter course id: ");
        view.readInt(cId);
        cFound = school->findCourse(cId, &course);
        if (!cFound){
          view.printStr("ERROR: Course not found\n");
          break;
        }
        school->addRegistration(stu,course);
        break;
      case 0: 
        view.printStr("\nExiting...\n");
        break;
    }
  } while (stuChoice != 0);
}
