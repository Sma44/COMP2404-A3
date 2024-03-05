#ifndef STUDENT_H
#define STUDENT_H
#include <string>

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