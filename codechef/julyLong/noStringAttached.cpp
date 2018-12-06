#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

ll val(char c)
{
	return (ll)c-(ll)'a';
}

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
		ll n=sz(s);
		ll i,j;
		ll frwd[100005][27],bcwrd[100005][27];
		for(i=0;i<=100000;i++)
			for(j=0;j<=25;j++)
				frwd[i][j]=0,bcwrd[i][j]=0;
		bcwrd[0][val(s[0])]++;
		for(i=1;i<sz(s);i++)
		{
			for(j=0;j<26;j++)
				bcwrd[i][j]=bcwrd[i-1][j];
			bcwrd[i][val(s[i])]++;
		}
		frwd[n-1][val(s[n-1])]++;
		for(i=n-2;i>=0;i--)
		{
			for(j=0;j<26;j++)
				frwd[i][j]=frwd[i+1][j];
			frwd[i][val(s[i])]++;
		}
		ll curr=0;
		ll maxred=0;
		for(i=0;i<n;i++)
		{
			ll x=val(s[i]);
			ll cost=1;
			ll num=0;
			for(j=x-1;j>=0;j--)
			{
				num+=bcwrd[i][j];
				num-=frwd[i][j+1];
				if(j+1==x)
					num++;
				maxred=max(maxred,num-cost);
				cost++;
			}
			cost=1;
			num=0;
			for(j=x+1;j<26;j++)
			{
				curr+=frwd[i][j];
				num+=frwd[i][j];
				num-=bcwrd[i][j-1];
				if(j-1==x)
					num++;
				maxred=max(maxred,num-cost);
				cost++;
			}
		}
		curr-=maxred;
		cout<<curr<<"\n";
	}
	return 0;
}