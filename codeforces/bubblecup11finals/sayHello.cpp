#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;
#define ff first
#define ss second

const ll lt=100005;
ll mod=1000000007;
struct coor
{
	ll x,y;
};

struct vel
{
	ll x,y;
};

ll dist(coor c1, coor c2)
{
	return (c1.x-c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y);
}

pii minDistance(coor c1,coor c2, coor c3, coor c4)
{
	vel v1,v2;
	v1.x=c3.x-c1.x;
	v1.y=c3.y-c1.y;
	v2.x=c4.x-c2.x;
	v2.y=c4.y-c2.y;
	ll a=c1.x-c2.x;
	ll b=c1.y-c2.y;
	ll c=v1.x-v2.x;
	ll d=v1.y-v2.y;
	ll numt=-(a*c+b*d);
	ll dent=c*c+d*d;
	if(dent<numt)
		return mp(-1,-1);
	if((numt<0 && dent>0) || (numt>0 && dent<0))
		return mp(-1,-1);
	return mp((a*a+b*b)*(c*c+d*d)-(a*c+b*d)*(a*c+b*d),c*c+d*d);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,i;
	ll flag = 1;
	ll d1,d2;
	ll ans=0;
	coor c1, c2;
	cin>>n;
	cin>>d1>>d2;
	d1*=d1;
	d2*=d2;
	cin>>c1.x>>c1.y>>c2.x>>c2.y;
	ll d=dist(c1,c2);
	if(d<=d1)
	{
		ans++;
		flag=0;
	}
	for(i=1;i<n;i++)
	{
		coor c3,c4;
		cin>>c3.x>>c3.y>>c4.x>>c4.y;
		if(dist(c1,c2)>d2)
			flag=1;
		else if(dist(c1,c2)<=d1 && flag==1)
		{
			ans++;
			flag=0;
		}
		pii tmp=minDistance(c1,c2,c3,c4);
		// cout<<endl<<(double)tmp.first/tmp.second<<endl;
		if((tmp.first!=-1 || tmp.second!=-1) && flag==1 && tmp.first<=d1*tmp.second)
		{
			ans++;
			flag=0;
		}
		c1=c3;
		c2=c4;
	}
	if(flag==1 && dist(c1,c2)<=d1)
		ans++;
	cout<<ans<<endl;
	return 0;
}