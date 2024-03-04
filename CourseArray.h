#ifndef COURSEARRAY_H
#define COURSEARRAY_H
#include "Course.h"
#include <string>


class CourseArray{
    public:
        CourseArray();
        ~CourseArray();
        void add(Course*);
        void print() const;
        void print(std::string term) const;
        bool find(int, Course**) const;

    private:
        Course* arr[MAX_ARR];
        int size;

};

#endif