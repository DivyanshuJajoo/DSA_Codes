#include <iostream>
#include <unordered_set>
using namespace std;

int Distinct(int arr[], int n){
unordered_set<int>s(arr,arr+n);
return s.size();
}

int main(){
int arr[]={10,20,30,30,50,40,20,10};
int n=8;
int p=Distinct(arr,8);
cout<<p;
return 0;
}