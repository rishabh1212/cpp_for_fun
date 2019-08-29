#include <iostream>
#include <string>
using namespace std;
string lcs(string a , string b){
	int m = a.size();
	int n = b.size();
	string c;
	int l[m+1][n+1];
	for(int i=0 ; i<m+1 ; i++){
		for(int j=0 ; j<n+1 ; j++){
			if(i==0||j==0){
				l[i][j]=0;
			}
			else{
				if(a[i-1]==b[j-1]){
					l[i][j]=l[i-1][j-1]+1;
				}
				else{
					if(l[i-1][j]>l[i][j-1]){
						l[i][j]=l[i-1][j];
					}
					else{
						l[i][j]=l[i][j-1];
					}
				}
			}
		}
	}
	int i=m , j=n;
	while(i>0&&j>0){
		if(a[i-1]==b[j-1]){
			c.push_back(a[i-1]);
			i--;
			j--;
		}
		else{
			if(l[i-1][j]>l[i][j-1]){
				i--;
			}
			else{
				j--;
			}
		}
	}
	return c;
}
int main(){
	string a,b;
	cin>>a>>b;
	string c = lcs(a , b);
	cout<<c;
}