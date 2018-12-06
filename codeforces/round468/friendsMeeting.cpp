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
	ll a,b;
	cin>>a>>b;
	ll x=(a+b)/2;
	ll aa=x-min(a,b);
	ll bb=max(a,b)-x;
	ll ans=((aa)*(aa+1))/2+((bb)*(bb+1))/2;
	cout<<ans<<endl;
	return 0;
}