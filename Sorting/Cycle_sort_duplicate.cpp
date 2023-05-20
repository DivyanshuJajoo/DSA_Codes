#include<bits/stdc++.h> 
using namespace std; 

void cycleSortDistinct(int arr[], int n) 
{ int swaps=0;
    for(int cs=0;cs<n-1;cs++){
        int item=arr[cs];
        int pos=cs;
        for(int i=cs+1;i<n;i++)
            if(arr[i]<item)
                pos++;
                  if (pos == cs)
            continue;
 
        // ignore all duplicate  elements
        while (item == arr[pos])
            pos += 1;
 
        // put the item to it's right position
        if (pos != cs) {
            swap(item, arr[pos]);
           
        }


            
        
        while(pos!=cs){
            pos=cs;
            for(int i=cs+1;i<n;i++)
                if(arr[i]<item)
                    pos++;
            swap(item,arr[pos]);
           
        }
    }
} 
  
int main() 
{ 
    int arr[] = { 20,20,50,10,30 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cycleSortDistinct(arr, n); 
   
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    return 0; 
} 