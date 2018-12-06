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
	vector<string> m1;
	vector<string> m2;
	ll i;
	for(i=0;i<n;i++)
	{
		string s;
		cin>>s;
		m1.pb(s);
	}
	for(i=0;i<n;i++)
	{
		string s;
		cin>>s;
		m2.pb(s);
	}
	ll j,k,l;
	ll flag=0;
	for(i=0,k=0;i<n,k<n;i++,k++)
	{
		for(j=0,l=0;j<n,l<n;j++,l++)
		{
			if(m1[i][j]!=m2[k][l])
			{
				flag=1;
				break;
			}
		}
	}
	if(flag==0)
	{
		cout<<"Yes\n";
		return 0;
	}
	flag=0;
	for(i=0,k=0;i<n,k<n;i++,k++)
	{
		for(j=n-1,l=0;j>=0,l<n;j--,l++)
		{
			if(m1[i][j]!=m2[k][l])
			{
				flag=1;
				break;
			}
		}
	}
	if(flag==0)
	{
		cout<<"Yes\n";
		return 0;
	}
	flag=0;
	for(i=n-1,k=0;i>=0,k<n;i--,k++)
	{
		for(j=0,l=0;j<n,l<n;j++,l++)
		{
			if(m1[i][j]!=m2[k][l])
			{
				flag=1;
				break;
			}
		}
	}
	if(flag==0)
	{
		cout<<"Yes\n";
		return 0;
	}
	flag=0;
	for(i=n-1,k=0;i>=0,k<n;i--,k++)
	{
		for(j=n-1,l=0;j>=0,l<n;j--,l++)
		{
			if(m1[i][j]!=m2[k][l])
			{
				flag=1;
				break;
			}
		}
	}
	if(flag==0)
	{
		cout<<"Yes\n";
		return 0;
	}
	flag=0;
	for(i=0,k=0;i<n,k<n;i++,k++)
	{
		for(j=0,l=0;j<n,l<n;j++,l++)
		{
			if(m1[j][i]!=m2[k][l])
			{
				flag=1;
				break;
			}
		}
	}
	if(flag==0)
	{
		cout<<"Yes\n";
		return 0;
	}
	flag=0;
	for(i=0,k=0;i<n,k<n;i++,k++)
	{
		for(j=n-1,l=0;j>=0,l<n;j--,l++)
		{
			if(m1[j][i]!=m2[k][l])
			{
				flag=1;
				break;
			}
		}
	}
	if(flag==0)
	{
		cout<<"Yes\n";
		return 0;
	}
	flag=0;
	for(i=n-1,k=0;i>=0,k<n;i--,k++)
	{
		for(j=0,l=0;j<n,l<n;j++,l++)
		{
			if(m1[j][i]!=m2[k][l])
			{
				flag=1;
				break;
			}
		}
	}
	if(flag==0)
	{
		cout<<"Yes\n";
		return 0;
	}
	flag=0;
	for(i=n-1,k=0;i>=0,k<n;i--,k++)
	{
		for(j=n-1,l=0;j>=0,l<n;j--,l++)
		{
			if(m1[j][i]!=m2[k][l])
			{
				flag=1;
				break;
			}
		}
	}
	if(flag==0)
	{
		cout<<"Yes\n";
		return 0;
	}
	cout<<"No\n";
	return 0;
}