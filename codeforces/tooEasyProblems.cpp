#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<pii> x;
vector<ll> a,t;
ll n,T;

ll check(ll m)
{
	ll i;
	for(i=0;i<n;i++)
		if(a[i]>=m)
			x.pb(mp(t[i],i));
	sort(x.begin(),x.end());
	// if(m==2)
	// 	for(i=0;i<sz(x);i++)
	// 		cout<<x[i].first<<" "<<x[i].second<<endl;
	ll k=0;
	if(sz(x)<m)
		return LLONG_MAX;
	for(i=0;i<m;i++)
		k+=x[i].first;
	return k;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>T;
	ll i,val1,val2;
	for(i=0;i<n;i++)
	{
		cin>>val1>>val2;
		a.pb(val1);
		t.pb(val2);
	}
	ll l=0;
	ll r=n;
	ll mid=(l+r)/2;
	ll k=0;
	while(l<r)
	{
		x.clear();
		mid=(l+r)/2;
		k=check(mid);
		if(k<T)
			l=mid+1;
		else if(k>T)
			r=mid-1;
		else
			break;
	}
	while(k<=T)
	{
		x.clear();
		mid++;
		k=check(mid);
	}
	while(k>T)
	{
		x.clear();
		mid--;
		k=check(mid);
	}
	cout<<mid<<endl<<mid<<endl;
	if(mid==0)
		return 0;
	for(i=0;i<mid;i++)
		cout<<x[i].second+1<<" ";
	cout<<endl;
	return 0;
}