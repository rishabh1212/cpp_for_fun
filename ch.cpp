#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

struct point
{
	int x, y;
};

bool intersect(point, point, point, point);

vector<point> r,b;

int main(char * argc, char * argv[])
{
	ifstream f1, f2;
	f1.open(argv[1]);
	f2.open(argv[2]);
	int n;
	f1 >> n;
	n = n/2;
	r.resize(n);
	b.resize(n);
	for (int i = 0; i < n; i++)
	f1 >> r[i].x >> r[i].y;
	for (int i = 0; i < n; i++)
	f1 >> b[i].x >> b[i].y;
	vector<int> match(n);
	int x, y;
	for (int i = 0; i < n; i++)
	{
		f2 >> x >> y;
		match[x] = y;
	}
	f1.close();
	f2.close();
	for (int i = 0; i < n; i++)
	for (int j = i+1; j < n; j++)
	      if (intersect(r[i],b[match[i]],r[j],b[match[j]]))
	      {
		      return 1;
	      }
	return 0;
}



bool intersect(point p, point q, point r, point s)
{
	int z1 = (r.x-p.x)*(q.y-p.y)-(r.y-p.y)*(q.x-p.x);
	int z2 = (s.x-p.x)*(q.y-p.y)-(s.y-p.y)*(q.x-p.x);
	if ((z1 > 0) && (z2 > 0)) return false;
	if ((z1 < 0) && (z2 < 0)) return false;
	z1 = (p.x-r.x)*(s.y-r.y)-(p.y-r.y)*(s.x-r.x);
	z2 = (q.x-r.x)*(s.y-r.y)-(q.y-r.y)*(s.x-r.x);
	if ((z1 > 0) && (z2 > 0)) return false;
	if ((z1 < 0) && (z2 < 0)) return false;
	return true;
}