#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()
#define all(a) a.begin(), a.end()
#define ff first
#define ss second
#define endl "\n"

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
//K-th smallest
//cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;

// priority_queue <ll,vector<ll>,greater<ll> > p;

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

bool allOne(vector<vector<ll>>& mat, ll i, ll j)
{
	if(mat[i][j] == 1 && mat[i+1][j]==1 && mat[i][j+1]==1 && mat[i+1][j+1]==1)
		return true;
	else
		return false;
}

void fillOne(vector<vector<ll>>& mat, ll i, ll j)
{
	mat[i][j]=1;
	mat[i+1][j]=1;
	mat[i][j+1]=1;
	mat[i+1][j+1]=1;
	return;
}

bool checkSame(vector<vector<ll>>& mat1, vector<vector<ll>>& mat2, ll n, ll m)
{
	ll i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(mat1[i][j]!=mat2[i][j])
				return false;
	return true;
}

void printMat(vector<vector<ll>>& mat1, ll n, ll m)
{
	ll i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			cout<<mat1[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	vector<vector<ll>> mat(n+5, vector<ll> (m+5));
	vector<vector<ll>> mat2(n+5, vector<ll> (m+5, 0));
	ll i,j;
	vector<pii> ans;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			cin>>mat[i][j];
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<m-1;j++)
		{
			if(allOne(mat, i, j))
			{
				fillOne(mat2, i, j);
				ans.pb(mp(i+1, j+1));
			}
		}
	}
	if(!checkSame(mat, mat2, n, m))
		cout<<-1<<endl;
	else
	{
		cout<<sz(ans)<<endl;
		for(i=0;i<sz(ans);i++)
			cout<<ans[i].ff<<" "<<ans[i].ss<<endl;
	}
	return 0;
}