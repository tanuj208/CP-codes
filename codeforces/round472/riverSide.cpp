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
	ll n;
	cin>>n;
	ll m[100005];
	ll i;
	for(i=0;i<n;i++)
		cin>>m[i];
	ll allowed[100005]={0};
	p numberAllowed[100005];
	for(i=2;i<n;i++)
	{
		numberAllowed[i].first=i-m[i];
		numberAllowed[i].second=i;
	}
	sort(numberAllowed+2,numberAllowed+n);
	ll prevIndex=1;
	ll temp1=0;
	for(i=2;i<n;i++)
	{
		if(numberAllowed[i].second<prevIndex)
			continue;
		ll temp=numberAllowed[i].first;
		numberAllowed[i].first-=temp1;
		while(numberAllowed[i].first>0 && prevIndex<n)
		{
			allowed[prevIndex]=1;
			prevIndex++;
			if(prevIndex>numberAllowed[i].second)
				break;
			numberAllowed[i].first--;
		}
		temp1=temp-numberAllowed[i].first;
		prevIndex=numberAllowed[i].second;
	}
	ll total=0;
	ll ans=0;
	for(i=1;i<n;i++)
	{
		total++;
		if(allowed[i]==1)
			total--;
		ans+=total-m[i];
	}
	for(i=1;i<n;i++)
		cout<<allowed[i]<<" ";
	cout<<endl;
	cout<<ans<<endl;
	return 0;
}