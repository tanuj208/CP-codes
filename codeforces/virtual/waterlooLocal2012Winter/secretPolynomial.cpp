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
	ll n;
	cin>>n;
	ll i;
	for(i=0;i<n;i++)
	{
		ll a,b;
		cin>>a>>b;
		if(a<0 || b<0)
		{
			cout<<"IMPOSSIBLE\n";
			continue;
		}
		if(a==0 && b==0)
		{
			cout<<"0\n";
			continue;
		}
		if(a==0)
		{
			cout<<"IMPOSSIBLE\n";
			continue;
		}
		if(a==1 && b!=1)
		{
			cout<<"IMPOSSIBLE\n";
			continue;
		}
		if(a==1 && b==1)
		{
			cout<<"AMBIGUOUS\n";
			continue;
		}
		ll arr[40];
		ll tmp=b;
		ll k=0;
		ll sum=0;
		while(tmp!=0)
		{
			arr[k]=tmp%a;
			sum+=arr[k];
			tmp/=a;
			k++;
		}
		if(sum>a)
		{
			cout<<"IMPOSSIBLE\n";
			continue;
		}
		if(a>b)
		{
			cout<<"IMPOSSIBLE\n";
			continue;
		}
		if((a-sum)%(a-1)!=0)
		{
			cout<<"IMPOSSIBLE\n";
			continue;
		}
		ll x=(a-sum)/(a-1);
		ll flag=0;
		ll j;
		for(j=k-1;j>=0;j--)
		{
			if(x>0)
			{
				if(arr[j]>=x)
				{
					arr[j]-=x;
					arr[j-1]+=(a*x);
					x=0;
				}
				else
				{
					arr[j-1]+=(a*arr[j]);
					x-=arr[j];
					arr[j]=0;
				}
			}
			if(arr[j]==0 && flag==0)
				continue;
			else
			{
				cout<<arr[j]<<" ";
				flag=1;
			}
		}
		cout<<"\n";
	}
	return 0;
}