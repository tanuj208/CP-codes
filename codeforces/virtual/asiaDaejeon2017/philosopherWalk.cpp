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
	ll n,m,i;
	cin>>n>>m;
	ll cur=n;
	ll pow=-1;
	while(n!=0)
	{
		pow++;
		n/=2;
	}
	vector<ll> x;
	ll flag=0;
	ll cntr=0;
	while(cntr!=pow)
	{
		ll a=m%4;
		// cout<<m<<" "<<a<<endl;
		m/=4;
		if(cntr==0)
		{
			if(a==0)
				x.pb(4);
			else
				x.pb(a);
			cntr++;
			if(a!=0)
				flag=1;
			continue;
		}
		if(flag==0)
		{
			if(a==0)
				x.pb(4);
			else
				x.pb(a);
		}
		else
			x.pb(a+1);
		if(a!=0)
			flag=1;
		cntr++;
	}
	ll ori=1;
	ll ansx=1,ansy=1;
	// for(i=0;i<sz(x);i++)
	// 	cout<<x[i]<<" ";
	// cout<<endl;
	for(i=sz(x)-1;i>=0;i--)
	{
		// cout<<ansx<<" "<<ansy<<endl;
		cur/=2;
		if(ori==1)
		{
			if(x[i]==1)
			{
				ori=2;
				continue;
			}
			else if(x[i]==2)
			{
				ori=1;
				ansy+=cur;
				continue;
			}
			else if(x[i]==3)
			{
				ori=1;
				ansx+=cur;
				ansy+=cur;
				continue;
			}
			else if(x[i]==4)
			{
				ori=4;
				ansx+=cur;
				continue;
			}
		}
		else if(ori==2)
		{
			if(x[i]==1)
			{
				ori=1;
				continue;
			}
			else if(x[i]==2)
			{
				ori=2;
				ansx+=cur;
				continue;
			}
			else if(x[i]==3)
			{
				ori=2;
				ansx+=cur;
				ansy+=cur;
				continue;
			}
			else if(x[i]==4)
			{
				ori=3;
				ansy+=cur;
				continue;
			}
		}
		else if(ori==3)
		{
			if(x[i]==1)
			{
				ori=4;
				ansx+=cur;
				ansy+=cur;
				continue;
			}
			else if(x[i]==2)
			{
				ori=3;
				ansx+=cur;
				continue;
			}
			else if(x[i]==3)
			{
				ori=3;
				continue;
			}
			else if(x[i]==4)
			{
				ori=2;
				ansy+=cur;
				continue;
			}
		}
		else
		{
			if(x[i]==1)
			{
				ori=3;
				ansx+=cur;
				ansy+=cur;
				continue;
			}
			else if(x[i]==2)
			{
				ori=4;
				ansy+=cur;
				continue;
			}
			else if(x[i]==3)
			{
				ori=4;
				continue;
			}
			else if(x[i]==4)
			{
				ori=1;
				ansx+=cur;
				continue;
			}
		}
	}
	cout<<ansx<<" "<<ansy<<endl;
	return 0;
}