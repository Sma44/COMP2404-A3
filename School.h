#ifndef SCHOOL_H
#define SCHOOL_H
#include "StuArray.h"
#include "CourseArray.h"
#include "RegList.h"
#include <string>

/// @brief school class to model relationship between students enrolled and their courses registered
class School{
    public:
        School(std::string="Not Defined");
        ~School();
        void addStudent(Student*);
        void addCourse(Course*);
        void addRegistration(Student*, Course*);
        bool findStudent(std::string, Student**);
        bool findCourse(int, Course**);
        void printStudents();
        void printCourses();
        void printCourseByTerm(std::string);
        void printRegistrations();
        void printRegistrationsByStu(Student*);

    private:
        std::string name;
        StuArray stuArr;
        CourseArray courseArr;
        RegList regList;
};
#endif