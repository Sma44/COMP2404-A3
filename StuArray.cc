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
    if(size == MAX_ARR) {
        cout << "student array length exceeded" << endl;
        return;
    }
    bool flag = false;

    if (size == 0){
        cout << "in size block\n";
        arr[size] = student;
        size++;
        return;
    }
    cout << "passed size check\n";

    cout << "size = " << size << endl;

    for (int i = 0; i < size; i++){
        student->print();
        cout << "\n";
        arr[i]->print();
        cout << endl;
        if (student->lessThan(arr[i])){
            cout << "entered lessTHan block\n";
            for (int j = size; j < i; j--){
                arr[j] = arr[j-1];
            }
            arr[i] = student;
            flag = true;
            size++;
            return;
        }
    }
    if (!flag){
        arr[size] = student;
    }
    size++;
}

void StuArray::print(){
    for (int i = 0; i < size; i++){
        arr[i]->print();
        cout << endl;
    }
}

bool StuArray::find(string num, Student** stu){
    for (int i = 0; i < size; i++){
        if (arr[i]->getNumber() == num){
            *stu = arr[i];
            return true;
        }
    }
    *stu = nullptr;
    return false;
}