#include <iostream>
using namespace std;
int last_non_zero_digit(int n){
	if(n==0)return 1;
	if(n==1)return 1;
	if(n==2)return 2;
	if(n==3)return 6;
	if(n==4)return 4;
	int k = last_non_zero_digit(n/5);
	int l = last_non_zero_digit(n%5);
	int m = (k*l)%10;
	if(n/5==0)return m;
	int b = (n/5)%4;
	if(b==1) return (2*m)%10;
	if(b==2) return (4*m)%10;
	if(b==3) return (8*m)%10;
	return (6*m)%10;

}
int main(){
	int n;
	cin>>n;
	int h = last_non_zero_digit(n);
	cout<<h;
}