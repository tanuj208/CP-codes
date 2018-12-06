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
	string s;
	cin>>s;
	ll n=sz(s);
	ll ans[1000005];
	ll i=0,j=n-1;
	ll k;
	for(k=0;k<n;k++)
	{
		if(s[k]=='l')
			ans[j]=k+1,j--;
		else
			ans[i]=k+1,i++;
	}
	for(i=0;i<n;i++)
		cout<<ans[i]<<"\n";
	return 0;
}