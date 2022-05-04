#include <iostream>
#include "header.hpp"
using namespace std;
double sum(double arr [],int n){
    double sum=0;
    for(int i=0;i<n;i++){
    
        sum+=arr[i];
    }
    return sum;
}
double mean(double arr[],int n){
    return sum(arr,n)/n;
}
void print(double arr[],int n){
 for(int i=0;i<n;i++){
        cout<<"Array=";
        cout<<arr[i]<<" ";
    }
}
   
