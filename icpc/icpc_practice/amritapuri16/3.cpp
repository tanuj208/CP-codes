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

const ll N=1e6+5;
bool p[N];
vll fac[N];
ll seive()
{
	lp(i,2,N-1)
	{
		// cerr<<i<<" ";
		if(!p[i])
		{
			lp(j,i,N-1)
			{
				p[j]=1;
				fac[j].pb(i);
				j+=i-1;
			}
			p[i]=0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	seive();
	ll t;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		ll a[n];
		lp(i,0,n)
		{
			cin >> a[i];
			a[i]=-a[i];
		}
		sort(a,a+n);
		ll f=0;
		lp(i,0,n)
		{
			a[i]=-a[i];
			ll x=sqrt(a[i]);
			if(x*x==a[i])
			{
				ll c=0;
					
				if(fac[x].size()==1)
				{
					ll temp=x;
					while(x!=1)
					{
						x/=fac[temp][0];
						c++;
					}
					if(p[2*c+1]==0)
					{
						cout<<i+1<<" ";
						f=1;
					}
				}
			}
		}
		if(f==0)
		{
			cout<<"No supporter found.";
		}
		cout<<endl;
	}
}