#ifndef STUDENT_H
#define STUDENT_H
#include <string>

/// @brief student class models a student and their attributes
/// Note: the lessThan function is a strict less than equality
class Student{
    public:
        Student(std::string="N/A", std::string="N/A", std::string="N/A");
        bool lessThan(Student*);
        void print();
        std::string getNumber();
        std::string getName();

    private:
        std::string number;
        std::string name;
        std::string majorPgm;
};
#endif