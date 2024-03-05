#include "CourseArray.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

CourseArray::CourseArray(){
    size = 0;
}

CourseArray::~CourseArray(){
    for (int i = 0; i < size; i++){
        delete arr[i];
    }
}

void CourseArray::add(Course* course){
    if(size == MAX_ARR) {
        cout << "course array length exceeded" << endl;
        return;
    }

    for (int i = 0; i < size; i++){
        if (course->lessThan(arr[i])){
            for (int j = size; j < i; j--){
                arr[j] = arr[j-1];
            }
            arr[i] = course;
            size++;
            return;
        }
    }
    arr[size] = course;
    size++;
}

void CourseArray::print(){
    for (int i = 0; i < size; i++){
        arr[i]->print();
        cout << endl;
    }
}

void CourseArray::print(string term){
    for (int i = 0; i < size; i++){
        if (arr[i]->getTerm() == term){
            arr[i]->print();
            cout << endl;
        }
    }
}

bool CourseArray::find(int id, Course** c){
    for (int i = 0; i < size; i++){
        if (arr[i]->getId() == id){
            *c = arr[i];
            return true;
        }
    }
    *c = nullptr;
    return false;
}