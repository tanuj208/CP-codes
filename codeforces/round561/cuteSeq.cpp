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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll q;
	cin>>q;
	ll p[55];
	p[0]=1;
	ll i;
	for(i=1;i<=54;i++)
		p[i]=2*p[i-1];
	while(q--)
	{
		ll a,b,m;
		cin>>a>>b>>m;
		if(a==b)
		{
			cout<<"1 "<<a<<endl;
			continue;
		}
		bool ans=false;
		ll tmp=b;
		for(i=2;i<=50;i++)
		{
			b=tmp;
			if(p[i-2]>1e18/a)
				continue;
			b=b-a*p[i-2];
			if(b>=p[i-2] && (p[i-2] >1e18/m || b<=p[i-2]*m))
			{
				cout<<i<<" "<<a<<" ";
				ll cm=a;
				for(ll j=1;j<i-1;j++)
				{
					ll lam=p[i-2-j];
					ll x1=(b-lam*m)/lam;
					if(x1==0)
					{
						cout<<cm+1<<" ";
						cm+=(cm+1);
						b-=lam;
					}
					else
					{
						cout<<cm+x1<<" ";
						cm+=(cm+x1);
						b-=(lam*x1);
					}
				}
				cout<<tmp<<endl;
				ans=true;
				break;
			}
		}
		if(!ans)
			cout<<-1<<endl;
	}
	return 0;
}