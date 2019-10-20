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

ll mod=998244353;

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
	ll n;
	cin>>n;
	ll i;
	ll sorted1 = 1;
	ll sorted2 = 1;
	ll sub=1;
	vector<ll> cnt1(n+5, 0), cnt2(n+5, 0);
	vector<pii> seq;
	for(i=0;i<n;i++)
	{
		ll a,b;
		cin>>a>>b;
		seq.pb(mp(a,b));
		if(i==0)
		{
			cnt1[a]++;
			cnt2[b]++;
			continue;
		}
		sorted1 = (sorted1 * (1+cnt1[a]))%mod;
		sorted2 = (sorted2 * (1+cnt2[b]))%mod;
		cnt1[a]++;
		cnt2[b]++;
	}

	vector<ll> fac;
	fac.pb(1);
	for(i=1;i<=n;i++)
		fac.pb((fac[i-1] * i)%mod);

	ll st,en;
	bool flag=false;
	sort(all(seq));
	ll curMx = seq[0].ss;
	for(i=1;i<n;i++)
	{
		if(seq[i].ff==seq[i-1].ff && !flag)
		{
			flag=true;
			st=i-1;
		}
		else if(seq[i].ff!=seq[i-1].ff && flag)
		{
			en=i-1;
			flag=false;
			map<ll, ll> cc;
			for(ll j=st;j<=en;j++)
				cc[seq[j].ss]++;
			for(auto it=cc.begin();it!=cc.end();it++)
				sub = (sub * fac[it->second])%mod;
		}
		if(seq[i].ss >= curMx)
			curMx = seq[i].ss;
		else
		{
			sub=0;
			break;
		}
	}
	if(flag)
	{
		en=n-1;
		map<ll, ll> cc;
		for(ll j=st;j<=en;j++)
			cc[seq[j].ss]++;
		for(auto it=cc.begin();it!=cc.end();it++)
			sub = (sub * fac[it->second])%mod;
	}
	ll total=fac[n];
	cout<<(total + sub - sorted1 - sorted2+2*mod)%mod<<endl;
	return 0;
}