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

ll mat[1005][1005];
vector<ll> vis(1005,0);
ll n;

bool check(ll i,ll j)
{
	ll z;
	for(z=0;z<n;z++)
		if(mat[i][z]!=mat[j][z])
			return false;
	vis[j]=1;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	ll i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			char c;
			cin>>c;
			if(c=='T')
				mat[i][j]=1;
			else
				mat[i][j]=0;
		}
	}
	ll ans=0;
	for(i=0;i<n;i++)
	{
		if(vis[i]==1)
			continue;
		vis[i]=1;
		ll cnt=0;
		bool flag=true;
		for(j=0;j<n;j++)
		{
			if(mat[i][j]==1)
			{
				cnt++;
				if(!check(i,j))
				{
					flag=false;
					break;
				}
			}
		}
		if(flag)
			ans=max(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}