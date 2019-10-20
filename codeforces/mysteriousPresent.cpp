#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

vector<pii> x;
vector<pii> dp(5003,mp(-1,-1));
ll n, w, h;

void func(ll k)
{
	ll i;
	for(i = 0 ; i < n ; i ++)
	{
		if(i == k)
			continue;
		if(x[i].first > x[k].first && x[i].second > x[k].second)
		{
			if(dp[i].first == -1)
				func(i);
			if(dp[k].second < dp[i].second + 1)
			{
				dp[k].second = dp[i].second + 1;
				dp[k].first = i;
			}
		}
	}
	if(dp[k].second == -1)
		dp[k].second = 1;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> w >> h;
	ll i;
	for(i = 0 ; i < n ; i ++)
	{
		ll a, b;
		cin>>a>>b;
		x.pb(mp(a,b));
	}
	ll ans=0;
	ll index=-1;
	for(i = 0 ; i < n ; i ++)
	{
		if(dp[i].second == -1)
			func(i);
		if(w < x[i].first && h < x[i].second && ans < dp[i].second)
		{
			ans = dp[i].second;
			index = i;
		}
	}
	cout << ans << endl;
	if(ans == 0)
		return 0;
	i = index;
	cout << i + 1 << " ";
	while(dp[i].first != -1)
	{
		i = dp[i].first;
		cout << i + 1 << " ";
	}
	cout << endl;
	return 0;
}