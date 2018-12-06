#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll a,b;

void simplify()
{
	ll i;
	for(i=100;i>=2;i--)
	{
		if(a%i==0 && b%i==0)
		{
			a=a/i;
			b=b/i;
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll m;
	cin>>m;
	string s;
	vector<pii> xx;
	ll i,j;
	ll countt[1004][1004];
	for(i=0;i<=100;i++)
		for(j=0;j<=100;j++)
			countt[i][j]=0;
	ll c;
	for(i=0;i<m;i++)
	{
		cin>>s;
		if(s[2]=='+')
		{
			a=s[1]-'0';
			if(s[4]==')')
			{
				c=s[3]-'0';
				if(sz(s)==7)
					b=s[6]-'0';
				else
					b=(s[6]-'0')*10+s[7]-'0';
			}
			else
			{
				c=(s[3]-'0')*10+(s[4]-'0');
				if(sz(s)==8)
					b=s[7]-'0';
				else
					b=(s[7]-'0')*10+s[8]-'0';
			}
		}
		else
		{
			a=(s[1]-'0')*10+(s[2]-'0');
			if(s[5]==')')
			{
				c=s[4]-'0';
				if(sz(s)==8)
					b=s[7]-'0';
				else
					b=(s[7]-'0')*10+s[8]-'0';
			}
			else
			{
				c=(s[4]-'0')*10+(s[5]-'0');
				if(sz(s)==9)
					b=s[8]-'0';
				else
					b=(s[8]-'0')*10+s[9]-'0';
			}
		}
		a=a+c;
		simplify();
		xx.pb(mp(a,b));
		countt[a][b]++;
	}
	for(i=0;i<m;i++)
	{
		a=xx[i].first;
		b=xx[i].second;
		cout<<countt[a][b]<<" ";
	}
	cout<<endl;
	return 0;
}