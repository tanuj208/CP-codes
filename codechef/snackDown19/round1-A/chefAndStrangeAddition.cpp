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

ll dp[30][30][30][2];   // i=>index j=> number of 1's in first num k=> number of 1's in 2nd number l=> if carry
ll bit3[30];
ll limit=0;

void reset()
{
	ll i,j,k,l;
	for(i=0;i<30;i++)
		for(j=0;j<30;j++)
			for(k=0;k<30;k++)
				for(l=0;l<2;l++)
					dp[i][j][k][l]=-1;
	for(i=0;i<30;i++)
		bit3[i]=0;
	return;
}

ll func(ll ind,ll ones1, ll ones2, ll carry)
{
	if(ones1<0 || ones2<0)
		return 0;
	if(ind==limit && ones1==0 && ones2==0 && carry==0)
		return 1;
	else if(ind==limit)
		return 0;
	if(dp[ind][ones1][ones2][carry]!=-1)
		return dp[ind][ones1][ones2][carry];
	ll x;
	if(carry==1)
	{
		if(bit3[ind]==1)
			x=func(ind+1,ones1,ones2,0)+func(ind+1,ones1-1,ones2-1,1);
		else
			x=func(ind+1,ones1-1,ones2,1)+func(ind+1,ones1,ones2-1,1);
	}
	else
	{
		if(bit3[ind]==1)
			x=func(ind+1,ones1-1,ones2,0)+func(ind+1,ones1,ones2-1,0);
		else
			x=func(ind+1,ones1,ones2,0)+func(ind+1,ones1-1,ones2-1,1);
	}
	dp[ind][ones1][ones2][carry]=x;
	return x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		reset();
		ll a,b,c;
		cin>>a>>b>>c;
		ll i=0;
		ll cnt1=0,cnt2=0;
		while(a!=0)
		{
			if(a%2==1)
				cnt1++;
			a/=2;
			i++;
		}
		i=0;
		while(b!=0)
		{
			if(b%2==1)
				cnt2++;
			b/=2;
			i++;
		}
		i=0;
		while(c!=0)
		{
			bit3[i]=c%2;
			c/=2;
			i++;
		}
		limit=i;
		cout<<func(0,cnt1,cnt2,0)<<"\n";
	}
	return 0;
}