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

ll lcm(ll a, ll b)
{
	if(a==-1 || b==-1)
		return -1;
	ll gcd = __gcd(a,b);
	a/=gcd;
	if(a>1e18/b)
		return -1;
	else
		return a*b;
}

bool isPrime(ll a)
{
	ll i;
	if(a==2)
		return true;
	for(i=2;i<=sqrt(a);i++)
		if(a%i==0)
			return false;
	return true;
}

bool check(ll a, vector<ll> div)
{
	ll i;
	ll cntr=0;
	for(i=2;i<a;i++)
	{
		if(a%i==0)
		{
			if(div[cntr]!=i)
				return false;
			cntr++;
		}
	}
	return true;
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
		ll n;
		cin>>n;
		ll i;
		ll cur = 1;
		bool ans=true;
		vector<ll> div;
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			cur=lcm(cur, val);
			div.pb(val);
			if(cur==-1)
				ans=false;
		}
		sort(all(div));
		ll mn = div[0];
		if(!isPrime(mn))
		{
			cout<<-1<<endl;
			continue;
		}
		if(!ans)
		{
			cout<<-1<<endl;
			continue;
		}
		ll finalAns;
		for(i=0;i<n;i++)
			if(cur==div[i])
				ans=false;
		if(!ans)
		{
			if(cur>1e18/mn)
				cout<<-1<<endl;
			else
				finalAns=cur*mn;
		}
		else
			finalAns=cur;
		if(check(finalAns, div))
			cout<<finalAns<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}