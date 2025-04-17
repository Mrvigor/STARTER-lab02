// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    head = nullptr;
    tail = nullptr;
    Node* curr = source.head;
    while(curr != nullptr){
        this -> push_back(curr -> info);
        curr = curr -> next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* curr = head;
    while(curr != nullptr){
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
}


// return sum of values in list
int IntList::sum() const {
   int summation = 0;
   Node* curr = head;
   while(curr != nullptr){
        summation += curr ->info;
        curr = curr -> next;
   }
   return summation;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* curr = head;
    while(curr != nullptr){
        if (curr -> info == value){
            return true;
        }
        curr = curr -> next;
    }
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (head == nullptr) return 0;
    Node* curr = head -> next;
    int max = head -> info;
    while (curr != nullptr){
        if (curr -> info > max ){
            max = curr -> info;
        }
        curr = curr -> next;
    }
    return max; // REPLACE THIS NON-SOLUTION
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (count() == 0){
        return 0.0;
    }
    double result = static_cast<double> (sum()) / count();
    return result;
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* newnode = new Node;
    newnode -> info = value;
    newnode -> next = head;
    head = newnode;
    if(tail == nullptr){
        tail = newnode;
    }
}

// append value at end of list
void IntList::push_back(int value) {
    Node* newnode = new Node;
    newnode -> info = value;
    newnode -> next = nullptr;
    if (head == nullptr) {
        head = newnode;
        tail = newnode;
    } else {
        tail->next = newnode; 
        tail = newnode;
    }
}

// return count of values
int IntList::count() const {
   int cot = 0;
   Node* curr = head;
   while(curr != nullptr){
        cot ++;
        curr = curr -> next;
   }
   return cot;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this == &source) return *this;
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
    Node* srcCurrent = source.head;
    while (srcCurrent != nullptr) {
        this->push_back(srcCurrent->info);
        srcCurrent = srcCurrent->next;
    }
    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    head = nullptr;
    tail = nullptr;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}
