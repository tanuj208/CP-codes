#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
//K-th smallest
//cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;


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
vector<bool> leaf(200005,false);
vector<ll> d(200005,0);

void reset(ll n)
{
	ll i;
	for(i=0;i<=n;i++)
	{
		leaf[i]=false;
		d[i]=0;
	}
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
		reset(n);
		ll i;
		ll finalAns=0;
		ll L=1;
		leaf[1]=true;
		ll tmpAns=0;
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			if(!leaf[val])
				L++;
			else
			{
				leaf[val]=false;
				if(d[val]%2==1)
					tmpAns--;
			}

			if(i==0)
			{
				leaf[val]=true;
				L++;
			}

			leaf[i+2]=true;
			d[i+2]=d[val]+1;
			if(d[i+2]%2==1)
				tmpAns++;
			finalAns+=max(tmpAns,L-tmpAns);
			// cout<<tmpAns<<" "<<L<<endl;
		}
		cout<<finalAns<<"\n";
	}
	return 0;
}