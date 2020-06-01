#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()
#define all(a) a.begin(), a.end()
#define ff first
#define ss second
#define endl "\n"

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
//K-th smallest
//cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;

// priority_queue <ll,vector<ll>,greater<ll> > p;

typedef long long ll;
typedef pair<ll,ll> pii;

ll mod=1000000007;

ll power(ll x, ll y) 
{
	ll temp;
	if( y == 0)
		return 1;
	temp = power(x, y/2);
	if (y%2 == 0)
		return (temp*temp)%mod;
	else
		return (((x*temp)%mod)*temp)%mod; 
}

vector<ll> p;

bool compatible(ll x, ll y)
{
	if(x==y)
		return false;
	ll z = x^y;
	z++;
	if(z<x || z<y)
		return false;
	return binary_search(all(p), z);
}

ll get_next_bit(ll& x)
{
	ll ret=x%2;
	x/=2;
	return ret;
}

bool problem(vector<ll>& xx, vector<ll>& yy, ll idx)
{
	if(xx[idx] != yy[idx])
		return false;
	if(xx[idx] == 1)
		return true;
	bool pblm = false;
	for(ll i = idx+1 ;i <sz(xx);i++)
		if(xx[i] == 1 || yy[i] == 1)
			pblm = true;
	return pblm;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	p.pb(1);
	ll i;
	for(i=1;i<=40;i++)
		p.pb(p[i-1]*2);
	ll t;
	cin>>t;
	for(ll z=1;z<=t;z++)
	{
		cout<<"Case #"<<z<<": ";
		ll x,y;
		cin>>x>>y;
		char n,s,w,e;
		if(x>0)
		{
			e='E';
			w='W';
		}
		else
		{
			e='W';
			w='E';
			x=-x;
		}
		if(y>0)
		{
			n='N';
			s='S';
		}
		else
		{
			n='S';
			s='N';
			y=-y;
		}
		string ans = "";
		vector<ll> xx,yy;
		while(x!=0)
		{
			xx.pb(x%2);
			x/=2;
		}
		while(y!=0)
		{
			yy.pb(y%2);
			y/=2;
		}
		while(sz(xx) < sz(yy))
			xx.pb(0);
		while(sz(yy) < sz(xx))
			yy.pb(0);
		xx.pb(0);
		yy.pb(0);
		bool poss = true;
		for(i=0;i<sz(xx);i++)
		{
			ll x1 = xx[i];
			ll y1 = yy[i];
			if(problem(xx, yy, i))
			{
				poss=false;
				break;
			}
			if(x1^y1==0)
				break;
			if(i == sz(xx) -1 || !problem(xx, yy, i+1))
			{
				if(x1==1)
					ans += e;
				else
					ans += n;
				continue;
			}
			if(x1==1)
				ans += w;
			else
				ans += s;
			ll j;
			for(j=i+1;j<sz(xx);j++)
			{
				if(j+1 == sz(xx))
					break;
				if((xx[j+1] ^ yy[j+1]) == 1)
					break;
				if(!problem(xx, yy, j+1))
				{
					if(xx[j] == 0)
						break;
				}
				if(xx[j] == 1)
				{
					if(x1==0)
						ans += e;
					else
						ans += n;
				}
				else
				{
					if(x1==1)
						ans += w;
					else
						ans += s;
				}
			}
			if(xx[j] == 1)
			{
				poss=false;
				break;
			}
			i = j;
			if(x1==1)
				ans += e;
			else
				ans += n;
		}
		if(poss)
			cout<<ans<<endl;
		else
			cout<<"IMPOSSIBLE"<<endl;
	}
	return 0;
}