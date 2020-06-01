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

const int L=2e5+7;
map<ll,ll> counter;

ll size_of_base=2e5+5, inf=0;
vector<ll> baseArray(L),seg(4*L),lazy(4*L);

ll combine(ll a, ll b)
{
	return (a+b);
}

void lazyUpdate(int start, int end, int index)
{
	if(lazy[index] != 0)
	{
		seg[index] += lazy[index];
		if(start != end)
		{
			lazy[2*index] += lazy[index];
			lazy[(2*index) + 1] += lazy[index];
		}
		lazy[index] = 0;
	}
	return;
}

void updateRange(int l, int r, ll value, int start = 1, int end = size_of_base, int index = 1)
{
	lazyUpdate(start, end, index);
	if(r < start || l > end || start > end )return;
	if( l <= start && r >= end )
	{
		seg[index] += value;
		if(start != end)
		{
			lazy[2*index] += value;
			lazy[2*index + 1] += value;
		}
		return;
	}
	int mid = (start + end)/2;
	updateRange(l, r, value, start, mid, 2*index );
	updateRange(l, r, value, mid+1, end, 2*index + 1);
	seg[index] = combine(seg[2*index] , seg[2*index + 1]) ;
	return;
}

ll query(int l, int r, int start = 1, int end = size_of_base, int index = 1)
{
	lazyUpdate(start, end, index);
	if( start > r || end < l || start > end)
		return inf;
	if(start >= l && end <= r)
		return seg[index];
	int mid = (start + end)/2, query_left, query_right;
	query_left = query(l, r, start, mid, 2*index );
	query_right = query(l, r, mid+1, end, 2*index + 1);
	return combine(query_left , query_right);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m,p;
	cin>>n>>m>>p;
	vector<pii> att, deff;
	vector<pair<pii,ll>> mon;
	ll i;
	for(i=0;i<n;i++)
	{
		ll ai,cai;
		cin>>ai>>cai;
		att.pb(mp(cai,ai));
	}
	for(i=0;i<m;i++)
	{
		ll bi,cbi;
		cin>>bi>>cbi;
		deff.pb(mp(cbi, bi));
	}
	for(i=0;i<p;i++)
	{
		ll d,a,c;
		cin>>d>>a>>c;
		mon.pb(mp(mp(a,d), c));
	}

	sort(all(att));
	sort(all(deff));

	vector<pii> at,def;
	ll la=0;
	for(i=0;i<n;i++)
	{
		if(i==n-1 || att[i].ff != att[i+1].ff)
		{
			if(la < att[i].ss)
			{
				la=att[i].ss;
				at.pb(mp(att[i].ss, att[i].ff));
			}
		}
	}
	ll ld=0;
	for(i=0;i<m;i++)
	{
		if(i==m-1 || deff[i].ff != deff[i+1].ff)
		{
			if(ld < deff[i].ss)
			{
				ld=deff[i].ss;
				def.pb(mp(deff[i].ss, deff[i].ff));
			}
		}
	}

	n=sz(at);
	m = sz(def);
	// for(i=0;i<n;i++)
	// 	cout<<at[i].ff<<" "<<at[i].ss<<endl;
	// for(i=0;i<m;i++)
	// 	cout<<def[i].ff<<" "<<def[i].ss<<endl;

	vector<pii> mon_cor(p+1);
	vector<ll> new_mons[n+5];
	for(i=0;i<p;i++)
	{
		ll a=mon[i].ff.ff;
		ll d=mon[i].ff.ss;
		// cout<<a<<" F"<<d<<endl;
		pii tmp = mp(a+1, 0);
		ll tmpd = lower_bound(all(def), tmp)-def.begin();
		tmp = mp(d+1, 0);
		ll tmpa = lower_bound(all(at), tmp)-at.begin();
		mon_cor[i]=mp(tmpa,tmpd);
		new_mons[tmpa].pb(i);
	}
	// for(i=0;i<n;i++)
	// {
	// 	for(ll j=0;j<sz(new_mons[i]);j++)
	// 		cout<<new_mons[i][j]<<" ";
	// 	cout<<endl;
	// }
	// for(i=0;i<p;i++)
	// 	cout<<mon_cor[i].ff<<" "<<mon_cor[i].ss<<endl;
	ll ans=LLONG_MIN;
	for(i=0;i<n;i++)
	{
		ll j;
		for(j=0;j<sz(new_mons[i]);j++)
		{
			ll ttmp = new_mons[i][j];
			ll deffff = mon_cor[new_mons[i][j]].ss;
			// cout<<deffff<<endl;
			updateRange(deffff, deffff, mon[ttmp].ss);
			// arr[deffff]+=mon[new_mons[i][j]].ss;
		}
		for(j=0;j<sz(new_mons[i]);j++)
		{
			ll ttmp = new_mons[i][j];
			ll deffff = mon_cor[ttmp].ss;
			ll total_coins = query(0, deffff);
			ans=max(ans, total_coins - at[i].ss - def[deffff].ss);
		}
	}
	cout<<ans<<endl;
	return 0;
}