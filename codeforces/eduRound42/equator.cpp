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
	ll n;
	cin>>n;
	ll pblm[200005];
	ll i;
	ll sum=0;
	for(i=0;i<n;i++)
	{
		cin>>pblm[i];
		sum+=pblm[i];
	}
	ll temp=0;
	for(i=0;i<n;i++)
	{
		temp+=pblm[i];
		if(temp>=(sum+1)/2)
			break;
	}
	cout<<i+1<<endl;
	return 0;
}