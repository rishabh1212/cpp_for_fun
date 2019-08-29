#include <iostream>
using namespace std;
class graph_g{
public:
	int v , e;
	int **a;
	graph_g(int x,int y){
		this->v=x;
		this->e=y;
		a=new int*[2];
		a[0]=new int[e];
		a[1]=new int[e];
	}
};
int find(int *parent,int a){
	if(parent[a]==-1){
		return a;
	}
	else{
		parent[a]=find(parent,parent[a]);
		return parent[a];
	}
}
int main(){
	int x,y;
	cin>>x>>y;
	graph_g g(x,y);
	int *parent=new int[g.v];
	int *depth=new int[g.v];
	for(int i=0;i<g.v;i++){
		parent[i]=-1;
		depth[i]=1;
	}
	for(int i=0;i<g.e;i++){
		int a,b;
		cin>>a>>b;
		g.a[0][i]=a;
		g.a[1][i]=b;
		int p=find(parent,a);
		int q=find(parent,b);
		if(p==q){
			cout<<"cycle";
		}
		else{
			if(depth[p]<=depth[q]){
				parent[p]=q;
				if(depth[p]==depth[q]){
					depth[q]++;
				}
			}
			else{
				parent[q]=p;
			}
		}
	}
}