#ifndef REGISTRATION_H
#define REGISTRATION_H
#include "Course.h"
#include "Student.h"

/// @brief registration class to model student-course relationship
/// Note: the lessThan function is a strict less than equality
class Registration{
    public:
        Registration(Student*, Course*);
        bool lessThan(Registration*);
        void print();
        Student* getStu();

    private:
        static int nextId;
        int id;
        Course* course;
        Student* student;
};
#endif