#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,a;
	cin>>n>>a;
	vector<ll> x[1000006],y[1000006];
	ll i;
	for(i=0;i<n;i++)
	{
		ll q,w;
		cin>>q>>w;
		x[q].pb(w);
		y[w].pb(q);
	}
	for(i=1;i<=1000000;i++)
	{
		sort(x[i].begin(),x[i].end());
		sort(y[i].begin(),y[i].end());
	}
	ll ycor=0;
	ll xcor=a+1;
	if(xcor>1000000)
		xcor=1000000;
	ll prevx;
	ll ans=0;
	ll cc=0;
	for(ycor=1;ycor<=a;ycor++)
	{
		if(ycor>1000000)
			break;
		prevx=xcor;
		xcor=a/ycor;
		if(xcor>1000000)
			xcor=1000000;
		for(i=prevx;i>xcor;i--)
		{
			cc-=(upper_bound(x[i].begin(),x[i].end(),ycor-1)-x[i].begin());
		}
		cc+=(upper_bound(y[ycor].begin(),y[ycor].end(),xcor)-y[ycor].begin());
		ans=max(ans,cc);
	}
	cout<<ans<<endl;
	return 0;
}