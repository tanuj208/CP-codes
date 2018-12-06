#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<ll> p(61,0);
ll bit[61]={0};

ll calc(ll x)
{
	ll ones=0;
	ll j=0;
	ll bits=0;
	while(x!=0)
	{
		if(x%2==1)
			bit[j]=1,bits++;
		x/=2;
		j++;
	}
	return bits;
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	ll t;
	cin>>t;
	ll i;
	p[0]=1;
	for(i=1;i<=60;i++)
		p[i]=2*p[i-1];
	while(t--)
	{
		ll n;
		cin>>n;
		ll fac=1;
		ll flag=0;
		while(flag==0)
		{
			for(ll xx=0;xx<=60;xx++)
				bit[xx]=0;
			ll b=calc(n*fac);
			cout<<fac<<" "<<b<<endl;
			if(b>fac)
			{
				fac++;
				continue;
			}
			// cout<<fac<<endl;
			for(i=60;i>0;i--)
			{
				while(b<fac && bit[i]!=0)
				{
					bit[i]--;
					bit[i-1]+=2;
					b++;
				}
				if(b==fac)
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
			fac++;
		}
		cout<<fac<<" ";
		for(i=0;i<=60;i++)
		{
			while(bit[i]!=0)
			{
				cout<<i<<" ";
				bit[i]--;
			}
		}
		cout<<"\n";
	}
	return 0;
}