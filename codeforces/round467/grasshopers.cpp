#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
#define lp(var,start,end) for(ll var=start;var<end;++var)
#define sz(a) (int)(a).size()

ll p,y;

ll isValid(ll x)
{
	ll i;
	ll s=sqrt(x);
	ll sq=min(s,p);
	for(i=2;i<=sq;i++)
	{
		if(x%i==0)
			return 0;
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>p>>y;
	ll i;
	for(i=y;i>p;i--)
	{
		if(isValid(i)==1)
		{
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<"-1\n";
	return 0;
}