// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    //IMPLEMENT THIS
    /*
    if (source==nullptr)
    {
      return nullptr;
    }
    */
    Node *temp = source.first;

    while(temp)
    {
      (*this).append(temp->info);

      temp = temp->next;
    }

    






}

// destructor deletes all nodes
IntList::~IntList() {
    //IMPLEMENT THIS

    Node *head = this->first;

    Node *temp = head;

    while(head)
    {
      temp = head->next;

      delete head;

      head = temp;
    }


}


// return sum of values in list
int IntList::sum() const {
    Node *temp = first;

    int total = 0;

    while(temp)
    {
      total = total + (temp->info);

      temp = temp->next;
    }





    return total; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {

    Node *temp = first;

    while(temp)
    {
      if(temp->info==value)
      {
        return true;
      }
      temp = temp->next;
    }
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    int max = 0;
    Node *temp = first;

    while(temp)
    {
      if(temp->info>max)
      {
        max = temp->info;
      }
      temp = temp->next;
    }
    return max; // REPLACE THIS NON-SOLUTION
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {

    if (this->first ==nullptr)
    {
      return 0;
    }

    double sum = (double) ((*this).sum());


    return sum/((*this).count()); 
    // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    // IMPLEMENT

    Node *head = new Node;

    head->info = value;

    head->next = this->first;

    this->first = head;

    


}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //IMPLEMENT
    Node *head = this->first;

    Node *temp = head;

    while(head)
    {
      temp = head->next;

      delete head;

      head = temp;
    }
    


    this->first = nullptr;

    temp = source.first;

    while(temp)
    {
      (*this).append(temp->info);

      temp = temp->next;
    }
    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
