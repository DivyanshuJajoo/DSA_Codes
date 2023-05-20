#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

void printNum(int n){
    queue <string>q;
    q.push("5");
    q.push("6");
    for(int i=0;i<n;i++){
        string str=q.front();
        cout<<str<<" ";
        q.pop();
        q.push(str + "5");
        q.push(str + "6");        

    }

}

int main() 
{ 
	int n = 5;
		
	printNum(n);
} 