//============================================================================
// Name        : HeapSort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void print(int A[],int N){
    cout<<"------heap-------"<<endl;
    for (int i = 0; i < N; i++) {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}


//Heapify downward (max-heap)
void heapify(int A[], int root, int N) {
    int L, R, child;
    L = 2 * root + 1;//left child
    R = 2 * root + 2;//right child
    /* find the big child*/
    child = L;//select left child initially

    if (child < N) {//if there is left child
        if (R < N) {//if there is right child
            if (A[R] > A[L])//which one is big
                child = R; //select right child
        }
        if (A[root] < A[child] ) {
            swap(A[root],A[child]);
            heapify(A, child, N);
        }
    }
}

void heapSort(int A[], int N) {
    //heapify the array first before sorting
    for (int root = N/2-1; root >= 0; root--) {
        heapify(A, root, N);//O(log(n))
    }

    //sort O(nlog(n))
    for (int last = N - 1; last > 0;last--) {
        //heap sort
        swap(A[0], A[last]);
        //heapify array again
        heapify(A, 0, last); // O(log(n))

    }
}


void randomArray(int *A,int N){
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        A[i]=rand()%(10*N);
    }
}

int main(int argc, char** argv) {
    int N=8;
    //int A[N];randomArray(A, N);
    int A[]={5,3,1,4,2,8,7,6};
    print(A,N);
    heapSort(A,N);
    print(A,N);
    return 0;
}
