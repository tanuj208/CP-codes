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

string s;

pair<ll,string> func(char a, char b, char c)
{
	ll cnt=0;
	string ss="";
	ll i;
	for(i=0;i<sz(s);i++)
	{
		if(i%3==0)
		{
			if(s[i]!=a)
				cnt++;
			ss+=a;
		}
		else if(i%3==1)
		{
			if(s[i]!=b)
				cnt++;
			ss+=b;
		}
		else
		{
			if(s[i]!=c)
				cnt++;
			ss+=c;
		}
	}
	return mp(cnt,ss);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	cin>>s;
	ll ans=LLONG_MAX;
	string anss;
	string a;
	ll cnt;
	pair<ll,string> tmp;
	tmp=func('R', 'G', 'B');
	cnt = tmp.first;
	a=tmp.second;
	if(ans > cnt)
	{
		ans = cnt;
		anss=a;
	}
	tmp=func('R', 'B', 'G');
	cnt = tmp.first;
	a=tmp.second;
	if(ans > cnt)
	{
		ans = cnt;
		anss=a;
	}
	tmp=func('B', 'R', 'G');
	cnt = tmp.first;
	a=tmp.second;
	if(ans > cnt)
	{
		ans = cnt;
		anss=a;
	}
	tmp=func('B', 'G', 'R');
	cnt = tmp.first;
	a=tmp.second;
	if(ans > cnt)
	{
		ans = cnt;
		anss=a;
	}
	tmp=func('G', 'R', 'B');
	cnt = tmp.first;
	a=tmp.second;
	if(ans > cnt)
	{
		ans = cnt;
		anss=a;
	}
	tmp=func('G', 'B', 'R');
	cnt = tmp.first;
	a=tmp.second;
	if(ans > cnt)
	{
		ans = cnt;
		anss=a;
	}
	cout<<ans<<endl;
	cout<<anss<<endl;
	return 0;
}