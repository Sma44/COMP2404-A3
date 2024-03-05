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
        view.printStr("\n\n\n");
        school->printStudents();
        view.printStr("\n");
        break;
      case 2:
        view.printStr("\n\n\n");
        school->printCourses();
        view.printStr("\n");
        break;
      case 3: 
        view.printStr("\n\n\n");
        school->printRegistrations();
        view.printStr("\n");
        break;
      case 4: 
        view.printStr("\n\n\n");
        stuControlFlow();
        view.printStr("\n");
        break;
      case 0: 
        break;
      default:
        view.printStr("\nUser Choice Invalid. Try again:\n");
        break;
    }      
  } while (userChoice != 0);
}

void Control::stuControlFlow(){
  int stuChoice;
  string stuNum;
  
  view.printStr("Please enter student number: ");
  view.readStr(stuNum);

  Student* stu = nullptr;
  while(!school->findStudent(stuNum, &stu)){
    view.printStr("\nERROR: Student number not found. Try again: ");
  }
  view.printStr("\n\n\n");

  do{
    view.showStudentMenu(stu->getName(), stuChoice);
    string term;
    switch(stuChoice){
      case 1: 
        view.printStr("enter a term: ");
        view.readStr(term);
        view.printStr("\n\n");
        school->printCourseByTerm(term);
        view.printStr("\n\n\n");
        break;
      case 2: // View registrations by student
        view.printStr("\n\n");
        school->printRegistrationsByStu(stu);
        view.printStr("\n\n");
        break;
      case 3:
        int cId;
        view.printStr("\nPlease enter course id: ");
        Course* course = nullptr;
        bool cFound = school->findCourse(cId, &course);
        if (!cFound){
          view.printStr("ERROR: Course not found\n");
          break;
        }
        school->addRegistration(stu,course);
        break;
      case 0: 
        break;
      default:
        view.printStr("ERROR: choice invalid\n");
        break;
    }
  } while (stuChoice != 0);
}
