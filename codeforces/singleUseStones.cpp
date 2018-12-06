#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<ll> x(100005,0);
ll w,len;

bool possible(ll m)
{
	ll i;
	if(m==0)
		return true;
	for(i=len;i<w;i++)
		if(x[i]-x[i-len]<m)
			return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>w>>len;
	vector<ll> a(100005);
	ll i,val;
	for(i=1;i<w;i++)
	{
		cin>>a[i];
		x[i]=x[i-1]+a[i];
	}
	x[0]=0;
	ll l=0;
	ll r=1000000005;
	ll mid=(l+r)/2;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(possible(mid)==false)
			r=mid-1;
		else
			l=mid+1;
	}
	while(possible(mid)==true)
		mid++;
	while(possible(mid)==false && mid>0)
		mid--;
	cout<<mid<<endl;
	return 0;
}