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
	ll n,k;
	cin>>n>>k;
	vector<ll> key(300,-1);
	ll i,val;
	for(i=0;i<n;i++)
	{
		cin>>val;
		if(key[val]==-1)
		{
			ll j;
			for(j=val;j>=0;j--)
			{
				if(key[j]!=-1)
					break;
			}
			ll temp=j;
			ll temp2=key[temp];
			if(temp!=-1)
			{
				if((val-temp2+1)<=k)
				{
					for(j=temp2;j<=val;j++)
						key[j]=key[temp2];
				}
			}
			if(temp==-1 || (val-temp2+1)>k)
			{
				for(j=val+1-k;j<=val;j++)
				{
					if(key[j]==-1)
						break;
				}
				ll tempp=j;
				for(j=tempp;j<=val;j++)
					key[j]=tempp;
			}
		}
		cout<<key[val]<<" ";
	}
	cout<<endl;
	return 0;
}