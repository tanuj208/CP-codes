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

vector<ll> p(100005, -1);
vector<ll> s(100005, 1);

multiset<ll> tmp;
multiset<ll> tmp2;

ll parent(ll x)
{
	if(p[x]==-1)
		return x;
	p[x] = parent(p[x]);
	return p[x];
}

void erase(ll x)
{
	auto it = tmp.find(x);
	ll val1 = x;
	ll val2 = -1, val3 = -1;
	if(it!=tmp.begin())
	{
		it--;
		val2 = *it;
		it++;
	}
	it++;
	if(it!=tmp.end())
	{
		val3 = *it;
	}
	if(val2==-1 && val3 == -1)
	{
		return;
	}
	else if(val2==-1)
	{
		tmp2.erase(tmp2.find(val3-val1));
	}
	else if(val3==-1)
	{
		tmp2.erase(tmp2.find(val1-val2));
	}
	else
	{
		tmp2.erase(tmp2.find(val3-val1));
		tmp2.erase(tmp2.find(val1-val2));
		tmp2.insert(val3-val2);
	}
}

void insert(ll x)
{
	auto it=tmp.find(x);
	ll val1=x;
	ll val2=-1, val3=-1;
	if(it!= tmp.begin())
	{
		it--;
		val2 = *it;
		it++;
	}
	it++;
	if(it!=tmp.end())
	{
		val3=*it;
	}
	if(val2!=-1)
		tmp2.insert(val1-val2);
	if(val3!=-1)
		tmp2.insert(val3-val1);
	if(val2!=-1 && val3!=-1)
		tmp2.erase(tmp2.find(val3-val2));
}

void dsu(ll x, ll y)
{
	ll x1=parent(x);
	ll x2=parent(y);
	if(x1==x2)
		return;
	erase(s[x1]);
	tmp.erase(tmp.find(s[x1]));
	erase(s[x2]);
	tmp.erase(tmp.find(s[x2]));
	if(s[x1]<=s[x2])
	{
		p[x1] = x2;
		s[x2] += s[x1];
		tmp.insert(s[x2]);
		insert(s[x2]);
	}
	else
	{
		p[x2] = x1;
		s[x1] += s[x2];
		tmp.insert(s[x1]);
		insert(s[x1]);
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,q;
	cin>>n>>q;
	for(ll i=1;i<=n;i++)
		tmp.insert(1);
	for(ll i=1;i<n;i++)
		tmp2.insert(0);
	while(q--)
	{
		ll a,b;
		cin>>a>>b;
		dsu(a,b);
		if(sz(tmp)==1)
			cout<<0<<endl;
		else
			cout<<*(tmp.begin())<<endl;
	}
	return 0;
}