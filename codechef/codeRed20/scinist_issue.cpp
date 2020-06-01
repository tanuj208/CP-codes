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

vector<vector<ll>> mat(55, vector<ll> (55, -1));
ll n,m;

typedef pair<bool, bool> pbb;

pair<pbb, pbb> fill_mat(vector<vector<ll>>& mat, ll r, ll c, ll& cnt)
{
	pair<pbb, pbb> x=mp(mp(false, false), mp(false, false));
	if(r-1 >=0 && mat[r-1][c]==-1)
	{
		x.ff.ff=true;
		cnt++;
		mat[r-1][c]=1;
	}
	if(r+1 < n && mat[r+1][c]==-1)
	{
		cnt++;
		x.ff.ss=true;
		mat[r+1][c]=1;
	}
	if(c-1 >=0 && mat[r][c-1]==-1)
	{
		x.ss.ff=true;
		cnt++;
		mat[r][c-1]=1;
	}
	if(c+1 < m && mat[r][c+1]==-1)
	{
		x.ss.ss=true;
		cnt++;
		mat[r][c+1]=1;
	}
	return x;
}

void restore_mat(vector<vector<ll>>& mat, ll r, ll c, pair<pbb, pbb> x)
{
	if(x.ff.ff)
		mat[r-1][c]=-1;
	if(x.ff.ss)
		mat[r+1][c]=-1;
	if(x.ss.ff)
		mat[r][c-1]=-1;
	if(x.ss.ss)
		mat[r][c+1]=-1;
	return;
}

void print_mat()
{
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
}

ll rec(vector<vector<ll>>& mat, ll r, ll c, ll cur_cnt)
{
	if(c>=m)
	{
		r++;
		c=0;
	}
	if(r>=n)
		return cur_cnt;
	while(mat[r][c]!=-1)
	{
		c++;
		if(c==m)
		{
			c=0;
			r++;
		}
		if(r==n)
			break;
	}
	if(r>=n)
		return cur_cnt;
	ll tmp2=cur_cnt;
	ll ans=cur_cnt;
	pair<pbb,pbb> tmp = fill_mat(mat, r, c, tmp2);
	mat[r][c]=0;
	ans=max(ans, rec(mat, r, c+1,tmp2));
	restore_mat(mat, r, c, tmp);
	mat[r][c]=-1;
	if(r+1<n && mat[r+1][c]!=1)
	{
		tmp2=cur_cnt;
		tmp=fill_mat(mat, r+1, c, tmp2);
		mat[r+1][c]=0;
		ans=max(ans, rec(mat,r, c+1, tmp2));
		restore_mat(mat, r+1, c, tmp);
		mat[r+1][c]=-1;
	}
	if(c+1<m && mat[r][c+1]!=1)
	{
		tmp2=cur_cnt;
		tmp=fill_mat(mat, r, c+1, tmp2);
		mat[r][c+1]=0;
		ans=max(ans, rec(mat, r, c+1, tmp2));
		restore_mat(mat, r, c+1, tmp);
		mat[r][c+1]=-1;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	cout<<rec(mat, 0, 0, 0)<<endl;
	return 0;
}