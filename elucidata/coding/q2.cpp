#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()
#define all(a) a.begin(), a.end()
#define ff first
#define ss second
#define endl "\n"

typedef long long ll;
typedef pair<ll,ll> pii;

set<pii> coor;

void fill2(ll xa, ll ya, ll xb, ll yb)
{
	if(xa>xb)
	{
		while(xa!=xb)
		{
			coor.insert(mp(xa,ya));
			xa--;
		}
	}
	else
	{
		while(xa!=xb)
		{
			coor.insert(mp(xa,ya));
			xa++;
		}
	}
	if(ya>yb)
	{
		while(ya!=yb)
		{
			coor.insert(mp(xa, ya));
			ya--;
		}
	}
	else
	{
		while(ya!=yb)
		{
			coor.insert(mp(xa, ya));
			ya++;
		}
	}
	return;
}

void fillCoor(ll xa, ll ya, ll xb, ll yb, ll xc, ll yc)
{
	coor.insert(mp(xa,ya));
	coor.insert(mp(xb,yb));
	coor.insert(mp(xc,yc));
	fill2(xa, ya, xb, yb);
	fill2(xb, yb, xc, yc);
	return;
}

void fillCoor2(ll xa, ll ya, ll xb, ll yb, ll xc, ll yc, ll cx, ll cy)
{
	coor.insert(mp(xa,ya));
	coor.insert(mp(xb,yb));
	coor.insert(mp(xc,yc));
	fill2(xa, ya, cx, cy);
	fill2(xb, yb, cx, cy);
	fill2(xc, yc, cx, cy);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll xa,ya,xb,yb,xc,yc;
	ll i;
	cin>>xa>>ya>>xb>>yb>>xc>>yc;
	ll minSize = LLONG_MAX;
	set<pii> minSet;
	fillCoor(xa, ya, xb, yb, xc, yc);
	if(minSize > sz(coor))
	{
		minSize = sz(coor);
		minSet = coor;
	}
	coor.clear();
	fillCoor(xb, yb, xa, ya, xc, yc);
	if(minSize > sz(coor))
	{
		minSize = sz(coor);
		minSet = coor;
	}
	coor.clear();
	fillCoor(xa, ya, xc, yc, xb, yb);
	if(minSize > sz(coor))
	{
		minSize = sz(coor);
		minSet = coor;
	}
	coor.clear();
	ll cx1 = (xa+xb+xc)/3;
	ll cy1 = (ya+yb+yc)/3;
	ll cx2 = ceil(double(xa+xb+xc)/3);
	ll cy2 = ceil(double(ya+yb+yc)/3);

	fillCoor2(xa, ya, xc, yc, xb, yb, cx1, cy1);
	if(minSize > sz(coor))
	{
		minSize = sz(coor);
		minSet = coor;
	}
	coor.clear();

	fillCoor2(xa, ya, xc, yc, xb, yb, cx1, cy2);
	if(minSize > sz(coor))
	{
		minSize = sz(coor);
		minSet = coor;
	}
	coor.clear();
	fillCoor2(xa, ya, xc, yc, xb, yb, cx2, cy2);
	if(minSize > sz(coor))
	{
		minSize = sz(coor);
		minSet = coor;
	}
	coor.clear();
	fillCoor2(xa, ya, xc, yc, xb, yb, cx2, cy1);
	if(minSize > sz(coor))
	{
		minSize = sz(coor);
		minSet = coor;
	}

	cout<<minSize<<endl;
	for(auto it=minSet.begin();it!=minSet.end();it++)
		cout<<it->first<<" "<<it->second<<endl;
	return 0;
}