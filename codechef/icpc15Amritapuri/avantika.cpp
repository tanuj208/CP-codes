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

vector<ll> a;
vector<ll> segTree[40005];

vector<ll> merge(vector<ll> a1, vector<ll> a2)
{
	ll i,j;
	vector<ll> temp;
	i=j=0;
	ll n1,n2;
	n1=sz(a1);
	n2=sz(a2);
	while(i<n1 && j<n2)
	{
		if(a1[i]<=a2[j])
		{
			temp.pb(a1[i]);
			i++;
		}
		else
		{
			temp.pb(a2[j]);
			j++;
		}
	}
	while(i<n1)
	{
		temp.pb(a1[i]);
		i++;
	}
	while(j<n2)
	{
		temp.pb(a2[j]);
		j++;
	}
	return temp;
}

void make_segTree(ll s,ll e,ll i)
{
	if(s==e)
	{
		segTree[i].pb(a[s]);
		return;
	}
	ll m=(s+e)/2;
	make_segTree(s,m,(i<<1));
	make_segTree(m+1,e,(i<<1)+1);
	segTree[i]=merge(segTree[(i<<1)],segTree[(i<<1)+1]);
}

vector<ll> query(ll s,ll e,ll i,ll l,ll r)
{
	vector<ll> tmp;
	if(r<s || l>e)
		return tmp;
	if(l<=s && r>=e)
		return segTree[i];
	ll mid=(s+e)/2;
	return merge(query(s,mid,(i<<1),l,r),query(mid+1,e,(i<<1)+1,l,r));
}

void reset()
{
	ll i;
	a.clear();
	for(i=0;i<=10000;i++)
		segTree[i].clear();
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
		reset();
		ll n;
		cin>>n;
		ll i,val;
		for(i=0;i<n;i++)
		{
			cin>>val;
			a.pb(val);
		}
		make_segTree(0,n-1,1);
		ll m;
		cin>>m;
		while(m--)
		{
			ll l,r;
			cin>>l>>r;
			vector<ll> aa=query(0,n-1,1,l-1,r-1);
			ll fac=1;
			ll ans=0;
			ans+=aa[0];
			for(i=1;i<sz(aa);i++)
			{
				if(aa[i]!=aa[i-1])
				{
					fac++;
					ans += fac*aa[i];
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}