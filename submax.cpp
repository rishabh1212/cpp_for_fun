#include <iostream>
using namespace std;
void max(int *a , int *b , int k , int n){
	if(k==1){
		for(int i=0;i<n;i++){
			b[i]=a[i];
		}
		return;
	}
	if(n-k+2>0){
		int *c=new int[n-k+2];
		max(a,c,k-1,n);
		for(int i=0;i<n-k+1;i++){
			b[i]=c[i];
			if(c[i]<a[i+k-1])b[i]=a[i+k-1];
		}
		delete [] c;
	}
}
int main(){
	int T;
	cin>>T;
	for(int u=0;u<T;u++){
		int n,k;
		cin>>n>>k;
		int *a=new int[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int *b=new int[n-k+1];
		max(a,b,k,n);
		for(int i=0;i<n-k+1;i++){
			cout<<b[i]<<" ";
		}
		delete [] a;
		delete [] b;
		cout<<endl;
	}
}