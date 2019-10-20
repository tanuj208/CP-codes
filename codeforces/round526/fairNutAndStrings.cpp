#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
//K-th smallest
//cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;


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
	ll n,k;
	cin>>n>>k;
	ll totalStrings=k;
	k--;
	string s,t;
	cin>>s>>t;
	ll i;
	ll curFree=0;
	ll ans=0;
	bool different=false;
	for(i=0;i<n;i++)
	{
		if(!different && s[i]==t[i])
			ans++;
		else if(!different && s[i]=='a' && t[i]=='b')
		{
			ans+=2;
			k--;
			different=true;
		}
		else
		{
			k-=curFree;
			curFree*=2;
			if(s[i]=='a')
			{
				k--;
				curFree++;
			}
			if(t[i]=='b')
			{
				k--;
				curFree++;
			}
			ans+=curFree+2;
		}
		if(k<=0)
		{
			ans+=k;
			ans+=(n-i-1)*(totalStrings);
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}