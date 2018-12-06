#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
#define lp(var,start,end) for(ll var=start;var<end;++var)
#define sz(a) (int)(a).size()

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i;
	ll ans=0;
	for(i=1;i<n;i++)
	{
		if((n-i)%i==0)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}