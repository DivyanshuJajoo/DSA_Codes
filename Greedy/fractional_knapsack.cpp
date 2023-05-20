#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool MyCmp(pair<int,int>a,pair<int,int>b){
    return (((double)a.second/a.first)>((double)b.second/b.first));
}

int MaxCapacity(pair<int,int>arr[],int cap, int n){

    sort(arr,arr+n,MyCmp);
    double res=0.0;
    for(int i=0;i<n;i++){
        if(arr[i].first<=cap){
            res+=arr[i].second;
            cap-=arr[i].first;
        }
        else{
            res= ((double)arr[i].second/arr[i].first)*cap;
            return res;
        }
    }


}

int main(){
    pair<int,int>arr[]= {make_pair(50,600),make_pair(30,400),make_pair(20,500)};
    int capacity=70;
    int n=3;
    cout<<"The maximum value is: "<<MaxCapacity(arr,capacity,n)<<endl;

return 0;
}