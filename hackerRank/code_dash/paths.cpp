#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
//K-th smallest
//cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;


typedef long long ll;
typedef pair<ll,ll> pii;

ll mod=1000000007;

ll power(ll x, ll y) 
{
	ll temp;
	if( y == 0)
		return 1;
	temp = power(x, y/2);
	if (y%2 == 0)
		return (temp*temp)%mod;
	else
		return (((x*temp)%mod)*temp)%mod; 
}

ll dpu[1005][1005];
ll dpd[1005][1005];
ll n,m;

void recu(ll i,ll j)
{
	if(i==0 || j==0 || i==n+1 || j==m+1)
	{
		dpu[i][j]=0;
		return;
	}
	if(dpu[i][j]!=-1)
		return;
	if(i==1 && j==1)
	{
		dpu[i][j]=1;
		return;
	}
	recu(i-1,j);
	recu(i,j-1);
	dpu[i][j]=(dpu[i-1][j]+dpu[i][j-1])%mod;
	return;
}

void recd(ll i,ll j)
{
	if(i==0 || j==0 || i==n+1 || j==m+1)
	{
		dpd[i][j]=0;
		return;
	}
	if(dpd[i][j]!=-1)
		return;
	if(i==n && j==m)
	{
		dpd[i][j]=1;
		return;
	}
	recd(i+1,j);
	recd(i,j+1);
	dpd[i][j]=(dpd[i+1][j]+dpd[i][j+1])%mod;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll i,j;
	for(i=0;i<=1000;i++)
		for(j=0;j<=1000;j++)
			dpu[i][j]=-1,dpd[i][j]=-1;

	ll k,q;
	cin>>n>>m>>k>>q;
	for(i=0;i<k;i++)
	{
		ll x,y;
		cin>>x>>y;
		dpu[x][y]=0;
		dpd[x][y]=0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			recu(i,j);
			recd(i,j);
		}
	}

	while(q--)
	{
		ll x,y;
		cin>>x>>y;
		if(x==1 && y==1)
			cout<<dpd[x][y]<<"\n";
		else if(x==n && y==m)
			cout<<dpu[x][y]<<"\n";
		else
			cout<<(dpu[x][y]*dpd[x][y])%mod<<"\n";
	}	
	return 0;
}