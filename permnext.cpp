#include <iostream>
using namespace std;
int main(){
	string a;
	cin>>a;
	int n=a.size();
	while(1){
		int p=n-1;
		string d;
		for(int i=n-1;i>0;i--){
			//d.push_back(a[i]);
			if(a[i]<=a[i-1]){
				p--;
			}
			else{
				break;
			}
		}
		//cout<<p;
		if(p<=0)break;
		int c=-1;
		for(int i=n-1;i>=p;i--){
			if(a[i]>a[p-1]){
				c=i;
				break;
			}
		}
		if(c==-1)break;
		char x=a[p-1];
		a[p-1]=a[c];
		a[c]=x;
		for(int i=p;i<=(n-1-p)/2+p;i++){
			x=a[i];
			a[i]=a[n-1-i+p];
			a[n-1+p-i]=x;

		}
		//d[n-p-c-1]=x;
		//a=a.substr(0 , p)+d;

		cout<<a<<endl;
	}
}