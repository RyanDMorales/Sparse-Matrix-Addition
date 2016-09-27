//
// Created by Ryan Morales on 9/23/16.
//

#ifndef SPARSE_PHASE_2_ARRAYMATRIX_H
#define SPARSE_PHASE_2_ARRAYMATRIX_H

#include "array.h"

class ArrayMatrix{
    int rows;
    int cols;
    Array *arrayList;
public:
    ArrayMatrix();
    ArrayMatrix(string filename);
    ArrayMatrix(ArrayMatrix *copy);
    ~ArrayMatrix();
    double getValueAtCoordinate(int row, int col);
    void setValueAtCoordinate(int row, int col, double value);
    void copyMatrix(ArrayMatrix *copy);
    bool additionCompatible(ArrayMatrix *matrix);
    bool addMatrix(ArrayMatrix* matrix);
    bool addMatrixRecursive(ArrayMatrix* matrix);
    void addMatrixRecursive(ArrayMatrix *matrix, int current);
    void cleanZeroes();
    void sortMatrix();
    void printMatrix();
    void printToFile(string filename);
};

#endif //SPARSE_PHASE_2_ARRAYMATRIX_H
