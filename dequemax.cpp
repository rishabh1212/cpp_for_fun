#include <iostream>
#include <deque>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int *a =new int[n];
	if(k<1||k>n-1){
		cout<<"-1";
		return 0;
	}
	deque<int> q(k);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<k;i++){
		//cin>>a[i];
		while((!q.empty())&&a[q.back()]<=a[i]){
			q.pop_back();
		}
		q.push_back(i);
	}
	
	int i=k;
	for(;i<n;++i){
		int x=q.front();
		cout<<a[x]<<" ";
		while((!q.empty())&&q.front()<=i-k){
			q.pop_front();
		}
		while((!q.empty())&&a[q.back()]<=a[i]){
			q.pop_back();
		}
		q.push_back(i);
		
	}
	cout<<a[q.front()];
}