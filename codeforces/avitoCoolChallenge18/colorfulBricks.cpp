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

ll mod=998244353;

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
	ll n,m,k;
	cin>>n>>m>>k;
	if(m==1 && k==0)
		cout<<1<<endl;
	else if(m==1 && k>0)
		cout<<0<<endl;
	else
	{
		ll num=1;
		ll i;
		for(i=1;i<=n-1;i++)
			num=(num*i)%mod;
		num = (num * m)%mod;
		num=(num*power(m-1,k))%mod;
		ll den=1;
		for(i=1;i<=max(k,n-1-k);i++)
		{
			if(i>min(k,n-1-k))
				den=(den*i)%mod;
			else
			{
				den=(den*i)%mod;
				den=(den*i)%mod;
			}
		}
		// cout<<den<<endl;
		den=power(den,mod-2);
		cout<<(num*den)%mod<<endl;
	}
	return 0;
}