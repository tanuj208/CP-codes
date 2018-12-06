#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
string s;

// a's ith index and search from s's kth index
bool isPresent(string a,ll i, ll k)
{
	if(i>=sz(a))
		return true;
	if(k>=sz(s))
		return false;
	ll j;
	for(j=k;j<sz(s);j++)
	{
		if(a[i]==s[j])
		{
			if(isPresent(a,i+1,j+1))
				return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	s=to_string(n);
	ll i;
	vector<ll> sqr;
	sqr.pb(10000000000);
	for(i=1;i<100000;i++)
	{
		sqr.pb((i*i));
		if(sqr[i]>=n)
			break;
	}
	string sqrr[100000];
	for(i=0;i<sz(sqr);i++)
		sqrr[i]=to_string(sqr[i]);
	for(i=sz(sqr)-1;i>=1;i--)
	{
		if(isPresent(sqrr[i],0,0))
		{
			cout<<sz(s)-sz(sqrr[i])<<endl;
			return 0;
		}
	}
	cout<<"-1\n";
	return 0;
}