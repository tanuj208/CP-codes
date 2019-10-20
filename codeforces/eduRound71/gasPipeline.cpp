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

pii countZeros(string& s, ll st)
{
	ll i;
	ll cnt=0;
	ll n = sz(s);
	for(i=st;i<n;i++)
	{
		if(s[i]=='0')
			cnt++;
		else
			break;
	}
	// cout<<st<<" "<<cnt<<endl;
	if(i==n)
		return mp(-1, st+1);
	else
		return mp(cnt, i);
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
		ll n,a,b;
		cin>>n>>a>>b;
		string s;
		cin>>s;
		ll i;
		ll ans=b;
		bool flag=true;
		for(i=0;i<n;i++)
		{
			if(s[i]=='0')
			{
				ans+=(a+b);
				// cout<<ans<<endl;
				continue;
			}
			else if(flag && s[i]=='1')
			{
				ans+=(2*a+2*b);
				ans+=b;
				// cout<<ans<<endl;
				flag=false;
				i++;
			}
			while(s[i]=='1')
			{
				i++;
				ans+=(a+2*b);
				// cout<<ans<<endl;
			}
			pii xx=countZeros(s, i);
			ll x=xx.ff;
			i=xx.ss-1;
			if(x==-1)
				ans+=(2*a+b);
			else
				ans+=min(a*(x+2)+b*(x+1), a*x+2*b*x);
			// cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}