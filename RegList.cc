#include "RegList.h"
#include <iostream>
#include <iomanip>

RegList::RegList(): head(nullptr), tail(nullptr) {}

RegList::RegList(RegList& otherList, Student* stu){
    Node* currNode = otherList.head;

    while(currNode != nullptr){
        if (currNode->data->getStu()->getNumber() == stu->getNumber()){
            add(currNode->data);
        }
        currNode = currNode->next;
    }
}

RegList::~RegList(){
    Node* currNode = head;
    Node* nextNode;

    while(currNode != nullptr){
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }
}

void RegList::add(Registration* r){
    Node* prevNode = nullptr;
    Node* currNode = head;

    Node* newNode = new Node();
    newNode->data = r;
    newNode->next = nullptr;

    while(currNode != nullptr){
        if (r->lessThan(currNode->data)){
            break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (prevNode == nullptr){
        head = newNode;
    }else{
        prevNode->next = newNode;
    }
    
    newNode->next = currNode;

    if (currNode == nullptr){
        tail = newNode;
    }
}

void RegList::cleanData(){
    Node* currNode = head;
    Node* nextNode;

    while(currNode != nullptr){
        nextNode = currNode->next;
        delete currNode->data;
        currNode = nextNode;
    }
}

void RegList::print(){
    Node* currNode = head;
    Node* nextNode;

    while(currNode != nullptr){
        currNode->data->print();
        std::cout << std::endl;
        nextNode = currNode->next;
        currNode = nextNode;
    }
    std::cout << "HEAD: ";
    head->data->print();
    std::cout << std::endl << "Tail: ";
    tail->data->print();
    std::cout << std::endl;
}