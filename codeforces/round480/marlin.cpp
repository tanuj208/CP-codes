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
	cout<<"YES\n";
	ll i;
	for(i=0;i<n;i++)
		cout<<".";
	cout<<endl;
	if(k%2==1)
	{
		cout<<".";
		for(i=1;i<n-1;i++)
		{
			if(i<=n/2+k/2 && i>=n/2-k/2)
				cout<<"#";
			else
				cout<<".";
		}
		cout<<".\n";
		k=k-n+2;
		cout<<".";
		for(i=1;i<n-1;i++)
		{
			if(i<=n/2+k/2 && i>=n/2-k/2 && i!=n/2)
				cout<<"#";
			else
				cout<<".";
		}
		cout<<".\n";
		for(i=0;i<n;i++)
			cout<<".";
		cout<<endl;
	}
	else
	{
		cout<<".";
		ll temp=k/2;
		for(i=1;i<n;i++)
		{
			if(temp>0)
			{
				cout<<"#";
				temp--;
			}
			else
				cout<<".";
		}
		cout<<endl;
		cout<<".";
		temp=k/2;
		for(i=1;i<n;i++)
		{
			if(temp>0)
			{
				cout<<"#";
				temp--;
			}
			else
				cout<<".";
		}
		cout<<endl;
		for(i=0;i<n;i++)
			cout<<".";
		cout<<endl;
	}
	return 0;
}