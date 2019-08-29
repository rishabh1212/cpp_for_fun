#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
int main(){
	int n;
	int a[n][2];
	map< int , vector<int> > m;
	map<int , int> v;
	for(int i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1];
		m[a[i][0]].push_back(a[i][1]);
		v[a[i][0]]=0;
		v[a[i][1]]=0;
	}
	queue<int> q;
	q.push(a[0][0]);
	v[a[0][0]]=1;
	int i=a[0][0];
	for(int h=0;h<n;h++){
		if(v[1]==0){
			q.push(m[i][0]);
			v[i]=1;
		}
		else{
			cout<<"yes";
			break;
		}
	}
}