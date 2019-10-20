#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll ans=0;
vector<ll> fct(20,1);

ll ways(vector<ll> cnt,ll digits)
{
	ll i;
	ll tmpans=fct[digits];
	for(i=0;i<10;i++)
		tmpans/=fct[cnt[i]];
	if(cnt[0]==0)
		return tmpans;
	cnt[0]--;
	ll xx=fct[digits-1];
	for(i=0;i<10;i++)
		xx/=fct[cnt[i]];
	return tmpans-xx;
}

void func(ll i,vector<ll> cnt,ll digits)
{
	if(i==10)
	{
		ans+=ways(cnt,digits);
		return;
	}
	if(cnt[i]==0)
		func(i+1,cnt,digits);
	else
	{
		ll j;
		for(j=0;j<cnt[i];j++)
		{
			cnt[i]-=j;
			func(i+1,cnt,digits-j);
			cnt[i]+=j;
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll digits=0;
	ll i;
	vector<ll> cnt(10,0);
	for(i=2;i<=19;i++)
		fct[i]=i*fct[i-1];
	while(n!=0)
		cnt[n%10]++,n/=10,digits++;
	func(0,cnt,digits);
	cout<<ans<<endl;
	return 0;
}