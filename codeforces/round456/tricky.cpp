#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
	ll a,b,x,y,z;
	cin>>a>>b;
	cin>>x>>y>>z;
	ll m,n;
	m=(2*x)+y-a;
	if(m<0)
		m=0;
	n=y+(3*z)-b;
	if(n<0)
		n=0;
	ll ans=m+n;
	if(ans<0)
		ans=0;
	cout<<ans<<endl;
	return 0;
}