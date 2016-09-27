Ryan Morales
PSID: 1251511

About:
This program adds two sparse matrices together using arrays and doublylinked list both recursively and non-recursively depending on the users preference.
**To compile**

```
$ g++ -std=c++11 *.cpp -o sparse
```

**To test all cases in directory**

```
$ sh test.sh
```

**To view code**

```
$ cat sparse.cpp
```

Algorithm Used For Matrix Addition:

```
	for(int i = 0; i < matrix->list->getNumElements(); i++){
        MatrixElement* current = matrix->list->getMatrixElement(i);
        this->setValueAtCoordinate(current->row, current->col, current->value
                                + this->getValueAtCoordinate(current->row, current->col))
```

**EXAMPLE: Compile and test.sh**

```
$ g++ -std=c++11 *.cpp -o sparse
```
```
$ sh test.sh
```

```
Checking workspace...
Makefile OK
sparse.cpp OK
Test cases...
a1.txt OK
b1.txt OK
1.ans OK
a2.txt OK
b2.txt OK
2.ans OK
a3.txt OK
b3.txt OK
3.ans OK
Compiling...
rm -f sparse *.diff *.stdout *.stderr TIMEOUT COMPILE.err *.out
g++ -Wall -std=c++11 -o sparse *.cpp
Testing...
Program name is sparse.
Test case 1
    PASSED.
Test case 2
    PASSED.
Test case 3
    PASSED.
```

**EXAMPLE: Running individual test cases**

```
$ ./sparse "operation=add;A=a3.txt;B=b3.txt;recursive=N;result=3.out"
```

```
#Matrix C=A+B
2 9 2.00
3 18 2.00
100 1 1.00
100 2 1.00
100 3 4.50
100 12 -115.00
100 13 5.00
1000 20 0.10
100000 100000 -1.00
```

```
$ ./sparse "operation=add;A=10a.txt;B=10b.txt;storage=array;recursive=N;result=10.out"
```

```
#Matrix C=A+B
1 1 1.00
2 2 7.00
7 14 9.00
9 4 4.00
1000 1000 19.00
```
```
$ ./sparse "operation=add;A=10a.txt;B=10b.txt;storage=linkedlist;recursive=N;result=10.out"
```

```
#Matrix C=A+B
1 1 1.00
2 2 7.00
7 14 9.00
9 4 4.00
1000 1000 19.00
```
```
$ ./sparse "operation=add;A=10a.txt;B=10b.txt;storage=linkedlist;recursive=Y;result=10.out"
```

```
#Matrix C=A+B
1 1 1.00
2 2 7.00
7 14 9.00
9 4 4.00
1000 1000 19.00
```