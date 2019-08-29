#include <iostream>
#include <map>
#include <queue>
using namespace std;
int main(){
	int n;
	cin>>n;
	int *s=new int[n];
	int *t=new int[n+1];
	t[0]=1;
	map<int , queue<int> > m;
	for(int i=1;i<n+1;i++){
		cin>>s[i-1];
		m[s[i-1]].push(i-1);
		t[i]=2*t[i-1];
		if(m[s[i-1]].front()<i-1){
			t[i]-=t[m[s[i-1]].front()];
			m[s[i-1]].pop();
		}
	}
	cout<<t[n];
}