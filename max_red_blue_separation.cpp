#include <iostream>
#include <map>
using namespace std;

class rational{
public:
	int x;int y;int n;
	/*bool operator>(const rational& r){
		if((this->x)*(r.y)>(this->y)*(r.x)){
			return true;
		}
		return false;
	}
	bool operator<(const rational& r){
		if(((this->x)*(r.y))<((this->y)*(r.x))){
			return true;
		}
		return false;
	}
	bool operator<=(const rational& r){
		if((this->x)*(r.y)<=(this->y)*(r.x)){
			return true;
		}
		return false;
	}
	bool operator>=(const rational& r){
		if((this->x)*(r.y)>=(this->y)*(r.x)){
			return true;
		}
		return false;
	}
	bool operator==(const rational& r){
		if((this->x)*(r.y)==(this->y)*(r.x)){
			return true;
		}
		return false;
	}
	bool operator!=(const rational& r){
		if((this->x)*(r.y)!=(this->y)*(r.x)){
			return true;
		}
		return false;
	}*/
};
struct Class1Compare
{
   bool operator() (const rational& lhs, const rational& rhs) const
   {	
   	   float x,y;
   	   if(lhs.x==0&&lhs.y<0)return true;
   	   if(lhs.x==0&&lhs.y>0)return false;
   	   if(rhs.x==0&&rhs.y>0)return true;
   	   if(rhs.x==0&&rhs.y<0)return false;
       if(lhs.x!=0)x = (lhs.y/lhs.x)*1.0;
       if(rhs.x!=0)y = (rhs.y/rhs.x)*1.0;
       return x<y;
   }
};
void div_num(rational* red , rational* blue , int total_points , int* slope){
	map<rational , int , Class1Compare> m;
	for(int i=1;i<total_points/2;i++){
		rational t;
		t.x=red[i].x-red[0].x;
		t.y=red[i].y-red[0].y;
		m.insert(make_pair(t,i));
		t.x=blue[i].x-red[0].x;
		t.y=blue[i].y-red[0].y;
		m.insert(make_pair(t ,total_points/2+i ));
	}
	m.insert(make_pair(blue[total_points/2] , total_points/2));

	
	int h = 0;
	for(map<rational , int , Class1Compare>::iterator it = m.begin() ; it != m.end() ; ++it ){
		slope[h] = it->second;h++;
	}

}
void red_blue(rational* red , rational* blue , int total_points){
	if(total_points==2){
		cout<<red[0].n<<" "<<blue[0].n<<endl;
		return;
	}
	int *slope = new int[total_points-1];

	div_num(red , blue , total_points , slope);
	int i;
	for(int i = 0 ; i<total_points-1;i++)cout<<"sfdf"<<slope[i]<<endl;
	for(i = 0 ; i < total_points-1 ; i++){
		int a=0,b=0;
		for(int j = 0 ; j<i ; j++){
			if(slope[j]<total_points/2)a++;
			else {
				b++;
			}
		}
		//cout<<a<<b<<i<<"sss"<<endl;
		if(a==0&&b==0&&slope[i]<total_points/2)continue;
		if(a==b) break;
	}
	rational *red1,*red2,*blue1,*blue2;//cout<<i<<"dhf"<<endl;
	if(i!=0&&i!=total_points-2){cout<<"dhd"<<endl;
		red1 = new rational[i/2];
		blue1 = new rational[i/2];
		int z=0;
		for(int y=0;y<i/2;y++){
			for(;z<i-1;z++){
				if(slope[z]<total_points/2){red1[y]=red[slope[z]];cout<<red1[y].x<<red1[y].y<<red1[y].n<<endl;z++;break;}
			}
		}
		z=0;
		for(int y=0;y<i/2;y++){
			for(;z<i-1;z++){
				if(slope[z]>=total_points/2){blue1[y]=blue[slope[z]-total_points/2];z++;break;}
			}
		}
		red2 = new rational[(total_points-i)/2];
		blue2 = new rational[(total_points-i)/2];
		z=0;
		for(int y=i/2;y<total_points/2-1;y++){
			for(;z<i-1;z++){
				if(slope[z]<total_points/2){red2[y-i/2]=red[slope[z]];z++;break;}
			}
		}
		z=0;
		red2[total_points/2-1-i]=red[0];
		for(int y=i/2;y<(total_points)/2;y++){
			for(;z<i-1;z++){
				if(slope[z]>=total_points/2){blue2[y-i/2]=blue[slope[z]-total_points/2];z++;break;}
			}
		}
		red_blue(red1 , blue1 , i);
		red_blue(red2 , blue2 , total_points-i);
		delete [] slope;
	delete [] red1;
	delete [] red2;
	delete [] blue2;
	delete [] blue1;
		return;

	}
	if(i==0){cout<<"dhd22"<<endl;
		cout<<red[0].n<<" "<<blue[slope[0]-total_points/2].n<<endl;
		red2 = new rational[(total_points-2)/2];
		blue2 = new rational[(total_points-2)/2];
		int z=1;
		for(int y=0;y<total_points/2-1;y++){
			for(;z<total_points-1;z++){
				if(slope[z]<total_points/2){red2[y]=red[slope[z]];z++;break;}
			}
		}
		//red2[total_points/2-1]=red[0];
		z=1;
		for(int y=0;y<(total_points)/2-1;y++){
			for(;z<total_points-1;z++){
				if(slope[z]>=total_points/2){blue2[y]=blue[slope[z]-total_points/2];z++;break;}
			}
		}
		red_blue(red2 , blue2 , total_points-2);
		delete [] slope;
	delete [] red1;
	delete [] red2;
	delete [] blue2;
	delete [] blue1;
		return;

	}
	if(i==total_points-2){cout<<"dhdsef"<<endl;
		cout<<red[0].n<<" "<<blue[slope[i]-total_points/2].n<<endl;
		red2 = new rational[(total_points-2)/2];
		blue2 = new rational[(total_points-2)/2];
		int z=0;
		for(int y=0;y<total_points/2-1;y++){
			for(;z<i;z++){
				if(slope[z]<total_points/2){red2[y]=red[slope[z]];z++;break;}
			}
		}
		z=0;
		//red2[total_points/2-1-i]=red[0];
		for(int y=0;y<(total_points)/2-1;y++){
			for(;z<i;z++){
				if(slope[z]>=total_points/2){blue2[y]=blue[slope[z]-total_points/2];z++;break;}
			}
		}
		red_blue(red2 , blue2 , total_points-2);
		delete [] slope;
	delete [] red1;
	delete [] red2;
	delete [] blue2;
	delete [] blue1;
		return;

	}

	
	delete [] slope;
	delete [] red1;
	delete [] red2;
	delete [] blue2;
	delete [] blue1;
	
}


int main(){
	int total_points;int o_x,o_y;int n=0;
	cin>>total_points;
	rational *red = new rational[total_points/2];
	
	rational *blue = new rational[total_points/2];
	
	for(int i=0;i<total_points/2;i++){
		cin>>red[i].x>>red[i].y;
	}
	for(int i=0;i<total_points/2;i++){
		cin>>blue[i].x>>blue[i].y;
	}
	for(int i=0;i<total_points/2;i++){
		red[i].n=n;n++;
	}
	n=0;
	for(int i=0;i<total_points/2;i++){
		blue[i].n=n;n++;
	}
	red_blue(red , blue , total_points);
	delete [] red;
	delete [] blue;
	
}