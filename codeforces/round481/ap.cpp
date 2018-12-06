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
	ll i,val;
	ll change=0;
	vector<ll> b;
	vector<ll> temp;
	ll n;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>val;
		b.pb(val);
	}
	if(n<=2)
	{
		cout<<"0\n";
		return 0;
	}
	ll ans=1000000000;
	ll arr[5]={0,1,-1};

	ll j,k;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			temp=b;
			temp[0]+=arr[i];
			temp[1]+=arr[j];
			change=2;
			if(i==0)
				change--;
			if(j==0)
				change--;
			ll d=temp[1]-temp[0];
			for(k=2;k<n;k++)
			{
				if(temp[k]-temp[k-1]==d)
					continue;
				change++;
				if(temp[k]+1-temp[k-1]==d)
					temp[k]++;
				else if(temp[k]-1-temp[k-1]==d)
					temp[k]--;
				else
				{
					change=1000000000;
					break;
				}
			}
			ans=min(ans,change);
		}
	}

	if(ans == 1000000000)
	{
		cout<<"-1\n";
		return 0;
	}
	cout<<ans<<endl;
	return 0;
}