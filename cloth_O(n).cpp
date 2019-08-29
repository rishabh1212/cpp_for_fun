//O(n)
/*Problem 1:[25 marks] Suppose you are given as input an array A[1..n]. Think of this array as
defining a piece of cloth whose bottom boundary is a straight line of length n cm. The height
of the cloth above this bottom boundary between i − 1 cm and i cm (from left) is A[i]. The
term “rectangle” in what follows is meant to denote rectangles whose sides are either vertical or
horizontal.
Design an algorithm to determine the largest area rectangle that can be cut out of this cloth.
As an example, let A = (5, 1, 4, 3, 6, 4, 7, 2, 8). Then the largest rectangle would start 1 cm from
the left end and would have height 3 cm and width 5 cm.
*/
#include <iostream>
#include <map>
#include <queue>
using namespace std;
int find_min_from_b(int *a,int *b,int i){
	if(a[i]>a[i-1]){
		return i-1;
	}
	int j=b[i-1];
	if(a[j]<a[i]){

	}
}
int main(){
	int n;
	cin>>n;
	int *a=new int[n];
	int *b=new int[n];
	int *c=new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	b[0]=-1;
	//i-j is increasing or i is increasing thus 2*i-j is always increasing 2*i-j<n thus O(n);
	for(int i=1;i<n;i++){
		int j=b[i-1];
		if(a[i]>a[i-1]){
			b[i]=i-1;
		}
		else{
			b[i]=-1;
			while(j>=0){
				if(a[j]<a[i]){
					b[i]=j;
					break;
				}
				j=b[j];
			}
		}
	}
	c[n-1]=n;
	for(int i=n-2;i>=0;i--){
		int j=c[i+1];
		if(a[i]>a[i+1]){
			c[i]=i+1;
		}
		else{
			c[i]=-1;
			while(j<=n-1){
				if(a[j]<a[i]){
					c[i]=j;
					break;
				}
				j=c[j];
			}
		}
	}
	int max=0;
	int j=-1;
	for(int i=0;i<n;i++){
		if(max<a[i]*(c[i]-b[i]-1)){
			max=a[i]*(c[i]-b[i]-1);
			j=i;
		}
	}
	cout<<max<<" "<<a[b[j]+1]<<" "<<j<<" "<<a[c[j]-1];
}