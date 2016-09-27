//
// Created by Ryan Morales on 9/25/16.
//

#ifndef SPARSE_PHASE_2_LINKEDLIST_H
#define SPARSE_PHASE_2_LINKEDLIST_H

#include "MatrixElement.h"

class Node{
public:
    Node *next;
    Node *prev;
    MatrixElement data;
};
class LinkedList {
private:
    Node *head;
    Node *tail;
    int numOfElements;
public:
    LinkedList();
    ~LinkedList();
    int getNumElements();
    void setNumOfElements(int num);
    MatrixElement *getMatrixElement(int index);
    void setMatrixElement(int index, MatrixElement* matrixElement);
    void addMatrixElement(MatrixElement* matrixElement);
};


#endif //SPARSE_PHASE_2_LINKEDLIST_H
