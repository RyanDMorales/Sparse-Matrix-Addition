//
// Created by Ryan Morales on 9/25/16.
//


#include "linkedlist.h"


LinkedList::LinkedList(){
    head = nullptr;
    tail = nullptr;
    numOfElements = 0;
}
LinkedList::~LinkedList() {
    Node *currentNode = head;
    Node *tempNode = nullptr;
    while(currentNode != nullptr){
        tempNode = currentNode;
        currentNode = currentNode->next;
        delete tempNode;
    }
}
//Gets number of elements
int LinkedList::getNumElements() {
    return numOfElements;
}
void LinkedList::setNumOfElements(int num) {
    numOfElements = num;
}
//Returns Matrix element at index
MatrixElement *LinkedList::getMatrixElement(int index){
    Node *currentNode = head;
    for(int i = 0; i < index; i++){
        currentNode = currentNode->next;
    }
    return &currentNode->data;
}
//Sets matrix element
void LinkedList::setMatrixElement(int index, MatrixElement *matrixElement) {
    Node *currentNode = head;
    for(int i = 0; i <index; i++){
        currentNode = currentNode->next;
    }
    currentNode->data = *matrixElement;
}
//Adds matrix element
void LinkedList::addMatrixElement(MatrixElement *matrixElement) {
    Node *newNode = new Node;
    if(head == nullptr){
        newNode->data = *matrixElement;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->data = *matrixElement;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    numOfElements++;
}

