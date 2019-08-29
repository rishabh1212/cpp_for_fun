#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int c[n];
	for(int i=0;i<n;i++){
		c[i]=0;
	}
	while(1){
		int i;
		for(i=n-1;i>=0;i--){
			c[i]++;
			if(c[i]==1){
				cout<<n-1-i<<endl;
				break;
			}
			else{
				c[i]=0;
			}
		}
		if(i==-1){
			break;
		}
	}

}