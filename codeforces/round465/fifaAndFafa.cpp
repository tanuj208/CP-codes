#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
#define lp(var,start,end) for(ll var=start;var<end;++var)
#define sz(a) (int)(a).size()

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<fixed;
	cout<<setprecision(10);
	long double x1,y1,x2,y2,r;
	cin>>r>>x1>>y1>>x2>>y2;
	long double radius;
	long double distance=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	if(distance>=r)
	{
		cout<<x1<<" "<<y1<<" "<<r<<endl;
		return 0;
	}
	radius=(r+distance)/2;
	if(x2==x1 && y1==y2)
	{
		cout<<x1+r/2<<" "<<y1<<" "<<radius<<endl;
		return 0;
	}
	long double x,y;
	x=x2+(radius*(x1-x2))/distance;
	y=y2+(radius*(y1-y2))/distance;
	cout<<x<<" "<<y<<" "<<radius<<endl;
	// cout<<radius<<endl;
	return 0;
}