
//
// Zübeyr Furkan Eryilmaz
// 21202676
// CS 202 - 01
// Assignment 3
//


#ifndef HEAPSORT_HEAP_H
#define HEAPSORT_HEAP_H


class heap {

public:

    heap();
    heap( int numberOfElements);
    ~heap();

    void insert(const int a);
    int maximum();
    int popMaximum();
    int getComparisons();

private:

    int*  heapArr;
    int free; // beginning index of array's empty part
    int maxNumberOfElements;
    long long numberOfComparisons;
    void swap(int &a, int &b);

};


#endif //HEAPSORT_HEAP_H
