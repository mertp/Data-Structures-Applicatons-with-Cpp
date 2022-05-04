#include <iostream>
#include "header.hpp"
using namespace std;
int main(){

double arr[]={12,3,4,15};
int n=4;
cout<<"Array=";
print(arr,n); cout<<endl;
cout<<"Sum ="<<sum(arr,n)<<endl;
cout<<"Mean ="<<mean(arr,n)<<endl;
return 0;
}