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
	ll n,m;
	cin>>n>>m;
	vector<ll> a;
	ll i,val;
	for(i=0;i<n;i++)
	{
		cin>>val;
		a.pb(val);
	}
	ll left=m;
	for(i=0;i<n;i++)
	{
		ll turns=0;
		if(left>a[i])
		{
			cout<<"0 ";
			left-=a[i];
		}
		else
		{
			a[i]-=left;
			turns=(a[i]/m)+1;
			cout<<turns<<" ";
			left=m-a[i]%m;
			if(left==0)
				left=m;
		}
	}
	cout<<endl;
	return 0;
}