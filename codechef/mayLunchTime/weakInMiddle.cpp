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
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<pii> a;
		vector<ll> tmp;
		ll i,val;
		for(i=0;i<n;i++)
		{
			cin>>val;
			a.pb(mp(val,i));
			tmp.pb(val);
		}
		if(n==1)
		{
			cout<<"0\n";
			continue;
		}
		if(n==2)
		{
			cout<<"0 0\n";
			continue;
		}
		sort(a.begin(),a.end());
		vector<ll> ans(100005,-1);
		ans[0]=0;
		ans[n-1]=0;
		ll tt=tmp[0];
		for(i=1;i<n;i++)
		{
			if(tmp[i]>tt)
			{
				ans[i]=0;
				tt=tmp[i];
			}
		}
		tt=tmp[n-1];
		for(i=n-2;i>=0;i--)
		{
			if(tmp[i]>tt)
			{
				ans[i]=0;
				tt=tmp[i];
			}
		}
		for(i=0;i<n;i++)
		{
			ll ind=a[i].second;
			val=a[i].first;
			if(ans[ind]!=-1)
				continue;
			ll flag=0;
			if(tmp[ind]==tmp[ind+1] || tmp[ind]==tmp[ind-1])
			{
				ans[ind]=0;
				continue;
			}
			if(tmp[ind+1]>tmp[ind] && tmp[ind-1]>tmp[ind])
			{
				ans[ind]=1;
				continue;
			}
			ll j;
			ll maxx=0;
			for(j=ind+1;j<n;j++)
			{
				if(tmp[j]>val)
					break;
				else if(tmp[j]==val || ans[j]==0)
					ans[ind]=0;
				else
					maxx=max(maxx,ans[j]);
			}
			ll aaa=0;
			for(j=ind-1;j>=0;j--)
			{
				if(tmp[j]>val)
					break;
				else if(tmp[j]==val || ans[j]==0)
					ans[ind]=0;
				else
					aaa=max(aaa,ans[j]);
			}
			if(ans[ind]!=-1)
				continue;
			ans[ind]=max(aaa+1,maxx+1);
			for(i=0;i<n;i++)
				cout<<ans[i]<<" ";
			cout<<endl;
		}
	}
	return 0;
}