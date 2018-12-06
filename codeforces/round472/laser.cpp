#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

//true means d1/e1 is bigger
bool cmp(ll d1, ll e1, ll d2, ll e2)
{
	if(d1*e2>d2*e1)
		return true;
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,u;
	cin>>n>>u;
	vector<ll> e;
	ll i,val;
	for(i=0;i<n;i++)
	{
		cin>>val;
		e.pb(val);
	}
	vector<ll> ind;
	ll j=1;
	for(i=0;i<n-1;i++)
	{
		if(j<=i)
			j=i+1;
		while(e[j]-e[i]<=u && j<n)
			j++;
		ind.pb(j-1);
	}
	ll c=0;
	// for(i=0;i<n;i++)
	// 	cout<<ind[i]<<" ";
	// cout<<"\n";
	for(i=0;i<n;i++)
	{
		if(ind[i]!=i)
			c++;
	}
	// cout<<c<<endl;
	if(c<=2)
	{
		cout<<"-1\n";
		return 0;
	}
	ll ansd=INT_MAX,anse=1;
	for(i=0;i<n-2;i++)
	{
		ll d=e[i+1]-e[i];
		ll ee=e[ind[i]]-e[i];
		if(ee<d)
			continue;
		if(cmp(ansd,anse,d,ee)==true)
		{
			ansd=d;
			anse=ee;
		}
	}
	double ans=1.0-(((double)(ansd))/(double)(anse));
	if(ans<=0)
		ans=-1;
	printf("%.10lf\n",ans);
	// for(i=0;i<n;i++)
	// 	cout<<ind[i]<<" ";
	// cout<<endl;
	return 0;
}