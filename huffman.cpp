#include <iostream>
#include <queue>
using namespace std;
class huff_tree{
public:
	int a,f;huff_tree *left;huff_tree *right;string c;int isleaf;
	huff_tree(int i,int j){
		a=i;
		f=j;
		left=NULL;
		right=NULL;
	}
	~huff_tree(){

	}
	void newhuff_tree(huff_tree *x,huff_tree *y){
		if(x!=NULL&&y!=NULL){
			this->left=x;
			this->right=y;
			a=-1;
			f=x->f+y->f;
			isleaf=-1;
		}
	}
	void print(){
		queue<huff_tree> q,q1;
		q.push(*this);
		while(!q.empty()){
			if(q.front().left==NULL&&q.front().right==NULL){
				q1.push(q.front());
				q.pop();
				continue;
			}
			if(q.front().left!=NULL&&q.front().right!=NULL){
				(q.front().left)->c=q.front().c+"0";
				(q.front().right)->c=q.front().c+"1";
				q.push(*(q.front().left));
				q.push(*(q.front().right));
				q.pop();
			}
		}
		while(!q1.empty()){
			cout<<q1.front().a<<" "<<q1.front().f<<" "<<q1.front().c<<endl;
			q1.pop();
		}
	}
};
int main(){
	int n;
	cin>>n;
	int *a=new int[n];
	queue<huff_tree> q1;
	queue<huff_tree> q2;
	for(int i=0;i<n;i++){
		cin>>a[i];
		huff_tree x(i,a[i]);
		q1.push(x);
	}
	while(q1.size()+q2.size()>1){
		huff_tree l(0,0),r(0,0);
		if(q2.empty()){
			huff_tree b(0,0);
			l=q1.front();
			q1.pop();
			r=q1.front();
			q1.pop();
			b.newhuff_tree(&l,&r);
			q2.push(b);
			continue;

		}
		if(q1.empty()){
			huff_tree c(0,0);
			l=q2.front();
			q2.pop();
			r=q2.front();
			q2.pop();
			c.newhuff_tree(&l,&r);
			q2.push(c);
			
			continue;
		}
		if(!q1.empty()&&!q2.empty()){
			if(q1.front().f<q2.front().f){
				huff_tree d(0,0);
				l=q1.front();
				q1.pop();
				if(q1.empty()){
					r=q2.front();
				}
				else{
					if(q1.front().f<q2.front().f){
						r=q1.front();
						q1.pop();
					}
					else{
						r=q2.front();
						q2.pop();
					}
				}
				d.newhuff_tree(&l,&r);
				q2.push(d);
				continue;
			}
			else{
				huff_tree e(0,0);
				l=q2.front();
				q2.pop();
				if(q2.empty()){
					r=q1.front();
					q1.pop();
				}
				else{
					if(q1.front().f<q2.front().f){
						r=q1.front();
						q1.pop();
					}
					else{
						r=q2.front();
						q2.pop();
					}
				}
				e.newhuff_tree(&l,&r);
				q2.push(e);
				
			}
		}
	}
	q2.front().print();
}