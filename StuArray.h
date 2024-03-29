#ifndef STUARRAY_H
#define STUARRAY_H
#include "Student.h"
#include <string>
#include "defs.h"

/// @brief collection class for student objects
class StuArray{
    public:
        StuArray();
        ~StuArray();
        void add(Student*);
        void print();
        bool find(std::string, Student**);
    private:
        Student* arr[MAX_ARR];
        int size;

};
#endif