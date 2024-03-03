#ifndef REGISTRATION_H
#define REGISTRATION_H
#include "Course.h"
#include "Student.h"

class Registration{

    public:
        Registration(Student*, Course*);
        bool lessThan(Registration*) const;
        void print() const;
        Student* getStu() const;

    private:
        static int nextId;
        int id;
        Course* course;
        Student* student;

};


#endif