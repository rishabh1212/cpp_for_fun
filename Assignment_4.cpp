#include <iostream>
#include <vector>
#include <int>
using namespace std;
class web{
	vector<int > v ;list<list<int> > l1;vector<list<int>::iterator  > q;
	vector<list<list<int>::iterator >  > p;list<list<int> >::iterator zero;
public:

	//constructor
	counter(int n){
		list<int > l;
		for(int i=0 ; i<n ; i++){
			(this->v).push_back(0);
			l.push_back(i);
		}
		l1.push_back(l);
		p.resize(n);
		q.resize(n);
		list<int >::iterator it = l1.front().begin();
		for(int i=0 ; i<n ; i++){
			p[i] = l1.begin();
			q[i] = temp;
			temp++;
		}
		zero = l1.begin();

	}
	~counter(){
		v.clear();
		q.clear();
		p.clear();
		l1.clear();
	}

	//increment count for object i
	void increment(int i){
		int x = (this->v)[i]++;
		p[i]->erase(q[i]);
		list<int >::iterator t = p[i] , t1 = p[i];
		t++;
		if(t!=l1.end()){
			q[i]=t->insert(t,end(),i);
			p[i]=t;
		}
		else{
			p[i]=l1.insert(t,list<int >());
			q[i]=t->insert(t->end(),i);
		}
		if(t1->empty()&&x!=1)l1->erase(t1);
	}

	//decrement count gor object i
	void decrement(int i){
		int x=(this->v)[i]--;
		p[i]->erase(q[i]);
		list<int >::iterator t = p[i] , t1 = p[i];
		if(t!=l1.begin()){
			t--;
			p[i]=t;
			q[i]=t->insert(t->end(),i);

		}
		else{
			p[i]=l1.insert(t,list<int >());
			l1.back().push_back(i);
			q[i]=l1.back().back();
		}
	}

	//sets count of ith object 0
	void reset(int i){
		(this->v)[i] = 0;
	}

	//return count of ith object
	int count(int i){
		return (this->v)[i];
	}
};