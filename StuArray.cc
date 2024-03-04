#include "StuArray.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

StuArray::StuArray(){
    size = 0;
}

StuArray::~StuArray(){
    for (int i = 0; i < size; i++){
        delete arr[i];
    }
}

void StuArray::add(Student* student){
    for (int i = 0; i < size; i++){
        if (student->lessThan(arr[i])){
            for (int j = size; j < i; j--){
                arr[j] = arr[j-1];
            }
            arr[i] = student;
            size++;
            return;
        }
    }
    arr[size] = student;
    size++;
}

void StuArray::print() const {
    for (int i = 0; i < size; i++){
        arr[i]->print();
        cout << endl;
    }
}

bool StuArray::find(string num, Student** stu) const {
    for (int i = 0; i < size; i++){
        if (arr[i]->getNumber() == num){
            *stu = arr[i];
            return true;
        }
    }
    *stu = nullptr;
    return false;
}