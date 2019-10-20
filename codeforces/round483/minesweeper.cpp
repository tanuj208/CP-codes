#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
vector<string> mine;
ll n,m;

ll check(ll i,ll j,ll i1,ll j1)
{
	if(abs(i1-i)>=2 || abs(j1-j)>=2)
		return 0;
	if(i1<0 || i1>=n || j1<0 || j1>=m)
		return 0;
	ll c=0;
	if(mine[i1][j1]=='*')
		c++;
	ll x=0;
	if(i1==i && j1==j)
		x=check(i,j,i1+1,j1+1)+check(i,j,i1+1,j1)+check(i,j,i1+1,j1-1)+check(i,j,i1,j1+1)+check(i,j,i1,j1-1)+check(i,j,i1-1,j1+1)+check(i,j,i1-1,j1)+check(i,j,i1-1,j1-1);
	return c+x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	ll i;
	for(i=0;i<n;i++)
	{
		string s;
		cin>>s;
		mine.pb(s);
	}
	ll j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(mine[i][j]=='*')
				continue;
			ll x=check(i,j,i,j);
			if(mine[i][j]=='.' && x!=0)
			{
				cout<<"NO\n";
				return 0;
			}
			if(mine[i][j]!='.' && (ll)mine[i][j]-(ll)'0'!=x)
			{
				cout<<"NO\n";
				return 0;
			}
		}
	}
	cout<<"YES\n";
	return 0;
}