//presorted edges O(elogv)
#include <iostream>
#include <vector>
using namespace std;
class graph_g{
public:
	int v , e;
	int **a;
	graph_g(int x,int y){
		this->v=x;
		this->e=y;
		a=new int*[3];
		a[0]=new int[e];
		a[1]=new int[e];
		a[2]=new int[e];
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
	int v,e;
	cin>>v>>e;
	vector<int > c;
	graph_g g(v,e);
	int *parent=new int[g.v];
	int *depth=new int[g.v];
	for(int i=0;i<g.v;i++){
		parent[i]=-1;
		depth[i]=1;
	}
	for(int i=0;i<g.e;i++){
		cin>>g.a[0][i]>>g.a[1][i]>>g.a[2][i];
		int p=find(parent,g.a[1][i]);
		int q=find(parent,g.a[2][i]);
		if(p!=q){
			c.push_back(i);
			if(depth[p]>depth[q]){
				parent[q]=p;
			}
			else{
				if(depth[p]==depth[q]){
					parent[p]=q;
					depth[q]++;
				}
				else{
					parent[p]=q;
				}
			}
		}
	}
	for(int i=0;i<c.size();i++){
		cout<<g.a[0][c[i]]<<" "<<g.a[1][c[i]]<<" "<<g.a[2][c[i]]<<endl;
	}
}