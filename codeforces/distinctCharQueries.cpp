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
	string s;
	cin>>s;
	ll q;
	cin>>q;
	set<ll> char_pos[26];
	ll i;
	for(i=0;i<sz(s);i++)
		char_pos[s[i]-'a'].insert(i);
	while(q--)
	{
		ll x;
		cin>>x;
		if(x==1)
		{
			ll pos;
			char c;
			cin>>pos>>c;
			pos--;
			char or_char = s[pos];
			char_pos[or_char-'a'].erase(pos);
			char_pos[c-'a'].insert(pos);
			s[pos] = c;
		}
		else
		{
			ll l,r;
			cin>>l>>r;
			ll ans=0;
			l--;
			r--;
			for(i=0;i<26;i++)
			{
				auto it=char_pos[i].lower_bound(l);
				if(it==char_pos[i].end())
					continue;
				if(*it<=r && *it>=l)
					ans++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}