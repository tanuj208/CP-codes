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

bool allA(vector<string>& gr, ll r, ll c)
{
	for(ll i=0;i<r;i++)
		for(ll j=0;j<c;j++)
			if(gr[i][j]=='P')
				return false;
	return true;
}

bool allP(vector<string>& gr, ll r, ll c)
{
	for(ll i=0;i<r;i++)
		for(ll j=0;j<c;j++)
			if(gr[i][j]=='A')
				return false;
	return true;
}

bool rowA(vector<string>& gr, ll r, ll c, ll ri)
{
	for(ll j=0;j<c;j++)
		if(gr[ri][j] == 'P')
			return false;
	return true;
}

bool colA(vector<string>& gr, ll r, ll c, ll cj)
{
	for(ll i=0;i<r;i++)
		if(gr[i][cj] == 'P')
			return false;
	return true;
}

bool atleastrowA(vector<string>& gr, ll r, ll c, ll ri)
{
	for(ll j=0;j<c;j++)
		if(gr[ri][j] == 'A')
			return true;
	return false;
}

bool atleastcolA(vector<string>& gr, ll r, ll c, ll cj)
{
	for(ll i=0;i<r;i++)
		if(gr[i][cj] == 'A')
			return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll r,c;
		cin>>r>>c;
		vector<string> gr;
		ll i,j;
		for(i=0;i<r;i++)
		{
			string s;
			cin>>s;
			gr.pb(s);
		}
		if(allA(gr, r, c))
		{
			cout<<0<<endl;
			continue;
		}
		if(allP(gr, r, c))
		{
			cout<<"MORTAL"<<endl;
			continue;
		}
		if(rowA(gr, r, c, 0) || rowA(gr, r, c, r-1) || colA(gr, r, c, 0) || colA(gr, r, c, c-1))
		{
			cout<<1<<endl;
			continue;
		}
		bool found = false;
		for(i=0;i<r;i++)
		{
			if(rowA(gr, r, c, i))
			{
				found = true;
				break;
			}
		}
		for(j=0;j<c;j++)
		{
			if(colA(gr, r, c, j))
			{
				found = true;
				break;
			}
		}
		if(found)
		{
			cout<<2<<endl;
			continue;
		}
		if(gr[0][0] == 'A' || gr[r-1][0] == 'A' || gr[0][c-1] == 'A' || gr[r-1][c-1] == 'A')
		{
			cout<<2<<endl;
			continue;
		}
		if(atleastcolA(gr, r, c, 0) || atleastcolA(gr, r, c, c-1) || atleastrowA(gr, r, c, 0) || atleastrowA(gr, r, c, r-1))
		{
			cout<<3<<endl;
			continue;
		}
		cout<<4<<endl;
	}
	return 0;
}