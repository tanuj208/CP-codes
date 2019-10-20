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
	ll n,k,s;
	cin>>n>>k>>s;
	if(s>(n-1)*k || s<k)
	{
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	ll moves=k;
	ll dist=s;
	ll x=1;
	while(moves!=dist)
	{
		if(moves-1<dist-n+1)
		{
			x+=n-1;
			if(x>n)
				x=1;
			cout<<x<<" ";
			moves--;
			dist-=(n-1);
		}
		else
		{
			ll tmp=dist-moves+1;
			if(x==1)
				x+=tmp;
			else
				x-=tmp;
			cout<<x<<" ";
			moves--;
			dist=moves;
		}
	}
	ll i;
	for(i=0;i<moves;i++)
	{
		if(i%2==0)
		{
			if(x-1!=0)
				cout<<x-1<<" ";
			else
				cout<<x+1<<" ";
		}
		else
			cout<<x<<" ";
	}
	cout<<endl;
	return 0;
}