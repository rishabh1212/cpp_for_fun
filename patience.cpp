#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int b = n;
	int *d=new int[n];
	for(int i=0;i<n;i++){
		d[i]=-1;
	}
	vector< vector<int> > c;
	for(int i=0;i<b;i++){
		vector<int > q;
		q.push_back(-1);
		c.push_back(q);
	}
	c[0].push_back(0);
	int e=1;
	for(int i=1;i<b;i++){
		int a1=0;int b1=e-1;
		if(a[c[b1].back()]<a[i]){
			e++;
			c[b1+1].push_back(i);
			d[i] = c[b1].back();
			continue;
		}
		int x=0;
		while(1){
			if(a[c[(a1+b1)/2].back()] >= a[i]){
				if((a1+b1)/2<1){
					c[(a1+b1)/2].push_back(i);
					break;
				}
				else{
					if(a[c[(a1+b1)/2-1].back()] < a[i]){
						c[(a1+b1)/2].push_back(i);
						d[i] = c[(a1+b1)/2-1].back();
						break;
					}
				}
			}
			if(a[c[(a1+b1)/2].back()] < a[i]){
				a1 = (a1+b1)/2+1;
			}
			if(a[c[(a1+b1)/2].back()] > a[i]){
				b1=(a1+b1)/2;
			}
		}
	}
	for(int i=c[e-1].size()-1;i>0;i--){
		cout<<a[c[e-1][i]]<<" ";
		for(int j=d[c[e-1][i]];j>0;j=d[j]){
			cout<<a[j]<<" ";
		}
		cout<<endl;
	}

}