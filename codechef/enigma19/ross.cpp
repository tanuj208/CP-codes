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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m,i,j,k;
	cin>>n>>m;
	vector<ll> cnt(25,0);
	vector<ll> a;
	vector<ll> doneInd(100005,0);
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
		cnt[val]++;
	}
	vector<ll> done(25,0);
	vector<ll> tmpcnt(25,0);
	ll cur=0;
	ll ans=0;
	for(i=1;i<=m;i++)
	{
		ll minVal=LLONG_MAX;
		ll minNum=-1;
		for(j=1;j<=m;j++)
		{
			if(done[j]==1)
				continue;
			ll dones=0;
			ll countt=0;
			for(k=cur;k<cur+cnt[j];k++)
			{
				if(a[k]==j)
					countt++;
				else if(doneInd[k]==1)
					dones++;
			}
			ll tmp=2*cnt[j]-2*countt-tmpcnt[j]-dones;
			if(minVal>tmp)
			{
				minVal=tmp;
				minNum=j;
			}
		}
		j=minNum;
		ans+=minVal;
		done[j]=1;
		for(k=0;k<n;k++)
			if(a[k]==j)
				doneInd[k]=1;
		for(k=cur;k<cur+cnt[j];k++)
			if(doneInd[k]!=1)
				tmpcnt[a[k]]++;
		cur+=cnt[j];
	}
	cout<<ans<<endl;
	return 0;
}