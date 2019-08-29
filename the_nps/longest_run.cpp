#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	int *a=new int[m];
	vector<vector<int> >v(n);
	for(int i=0;i<n;i++){
		v[a[i]].push_back(i);
	}
	int max=0;
	for(int i=0;i<n;i++){
		queue<int> q;
		int pre=v[i][0];
		q.push(pre);
		int x=k;
		int c=1;
		for(int j=1;j<v[i].size();j++){
			q.push(v[i][j]);
			c++;
			x=x-(v[i][j]-pre-1);
			if(x==0){
				if(max<k+c){
					max=k+c;
				}
				int u=q.first();
				q.pop();
				int v=q.first();
				x=x+v-u-1;
				c--;
				continue;
			}
			if(x<0){
				if(max<k+c-1){
					max=k+c-1;
				}
				c--;
				int w=q.first();
				q.pop();
				int g=q.first();
				x=x+g-w+1;
				continue;
			}
			else{
				if(j==v[i][v[i].size()-1]){
					if(max<k+c){
						max=k+c;
					}
				}
			}
		}
	}
}