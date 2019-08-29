#include <iostream>
#include <queue>
using namespace std;
class point{
public:
	int x,y;
};
int main(){
	int n,m;
	cin>>m>>n;
	char c[m][n];
	int a[m][n];
	queue<point> q;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>c[i][j];
			a[i][j]=-1;
			if(c[i][j]=='G'){
				point p;
				p.x=i;p.y=j;
				q.push(p);
				a[i][j]=0;
			}
		}
	}

	while(!q.empty()){
		point s=q.front();
		q.pop();
		int x=s.x;
		int y=s.y;
		//(x+1,y)
		if(x+1<m){
			if(a[x+1][y]==-1&&c[x+1][y]!='W'){
				a[x+1][y]=a[x][y]+1;
				s.x=x+1;s.y=y;
				q.push(s);
			}
		}
		//(x,y-1)
		if(y-1>=0){
			if(a[x][y-1]==-1&&c[x][y-1]!='W'){
				a[x][y-1]=a[x][y]+1;
				s.x=x;s.y=y-1;
				q.push(s);
			}
		}
		//(x,y+1)
		if(y+1<n){
			if(a[x][y+1]==-1&&c[x][y+1]!='W'){
				a[x][y+1]=a[x][y]+1;
				s.x=x;s.y=y+1;
				q.push(s);
			}
		}
		//(x-1,y)
		if(x-1>=0){
			if(a[x-1][y]==-1&&c[x-1][y]!='W'){
				a[x-1][y]=a[x][y]+1;
				s.x=x-1;s.y=y;
				q.push(s);
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}