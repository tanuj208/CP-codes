#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

ll val(char c)
{
	return (ll)c-(ll)'0';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	vector<ll> dp(100005,INT_MAX);
	vector<ll> minReach(15,INT_MAX);
	dp[0]=0;
	minReach[val(s[0])]=0;
	ll n=sz(s);
	ll i;
	ll q=20;
	while(q--)
	{
		for(i=1;i<n;i++)
		{
			ll x=val(s[i]);
			dp[i]=min(dp[i],1+dp[i-1]);
			dp[i]=min(dp[i],1+minReach[x]);
			dp[i]=min(dp[i],1+dp[i+1]);
			minReach[x]=min(minReach[x],dp[i]);
		}
	}
	cout<<dp[n-1]<<endl;
	return 0;
}