/*O(K) method to find the consecutive numbers if exist
*/

#include <iostream>
using namespace std;
int main(){
	int K;
	cin>>K;
	int i=1;
	int n=1;
	int c=0;
	while(i<K){
		int j;
		for(j=i;n<K;j++){
			n*=j;
			c++;
		}
		if(n==K){
			for(int k=j-c;k<=j-1;k++){
				cout<<k<<" ";
			}
			break;
		}
		else{
			n/=j-c;
			i=j;
			c--;
		}
	}
}