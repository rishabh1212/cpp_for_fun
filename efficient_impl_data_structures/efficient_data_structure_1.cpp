/*Consider a data structure that stores a sequence of n integers.
The operations to be performed on the sequence are:

(i) set(i,x) : sets the ith element to x.
(ii) find(i) : returns the ith element in the sequence. 
(iii) All_equal() : returns true if and only if all elements in the
      sequence are equal.

Describe a data structure that implements these operations in O(1)
time. Assume that initially, all elements in the sequence are 0,
and initialization can take O(n) time. Can you do this if another
operation At_most_two() is required, which returns true iff the
sequence contains at most two distinct values?*/
#include <iostream>
using namespace std;
class find_f{
	int *a,s,n;
public:
	find_f(int m){
		a=new int[m];
		n=m;
		for(int i=0;i<n;i++){
			a[i]=0;
		}
		s=0;
	}
	void set(int i,int x){
		if(i>0&&i<n-1){
			if(a[i]>a[i+1]){
				s=s-(a[i]-a[i+1]);
			}
			else{
				s=s-(a[i+1]-a[i]);
			}
			
			if(a[i]>a[i-1]){
				s=s-(a[i]-a[i-1]);
			}
			else{
				s=s-(a[i-1]-a[i]);
			}
			
			a[i]=x;
			if(a[i]>a[i+1]){
				s=s+(a[i]-a[i+1]);
			}
			else{
				s=s+(a[i+1]-a[i]);
			}
			
			if(a[i]>a[i-1]){
				s=s+(a[i]-a[i-1]);
			}
			else{
				s=s+(a[i-1]-a[i]);
			}
		}
			
		a[i]=x;
	}
	int find(int i){
		return a[i];
	}
	int allequal(){
		if(n==2){
			return a[0]==a[1];
		}
		else{
			if(s==0){
				return 1;
			}
			else{
				return 0;
			}
		}
	}
};
int main(){
	find_f h(5);
	h.set(0,5);
	h.set(1,5);
	h.set(2,5);
	h.set(3,5);
	h.set(4,5);
	h.set(1,3);
	cout<<h.allequal();
}