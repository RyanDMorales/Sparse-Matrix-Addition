//
// Created by Ryan Morales on 9/25/16.
//

#ifndef SPARSE_PHASE_2_LINKEDLISTMATRIX_H
#define SPARSE_PHASE_2_LINKEDLISTMATRIX_H

#include "linkedlist.h"

class LinkedListMatrix {
    int rows;
    int cols;
    LinkedList *list;
public:
    LinkedListMatrix();
    LinkedListMatrix(string filename);
    LinkedListMatrix(LinkedListMatrix *copy);
    ~LinkedListMatrix();
    double getValueAtCoordinate(int row, int col);
    void setValueAtCoordinate(int row, int col, double value);
    void copyMatrix(LinkedListMatrix *copy);
    bool additionCompatible(LinkedListMatrix *matrix);
    bool addMatrix(LinkedListMatrix* matrix);
    bool addMatrixRecursive(LinkedListMatrix* matrix);
    void addMatrixRecursive(LinkedListMatrix *matrix, int current);
    void cleanZeroes();
    void sortMatrix();
    void printMatrix();
    void printToFile(string filename);
};


#endif //SPARSE_PHASE_2_LINKEDLISTMATRIX_H
