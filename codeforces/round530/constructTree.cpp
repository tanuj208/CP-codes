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


typedef int ll;
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
long long n,s;
vector<ll> parent(100005);
vector<ll> depth(100005);
vector<ll> deg(100005);
long long ans;

bool possible(ll branch)
{
	ll i;
	ll cur=1;
	ans=0;
	ll cnt=0;
	depth[1]=1;
	parent[2]=1;
	for(i=1;i<=n;i++)
		deg[i]=0;
	for(i=2;i<=n;i++)
	{
		if(cnt==branch)
		{
			cnt=0;
			cur++;
		}
		cnt++;
		parent[i]=cur;
		deg[cur]++;
		depth[i]=depth[parent[i]]+1;
		ans+=depth[i];
	}
	ans++;
	if(ans>s)
		return false;
	else
		return true;
}

set<ll> dLeaf[100005];
set<ll> scoped[100005];

// ll dfs(ll v, vector<ll> ad[])
// {
// 	ll i;
// 	ll tmp=1;
// 	for(i=0;i<sz(ad[v]);i++)
// 	{
// 		ll x=ad[v][i];
// 		tmp+=dfs(x,ad);
// 	}
// 	ans+=tmp;
// 	return tmp;
// }

// void check()
// {
// 	ll i;
// 	vector<ll> ad[100005];
// 	for(i=2;i<=n;i++)
// 		ad[parent[i]].pb(i);
// 	ans=0;
// 	ll tmp=dfs(1,ad);
// 	cout<<ans<<endl;
// 	return;
// }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>s;
	// n=40;
	// bool tmp=possible(3);
	if(s<2*n-1 || s>(n*(n+1))/2)
	{
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes\n";
	ll l=1;
	ll r=100000;
	ll mid=(l+r)/2;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(possible(mid))
			r=mid-1;
		else
			l=mid+1;
	}
	while(possible(mid))
		mid--;
	while(!possible(mid))
		mid++;
	ll i;
	long long needed=s-ans;
	bool tmp=possible(mid-1);
	long long needed2=ans-s;
	i=1;
	if(needed<=needed2)
	{
		i=n;
		tmp=possible(mid);
		for(i=2;i<=n;i++)
			if(deg[i]==0)
				dLeaf[depth[i]].insert(i);
		for(i=2;i<=n;i++)
			if(deg[i]<mid)
				scoped[depth[i]].insert(i);
		while(needed!=0)
		{
			for(;i>=1;i--)
				if(sz(dLeaf[i])!=0 && sz(scoped[i])>1)
					break;
			if(i==0)
			{
				i=n;
				continue;
			}
			ll xx=*(dLeaf[i].begin());
			auto it=scoped[i].begin();
			ll yy=*it;
			if(xx==yy)
			{
				it++;
				yy=*it;
			}
			deg[parent[xx]]--;
			scoped[i-1].insert(parent[xx]);
			if(deg[parent[xx]]==0)
				dLeaf[i-1].insert(parent[xx]);
			parent[xx]=yy;
			dLeaf[i].erase(xx);
			scoped[i].erase(xx);
			dLeaf[i+1].insert(xx);
			scoped[i+1].insert(xx);
			needed--;
			if(deg[yy]==0)
				dLeaf[i].erase(yy);
			deg[yy]++;
			if(deg[yy]==mid)
				scoped[i].erase(yy);
		}
	}
	else
	{
		tmp=possible(mid-1);
		for(i=2;i<=n;i++)
			if(deg[i]==0)
				dLeaf[depth[i]].insert(i);
		for(i=2;i<=n;i++)
			if(deg[i]<mid)
				scoped[depth[i]].insert(i);
		i=n;
		while(needed2!=0)
		{
			for(;i>=3;i--)
				if(sz(dLeaf[i])!=0 && sz(scoped[i-2])!=0)
					break;
			if(i==2)
			{
				i=n;
				continue;
			}
			ll xx=*(dLeaf[i].begin());
			ll yy=*(scoped[i-2].begin());
			deg[parent[xx]]--;
			scoped[i-1].insert(parent[xx]);
			if(deg[parent[xx]]==0)
				dLeaf[i-1].insert(parent[xx]);
			parent[xx]=yy;
			dLeaf[i].erase(xx);
			scoped[i].erase(xx);
			dLeaf[i-1].insert(xx);
			scoped[i-1].insert(xx);
			needed2--;
			if(deg[yy]==0)
				dLeaf[i-2].erase(yy);
			deg[yy]++;
			if(deg[yy]==mid)
				scoped[i-2].erase(yy);
		}
	}
	for(i=2;i<=n;i++)
		cout<<parent[i]<<" ";
	cout<<endl;
	// check();
	return 0;
}