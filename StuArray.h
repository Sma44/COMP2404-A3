#ifndef STUARRAY_H
#define STUARRAY_H
#include "Student.h"
#include <string>
#include "defs.h"

class StuArray{
    public:
        StuArray();
        ~StuArray();
        void add(Student*);
        void print() const;
        bool find(std::string, Student**) const;
    private:
        Student* arr[MAX_ARR];
        int size;

};

#endif