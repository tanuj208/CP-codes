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
	vector<ll> hsh(26, 0);
	ll n = sz(s);
	bool odd = false;
	if(n%2==1)
		odd = true;
	ll i;
	for(i=0;i<sz(s);i++)
		hsh[s[i]-'a']++;
	ll oddidx;
	ll lo = -1;
	ll oddcnt=0;
	for(i=0;i<26;i++)
		if(hsh[i]%2==1)
			oddcnt++;
	ll cur=0;
	for(i=0;i<26;i++)
	{
		if(hsh[i]%2==1)
		{
			cur++;
			if(cur <= oddcnt/2)
				hsh[i]++;
			else if(cur == 1+oddcnt/2 && oddcnt %2 ==1);
			else
				hsh[i]--;
		}
	}
	vector<char> ans(n);
	ll idx = 0;
	for(i=0;i<26;i++)
	{
		while(hsh[i]>=2)
		{
			char c = i+'a';
			ans[idx] = c;
			ans[n-idx-1] = c;
			hsh[i]-=2;
			idx++;
		}
		if(hsh[i]>0)
		{
			oddidx = i;
		}
	}
	if(n%2==1)
		ans[n/2] = (char)(oddidx+'a');
	for(i=0;i<n;i++)
		cout<<ans[i];
	cout<<endl;
	return 0;
}