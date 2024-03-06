#ifndef REGLIST_H
#define REGLIST_H
#include "Registration.h"

/// @brief collection class to store linked-list of registration objects
/// Note: Nodes are stored in increasing order based on the registration course
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