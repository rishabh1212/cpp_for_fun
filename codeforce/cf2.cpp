#include <iostream>
using namespace std;
int main(){
	int k_2,k_3,k_5,k_6;
	cin>>k_2>>k_3>>k_5>>k_6;
	int s=0;
	while((k_2>0&&k_5>0&&k_6>0)){
		k_2--;
		k_5--;
		k_6--;
		s+=256;
	}
	while(k_2>0&&k_3>0){
		k_2--;
		k_3--;
		s+=32;
	}
	cout<<s;
}