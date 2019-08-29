#include <iostream>
using namespace std;
int main(){
	int m,n;
	cin>>n>>m;
	int a[n][m];
	bool l[n][m];
	bool r[n][m];
	bool u[n][m];
	bool d[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			l[i][j]=0;
			r[i][j]=0;
			u[i][j]=0;
			d[i][j]=0;
			cin>>a[i][j];
		}
	}
	for(int j=1;j<m;j++){
		for(int i=0;i<n;i++){
			if(l[i][j-1]||a[i][j-1]){
				l[i][j]=1;
			}
		}
	}
	for(int j=m-2;j>-1;j--){
		for(int i=0;i<n;i++){
			if(r[i][j+1]||a[i][j+1]){
				r[i][j]=1;
				//cout<<i<<" "<<j<<r[i][j]<<endl;
			}
		}
	}
	//cout<<0<<" err "<<41<<r[0][4]<<r[0][4]<<endl;
	cout<<r[0][4]<<endl;
	cout<<a[0]<<" "<<u[0]<<" "<<r[0]+4<<" "<<endl;
	for(int i=1;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<r[0][4]<<endl;
			if(u[i-1][j]||a[i-1][j]){
				u[i][j]=1;
				cout<<"dfd"<<u[i]+j<<endl;
			}
			cout<<"poo"<<r[0][4]<<endl;
		}
	}
	cout<<r[0][4]<<endl;

	for(int i=n-2;i>-1;i--){
		for(int j=0;j<m;j++){
			if(d[i+1][j]||a[i+1][j]){
				d[i][j]=1;
			}
		}
	}
	//cout<<0<<" err "<<41<<r[0][4]<<r[0][4]<<endl;
	int c=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			//cout<<i<<" "<<j<<r[i][j]<<endl;
			if(a[i][j]){
				continue;
			}
			else{
				if(l[i][j]){
					c++;
				}
				if(r[i][j]){
					c++;
				}
				if(d[i][j]){
					c++;
				}
				if(u[i][j]){
					c++;
				}
			}
		}
	}
	cout<<c;
}