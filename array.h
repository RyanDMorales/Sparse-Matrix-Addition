//
// Created by Ryan Morales on 9/23/16.
//

#ifndef SPARSE_PHASE_2_ARRAY_H
#define SPARSE_PHASE_2_ARRAY_H

#include "MatrixElement.h"

class Array{
    MatrixElement* elements;                    //elements in the MatrixElement
    int numOfElements;                          //number of elements in Array
    int sizeOfArray;                            //size of Array
    void increaseArraySize(int arraySize);      //increases the size of the array

public:
    Array();
    Array(int initialSize);
    ~Array();
    int getNumElements();
    void setNumOfElements(int num);
    MatrixElement *getMatrixElement(int index);
    void setMatrixElement(int index, MatrixElement* matrixElement);
    void addMatrixElement(MatrixElement* matrixElement);
};




#endif //SPARSE_PHASE_2_ARRAY_H
