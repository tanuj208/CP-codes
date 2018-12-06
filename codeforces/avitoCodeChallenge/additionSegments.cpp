#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<pair<bool,pii> > ans(10004,mp(false,mp(-1,-1)));
vector<pair<bool,pii> > tempp(10004,mp(false,mp(-1,-1)));

void func(ll val,pii range)
{
	if(tempp[val].first==false)
	{
		tempp[val].first=true;
		tempp[val].second=range;
	}
	else
	{
		ll tmp=tempp[val].second.first;
		tempp[val].second.first=min(tmp,range.first);
		tmp=tempp[val].second.second;
		tempp[val].second.second=max(tmp,range.second);
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,q;
	cin>>n>>q;
	vector<pair<ll,pii> > x;
	ll i,j;
	for(i=0;i<q;i++)
	{
		ll l,r,xx;
		cin>>l>>r>>xx;
		x.pb(mp(xx,mp(l,r)));
	}
	sort(x.begin(),x.end());
	for(i=0;i<q;i++)
	{
		tempp=ans;
		ll val=x[i].first;
		pii range=x[i].second;
		func(val,range);
		for(j=1;j<=n;j++)
		{
			if(j+val>n)
				continue;
			if(ans[j].first==true)
			{
				if(ans[j].second.first<=range.second && range.first<=ans[j].second.second)
				{
					pii tt=mp(max(ans[j].second.first,range.first),min(ans[j].second.second,range.second));
					func(j+val,tt);
				}
			}
		}
		ans=tempp;
	}
	vector<ll> anss;
	for(i=1;i<=n;i++)
	{
		if(ans[i].first==true)
			anss.pb(i);
	}
	cout<<sz(anss)<<endl;
	for(i=0;i<sz(anss);i++)
		cout<<anss[i]<<" ";
	cout<<endl;
	return 0;
}