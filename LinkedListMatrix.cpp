//
// Created by Ryan Morales on 9/25/16.
//



#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include "LinkedListMatrix.h"
//help functions
int max(int a, int b);
bool goodInput(string line);
bool greaterThan(MatrixElement a, MatrixElement b);

LinkedListMatrix::LinkedListMatrix() {
    rows = 0;
    cols = 0;
    list = new LinkedList;
}

LinkedListMatrix::LinkedListMatrix(string filename) : LinkedListMatrix(){
    fstream ifs(filename.c_str());
    if(ifs.fail()){                                        //Checks to see if there is an input file
        cout<<"Error File: "<< filename<< " "<< "could not be opened!"<<endl;          //Prints error is file does not open or exists
        return;
    }
    else {
        if(ifs.peek() == ifstream::traits_type::eof()){    //Checks to see if the file is empty
            cout<<"Error: File is empty!!!"<<endl;
            return;
        }
    }
    //Matrix that holds zero values
    LinkedListMatrix *zeroMatrix = new LinkedListMatrix();

    while(!ifs.eof()){
        //break at end of file
        if(ifs.eof()){
            break;
        }
        //get line
        string line;
        getline(ifs, line);

        //check if input is valid
        if(goodInput(line)){
            //parse string
            int row = 0, col = 0;
            double value = 0;
            stringstream fn(line);
            fn >> row >> col >> value;

            //if value == 0, add to zero matrix;
            if(value == 0){
                zeroMatrix->setValueAtCoordinate(row, col, value);
            }
            else{
                this->setValueAtCoordinate(row, col, value);
            }
        }
    }
    //if zeroMatrix row, col or both are bigger, then add biggest zero to matrix
    if((zeroMatrix->rows >= this->rows && zeroMatrix->cols >= this->cols)){
        this->setValueAtCoordinate(zeroMatrix->rows, zeroMatrix->cols, 0);
    }

    //Delete zeroMatrix
    delete zeroMatrix;

    //sort the Matrix
    this->sortMatrix();
}

LinkedListMatrix::~LinkedListMatrix() {
    delete list;
}

LinkedListMatrix::LinkedListMatrix(LinkedListMatrix *copy) : LinkedListMatrix() {
    this->copyMatrix(copy);
}
//Returns value at coordinates
double LinkedListMatrix::getValueAtCoordinate(int row, int col) {
    for(int i = 0; i < this->list->getNumElements();i++){
        MatrixElement* current = this->list->getMatrixElement(i);
        if(current->row == row && current->col == col){
            return current->value;
        }
    }
    return 0;
}
//Sets value at coordinates
void LinkedListMatrix::setValueAtCoordinate(int row, int col, double value) {
    //Update Max rows and cols
    this->rows = max(this->rows, row);
    this->cols = max(this->cols, col);
    for(int i = 0; i < this->list->getNumElements();i++){
        MatrixElement* current = this->list->getMatrixElement(i);
        if(current->row == row && current->col == col){
            current->value = value;
            return;
        }
    }
    MatrixElement* newElement = new MatrixElement;
    newElement->row = row;
    newElement->col = col;
    newElement->value = value;
    this->list->addMatrixElement(newElement);
}
//Copies Matrix
void LinkedListMatrix::copyMatrix(LinkedListMatrix *copy) {
    for(int i = 0; i < copy->list->getNumElements(); i++){
        MatrixElement* current = copy->list->getMatrixElement(i);
        this->setValueAtCoordinate(current->row, current->col, current->value);
    }
}
//Checks to see if Matrix is Compatible for additon
bool LinkedListMatrix::additionCompatible(LinkedListMatrix *matrix) {
    return matrix->rows == this->rows && matrix->cols == this->cols;
}
//Adds matrices together
bool LinkedListMatrix::addMatrix(LinkedListMatrix *matrix) {
    if(!this->additionCompatible(matrix)){
        return false;
    }
    for(int i = 0; i < matrix->list->getNumElements(); i++){
        MatrixElement* current = matrix->list->getMatrixElement(i);
        this->setValueAtCoordinate(current->row, current->col, current->value
                                                               + this->getValueAtCoordinate(current->row, current->col));
    }
    return true;
}
//Adds matrices together
bool LinkedListMatrix::addMatrixRecursive(LinkedListMatrix *matrix) {
    if(!this->additionCompatible(matrix)){
        return false;
    }
    addMatrixRecursive(matrix, 0);
    return true;
}
//Adds matrices together
void LinkedListMatrix::addMatrixRecursive(LinkedListMatrix *matrix, int current) {
    if(current == matrix->list->getNumElements()){
        return;
    }
    MatrixElement currentElement = *matrix->list->getMatrixElement(current);
    currentElement.value += this->getValueAtCoordinate(currentElement.row, currentElement.col);

    this->setValueAtCoordinate(currentElement.row, currentElement.col, currentElement.value);
    addMatrixRecursive(matrix, current+1);
}
//Sorts Matrix
void LinkedListMatrix::sortMatrix() {
    // simple insertion sort in ascending order
    int i, j;
    for(i = 1; i < this->list->getNumElements(); i++){
        MatrixElement currentElement = *this->list->getMatrixElement(i);
        for(j = i-1; j>= 0 && greaterThan(*this->list->getMatrixElement(j), currentElement); j--){
            this->list->setMatrixElement(j+1, this->list->getMatrixElement(j));
        }
        this->list->setMatrixElement(j+1, &currentElement);
    }
}
void LinkedListMatrix::cleanZeroes() {
    int i, j;
    for(i = 0; i < list->getNumElements(); i++){
        MatrixElement currentElement = *this->list->getMatrixElement(i);
        if(currentElement.value == 0 && ((currentElement.row != rows) && (currentElement.col != cols))){
            for(j = i; j < list->getNumElements() - 1; j++){
                currentElement = *this->list->getMatrixElement(j+1);
                this->list->setMatrixElement(j, &currentElement);
            }
            list->setNumOfElements(list->getNumElements()-1);
        }
    }
}
//Prints Matrix
void LinkedListMatrix::printMatrix() {
    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(2);
    cout<<"#Matrix C=A+B"<<endl;
    for(int i = 0; i < this->list->getNumElements(); i++){
        MatrixElement* current = this->list->getMatrixElement(i);
        cout<<current->row<<" "<<current->col<<" "<<current->value<<endl;
    }
}
//Prints Matrix to file
void LinkedListMatrix::printToFile(string filename) {
    ofstream ofs(filename.c_str());
    ofs<<"#Matrix C=A+B"<<endl;
    ofs.setf(ios::fixed | ios::showpoint);
    ofs.precision(2);
    for(int i = 0; i < this->list->getNumElements(); i++){
        MatrixElement *current = this->list->getMatrixElement(i);
        ofs<<" "<<current->row<<" "<<current->col<<" "<<current->value<<endl;
    }
}
