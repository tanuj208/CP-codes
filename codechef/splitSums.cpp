#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

ll gcd(ll a, ll b)
{
	if(a==0)
		return b;
	if(b==0)
		return a;
	if(b>=a)
		return gcd(a,b%a);
	if(a>b)
		return gcd(b,a);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll h,m;
		cin>>h>>m;
		if(h==1)
		{
			if(m==1)
				cout<<"Yes\n";
			else
				cout<<"No\n";
			continue;
		}
		ll n=((h+1)*h)/2;
		if((n+m)%2==1 || (n-m)%2==1)
		{
			cout<<"No\n";
			continue;
		}
		ll a=(n+m)/2;
		ll b=(n-m)/2;
		if(gcd(a,b)==1)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}