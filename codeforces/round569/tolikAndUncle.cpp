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

ll n,m;

void rec2(ll col_st, ll col_en)
{
	ll i;
	for(i=1;i<=n;i++)
	{
		cout<<i<<" "<<col_st<<endl;
		cout<<n+1-i<<" "<<col_en<<endl;
	}
	return;
}

void rec1()
{
	ll col_st = 1;
	ll col_en = m;
	while(true)
	{
		if(col_st==col_en)
		{
			ll row_st = 1;
			ll row_en = n;
			while(true)
			{
				if(row_st==row_en)
				{
					cout<<row_st<<" "<<col_st<<endl;
					break;
				}
				cout<<row_st<<" "<<col_st<<endl;
				cout<<row_en<<" "<<col_st<<endl;
				row_st++;
				row_en--;
				if(row_st > row_en)
					break;
			}
			break;
		}
		rec2(col_st, col_en);
		col_st++;
		col_en--;
		if(col_st>col_en)
			break;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	rec1();
	return 0;
}