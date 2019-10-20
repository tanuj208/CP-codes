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
	vector<ll> a;
	ll i,val;
	ll all=1;
	ll sum=0;
	ll ind=-1;
	for(i=0;i<n;i++)
	{
		cin>>val;
		if(val!=0 && ind==-1)
			all=0,ind=i;
		sum+=val;
		a.pb(val);
	}
	if(all==1)
	{
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	if(sum!=0)
	{
		cout<<"1\n1 "<<n<<endl;
		return 0;
	}
	else
	{
		cout<<"2\n1 "<<ind+1<<endl<<ind+2<<" "<<n<<endl;
		return 0;
	}
	return 0;
}