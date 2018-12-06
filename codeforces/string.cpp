#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

ll val(char c)
{
	return (ll)c-(ll)'a';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	ll k,i;
	cin>>s>>k;
	ll n=sz(s);
	if(k>(n*(n+1))/2)
	{
		cout<<"No such line.\n";
		return 0;
	}
	string ans;
	vector<ll> x[26];
	for(i=0;i<n;i++)
		x[val(s[i])].pb(i);
	while(true)
	{
		ll j;
		ll cnt=0;
		ll tmp=0;
		for(i=0;i<26;i++)
		{
			tmp=cnt;
			for(j=0;j<sz(x[i]);j++)
				cnt+=(n-x[i][j]);
			if(cnt>=k)
				break;
		}
		k-=tmp;
		ans.pb('a'+(char)i);
		if(k<=sz(x[i]))
			break;
		else
			k-=sz(x[i]);
		vector<ll> xx[26];
		for(j=0;j<sz(x[i]);j++)
			if(x[i][j]+1<n)
				xx[val(s[x[i][j]+1])].pb(x[i][j]+1);
		for(i=0;i<26;i++)
			x[i]=xx[i];
	}
	cout<<ans<<endl;
	return 0;
}