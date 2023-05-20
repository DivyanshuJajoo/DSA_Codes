//linear time
#include <bits/stdc++.h> 
using namespace std; 
 
const int CHAR=256; 
int fact(int n) 
{ 
    return (n <= 1) ? 1 : n * fact(n - 1); 
} 
 
int lexRank(string &str) 
{ 
    int res = 1; 
    int n=str.length();
    int mul= fact(n);
    int count[CHAR]={0};
    for(int i=0;i<n;i++)
        count[str[i]]++;  //count of individual characters
    for(int i=1;i<CHAR;i++)
        count[i]+=count[i-1];  //cumilitive count of charaters smaller than a given character
    for(int i=0;i<n-1;i++){
        mul=mul/(n-i);         
        res=res+count[str[i]-1]*mul;    //first loop counts all words starting with characters smaller than S
        for(int j=str[i];j<CHAR;j++)    //now s is fixed at first place and we go for second character.
            count[j]--;                 // since s is fixed so for all characters after s we decrease their count as s is fixed
    }                                   //so it is not to be included in permutations.........
    return res; 
} 
  
 
int main() 
{ 
    string str = "STRING"; 
    cout << lexRank(str); 
    return 0; 
}