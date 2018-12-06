#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll n;

bool satisfy(ll x)
{
	if(x==0)
		return false;
	ll eaten=0;
	ll tmp=n;
	while(true)
	{
		if(tmp>x)
		{
			eaten+=x;
			tmp-=x;
		}
		else
		{
			eaten+=tmp;
			break;
		}
		tmp=tmp-tmp/10;
	}
	if(eaten>=(n+1)/2)
		return true;
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	if(n<=10)
	{
		cout<<"1\n";
		return 0;
	}
	ll l=n/100;
	ll r=n/10;
	ll mid=(l+r)/2;
	bool xxxx=satisfy(3);
	while(l<=r)
	{
		mid=(l+r)/2;
		if(satisfy(mid)==false)
			l=mid+1;
		else
			r=mid-1;
	}
	while(satisfy(mid)==false)
		mid++;
	cout<<mid<<endl;
	return 0;
}