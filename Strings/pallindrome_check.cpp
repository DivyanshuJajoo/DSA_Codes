#include <iostream>
#include <cstring>
using namespace std;

bool ispallindrome(string &str){
    int begin=0,end=str.length()-1;
    while(begin<end){
        if(str[begin]!=str[end]) return false;
        begin++;
        end--;
    }
    return true;
}

int main(){
string str="abccba";
if(ispallindrome(str))cout<<"true";
else cout<<"false";
return 0;
}