#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a=0,b=0;
	for(int i=0;i<n;i++){
		char x;
		cin>>x;
		if(x=='A'){
			a++;
		}
		else{
			if(x=='D'){
				b++;
			}
		}
	}
	if(a==b){
		cout<<"Friendship";
		return 0;
	}
	if(a>b){
		cout<<"Anton";
		return 0;
	}
	cout<<"Danik";
}