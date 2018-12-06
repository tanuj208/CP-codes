#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
double fac=100000000;
ll n,m;
vector<ll> a,b;

bool possible(ll w)
{
	double x=((double)w/fac);
	ll i;
	for(i=0;i<n;i++)
	{
		double totalwt=m+x;
		double fuel=totalwt/a[i];
		if(x<fuel)
			return false;
		x-=fuel;
		totalwt=m+x;
		double tmp;
		if(i==n-1)
			tmp=b[0];
		else
			tmp=b[i+1];
		fuel=totalwt/tmp;
		if(x<fuel)
			return false;
		x-=fuel;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	ll i,val;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
	}
	for(i=0;i<n;i++)
	{
		cin>>val;
		b.pb(val);
	}
	ll l=0;
	ll r=100000000000000000;
	ll lt=r;
	ll mid=(l+r)/2;
	while(l<r)
	{
		mid=(l+r)/2;
		if(possible(mid)==true)
			r=mid-1;
		else
			l=mid+1;
	}
	while(possible(mid)==true && mid>0)
		mid--;
	while(possible(mid)==false && mid<=lt)
		mid++;
	if(possible(mid)==false)
	{
		cout<<"-1\n";
		return 0;
	}
	double ans=(double)mid/(double)fac;
	printf("%.8f\n",ans);
	return 0;
}