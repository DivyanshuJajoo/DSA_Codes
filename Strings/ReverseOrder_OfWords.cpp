#include <bits/stdc++.h> 
using namespace std; 
//instead of making this function we can directly use reverse(str+start, str+end) in c++****
void reverse(char str[],int low, int high){
    while(low<=high){
        swap(str[low],str[high]);
        low++;
        high--;
    }
}

void reverseWords(char str[],int n){
    int start=0;
    for(int end=0;end<n;end++){
        if(str[end]==' '){
            reverse(str+start,str+end);
            start=end+1;
        }
    }
    reverse(str,start,n-1);
    reverse(str,0,n-1);
}
 
int main() 
{ 
    char str[]="Welcome to Gfg";
    int n=strlen(str);//check as it may show extra size because of /0....
    // or create string s and convert to char str by using
    // string s = "Welcome to Gfg";int n=s.length();char str[n];
    // strcpy(str, s.c_str());
    cout<<"After reversing words in the string:"<<endl;
    reverseWords(str,n);
    for (int i = 0; i < n; i++) 
        cout << str[i];
    
    return 0; 
}  