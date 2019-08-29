#include <iostream>
#include <queue>
using namespace std;
class gray_g{
	string c;int *a;int l;queue<int> q;
	gray_g(int n){
		a=new int[n];
		l=0;
		for(int i=0;i<n;i++){
			c.push_back('0');
			q.push(i);
			a[i]=0;
		}
			
	}
	void next(){
		l++;
		if(l%2==1){
			if(c[n-1]=='1'){
				c[n-1]='0';
			}
			else{
				c[n-1]='1';
			}
			return c;
		}
	}
};
int main(){

}