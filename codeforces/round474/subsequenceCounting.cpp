#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll a[1000],i;
	ll x,d;
	cin>>x>>d;
	a[0]=1;
	for(i=1;i<50;i++)
		a[i]=(a[i-1]+1)*2-1;
	vector<ll> arr;
	for(i=49;i>=0;i--)
	{
		if(x>=a[i])
		{
			x-=a[i];
			arr.pb(i+1);
		}
		if(x>=a[i])
		{
			x-=a[i];
			arr.pb(i+1);
		}
	}
	sort(arr.begin(),arr.end());
	ll size=0;
	for(i=0;i<sz(arr);i++)
		size+=arr[i];
	cout<<size<<endl;
	ll l=d;
	ll k;
	for(i=0;i<sz(arr);i++)
	{
		ll j=arr[i];
		for(k=0;k<j;k++)
			cout<<l<<" ";
		l+=2*d;
	}
	cout<<endl;
	return 0;
}