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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i;
	vector<string> str[26];
	for(i=0;i<n;i++)
	{
		string s;
		cin>>s;
		ll j;
		vector<bool> ss(26, false);
		for(j=0;j<sz(s);j++)
			ss[s[j]-'a']=true;
		for(j=0;j<26;j++)
			if(ss[j])
				str[j].pb(s);
	}
	vector<ll> vis(26, 0);
	ll ans=0;
	for(i=0;i<26;i++)
	{
		if(sz(str[i])==0 || vis[i]==2)
			continue;
		ll z=i;
		while(true)
		{
			ll tmp=-1;
			if(vis[i]==0)
				ans++;
			vis[i]=1;
			ll j;
			for(j=0;j<sz(str[i]);j++)
			{
				for(ll k=0;k<sz(str[i][j]);k++)
				{
					char c=str[i][j][k];
					if(vis[c-'a']==0)
					{
						vis[c-'a']=1;
						tmp=c-'a';
					}
				}
			}
			vis[i]=2;
			if(tmp==-1)
				break;
			i=tmp;
		}
		i=z;
	}
	cout<<ans<<endl;
	return 0;
}