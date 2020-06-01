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
		ll n;
		cin>>n;
		vector<ll> zz, zo, oz, oo;
		ll i;
		set<string> x;
		vector<string> vec;
		for(i=0;i<n;i++)
		{
			string s;
			cin>>s;
			x.insert(s);
			vec.pb(s);
		}
		ll czo=0;
		ll coz=0;
		ll coo=0;
		ll czz=0;
		for(i=0;i<n;i++)
		{
			string s=vec[i];
			char fir = s[0];
			char las = s[sz(s)-1];
			if(fir=='0' && las=='0')
				czz++;
			else if(fir=='1' && las=='0')
			{
				coz++;
				reverse(all(s));
				if(x.find(s)!=x.end())
					continue;
				oz.pb(i+1);
			}
			else if(fir=='1' && las=='1')
				coo++;
			else
			{
				czo++;
				reverse(all(s));
				if(x.find(s)!=x.end())
					continue;
				zo.pb(i+1);
			}
		}
		if(coo!=0 && czz!=0 && coz==0 && czo==0)
		{
			cout<<-1<<endl;
			continue;
		}
		ll ans=0;
		vector<ll> ans_vec;
		for(i=0;i<sz(oz);i++)
		{
			if(coz>czo+1)
			{
				ans++;
				ans_vec.pb(oz[i]);
				coz--;
				czo++;
			}
			else
				break;
		}

		for(i=0;i<sz(zo);i++)
		{
			if(czo>coz+1)
			{
				ans++;
				ans_vec.pb(zo[i]);
				czo--;
				coz++;
			}
			else
				break;
		}
		if(abs(coz-czo)>1)
		{
			cout<<-1<<endl;
			continue;
		}

		cout<<ans<<endl;
		for(i=0;i<sz(ans_vec);i++)
			cout<<ans_vec[i]<<" ";
		cout<<endl;
	}
	return 0;
}