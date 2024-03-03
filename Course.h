#ifndef COURSE_H
#define COURSE_H
#include <string>
#include "defs.h"

class Course{
    public:
        Course(std::string="N/A", std::string="N/A", int=0, char='N', std::string="N/A");
        bool lessThan(Course*) const;
        void print() const;
        int getId() const;
        std::string getTerm() const;
        std::string getFormatString() const;

    private:
        static int nextId; 
        int id;
        std::string term;
        std::string subject;
        int code;
        char section;
        std::string instructor;

};


#endif