/*
	finding median of input stream in O(nlog(n)) by maintaining max_heap and min_heap with 
	size difference between them being at most 1
*/
#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	int *a=new int[n];
	vector<int> l;
	l.push_back(-1);
	vector<int> r;
	r.push_back(-1);
	vector<float> m;
	cin>>a[0]>>a[1];
	m.push_back(a[0]);
	m.push_back((a[0]+a[1])/2.0);
	if(a[0]<=a[1]){
		l.push_back(a[0]);
		r.push_back(a[1]);
	}
	else{
		l.push_back(a[1]);
		r.push_back(a[0]);
	}
	for(int i=2;i<n;i++){
		cin>>a[i];
		if(l.size()==r.size()){
			if(a[i]<m.back()){
				l.push_back(a[i]);
				int j=l.size()-1;
				while(l[j]>l[j/2]&&j!=1){
					int x=l[j/2];
					l[j/2]=l[j];
					l[j]=x;
					j=j/2;
				}
				m.push_back(l[1]);
				continue;
			}
			else{
				r.push_back(a[i]);
				int j=r.size()-1;
				while(r[j]<r[j/2]&&j!=1){
					int x=r[j/2];
					r[j/2]=r[j];
					r[j]=x;
					j=j/2;
				}
				m.push_back(r[1]);
				continue;
			}
			continue;
		}
		if(l.size()>r.size()){
			if(a[i]<m.back()){
				int x1=l[1];
				int y=l.back();
				l[1]=y;
				l.pop_back();
				int j=1;
				while(1){
					if(2*j>=l.size()){
						break;
					}
					if(2*j+1>=l.size()){
						if(l[j]<l[2*j]){
							int x=l[j];
							l[j]=l[2*j];
							l[2*j]=x;
							j=2*j;
							continue;
						}
						else{
							break;
						}
					}
					if(l[2*j]<=l[2*j+1]){
						if(l[j]<l[2*j+1]){
							int x=l[j];
							l[j]=l[2*j+1];
							l[2*j+1]=x;
							j=2*j+1;
							continue;
						}
						else{
							break;
						}
					}
					else{
						if(l[j]<l[2*j]){
							int x=l[j];
							l[j]=l[2*j];
							l[2*j]=x;
							j=2*j;
						}
						else{
							break;
						}
					}
				}
				l.push_back(a[i]);
				j=l.size()-1;
				while(l[j/2]<l[j]&&j!=1){
					int x=l[j/2];
					l[j/2]=l[j];
					l[j]=x;
					j=j/2;
				}
				r.push_back(x1);
				j=r.size()-1;
				while(r[j/2]>r[j]&&j!=1){
					int x=r[j/2];
					r[j/2]=r[j];
					r[j]=x;
					j=j/2;
				}
				m.push_back((l[1]+r[1])/2.0);
				continue;
			}
			else{
				r.push_back(a[i]);
				int j=r.size()-1;
				while(r[j]<r[j/2]&&j!=1){
					int x=r[j/2];
					r[j/2]=r[j];
					r[j]=x;
					j=j/2;
				}
				m.push_back((l[1]+r[1])/2.0);
				continue;
			}
		}
		if(l.size()<r.size()){
			if(a[i]<m.back()){
				l.push_back(a[i]);
				int j=l.size()-1;
				while(l[j/2]<l[j]){
					int x=l[j/2];
					l[j/2]=l[j];
					l[j]=x;
					j=j/2;
				}
				m.push_back((l[1]+r[1])/2.0);
				continue;
			}
			else{
				l.push_back(r[1]);
				int j=l.size()-1;
				while(l[j/2]<l[j]&&j!=1){
					int x=l[j/2];
					l[j/2]=l[j];
					l[j]=x;
					j=j/2;
				}
				r[1]=r.back();
				r.pop_back();
				j=1;
				while(1){
					if(2*j>=r.size()){
						break;
					}
					if(2*j+1>=r.size()){
						if(r[j]>r[2*j]){
							int x=r[j];
							r[j]=r[2*j];
							r[2*j]=x;
							j=2*j;
							continue;
						}
						else{
							break;
						}
					}
					if(r[2*j]<=r[2*j+1]){
						if(r[j]>r[2*j]){
							int x=r[j];
							r[j]=r[2*j];
							r[2*j]=x;
							j=2*j;
							continue;
						}
						else{
							break;
						}
					}
					else{
						if(r[j]>r[2*j+1]){
							int x=r[j];
							r[j]=r[2*j+1];
							r[2*j+1]=x;
							j=2*j+1;
							continue;
						}
						else{
							break;
						}
					}
				}
				r.push_back(a[i]);
				j=r.size()-1;
				while(r[j]<r[j/2]&&j!=1){
					int x=r[j/2];
					r[j/2]=r[j];
					r[j]=x;
					j=j/2;
					continue;
				}
				m.push_back((l[1]+r[1])/2.0);
			}
		}
	}
	for(int i=0;i<m.size();i++){
		cout<<m[i]<<endl;
	}
}