#ifndef REGLIST_H
#define REGLIST_H
#include "Registration.h"

class RegList{
    class Node{
        public:
            Registration* data;
            Node* next;
    };

    public:
        RegList();
        RegList(RegList&, Student*);
        ~RegList();
        void add(Registration*);
        void cleanData();
        void print();

    private:
        Node* head;
        Node* tail;

};

#endif