#include <iostream>
using namespace std;
int main(){
	string a;
	cin>>a;
	int *b = new int[256];
	int T=a.size();
	for(int i=0;i<256;i++){
		b[i]=-1;
	}
	int c=0,d=0;
	int s=0,t=0;
	for(int i=0;i<T;i++){
		if(b[a[i]]!=-1){
			for(int j=i-c;j<b[a[i]];j++){
				b[a[j]]=-1;
			}
			if(d<c){
				d=c;
				t=s;
			}
			c=i-b[a[i]];
			s=b[a[i]]+1;
			b[a[i]]=i;
		}
		else{
			b[a[i]]=i;
			c++;
		}
		if(d<c){
			d=c;
			t=s;
		}
	}
	cout<<d;
	for(int i=0;i<d;i++){
		cout<<a[t+i];
	}
}