#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
#define lp(var,start,end) for(ll var=start;var<end;++var)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	vector<ll> a;
	ll i,val;
	lp(i,0,n)
	{
		cin>>val;
		a.pb(val);
	}
	ll m1;
	ll m2=0;
	lp(i,0,n)
	{
		m1=min(a[i]-1,1000000-a[i]);
		m2=max(m2,m1);
	}
	cout<<m2<<endl;
	return 0;
}
		