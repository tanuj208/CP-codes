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

vector<vector<ll>> mult_mat(vector<vector<ll>> a, vector<vector<ll>> b)
{
	vector<vector<ll>> c(3, vector<ll> (3));
	ll i,j,k;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			ll cur=0;
			for(k=0;k<3;k++)
				cur+=(a[i][k]*b[k][j])%mod;
			c[i][j] = cur%mod;
		}
	}
	return c;
}

vector<ll> mult_vec(vector<vector<ll>> a, vector<ll> b)
{
	vector<ll> c(3);
	ll i,j;
	for(i=0;i<3;i++)
	{
		ll cur=0;
		for(j=0;j<3;j++)
			cur += (a[i][j] * b[j])%mod;
		c[i] = cur%mod;
	}
	return c;
}

vector<vector<ll>> iden({{1,0,0},{0,1,0},{0,0,1}});

ll power_num(ll x, ll y) 
{
	ll temp;
	if( y == 0)
		return 1;
	temp = power_num(x, y/2);
	if (y%2 == 0)
		return (temp*temp)%mod;
	else
		return (((x*temp)%mod)*temp)%mod; 
}


vector<vector<ll>> power(vector<vector<ll>> x, ll y) 
{
	vector<vector<ll>> temp;
	if( y == 0)
		return iden;
	temp = power(x, y/2);
	if (y%2 == 0)
		return mult_mat(temp, temp);
	else
		return mult_mat(x, mult_mat(temp, temp));
}

void print_mat(vector<vector<ll>> m)
{
	ll i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			cerr<<m[i][j]<<" ";
		cerr<<endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll k;
	cin>>k;
	ll i;
	vector<vector<ll>> base{{1,2,0}, {1,0,0}, {0,1,0}};
	vector<ll> base_vec{1,1,0};
	vector<vector<ll>> cur = base;
	ll den = 2;
	for(i=0;i<k;i++)
	{
		ll val;
		cin>>val;
		cur = power(cur, val);
		den = power_num(den, val);
	}
	// print_mat(cur);
	base_vec = mult_vec(cur, base_vec);
	ll val = base_vec[1]-base_vec[2];
	val += mod;
	val %= mod;

	ll temp = power_num(2, mod-2);
	val = (val * temp) % mod;

	ll num = val;
	den = (den * temp) % mod;

	cout<<num<<"/"<<den<<endl;

	return 0;
}