#include <iostream>
#include <queue>
using namespace std;

struct Stack{
  queue <int>q1,q2;
  int curr_size;

  Stack(){
    curr_size=0;
  }

  void push(int x){
    //queue m last entered element top pe hota h or sbse last m remove hota h.
    //stack m first entered element top pe hota h or sbse pahale m remove hota h.
    //isliye stack banane ke liye pahale q1 m insert krte h or q2 m fir daalte h one by one q1 se taki ulte order m add ho
    //using this we get desired result.... now q2 m reverse order m add honge

  curr_size++; 

		// Push x first in empty q2 
		q2.push(x); 

		// Push all the remaining 
		// elements in q1 to q2. 
		while (!q1.empty()) { 
			q2.push(q1.front()); 
			q1.pop(); 
		} 

		// swap the names of two queues 
		queue<int> q = q1; 
		q1 = q2; 
		q2 = q; 
  }

  void pop() 
	{ 

		// if no elements are there in q1 
		if (q1.empty()) 
			return; 
		q1.pop(); 
		curr_size--; 
	} 

	int top() 
	{ 
		if (q1.empty()) 
			return -1; 
		return q1.front(); 
	} 

	int size() 
	{ 
		return curr_size; 
	} 
};

int main(){
	Stack s; 
	s.push(10); 
	s.push(5); 
	s.push(15); 
	s.push(20);

	cout << "current size: " << s.size() << endl; 
	cout << s.top() << endl; 
	s.pop(); 
	cout << s.top() << endl; 
	s.pop(); 
	cout << s.top() << endl; 

	cout << "current size: " <<  s.size() << endl; 
return 0;
}