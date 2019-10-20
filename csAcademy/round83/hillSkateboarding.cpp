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
	ll n;
	cin>>n;
	ll i,val,j;
	vector<ll> a;
	double ans=0;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
	}
	for(i=0;i<n;i++)
	{
		if(a[i]!=-1)
			continue;
		ll vel=0;
		double c=0;
		for(j=i;j<n;j++)
		{
			if(a[j]==-1)
			{
				vel+=2;
				c++;
			}

			if(a[j]==0 && vel>0)
			{
				vel--;
				c++;
			}
			else if(a[j]==0 && vel==0)
				break;

			if(a[j]==1 && vel>=2)
			{
				vel-=2;
				c++;
			}
			else if(a[j]==1 && vel==1)
			{
				vel--;
				c+=0.5;
				break;
			}
			else if(a[j]==1 && vel==0)
				break;
		}
		ans=max(ans,c);
		i=j;
	}
	cout<<ans<<endl;
	return 0;
}