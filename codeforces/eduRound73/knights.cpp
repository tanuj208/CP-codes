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

vector<vector<char>> mat(105, vector<char> (105, '@'));
ll n;

bool valid(ll i,ll j)
{
	if(i<0 || j<0 || i>=n || j>=n || mat[i][j]!='@')
		return false;
	return true;
}

void dfs(ll i,ll j, char c)
{
	if(mat[i][j] != '@')
		return;
	mat[i][j]=c;
	char new_char;
	if(c=='W')
		new_char='B';
	else
		new_char='W';

	if(valid(i+2, j+1))
		dfs(i+2, j+1, new_char);
	if(valid(i+2, j-1))
		dfs(i+2, j-1, new_char);
	if(valid(i-2, j+1))
		dfs(i-2, j+1, new_char);
	if(valid(i-2, j-1))
		dfs(i-2, j-1, new_char);
	if(valid(i+1, j+2))
		dfs(i+1, j+2, new_char);
	if(valid(i+1, j-2))
		dfs(i+1, j-2, new_char);
	if(valid(i-1, j+2))
		dfs(i-1, j+2, new_char);
	if(valid(i-1, j-2))
		dfs(i-1, j-2, new_char);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	ll i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			dfs(i, j, 'W');
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<mat[i][j];
		cout<<endl;
	}
	return 0;
}