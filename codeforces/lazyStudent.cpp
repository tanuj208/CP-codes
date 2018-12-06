#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

bool cmp(pair<p,ll> a, pair<p,ll> b)
{
	if(a.first.first<b.first.first)
		return true;
	else if(a.first.first>b.first.first)
		return false;
	else
	{
		if(a.second>b.second)
			return true;
		else
			return false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	vector<pair<p,ll> >wts;
	ll i;
	for(i=0;i<m;i++)
	{
		ll a,b;
		cin>>a>>b;
		wts.pb(mp(mp(a,i),b));
	}
	sort(wts.begin(),wts.end(),cmp);
	ll j,k;
	i=1;
	j=i+2;
	if(wts[0].second==0 || wts[1].second==0)
	{
		cout<<"-1\n";
		return 0;
	}
	vector<pair<ll,p> > ans;
	ans.pb(mp(wts[0].first.second,mp(1,2)));
	ans.pb(mp(wts[1].first.second,mp(2,3)));
	ll x;
	k=3;
	for(x=2;x<m;x++)
	{
		if(wts[x].second==0)
		{
			if(i>j-2)
			{
				j++;
				i=1;
			}
			if(j>k)
			{
				cout<<"-1\n";
				return 0;
			}
			ans.pb(mp(wts[x].first.second,mp(i,j)));
			i++;
		}
		else
		{
			ans.pb(mp(wts[x].first.second,mp(k,k+1)));
			k++;
		}
	}
	sort(ans.begin(),ans.end());
	for(i=0;i<m;i++)
		cout<<ans[i].second.first<<" "<<ans[i].second.second<<"\n";
	return 0;
}