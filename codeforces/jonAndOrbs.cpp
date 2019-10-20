#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
double dp[1004]={0};
ll k,q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>k>>q;
	ll i,j;
	ll ans[1004];
	ll d=1;
	for(i=1;i<=1000;i++)
		dp[i]=0;
	dp[0]=1;
	for(i=1;d<=1000;i++)
	{
		for(j=k;j>=1;j--)
			dp[j]=(dp[j]*j+dp[j-1]*(k-j+1))/k;
		while(d<=1000 && dp[k]*2000>=d)
		{
			ans[d]=i;
			d++;
		}
		dp[0]=0;
	}
	while(q--)
	{
		ll p;
		cin>>p;
		cout<<ans[p]<<"\n";
	}
	return 0;
}