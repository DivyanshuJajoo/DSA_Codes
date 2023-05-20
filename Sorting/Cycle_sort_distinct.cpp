#include<bits/stdc++.h> 
using namespace std; 

int cycleSortDistinct(int arr[], int n) 
{ int swaps=0;
    for(int cs=0;cs<n-1;cs++){
        int item=arr[cs];
        int pos=cs;
        for(int i=cs+1;i<n;i++)
            if(arr[i]<item)
                pos++;
                if (pos == cs)
            continue;
        if (pos != cs) {
            swap(item, arr[pos]);
           
        }
        swaps++;
        while(pos!=cs){
            pos=cs;
            for(int i=cs+1;i<n;i++)
                if(arr[i]<item)
                    pos++;
            swap(item,arr[pos]);
            swaps++;
        }
    }return swaps;
} 
  
int main() 
{ 
    int arr[] = { 20,40,50,10,30 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int m=cycleSortDistinct(arr, n); 
   
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
        cout<<endl;
        cout<<"No. of swaps done are "<<m;
    return 0; 
} 