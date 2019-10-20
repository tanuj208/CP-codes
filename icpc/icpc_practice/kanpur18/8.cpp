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

ll dp[20][10];
ll p[20];
ll sc[15];
ll cum[20];
ll cum0[20];

void pre()
{
	ll i,j;
	p[0]=1;
	for(i=1;i<=19;i++)
		p[i]=(p[i-1]*10)%mod;

	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			sc[i]+=abs(i-j);

	for(i=1;i<=19;i++)
	{
		for(j=1;j<=9;j++)
			cum[i]=(cum[i]+dp[i-1][j])%mod;
		cum0[i]=(cum[i]+dp[i-1][0])%mod;
		for(j=0;j<10;j++)
		{
			dp[i][j]=(cum0[i]+(sc[j]*((i*p[i-1])%mod))%mod)%mod;
			// if(i==2)
			// 	cout<<dp[2][j]<<endl;
		}
	}
}


ll ans(ll x)
{
	ll i,j,k;
	vector<ll> dig;
	while(x!=0)
	{
		dig.pb(x%10);
		x/=10;
	}
	reverse(dig.begin(),dig.end());
	ll digLen=sz(dig);
	ll s=0;
	ll retVal=0;
	// retVal=cum[digLen-1];
	for(i=1;i<digLen;i++)
		retVal+=cum[i];
	retVal%=mod;
	// cout<<retVal<<endl;
	for(i=0;i<digLen;i++)
	{
		j=1;
		if(i)
			j--;
		for(;j<dig[i];j++)
		{
			ll tp=0;
			for(k=i-1;k>=0;k--)
				tp=tp+abs(j-dig[k]);
			tp=tp+s;
			tp=(tp*p[digLen-i-1])%mod;
			tp=(tp+dp[digLen-i-1][j])%mod;
			// cout<<dp[2][1]<<" "<<tp<<endl;
			// cout<<tp<<endl;
			for(k=i-1;k>=0;k--)
				tp=(tp+dp[digLen-i-1][dig[k]])%mod;
			retVal=(retVal+tp)%mod;
		}
		for(k=i-1;k>=0;k--)
			s=s+abs(dig[i]-dig[k]);
	}
	// cout<<retVal<<endl;
	retVal=(retVal+s)%mod;
	return retVal;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	
	pre();
	cin>>t;
	while(t--)
	{
		ll l,r;
		cin>>l>>r;
		cout<<(ans(r)-ans(l-1)+mod)%mod<<"\n";
	}
	return 0;
}