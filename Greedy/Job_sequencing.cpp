//Max profit
// One unit by every job
// only one job can be assigned at a time
// time starts with 0
//eg 4 1 1 1 dealines h toh 1 walo m se sbe jada profit wala lenge then jo  4 baje tk krni h usko lenge
//pair.first deadline .second profit
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool MyCmp(pair<int,int>a,pair<int,int>b){
    return a.second>b.second;
}

bool checkprev(bool slot[] ,int n){
    for(int i=0;i<n;i++){
        if(!slot[i]) {
            slot[i]=true;
            return true;
        }
    }
    return false;
}

int MaxProfit(pair<int,int>arr[],int n){
    sort(arr,arr+n,MyCmp);
    int res=0;
    bool slot[n];
    for(int i=0;i<n;i++){
        if(!slot[arr[i].first]){
            res+=arr[i].second;
            slot[arr[i].first]=true;
        }
        else if(slot[arr[i].first]&& checkprev(slot,arr[i].first)){
            res+=arr[i].second;
        }

    }
    return res;

}

int main(){
    pair<int,int>arr[]={make_pair(4,50),make_pair(1,5),make_pair(1,20),make_pair(5,10),make_pair(5,50)};
    cout<<"The maximum profit is: "<<MaxProfit(arr,5);

return 0;
}