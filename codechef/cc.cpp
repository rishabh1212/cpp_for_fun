#include <iostream>
#include <vector>
using namespace std;
class ff{
public:
	int a,b;
	ff(int x,int y){
		a=x;b=y;
	}
};
ff band(int a,int b){
	int x=1;
	int s1=0,s2=0;
	while(1){
		if(a%2+b%2==2){
			s1=s1+x;
		}
		if(a%2+b%2>0){
			s2=s2+x;
		}
		a=a/2;b=b/2;
		x=2*x;
		if(b==0&&a==0){
			return ff(s1,s2) ;
		}
	}
}
int main(){
	int n;
	cin>>n;
	int *a=new int[n];
	int *b=new int[n];
	int *c=new int[n];
	long long int x=0;
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
		return 0;
	}
	else{
		int s=x/(2*n);
		for(int i=0;i<n;i++){
			a[i]=(b[i]+c[i]-s)/(n);
		}
		for(int i=0;i<n;i++){
			ff x(0,0);int x1=0,y1=0;
			for(int j=0;j<n;j++){
				x=band(a[i],a[j]);
				x1=x1+x.a;
				y1=y1+x.b;
			}
			if(x1!=b[i]||y1!=c[i]){
				cout<<"-1";
				return 0;
			}
		}
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
	}
}