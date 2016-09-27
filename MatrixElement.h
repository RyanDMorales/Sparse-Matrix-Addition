//
// Created by Ryan Morales on 9/25/16.
//



#ifndef SPARSE_PHASE_2_MATRIXELEMENT_H
#define SPARSE_PHASE_2_MATRIXELEMENT_H

#include <string>

using namespace std;
struct MatrixElement{
    int row = 0;                                    //row index
    int col = 0;                                    //col index
    double value = 0;                               //value at row and col index
};

//help functions
int max(int a, int b);
bool goodInput(string line);
bool greaterThan(MatrixElement a, MatrixElement b);


#endif //SPARSE_PHASE_2_MATRIXELEMENT_H
