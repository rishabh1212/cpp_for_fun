#include <iostream>
#include <queue>
using namespace std;
int main(){
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	queue<int> q;
	int max1=0;
	int min1=0;
	int max=0;
	q.push(0);
	for(int i=0;i<n;i++){
		if(a[i]<q.front()){
			while(!q.empty()){
				q.pop();
			}
			if(max<max1-min1){
				max=max1-min1;
			}
			q.push(i);
			max1=i;
			min1=i;
		}
		else{
			if(a[i]>=a[max1]){
				max1=i;
			}
		}
	}
}