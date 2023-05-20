//one possibleviolation in heap....fix it....O(h) or O(logn) kyuki h =logn
#include <iostream>
#include<limits.h>
using namespace std;

struct MinHeap{
    int *arr;
    int size;
    int cap;
    MinHeap(int c){
        cap=c;
        size=0;
        arr=new int(c);

    }
    int left(int i) { return (2*i + 1); } 
    int right(int i) { return (2*i + 2); } 
    int parent(int i) { return (i-1)/2; } 

    void insert(int x){
        if(size==cap) return;
        size++;
        arr[size-1]=x;
        for(int i=size-1;i!=0&&arr[parent(i)]>arr[i];){
            swap(arr[i],arr[parent(i)]);
            i=parent(i);
        }
    }

    void Heapify(int i){
        int lt=left(i);
        int rt=right(i);
        int small=i;
        if(lt<size&& arr[lt]<arr[i]){
            small=lt;
        }
        if(rt<size&&arr[lt]<arr[small]){
            small=rt;
        }
        if(small!=i){
            swap(arr[small], arr[i]);
            Heapify(small);//small index. not arr[small]....
        }

    }
    //to remove and return min element that is the root.....
    int ExtractMin(){//O(logn)
        if (size <= 0) 
        return INT_MAX; 
    if (size == 1) 
    { 
        size--; 
        return arr[0]; 
    }  
    swap(arr[0],arr[size-1]);
    size--; 
    Heapify(0); 
  
    return arr[size];

    }
};

int main(){
    MinHeap h(11);
    h.insert(3); 
    h.insert(2);
    h.insert(15);
    h.insert(20);
    cout << h.ExtractMin() << " ";

return 0;
}