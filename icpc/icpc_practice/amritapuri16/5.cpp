#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define ff first
#define ss second
#define vll vector<ll>
#define pll pair<ll,ll> 
#define vpll vector<pll>
#define all(X) X.begin(),X.end()
#define endl "\n"
const ll N=1000;
ll a[N];
int main()
{
	ll test;
	cin>>test;
	while(test--)
	{
		ll n,i,j,k;
		cin>>n;
		ll curr=1;
		i=0;
		std::vector<pll> v1,v2;
		while(curr<n)
		{
			curr*=2;
			i++;
		}
		cout<<i<<"\n";
		for(j=1;j<=n;j++)
			a[j]=j;
		ll len=i;
		v1.pb(mp(1,n/2));
		v2.pb(mp(n/2+1,n));
		for(j=0;j<len;j++)
		{
			std::vector<pll> t1,t2;
			for(i=1;i<=n;i++)
				cout<<a[i]<<" ";
			cout<<"\n";
			for(i=0;i<v1.size();i++)
			{
				ll s=v1[i].ff;
				ll e=v1[i].ss;
				if(s!=e)
				{
					ll m=(s+e)/2;
					t1.pb(mp(s,m));
					t1.pb(mp(m+1,e));
				}
				else
					t1.pb(mp(s,e));
			}
			for(i=0;i<v2.size();i++)
			{
				ll s=v2[i].ff;
				ll e=v2[i].ss;
				if(s!=e)
				{
					ll m=(s+e)/2;
					t2.pb(mp(s,m));
					t2.pb(mp(m+1,e));
				}
				else
					t2.pb(mp(s,e));
			}
			v1=t1;v2=t2;
			for(i=1;i<v1.size();i+=2)
			{
				for(k=0;k<=v1[i].ss-v1[i].ff;k++)
				{
					swap(a[v1[i].ff+k],a[v2[i].ff+k]);
				}
			}
		}
	}
}