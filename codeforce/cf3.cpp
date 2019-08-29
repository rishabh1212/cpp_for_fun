#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n,m,k,x,s;
	cin>>n>>m>>k>>x>>s;
	int *a=new int[m];
	int *b=new int[m];
	int x1=-1;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cin>>b[i];
		if(b[i]<=s){
			if(x1==-1||x1>a[i]){
				x1=a[i];
			}
		}
	}
	int *c=new int[k];
	int *d=new int[k];
	vector<int> v;
	for(int i=0;i<k;i++){
		cin>>c[i];
	}
	for(int i=0;i<k;i++){
		cin>>d[i];
		if(d[i]<=s){
			v.push_back(i);
		}
	}
	int t=-1;
	if(v.size()!=0)
	if(c[v.back()]>=n){
		cout<<0;
		return 0;
	}
	while(v.size()!=0){
		if(v.size()>=2){
			if(c[v.size()-1]==c[v.size()-2]){
				v.pop_back();
				continue;
			}
		}
		int n1;
		int h=v.back();
		int t1=0;
		n1=n-c[h];
		int s1=s-d[h];
		int min=-1;
		for(int i=0;i<m;i++){
			if(s1>=b[i]){
				if(min==-1){
					min=a[i];
				}
				else{
					if(min>a[i]){
						min=a[i];
					}
				}
			}
		}
		if(min==-1){
			t1=n1*x;
		}
		else{
			if(min<=x)t1=min+(n1-1)*x;
			else{
				t1=n1*x;
			}
		}
		if(t>t1){
			t=t1;
		}
		else{
			if(t==-1){
				t=t1;
			}
		}
		v.pop_back();
		if(v.size()==0){
			break;
		}
	}
	int t2=n*x;
	if(t2>x1+(n-1)*x&&x1!=-1){
		t2=x1+(n-1)*x;
	}
	if(t>t2||t==-1){
		t=t2;
	}
	cout<<t;
}