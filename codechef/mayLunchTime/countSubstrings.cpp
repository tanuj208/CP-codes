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
	ll t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		ll k;
		cin>>k;
		ll ans=0;
		ll i,j;
		ll n=sz(s);
		for(i=0;i<n;i++)
		{
			ll hashh[30]={0};
			ll distinct=0;
			for(j=i;j<n;j++)
			{
				ll xxx=s[j]-'a';
				if(hashh[xxx]==0)
					distinct++;
				hashh[xxx]++;
				ll temp=hashh[xxx];
				ll flag=0;
				if(distinct>=k)
				{
					for(ll x=0;x<26;x++)
						if(hashh[x]!=0 && hashh[x]!=temp)
							flag=1;
					if(flag==0)
						ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}