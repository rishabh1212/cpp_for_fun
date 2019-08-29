#include <iostream>
#include <vector>
using namespace std;
int bor(int a,int b){
	int x=1;
	int s=0;
	while(a>=b){
		if(a%2+b%2>0){
			s=s+x;
		}
		a=a/2;b=b/2;
		x=2*x;
		if(a==0){
			return s;
		}
	}
	while(b>=a){
		if(a%2+b%2>0){
			s=s+x;
		}
		a=a/2;b=b/2;
		x=2*x;
		if(b==0){
			return s;
		}
	}
}
int band(int a,int b){
	int x=1;
	int s=0;
	while(a>=b){
		if(a%2+b%2==2){
			s=s+x;
		}
		a=a/2;b=b/2;
		x=2*x;
		if(a==0){
			return s;
		}
	}
	while(b>=a){
		if(a%2+b%2==2){
			s=s+x;
		}
		a=a/2;b=b/2;
		x=2*x;
		if(b==0){
			return s;
		}
	}
}
int main(){
	int n;
	cin>>n;
	int *a=new int[n];
	int *b=new int[n];
	int *c=new int[n];
	int d[n][n],e[n][n];
	long long int x=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			d[i][j]=-1;
			e[i][j]=-1;
		}
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
		x=x+b[i];
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
		x=x+c[i];
	}
	if(x%(2*n)!=0||(n==1&&b[0]!=c[0])){
		cout<<"-1";
	}
	else{
		int s=x/(2*n);
		for(int i=0;i<n;i++){
			if((b[i]+c[i]-s)%(n)!=0){
				cout<<"-1";
				return 0;
			}
		}
		for(int i=0;i<n;i++){
			a[i]=(b[i]+c[i]-s)/(n);
		}
		for(int i=0;i<n;i++){
			int x=0,y=0;
			for(int j=0;j<n;j++){
				if(d[i][j]==-1){
					d[i][j]=d[j][i]=band(a[i],a[j]);
				}
				if(e[i][j]=-1){
					e[i][j]=e[j][i]=bor(a[i],a[j]);
				}
				x=x+d[i][j];
				y=y+e[i][j];
			}
			if(x!=b[i]||y!=c[i]){
				cout<<"-1";
				return 0;
			}
		}
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
	}
}