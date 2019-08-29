#include <iostream>
#include <map>
using namespace std;
void swap(int x , int y , string &a){
	char temp = a[y];
	a[y] = a[x];
	a[x] = temp;
}
void perm(string &a , int s , int e){
	if(s==e){
		cout<<a<<endl;
	}
	else{
		for(int i = s ; i <= e ; i++){
			swap(s,i,a);
          	perm(a, s+1, e);
          	swap(s,i,a);
		}
	}
}
int main(){
	string a;
	cin>>a;
	int n = a.size();
	perm(a , 0 , n-1);
}