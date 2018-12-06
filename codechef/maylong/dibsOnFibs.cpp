#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll n,m;
typedef struct x{
	ll a,b,c,d;
}mat;

mat multi(mat a,mat b)
{
	mat temp;
	temp.a=(a.a)*(b.a)+(a.b)*(b.c);
	temp.b=(a.a)*(b.b)+(a.b)*(b.d);
	temp.c=(a.c)*(b.a)+(a.d)*(b.c);
	temp.d=(a.c)*(b.b)+(a.d)*(b.d);
	return temp;
}

// a is first and b is second number
mat fibn(ll a,ll b,ll p)
{
	cout<<p<<endl;
	mat x;
	x.a=a+b;
	x.b=b;
	x.c=b;
	x.d=a;
	if(p==0)
	{
		mat unit={1,0,0,1};
		return unit;
	}
	if(p==1)
		return x;
	if(p%2==0)
	{
		mat temp=fibn(a,b,p/2);
		return multi(temp,temp);
	}
	else
		return multi(fibn(a,b,(p-1)/2),fibn(a,b,(p+1)/2));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		ll i;
		vector<ll> a,b;
		for(i=0;i<m;i++)
		{
			ll val;
			cin>>val;
			a.pb(val);
		}
		for(i=0;i<m;i++)
		{
			ll val;
			cin>>val;
			b.pb(val);
		}
		mat temp=fibn(0,1,n-3);
		mat x={a[0]+b[0],b[0],b[0],a[0]};
		ll ans=(multi(x,temp).a*m)%mod;
		ll xx=fibn(0,1,n-4).a;
		ll suma=0;
		for(i=0;i<m;i++)
			suma+=a[i]-a[0];
		ans=(ans+(((m*suma)%mod)*xx)%mod)%mod;
		ans=(ans*m)%mod;
		ll sumb=0;
		for(i=0;i<m;i++)
			sumb+=b[i]-b[0];
		xx=fibn(0,1,n-3).a;
		ans=(ans+(((m*sumb)%mod)*xx)%mod)%mod;
		cout<<ans<<endl;
	}
	return 0;
}