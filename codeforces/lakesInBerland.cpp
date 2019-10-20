#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

vector<string> initialMap;
ll counted[100][100];
vector<vector<pii> > lakes;
vector<pii> q;
ll n,m,k;
ll flag=0;

void func(ll i,ll j)
{
	if(i>=n || j>=m || i<0 || j<0)
		return;
	if(counted[i][j]==1)
		return;
	counted[i][j]=1;
	if(initialMap[i][j]=='*')
		return;
	if(i==0 || i==n-1 || j==0 || j==m-1)
		flag=1;
	q.pb(mp(i,j));
	func(i+1,j);
	func(i,j+1);
	func(i-1,j);
	func(i,j-1);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>k;
	ll i,j;
	for(i=0;i<n;i++)
	{
		string s;
		cin>>s;
		initialMap.pb(s);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			flag=0;
			q.clear();
			func(i,j);
			if(sz(q)!=0 && flag==0)
				lakes.pb(q);
		}
	}
	vector<pii> tmp;
	for(i=0;i<sz(lakes);i++)
	{
		ll x=sz(lakes[i]);
		if(x==0)
			break;
		tmp.pb(mp(x,i));
	}
	sort(tmp.begin(),tmp.end());
	ll ans=0;
	for(i=0;i<sz(tmp)-k;i++)
	{
		ll index=tmp[i].second;
		for(j=0;j<sz(lakes[index]);j++)
		{
			initialMap[lakes[index][j].first][lakes[index][j].second]='*';
			ans++;
		}
	}
	cout<<ans<<endl;
	for(i=0;i<n;i++)
		cout<<initialMap[i]<<"\n";
	return 0;
}