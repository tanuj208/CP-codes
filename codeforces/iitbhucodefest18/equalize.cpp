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
	string a,b;
	cin>>a>>b;
	ll ans = 0;
	ll i;
	for(i=0;i<n;i++)
	{
		if(a[i]!=b[i] && i+1<n && a[i+1]!=b[i+1] && a[i+1]!=a[i])
			ans++,i+=1;
		else if(a[i] != b[i])
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}