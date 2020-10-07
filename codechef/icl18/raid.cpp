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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,q;
	cin>>n;
	set<ll> mat[100][n+1];
	ll i,j;
	for(i=0;i<n;i++)
		mat[0][i].insert(i);
	for(i=1;i<100;i++)
	{
		mat[i][n-1].insert(n-1);
		bool flag=true;
		for(j=n-2;j>=0;j--)
		{
			for(auto it1=mat[i][j+1].begin();it1!=mat[i][j+1].end();it1++)
			{
				if(mat[i][j].find(*it1) != mat[i][j].end())
					mat[i][j].erase(*it1);
			}
			if(sz(mat[i][j])!=1)
				flag = false;
		}
		if(flag)
			break;
	}
	cout<<i<<endl;
	return 0;
}