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

ll n,k;

vector<ll> get_sorted_idx(vector<string>& dp)
{
	ll i;
	vector<pair<string, ll>> tmp;
	for(i=0;i<=k;i++)
		tmp.pb(mp(dp[i], i));
	sort(all(tmp));
	vector<ll> ret;
	for(i=0;i<sz(tmp);i++)
		ret.pb(tmp[i].ss);
	return ret;
}

map<ll,ll> num;
vector<vector<ll>> t(130, vector<ll> (8, -1));
vector<vector<pii>> pt(130);
vector<ll> sp;

ll bit_diff(ll x, ll y) // x -> y
{
	ll cnt=0;
	for(ll i=0;i<=7;i++)
	{
		if(x%2==1 && y%2==0)
			return -1;
		if(x%2==0 && y%2==1)
			cnt++;
		x/=2;
		y/=2;
	}
	return cnt;
}

void fill_pt()
{
	ll i,j;
	for(i=0;i<=127;i++)
	{
		for(j=sz(sp)-1;j>=0;j--)
		{
			ll x=bit_diff(i, sp[j]);
			if(x!=-1)
				t[i][x] = num[sp[j]];
		}
	}
	for(i=0;i<=127;i++)
	{
		vector<pii> x;
		for(j=0;j<8;j++)
		{
			if(t[i][j] != -1)
				x.pb(mp(j, t[i][j]));
		}
		pt[i] = x;
	}
	return;
}

ll get_num(string s)
{
	ll p = 1;
	ll res=0;
	for(ll i=s.size()-1;i>=0;i--)
	{
		ll x= (ll) (s[i] - '0');
		res += p*x;
		p*=2;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	num[119] = 0;
	num[18] = 1;
	num[93] = 2;
	num[91] = 3;
	num[58] = 4;
	num[107] = 5;
	num[111] = 6;
	num[82] = 7;
	num[127] = 8;
	num[123] = 9;
	sp.pb(123);
	sp.pb(127);
	sp.pb(82);
	sp.pb(111);
	sp.pb(107);
	sp.pb(58);
	sp.pb(91);
	sp.pb(93);
	sp.pb(18);
	sp.pb(119);
	fill_pt();

	cin>>n>>k;
	vector<ll> a;
	ll i,j;
	for(i=0;i<n;i++)
	{
		string s;
		cin>>s;
		a.pb(get_num(s));
	}

	vector<ll> hsh(k+1, 0);
	vector<vector<ll>> poss(n+2);
	hsh[0] = 1;
	poss[n] = hsh;
	for(i=n-1;i>=0;i--)
	{
		vector<ll> hsh2(k+1, 0);
		for(j=0;j<sz(pt[a[i]]);j++)
		{
			ll xx=pt[a[i]][j].ff;
			for(ll z=0;z<=k;z++)
			{
				ll tmp = z+xx;
				if(tmp <= k)
					hsh2[tmp] += hsh[z];
			}
		}
		poss[i] = hsh2;
		hsh = hsh2;
	}

	ll remk=k;

	for(i=0;i<n;i++)
	{
		ll best_num = -1;
		ll tr;
		for(j=0;j<sz(pt[a[i]]);j++)
		{
			pii tmp = pt[a[i]][j];
			ll xx = remk-tmp.ff;
			if(xx >= 0 && xx <= k && poss[i+1][xx] != 0)
			{
				if(best_num < tmp.ss)
				{
					best_num = tmp.ss;
					tr = tmp.ff;
				}
			}
		}
		if(best_num == -1)
		{
			cout<<-1<<endl;
			return 0;
		}
		else
			cout<<best_num;
		remk-=tr;
	}
	cout<<endl;

	return 0;
}