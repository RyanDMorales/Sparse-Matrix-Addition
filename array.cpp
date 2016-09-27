//
// Created by Ryan Morales on 9/23/16.
//

#include "array.h"

Array::Array() {
    elements = nullptr;
    sizeOfArray = 0;
    numOfElements = 0;
}
Array::Array(int initialSize) {
    elements = new MatrixElement[initialSize];
    numOfElements = 0;
    sizeOfArray = initialSize;
}
Array::~Array() {
    delete[] elements;
}
//Increases size of the Array
void Array::increaseArraySize(int arraySize){
    //return; if arraySize is smaller than sizeOfArray
    if(arraySize < sizeOfArray){
        return;
    }
    //Create new array
    MatrixElement *newArray = new MatrixElement[arraySize];
    //Copy old array data to new array data
    for(int i = 0; i < sizeOfArray; i++){
        newArray[i] = elements[i];
    }
    //Delete old elements array
    delete[] elements;
    // set elements to newArray size
    elements = newArray;
    //increase sizeOfArray to new size
    sizeOfArray = arraySize;
}
//Gets number of elements
int Array::getNumElements() {
    return numOfElements;
}
void Array::setNumOfElements(int num) {
    numOfElements = num;
}
//Returns Matrix element at index
MatrixElement* Array::getMatrixElement(int index){
    return &elements[index];
}
//Sets matrix element
void Array::setMatrixElement(int index, MatrixElement* matrixElement){
    //If trying to add outside of the element size
    if(index >= sizeOfArray){
        return;
    }
    //Add element to index
    elements[index] = *matrixElement;
}
//Adds matrix element
void Array::addMatrixElement(MatrixElement* matrixElement){
    //If array size is at max capacity increase it by 1
    if(sizeOfArray == numOfElements){
        increaseArraySize(sizeOfArray+1);
    }
    //Add elements to numOfElements
    setMatrixElement(numOfElements, matrixElement);
    //Increase numOfElements
    numOfElements++;
}