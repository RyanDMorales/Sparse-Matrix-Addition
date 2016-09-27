//
// Created by Ryan Morales on 9/25/16.
//
#include "MatrixElement.h"

bool greaterThan(MatrixElement a, MatrixElement b){
    return a.row > b.row || (a.row == b.row && a.col > b.col);
}
int max(int a, int b) {
    return a > b ? a : b;
}
bool goodInput(string line){
    //If line length <= 0 return false
    if(line.length() <= 0){
        return false;
    }
    for(int i = 0; i < line.length(); i++){
        char currentChar = line[i];
        if(!((currentChar >= '0' && currentChar <= '9') || currentChar == '.' ||
             currentChar == ' ' || currentChar == '-')){
            return false;
        }
    }
    //if good return true
    return true;
}