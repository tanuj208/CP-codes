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

ll dp[105][105][2][2];    // i->p, j->q, k->0 means my turn, l->1 means first black
// stores my happiness
ll flag; // 1 means lower right black
ll P,Q;

void func(ll p,ll q,ll turn, ll black)
{
	// cout<<p<<" "<<q<<" "<<turn<<" "<<black<<endl;
	if(dp[p][q][turn][black]!=-100)
		return;

	ll i;
	if(p==0 || q==0)
	{
		dp[p][q][turn][black]=0;
		return;
	}
	if(turn==0)
	{
		dp[p][q][turn][black]=LLONG_MIN;
		ll buffer;
		if(p%2==1 && black==1)
			buffer=1;
		else if(p%2==1 && black==0)
			buffer=-1;
		if(p%2==0)
			buffer=0;
		for(i=1;i<=q;i++)
		{
			ll tmp;
			if((P-p)%2==0)
				tmp=flag;
			else
				tmp=(1+flag)%2;
			func(p,q-i,1,tmp);
			// cout<<p<<" "<<q-i<<" "<<dp[p][q-i][1][tmp]<<endl;
			if(i%2==1)
				dp[p][q][turn][black]=max(dp[p][q][turn][black], buffer+dp[p][q-i][1][tmp]);
			else
				dp[p][q][turn][black]=max(dp[p][q][turn][black], dp[p][q-i][1][tmp]);
		}
	}
	else
	{
		dp[p][q][turn][black]=LLONG_MAX;
		// cout<<p<<" "<<q<<endl;
		ll buffer;
		if(q%2==1 && black==1)
			buffer=-1;
		else if(q%2==1 && black==0)
			buffer=1;
		if(q%2==0)
			buffer=0;

		for(i=1;i<=p;i++)
		{
			ll tmp;
			if((Q-q)%2==0)
				tmp=1;
			else
				tmp=0;
			func(p-i,q,0,tmp);
			if(i%2==1)
				dp[p][q][turn][black]=min(dp[p][q][turn][black], buffer+dp[p-i][q][0][tmp]);
			else
				dp[p][q][turn][black]=min(dp[p][q][turn][black], dp[p-i][q][0][tmp]);
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>P>>Q;
	if(P%2==1 && Q%2==1)
		flag=1;
	else if(P%2==0 && Q%2==0)
		flag=1;
	else
		flag=0;
	for(ll i=0;i<=100;i++)
		for(ll j=0;j<=100;j++)
			for(ll k=0;k<2;k++)
				for(ll l=0;l<2;l++)
					dp[i][j][k][l]=-100;

	func(P,Q,0,1);
	cout<<dp[P][Q][0][1]<<endl;
	return 0;
}