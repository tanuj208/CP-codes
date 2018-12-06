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

ll ans=LLONG_MAX;
pair<pii,ll> mincor;

ll n,p,q;

void func(ll a,ll b,ll c)
{
	if(c>=a+b)
		return;
	ll x=q*(a*a+b*b-c*c)-2*a*b*p;
	if(x<0)
		return;
	if(x<ans)
	{
		ans=x;
		mincor=mp(mp(a,b),c);
	}
	return;
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
		ans=LLONG_MAX;
		mincor = mp(mp(-1,-1),-1);
		cin>>n>>p>>q;
		vector<ll> x;
		vector<ll> mchutiya;
		ll i,j;
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			x.pb(val);
		}
		mchutiya=x;
		sort(x.begin(),x.end());
		for(i=0;i<n-2;i++)
		{
			for(j=i+1;j<n-1;j++)
			{
				ll a=x[i];
				ll b=x[j];
				if(x[j+1]>=a+b)
					continue;
				func(a,b,x[j+1]);
				ll constraint = q*a*a+q*b*b-2*a*p*b;
				ll l=j+1;
				ll r=n-1;
				ll mid=(l+r)/2;
				while(l<=r)
				{
					mid=(l+r)/2;
					if(q*x[mid]*x[mid]>constraint || x[mid]>=a+b)
						r=mid-1;
					else
					{
						if(ans>constraint-q*x[mid]*x[mid])
						{
							ans=constraint-q*x[mid]*x[mid];
							mincor=mp(mp(x[i],x[j]),x[mid]);
						}
						l=mid+1;
					}
				}
				if(l>=n)
					l=n-1;
				if(r>=n)
					r=n-1;
				if(mid>=n)
					mid=n-1;
				if(l<0)
					l=0;
				if(r<0)
					r=0;
				if(mid<0)
					mid=0;
				func(a,b,x[l]);
				func(a,b,x[r]);
				func(a,b,x[mid]);
			}
		}
		x=mchutiya;
		if(ans==LLONG_MAX)
			cout<<"-1\n";
		else
		{
			ll ansa=-1,ansb=-1,ansc=-1;
			for(i=0;i<n;i++)
			{
				if(x[i]==mincor.first.first && ansa==-1)
				{
					ansa=i;
					continue;
				}
				if(x[i]==mincor.first.second && ansb==-1)
				{
					ansb=i;
					continue;
				}
				if(x[i]==mincor.second && ansc==-1)
				{
					ansc=i;
					continue;
				}
			}
			cout<<ansa+1<<" "<<ansb+1<<" "<<ansc+1<<"\n";
		}
	}
	return 0;
}