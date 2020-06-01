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

string dfs(ll v, vector<ll>& vis, set<ll> adj_chars[])
{
	if(vis[v]==1)
		return "-";
	vis[v]=1;

	char tmp=('a'+v);
	string ret = "";
	ret+=tmp;
	if(sz(adj_chars[v])==0)
		return ret;
	ll x=*adj_chars[v].begin();
	adj_chars[v].erase(x);
	adj_chars[x].erase(v);

	string got = dfs(x, vis, adj_chars);
	if(got=="-")
		return got;
	else
		return ret+got;
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
		string s;
		cin>>s;
		set<ll> adj_chars[26];
		vector<ll> vis(26, 0);
		ll i;
		for(i=1;i<sz(s);i++)
		{
			ll x=s[i]-'a';
			ll y=s[i-1]-'a';
			adj_chars[x].insert(y);
			adj_chars[y].insert(x);
		}
		string ans="";
		bool possible=true;
		for(i=0;i<26;i++)
		{
			if(vis[i]==1)
				continue;
			if(sz(adj_chars[i])==0)
			{
				ans+=(char)(i+'a');
				vis[i]=1;
			}
			else if(sz(adj_chars[i])==1)
			{
				string ret=dfs(i, vis, adj_chars);
				if(ret=="-")
					possible=false;
				ans+=ret;
			}
			else if(sz(adj_chars[i])>2)
				possible=false;
		}
		for(i=0;i<26;i++)
		{
			if(vis[i]==0 || sz(adj_chars[i])!=0)
				possible=false;
		}
		if(possible)
		{
			cout<<"YES\n";
			cout<<ans<<endl;
		}
		else
			cout<<"NO\n";
	}
	return 0;
}