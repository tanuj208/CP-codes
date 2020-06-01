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
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		string s;
		vector<ll> hsh(27,0);
		ll i;
		cin>>s;
		for(i=0;i<n;i++)
			hsh[s[i]-'a']++;
		if(k==1)
		{
			for(i=0;i<26;i++)
				while(hsh[i]--)
					cout<<(char)(i+'a');
			cout<<endl;
			continue;
		}
		for(i=0;i<26;i++)
		{
			if(hsh[i] != 0)
				break;
		}
		if(hsh[i] < k)
		{
			ll tmp=hsh[i];
			for(i=i+1;i<26;i++)
			{
				tmp += hsh[i];
				if(tmp >= k)
				{
					cout<<(char) ('a'+i)<<endl;
					break;
				}
			}
		}
		else
		{
			char c = i + 'a';
			string ans = "";
			ans += c;
			ll done = k;
			hsh[i]-=k;
			if(hsh[i]==0)
			{
				for(i=i+1;i<26;i++)
					if(hsh[i]!=0)
						break;
			}
			if(hsh[i] + done == n)
			{
				ll tmp = ceil((double)hsh[i]/(double)k);
				while(tmp--)
					ans += (char)(i+'a');
			}
			else
			{
				for(;i<26;i++)
					while(hsh[i]--)
						ans += (char) (i+'a');
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}