#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

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

typedef long long ll;
typedef pair<long long,long long> pii;

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

vector<long long> a;
vector<ll> b;
priority_queue <pii,vector<pii>,greater<pii> > q;
vector<ll> used(200005,0);
ll n,k;

bool pos(ll x)
{
	while(!q.empty())
		q.pop();
	ll i;
	for(i=0;i<=n;i++)
		used[i]=0;
	vector<long long> tmp=a;
	for(i=0;i<n;i++)
		q.push(mp(a[i]/b[i], i));
	for(i=0;i<k;i++)
	{
		ll ind=q.top().second;
		q.pop();
		a[ind]-=(b[ind]-x);
		if(a[ind]<0 && i!=k-1)
		{
			a=tmp;
			return false;
		}
		used[ind]++;
		q.push(mp(used[ind]+a[ind]/b[ind], ind));
		if(i==k-1)
			break;
		if(q.top().first <= i)
		{
			a = tmp;
			return false;
		}
	}
	a=tmp;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k;
	ll i;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		b.pb(val);
	}
	ll r_limit = 1e12;
	ll l=0;
	ll r=r_limit;
	ll mid=(l+r)/2;
	while(l<r)
	{
		mid = (l+r)/2;
		if(pos(mid))
			r=mid-1;
		else
			l=mid+1;
	}
	while(pos(mid) && mid>=0)
		mid--;
	if(mid==-1)
	{
		cout<<0<<endl;
		return 0;
	}
	while(!pos(mid) && mid<=r_limit)
		mid++;
	if(mid<=r_limit)
		cout<<mid<<endl;
	else
		cout<<-1<<endl;
	return 0;
}