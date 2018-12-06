#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
ll segTree[5003][5003];
vector<ll> a;

void makeSegTree(ll i,ll j)
{
	if(segTree[i][j]!=-2)
		return;
	if(i==j)
	{
		segTree[i][j]=a[i];
		return;
	}
	if(i>j)
		segTree[i][j]=-1;
	makeSegTree(i+1,j);
	makeSegTree(i,j-1);
	segTree[i][j]=segTree[i][j-1]^segTree[i+1][j];
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i;
	a.pb(-1);
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	ll j;
	for(i=1;i<=5000;i++)
		for(j=1;j<=5000;j++)
			segTree[i][j]=-2;
	makeSegTree(1,n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(segTree[i][j]==-2)
				makeSegTree(i,j);
		}
	}
	ll mat[5002][5002];
	for(i=1;i<=5000;i++)
		for(j=1;j<=5000;j++)
			mat[i][j]=-1;
	for(i=0;i<=n+1;i++)
	{
		mat[i][n+1]=0;
		mat[i][0]=0;
	}
	for(j=0;j<=n+1;j++)
	{
		mat[n+1][j]=0;
		mat[0][j]=0;
	}
	for(i=n;i>=1;i--)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j)
				mat[i][j]=a[i];
			if(i>j)
				continue;
			mat[i][j]=max(segTree[i][j],max(mat[i+1][j],mat[i][j-1]));
		}
	}
	ll q;
	cin>>q;
	while(q--)
	{
		ll l,r;
		cin>>l>>r;
		cout<<mat[l][r]<<endl;
	}
	return 0;
}