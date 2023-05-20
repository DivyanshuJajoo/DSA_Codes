#include <iostream>
using namespace std;

int ipartition(int arr[], int l, int h)
{   
    int pivot=arr[l];
    int i=l-1,j=h+1;
    while(true){
        do{
            i++;
        }while(arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i>=j)return j;
        swap(arr[i],arr[j]);
    }
}
int Qsort(int arr[],int l,int h){
    if(l<h){
        int p=ipartition(arr,l,h);
        Qsort(arr,l,p);
        Qsort(arr,p+1,h);
    }
}

int ChocDistri(int arr[],int n,int l, int h, int k){
    Qsort(arr,l,h);
    int minimum=arr[k-1]-arr[0];
    for(int i=k;i<n;i++){
        minimum= min(minimum,(arr[i]-arr[i-k]));
    }
    return minimum;
}
int main(){
    int arr[]={7,3,2,4,9,12,56};
    int n=sizeof(arr)/sizeof(arr[0]);
	int k=4;
    int ans= ChocDistri(arr,n,0,n-1,k);
    cout<<ans;
    

return 0;
}