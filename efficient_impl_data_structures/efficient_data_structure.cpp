/*1.  A data structure is required to maintain a set of n boolean
flags, each of which may be true or false. The operations to be performed
are:

a) set(i) : set the ith flag to true. 
b) reset(i) : set the ith flag to false.
c) test(i) : return the value of the ith flag.
d) setAll() : set all flags to true. 
e) resetAll() : set all flags to false. 

Describe a data structure that implements all these operations in O(1)
time. 
*/
//woohoo
#include <iostream>
using namespace std;
class bool_b{
	int x,recent_resetall,recent_setall;int **e,*initialised,init;
public:
	bool_b(int n){
		e=new int*[2];
		e[0]=new int[n];
		e[1]=new int[n];
		initialised=new int[n];
		for(int i=0;i<n;i++){
			initialised[i]=0;
		}
		x=0;
		init=0;
	}
	void set(int i){
		e[0][i]=1;
		e[1][i]=(++x);
		initialised[i]=1;
	}
	void reset(int i){
		e[0][i]=0;
		e[1][i]=(++x);
		initialised[i]=1;
	}
	void setall(){
		++x;
		recent_setall=x;
		init=1;
	}
	void resetall(){
		++x;
		recent_resetall=x;
		init=1;
	}
	int test(int i){
		if(!initialised[i]&&!init){
			return 200;
		}
		if(recent_setall<recent_resetall){
			if(e[1][i]>recent_resetall){
				return e[0][i];
			}
			else{
				return 0;
			}
		}
		else{
			if(e[1][i]>recent_setall){
				return e[0][i];
			}
			else{
				return 1;
			}
		}
	}
};
int main(){
	bool_b x(5);
	x.set(0);
	x.set(1);
	x.reset(1);
	x.resetall();
	//x.set(4);
	x.set(3);
	for(int i=0;i<5;i++){
		cout<<x.test(i)<<" ";
	}
}