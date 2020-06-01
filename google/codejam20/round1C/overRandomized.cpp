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

vector<ll> get_dig(ll x)
{
	vector<ll> ret;
	while(x!=0)
	{
		ret.pb(x%10);
		x/=10;
	}
	// reverse(all(x));
	return ret;
}

vector<char> get_char(string s)
{
	ll n = sz(s);
	ll i;
	vector<char> ret;
	for(i=n-1;i>=0;i--)
		ret.pb(s[i]);
	return ret;
}

void put_in_map(unordered_map<char,ll>& lt, char c, ll val)
{
	if(lt.find(c) == lt.end())
		lt[c] = val;
	else
		lt[c] = min(lt[c], val);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	for(ll z=1;z<=t;z++)
	{
		cout<<"Case #"<<z<<": ";
		ll U;
		cin>>U;
		ll i;
		vector<ll> hsh(27, 0); // exists
		vector<ll> no(27,0); // can't be zero
		vector<vector<char>> s;
		vector<vector<ll>> Q;
		unordered_map<char,ll> lt;
		bool special_case = false;
		ll N = 10000;
		for(i=0;i<N;i++)
		{
			ll q;
			string r;
			cin>>q>>r;
			if(q==-1)
			{
				special_case = true;
				s.pb(get_char(r));
			}
			for(ll j=0;j<sz(r);j++)
				hsh[r[j]-'A']=1;
			no[r[0]-'A'] = 1;
			vector<ll> tmp = get_dig(q);
			if(sz(tmp) == sz(r))
			{
				ll tt = sz(tmp);
				put_in_map(lt, r[0], tmp[tt-1]);
				s.pb(get_char(r));
				Q.pb(tmp);
			}
		}
		if(special_case)
		{
			char zero;
			vector<ll> cnt(27, 0);
			for(i=0;i<sz(s);i++)
			{
				if(sz(s[i]) == U)
				{
					char cc = s[i][U-1];
					cnt[cc-'A']++;
				}
			}
			vector<pair<ll,char>> ttt;
			for(i=0;i<26;i++)
				if(hsh[i]!=0)
					ttt.pb(mp(cnt[i], (char)(i+'A')));
			sort(all(ttt));
			vector<char> ans(11, 0);
			ans[0] = ttt[0].ss;
			ll cur=9;
			for(i=1;i<10;i++)
			{
				ans[cur] = ttt[i].ss;
				cur--;
			}
			for(i=0;i<10;i++)
				cout<<ans[i];
			cout<<endl;
			continue;
		}
		bool zero_done = false;
		map<char,ll> ans;
		ll cur_min = 1;
		while(!lt.empty())
		{
			auto tmp = lt.begin();
			ll lowest_lt = 10;
			for(auto it=lt.begin();it!=lt.end();it++)
			{
				if(lowest_lt >= it->second)
				{
					lowest_lt = it->second;
					tmp = it;
				}
			}
			char c = tmp->first;
			lt.erase(tmp);
			if(!zero_done && no[c-'A'] == 0)
			{
				ans[c] = 0;
				continue;
			}
			ans[c] = cur_min;
			for(i=0;i<sz(s);i++)
			{
				ll xx = sz(s[i]);
				if(xx == 0)
					continue;
				if(s[i][xx-1] == c && Q[i][xx-1] == cur_min)
				{
					s[i].pop_back();
					Q[i].pop_back();
					xx--;
					if(xx!=0 && ans.find(s[i][xx-1]) == ans.end())
						put_in_map(lt, s[i][xx-1], Q[i][xx-1]);
				}
			}
			cur_min++;
		}
		vector<char> final_ans(11, '-');
		for(auto it = ans.begin(); it != ans.end() ; it++)
			final_ans[it->second] = it->first;
		vector<char> rem;
		for(i=0;i<26;i++)
		{
			if(hsh[i] != 0)
			{
				char cc = 'A' + i ;
				if(ans.find(cc) == ans.end())
					rem.pb(cc);
			}
		}
		ll idx=0;
		for(i=0;i<10;i++)
		{
			if(final_ans[i] == '-')
			{
				final_ans[i] = rem[idx];
				idx++;
			}
			cout<<final_ans[i];
		}
		cout<<endl;
	}
	return 0;
}