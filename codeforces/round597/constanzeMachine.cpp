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
	vector<ll> fib(100005);
	fib[0]=1;
	fib[1]=1;
	ll i;
	bool aans=true;
	for(i=0;i<sz(s);i++)
		if(s[i]=='m' || s[i]=='w')
			aans=false;
	if(!aans)
	{
		cout<<0<<endl;
		return 0;
	}
	for(i=2;i<=100000;i++)
		fib[i]=(fib[i-1]+fib[i-2])%mod;
	ll ans=1;
	ll cur=0;
	if(s[0]=='u' || s[0]=='n')
		cur++;
	for(i=1;i<sz(s);i++)
	{
		if(s[i]=='n' && s[i-1]=='n')
			cur++;
		else if(s[i]=='u' && s[i-1]=='u')
			cur++;
		else if(s[i]=='u')
		{
			ans=(ans*fib[cur])%mod;
			cur=1;
		}
		else if(s[i]=='n')
		{
			ans=(ans*fib[cur])%mod;
			cur=1;
		}
		else
		{
			ans=(ans*fib[cur])%mod;
			cur=0;
		}
	}
	ans=(ans*fib[cur])%mod;
	cout<<ans<<endl;
	return 0;
}