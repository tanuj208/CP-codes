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
	ll n,d;
	cin>>n>>d;
	vector<ll> a;
	ll i,val;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
	}
	ll ans=0;
	ll blnc=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==0 && blnc<0)
		{
			blnc=0;
			ans++;
		}
		else
			blnc+=a[i];
		if(blnc>d)
		{
			cout<<"-1\n";
			return 0;
		}
	}
	if(ans==0 || ans==1)
	{
		cout<<ans<<endl;
		return 0;
	}
	ll cur=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==0 && cur<0)
			break;
		cur+=a[i];
	}
	cur=0;
	ll mx=0;
	ll days=1;
	ll daala=0;
	for(i=i+1;i<n;i++)
	{
		if(a[i]==0)
		{
			if(cur<0 && -cur+mx>d)
			{
				days++;
				cur=0;
				mx=0;
				daala=0;
			}
			else if(cur<0)
				daala=max(-cur,daala);
		}
		cur+=a[i];
		mx=max(mx,cur);
	}
	if(daala+mx>d)
		days++;
	cout<<days<<endl;
	return 0;
}