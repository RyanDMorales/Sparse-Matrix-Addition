//
// Created by Ryan Morales on 9/23/16.
//

#include <iostream>
using namespace std;
#include "ArrayMatrix.h"
#include "LinkedListMatrix.h"
#include "ArgumentManager.h"

int main(int argc, char* argv[] ) {

    ArgumentManager am(argc, argv);
    string op = am.get("operation");
    string str = am.get("storage");
    string rec = am.get("recursive");
    string inputA = am.get("A");
    string inputB = am.get("B");
    string output = am.get("result");

    //string inputA = "a1.txt";
    //string inputB = "b1.txt";
    //string output = "1.out";
    //string str = "array";
    //string str = "linkedlist";
    //string op = "add";
    //string rec = "Yes";



    bool recursive = rec.length() > 0 && rec[0] == 'Y';

    if(str == "array") {
        ArrayMatrix *matrixA = new ArrayMatrix(inputA);
        ArrayMatrix *matrixB = new ArrayMatrix(inputB);
        ArrayMatrix *matrixC = new ArrayMatrix(matrixA);
        switch (op[0]) {
            case 'a':
                if (recursive) {
                    if(matrixC->addMatrixRecursive(matrixB)){
                        matrixC->cleanZeroes();
                        matrixC->cleanZeroes();
                        matrixC->sortMatrix();
                        matrixC->printToFile(output);
                        matrixC->printMatrix();
                        //cout<<"R"<<endl;
                        break;
                    }
                    cout<<"Matrix addition not possible!"<<endl;break;}
                else
                if(matrixC->addMatrix(matrixB)) {
                    matrixC->cleanZeroes();
                    matrixC->cleanZeroes();
                    matrixC->sortMatrix();
                    matrixC->printToFile(output);
                    matrixC->printMatrix();
                    //cout << "NR" << endl;
                    break;
                } else {cout<<"Matrix addition not possible!"<<endl;break;}

            default:break;
        }
    }
    else{
        LinkedListMatrix *matrixA = new LinkedListMatrix(inputA);
        LinkedListMatrix *matrixB = new LinkedListMatrix(inputB);
        LinkedListMatrix *matrixC = new LinkedListMatrix(matrixA);

        switch (op[0]) {
            case 'a':
                if (recursive) {
                    if(matrixC->addMatrixRecursive(matrixB)){
                        matrixC->cleanZeroes();
                        matrixC->cleanZeroes();
                        matrixC->sortMatrix();
                        matrixC->printToFile(output);
                        matrixC->printMatrix();
                        //cout<<"R"<<endl;
                        break;
                    }
                    cout<<"Matrix addition not possible!"<<endl;break;}
                else
                if(matrixC->addMatrix(matrixB)) {
                    matrixC->cleanZeroes();
                    matrixC->cleanZeroes();
                    matrixC->sortMatrix();
                    matrixC->printToFile(output);
                    matrixC->printMatrix();
                    //cout << "NR" << endl;
                    break;
                } else {cout<<"Matrix addition not possible!"<<endl;break;}

            default:break;
        }
    }

    return 0;
}
