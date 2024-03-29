#ifndef COURSEARRAY_H
#define COURSEARRAY_H
#include "Course.h"
#include <string>

/// @brief collections class to store course objects
class CourseArray{
    public:
        CourseArray();
        ~CourseArray();
        void add(Course*);
        void print();
        void print(std::string term);
        bool find(int, Course**);

    private:
        Course* arr[MAX_ARR];
        int size;
};
#endif