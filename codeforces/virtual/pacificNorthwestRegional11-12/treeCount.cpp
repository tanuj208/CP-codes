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

ll mod=1000000000;

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
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	map<ll,ll> dp[1450];   // height and number
	ll i,j,k,l;
	dp[1][1]=1;
	dp[2][2]=2;
	for(i=3;i<=1427;i++)
	{
		for(j=1;j<=i-2;j++)
		{
			ll oth=i-1-j;
			for(auto it1=dp[j].begin();it1!=dp[j].end();it1++)
			{
				for(auto it2=dp[oth].begin();it2!=dp[oth].end();it2++)
				{
					ll h1=it1->first;
					ll h2=it2->first;
					if(abs(h1-h2)<=1)
					{
						ll tmp=(it1->second * it2->second)%mod;
						dp[i][1+max(h1,h2)]+=tmp;
						dp[i][1+max(h1,h2)]%=mod;
					}
				}
			}
		}
	}
	vector<string> ans(1450);
	for(i=1;i<=1427;i++)
	{
		ll an=0;
		for(auto it=dp[i].begin();it!=dp[i].end();it++)
			an+=it->second;
		an%=mod;
		string s="";
		while(an!=0)
		{
			s+=('0'+(an%10));
			an/=10;
		}
		while(sz(s)<9)
			s+='0';
		reverse(s.begin(),s.end());
		ans[i]=s;
	}
	ll n;
	while(cin>>n)
	{
		cout<<ans[n]<<"\n";
	}
	return 0;
}