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

vector<ll> ad[100005];

void check(vector<ll> x)
{
	ll i;
	for(i=0;i<sz(x);i++)
	{
		ll j;
		ll tmp = x[i];
		for(j=0;j<sz(ad[tmp]);j++)
		{
			if(binary_search(all(x), ad[tmp][j]))
			{
				cout<<-1<<endl;
				exit(0);
			}
		}
	}
}

void check2(vector<ll> x1, vector<ll> x2)
{
	ll i,j;
	for(i=0;i<sz(x1);i++)
	{
		ll x=x1[i];
		ll cnt=0;
		for(j=0;j<sz(ad[x]);j++)
			if(binary_search(all(x2), ad[x][j]))
				cnt++;
		if(cnt!=sz(x2))
		{
			cout<<-1<<endl;
			exit(0);
		}
	}
}

void print(vector<ll> x)
{
	for(ll i=0;i<sz(x);i++)
		cout<<x[i]<<" ";
	cout<<endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	ll i,j;
	for(i=0;i<m;i++)
	{
		ll u,v;
		cin>>u>>v;
		ad[u].pb(v);
		ad[v].pb(u);
	}
	for(i=1;i<=n;i++)
		sort(all(ad[i]));
	vector<ll> labels(n+5, -1);
	vector<ll> x1,x2,x3;
	labels[1]=1;
	x1.pb(1);
	for(i=2;i<=n;i++)
	{
		if(!binary_search(all(ad[1]), i))
		{
			labels[i]=1;
			x1.pb(i);
		}
	}
	// print(ad[2]);
	// cout<< binary_search(all(ad[2]), 3)<<endl;
	// cout<< binary_search(all(ad[2]), 4)<<endl;
	for(i=1;i<=n;i++)
	{
		if(labels[i]==-1)
		{
			labels[i]=2;
			x2.pb(i);
			for(j=1;j<=n;j++)
			{
				if(j==i)
					continue;
				if(!binary_search(all(ad[i]), j))
				{
					// cout<<j<<endl;
					if(labels[j]!=-1)
					{
						cout<<-1<<endl;
						exit(0);
					}
					labels[j]=2;
					x2.pb(j);
				}
			}
			break;
		}
	}
	// print(x2);
	for(i=1;i<=n;i++)
	{
		if(labels[i]==-1)
		{
			labels[i]=3;
			x3.pb(i);
		}
	}
	if(sz(x1)==0 || sz(x2)==0 || sz(x3)==0)
	{
		cout<<-1<<endl;
		return 0;
	}
	check(x1);
	check(x2);
	check(x3);
	check2(x1, x2);
	check2(x1, x3);
	check2(x3, x2);
	for(i=1;i<=n;i++)
		cout<<labels[i]<<" ";
	cout<<endl;
	return 0;
}