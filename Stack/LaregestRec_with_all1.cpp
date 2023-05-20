#include <bits/stdc++.h>
using namespace std;

#define R 4 
#define C 4

int largestHist(int arr[],int n) {
    stack <int> s;
    int res=0;
    int tp;
    int curr;
    
    for(int i=0;i<n;i++){
        while(s.empty()==false && arr[s.top()]>=arr[i]){
            tp=s.top();s.pop(); //jo element remove hua mtlb wo greater h i wale element se. 
            curr=arr[tp]* (s.empty() ? i : i - s.top() - 1);//toh i wala element uska next smaller h. and stack m iske neeche wala element 
            res=max(res,curr);                              //iss se bhi chota hoga. mtlb wo iska prev smaller h..
        }                                                   // toh area uss removed element ke liye removed*(i-s.top-1)
        s.push(i);                                          //i uska next smaller. and top prev smaller
    }
    while(s.empty()==false){//jinka next smaller nhi ho unke liye n aa jaega -1 ki jagah use n jo hoga next smaLLer...
        tp=s.top();s.pop();
        curr=arr[tp]* (s.empty() ? n : n - s.top() - 1);
        res=max(res,curr);
    }
    
    return res;
}

int maxRectangle(int mat[][C]) 
{ 
    int res = largestHist(mat[0],C); 
  
    for (int i = 1; i < R; i++) { 
  
        for (int j = 0; j < C; j++) 
            if (mat[i][j]) 
                mat[i][j] += mat[i - 1][j]; 

        res = max(res, largestHist(mat[i],C)); 
    } 
        return res;
}

int main() 
{ 
    int mat[][C] = { 
        { 0, 1, 1, 0 }, 
        { 1, 1, 1, 1 }, 
        { 1, 1, 1, 1 }, 
        { 1, 1, 0, 0 }, 
    }; 
  
    cout << "Area of maximum rectangle is " << maxRectangle(mat); 
  
    return 0;  
}