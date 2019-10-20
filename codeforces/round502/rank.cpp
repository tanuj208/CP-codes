#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

bool cmp(pii a,pii b)
{
	if(a.first==b.first)
		return b.second<a.second;
	else
		return a.first<b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	vector<pii> sum;
	ll i,val;
	for(i=0;i<n;i++)
	{
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		sum.pb(mp(a+b+c+d,i));		
	}
	sort(sum.begin(),sum.end(),cmp);
	reverse(sum.begin(),sum.end());
	ll ans;
	for(i=0;i<n;i++)
		if(sum[i].second==0)
			break;
	cout<<i+1<<endl;
	return 0;
}