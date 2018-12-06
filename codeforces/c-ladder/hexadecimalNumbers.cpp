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
	ll n,i;
	cin>>n;
	ll arr[600]={0};
	for(i=1;i<=512;i++)
	{
		ll temp=i;
		ll steps=1;
		while(temp!=0)
		{
			if(temp%2==1)
				arr[i]+=steps;
			temp/=2;
			steps*=10;
		}
	}
	ll ans=0;
	for(i=1;i<=512;i++)
	{
		if(n<arr[i])
			break;

	}
	cout<<i-1<<endl;
	return 0;
}