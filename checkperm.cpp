#include <iostream>
using namespace std;
int main(){
	string a,b;
	cin>>a>>b;
	int n=a.size();
	if(n!=b.size()){
		cout<<"no";
		return 0;
	}
	int *c=new int[256];
	for(int i=0;i<n;i++){
		c[a[i]]++;
	}
	for(int i=0;i<n;i++){
		c[b[i]]--;
		if(c[b[i]]<0){
			cout<<"no";
			return 0;
		}
	}
	cout<<"yes";
}