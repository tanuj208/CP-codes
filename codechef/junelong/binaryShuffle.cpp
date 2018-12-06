#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll a,b;

ll numberOfOnes(ll x)
{
	ll ans=0;
	while(x!=0)
	{
		if(x%2==1)
			ans++;
		x/=2;
	}
	return ans;
}

ll anss()
{
	b--;
	ll x1=numberOfOnes(a);
	ll x2=numberOfOnes(b);
	if(x2==0 && x1!=0)
		return -1;
	if(x2>=x1)
		return x2-x1+1;
	else
		return 2;
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
		cin>>a>>b;
		if(a==b)
			cout<<"0\n";
		else
			cout<<anss()<<"\n";
	}
	return 0;
}