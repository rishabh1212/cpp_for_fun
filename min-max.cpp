/*
Let a_0, a_1, ..., a_{n-1} be a sequence of integers. A pair of
numbers (a_i,a_j) is said to be a min-max pair if i < j and a_i <= a_k
<= a_j for all i <= k <= j.  In other words, a_i is the min of the
numbers from a_i to a_j and a_j is the max of these numbers.
Describe an O(n) time algorithm to find a min-max pair (a_i,a_j) such that
j-i is maximized. (Hit use stacks.) Find the number of min-max pairs
in the given sequence in O(nlog n) time. (Use Merge-sort).
*/
#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int *b=new int[n];
	b[0]=-1;
	for(int i=1;i<n;i++){
		int j=b[i-1];
		b[i]=-1;
		if(a[i]<a[i-1]){
			b[i]=i-1;
		}
		else{
			while(a[i]>=a[j]){
				j=b[j];
			}
			b[i]=j;
		}
	}
	int *c=new int[n];
	c[n-1]=n;
	for(int i=n-2;i>=0;i--){
		int j=c[i+1];
		if(a[i]>a[i+1]){
			c[i]=i+1;
		}
		else{
			while(a[i]<=a[j]){
				j=c[j];
			}
			c[i]=j;
		}
	}
	int *d=new int[n];
	d[0]=0;
	for(int i=1;i<n;i++){
		d[i]=i;
		if(a[i-1]>a[i]){
			continue;
		}
		if(c[b[i]+1]>i){
			d[i]=b[i]+1;
		}
		else{
			int j=c[b[i]+1];
			while(j<i){
				j=c[j];
			}
			d[i]=j;
		}
	}
}