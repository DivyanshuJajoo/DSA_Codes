//Hash value is used.here it stores sum of values of individual digit. eg a=1, b=2....
//if hash value sum of pattern is equal to the the sum of m no. of letters then it starts comparing.
//otherwise it does hash sliding by removing first letter and adding nextletter.
//however it will compare cba and abc also since they have same value.
//so to optimize furthur we use weighed sum. extra parameter D=5. abc= 1xD^2 +2xD + 3xD^0 which removes such cases....
// t(i+1)=d(ti-first character of previouswindowx d^m-1)+ t(i+m)
#include <bits/stdc++.h> 
using namespace std; 
#define d 256
const int q=101;
void RBSearch(string pat,string txt,int M, int N){
    
    //Compute (d^(M-1))%q
    int h=1;
    for(int i=1;i<=M-1;i++)
        h=(h*d)%q;
    
    //Compute p and t
    int p=0,t=0;
    for(int i=0;i<M;i++){
        p=(p*d+pat[i])%q;
        t=(t*d+txt[i])%q;
    }
    
    for(int i=0;i<=(N-M);i++){
       //Check for hit
       if(p==t){
           bool flag=true;
           for(int j=0;j<M;j++)
                if(txt[i+j]!=pat[j]){flag=false;break;}
            if(flag==true)cout<<i<<" ";
       }
       //Compute ti+1 using ti
       if(i<N-M){
           t=((d*(t-txt[i]*h))+txt[i+M])%q;
        if(t<0)t=t+q;
       }
    }
    
}
 
int main() 
{ 
    string txt = "GEEKS FOR GEEKS";string pat="GEEK";
    cout<<"All index numbers where pattern found:"<<" ";
    RBSearch(pat,txt,4,15);
    
    return 0; 
} 