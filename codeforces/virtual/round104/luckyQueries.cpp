#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll segTree[2][4000005]; // 0 for increasing
ll cntTree[2][4000005]; // 0 for 4s
ll flag[4000005];
string sr;

void makeTree(ll s,ll e,ll i)
{
	if(s==e)
	{
		segTree[0][i]=1;
		segTree[1][i]=1;
		if(sr[s]=='4')
			cntTree[0][i]=1;
		else
			cntTree[1][i]=1;
		return;
	}
	ll m=(s+e)/2;
	makeTree(s,m,(i<<1));
	makeTree(m+1,e,(i<<1)+1);
	cntTree[0][i]=cntTree[0][(i<<1)]+cntTree[0][(i<<1)+1];
	cntTree[1][i]=cntTree[1][(i<<1)]+cntTree[1][(i<<1)+1];
	segTree[0][i]=max(segTree[0][(i<<1)]+cntTree[1][(i<<1)+1],cntTree[0][(i<<1)]+segTree[0][(i<<1)+1]);
	segTree[1][i]=max(segTree[1][(i<<1)]+cntTree[0][(i<<1)+1],cntTree[1][(i<<1)]+segTree[1][(i<<1)+1]);
	return;
}

void query(ll s,ll e,ll i,ll l,ll r)
{
	if(l>e || r<s)
		return;
	if(l<=s && r>=e)
	{
		flag[i]=(flag[i]+1)%2;
		return;
	}
	ll m=(s+e)/2;
	ll a=i<<1;
	ll b=a+1;
	if(flag[i]==1)
		flag[i]=0,flag[a]=(flag[a]+1)%2,flag[b]=(flag[b]+1)%2;
	query(s,m,a,l,r);
	query(m+1,e,b,l,r);
	cntTree[0][i]=cntTree[flag[a]][a]+cntTree[flag[b]][b];
	cntTree[1][i]=cntTree[(flag[a]+1)%2][a]+cntTree[(flag[b]+1)%2][b];
	segTree[0][i]=max(segTree[flag[a]][a]+cntTree[(flag[b]+1)%2][b],cntTree[flag[a]][a]+segTree[flag[b]][b]);
	segTree[1][i]=max(segTree[(flag[a]+1)%2][a]+cntTree[flag[b]][b],cntTree[(flag[a]+1)%2][a]+segTree[(flag[b]+1)%2][b]);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	cin>>sr;
	makeTree(0,n-1,1);
	while(m--)
	{
		string ss;
		cin>>ss;
		if(ss=="count")
		{
			if(flag[1]==0)
				cout<<segTree[0][1]<<"\n";
			else
				cout<<segTree[1][1]<<"\n";
		}
		else
		{
			ll a,b;
			cin>>a>>b;
			query(0,n-1,1,a-1,b-1);
		}
	}
	return 0;
}