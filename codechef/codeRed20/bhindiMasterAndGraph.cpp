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

ll n;
vector<ll> a;
vector<ll> ad[100005];
vector<ll> lvl(100005);
set<pii> level_wise_max[100005]; //val, index
vector<ll> max_arr(100005, 0);
vector<ll> segTree(400005, 0);

void dfs(ll v, ll par)
{
	ll i;
	for(i=0;i<sz(ad[v]);i++)
	{
		ll x=ad[v][i];
		if(x==par)
			continue;
		lvl[x]=1+lvl[v];
		dfs(x, v);
	}
	return;
}

void make_segTree(ll s,ll e,ll i)
{
	if(s==e)
	{
		segTree[i]=max_arr[s];
		return;
	}
	ll mid=(s+e)/2;
	make_segTree(s,mid,(i<<1));
	make_segTree(mid+1,e,(i<<1)+1);
	segTree[i]=max(segTree[(i<<1)],segTree[(i<<1)+1]);
	return;
}

ll query(ll s,ll e,ll i,ll l, ll r)
{
	if(e<l || s>r)
	{
		return LLONG_MIN;
	}
	if(l<=s && e<=r)
		return segTree[i];
	ll mid=(s+e)/2;
	ll q1=query(s,mid,(i<<1),l,r);
	ll q2=query(mid+1,e,(i<<1)+1,l,r);
	ll q3=max(q1,q2);
	return q3;
}

void update(ll s,ll e, ll i,ll idx, ll val)
{
	if(idx < s || idx > e)
		return;
	if(s==e)
	{
		max_arr[s]=val;
		segTree[i]=val;
		return;
	}
	ll mid =(s+e)/2;
	update(s, mid, i<<1, idx, val);
	update(mid+1, e, (i<<1)+1, idx, val);
	segTree[i] = max(segTree[i<<1], segTree[(i<<1)+1]);
}

ll main_query(ll y)
{
	ll l=0;
	ll r=n;
	ll mid=(l+r)/2;
	while(l!=r)
	{
		mid=(l+r)/2;
		ll tmp = query(0, n-1, 1, l, mid);
		// cout<<l<<" "<<mid<<" "<<tmp<<endl;
		if(tmp > y)
			r=mid;
		else
			l=mid+1;
	}
	return l;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	a.pb(-1);
	ll i;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	for(i=0;i<n-1;i++)
	{
		ll u,v;
		cin>>u>>v;
		ad[u].pb(v);
		ad[v].pb(u);
	}
	lvl[1]=0;
	dfs(1, 0);
	for(i=1;i<=n;i++)
		level_wise_max[lvl[i]].insert(mp(a[i], i));
	for(i=0;i<=n;i++)
	{
		if(sz(level_wise_max[i])==0)
			break;
		pii mx_val = *level_wise_max[i].rbegin();
		max_arr[i]=mx_val.ff;
	}
	make_segTree(0, n-1, 1);
	ll q;
	cin>>q;
	while(q--)
	{
		// for(i=0;i<4*n;i++)
		// 	cout<<segTree[i]<<" ";
		// cout<<endl;
		ll c;
		cin>>c;
		if(c==1)
		{
			ll x,y;
			cin>>x>>y;
			ll level = lvl[x];
			level_wise_max[level].erase(mp(a[x], x));
			level_wise_max[level].insert(mp(y, x));
			a[x]=y;
			ll cur_max = level_wise_max[level].rbegin() -> ff;
			if(cur_max!=max_arr[level])
				update(0, n-1, 1, level, cur_max);
		}
		else
		{
			ll y;
			cin>>y;
			ll level;
			level = main_query(y);
			if(level==n)
			{
				cout<<-1<<endl;
				continue;
			}
			auto it = level_wise_max[level].lower_bound(mp(y+1,0));
			cout<<it->second<<endl;
		}
	}
	return 0;
}