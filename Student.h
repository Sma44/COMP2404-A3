#ifndef STUDENT_H
#define STUDENT_H
#include <string>

class Student{
    public:
        Student(std::string="N/A", std::string="N/A", std::string="N/A");
        bool lessThan(Student*) const;
        void print() const;
        std::string getNumber() const;
        std::string getName() const;

    private:
        std::string number;
        std::string name;
        std::string majorPgm;
};

#endif