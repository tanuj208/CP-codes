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

set<pii> lava;
set<pii> problem;

void check(ll r, ll c)
{
	ll newr;
	if(r==1)
		newr=2;
	else
		newr=1;
	if(lava.find(mp(newr, c)) != lava.end())
	{
		problem.insert(mp(r, c));
		problem.insert(mp(newr, c));
	}

	if(lava.find(mp(newr, c+1)) != lava.end())
	{
		problem.insert(mp(r, c));
		problem.insert(mp(newr, c+1));
	}

	if(lava.find(mp(newr, c-1)) != lava.end())
	{
		problem.insert(mp(r, c));
		problem.insert(mp(newr, c-1));
	}
}

bool check_problem(ll r,ll c)
{
	ll newr;
	if(r==1)
		newr=2;
	else
		newr=1;
	if(lava.find(mp(newr,c)) != lava.end())
		return true;
	if(lava.find(mp(newr,c+1)) != lava.end())
		return true;
	if(lava.find(mp(newr,c-1)) != lava.end())
		return true;
	return false;
}

void check2(ll r, ll c)
{
	ll newr;
	if(r==1)
		newr=2;
	else
		newr=1;
	if(lava.find(mp(newr, c)) != lava.end() && problem.find(mp(newr, c)) != problem.end() && !check_problem(newr, c))
		problem.erase(mp(newr, c));
	if(lava.find(mp(newr, c+1)) != lava.end() && problem.find(mp(newr, c+1)) != problem.end() && !check_problem(newr, c+1))
		problem.erase(mp(newr, c+1));
	if(lava.find(mp(newr, c-1)) != lava.end() && problem.find(mp(newr, c-1)) != problem.end() && !check_problem(newr, c-1))
		problem.erase(mp(newr, c-1));

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,q;
	cin>>n>>q;
	while(q--)
	{
		ll r,c;
		cin>>r>>c;
		if(lava.find(mp(r,c))==lava.end())
		{
			check(r,c);
			lava.insert(mp(r,c));
		}
		else
		{
			lava.erase(mp(r,c));
			if(problem.find(mp(r,c))!=problem.end())
			{
				problem.erase(mp(r,c));
				check2(r,c);
			}
		}
		if(sz(problem)==0)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}