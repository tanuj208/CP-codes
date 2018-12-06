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
		ll n;
		cin>>n;
		ll i;
		vector<ll> a;
		for(i=0;i<n;i++)
		{
			ll val;
			cin>>val;
			a.pb(val);
		}
		if(n%2==1)
		{
			cout<<"NO\n";
			continue;
		}
		ll flag=0;
		ll j=n/2;
		for(i=0;i<n/2;i++)
		{
			if(a[i]==-1 && a[j]==-1)
				a[i]=1,a[j]=1;
			else if(a[i]==-1)
				a[i]=a[j];
			else if(a[j]==-1)
				a[j]=a[i];
			else if(a[i]!=a[j])
			{
				cout<<"NO\n";
				flag=1;
				break;
			}
			j++;
		}
		if(flag==1)
			continue;
		cout<<"YES\n";
		for(i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<"\n";
	}
	return 0;
}