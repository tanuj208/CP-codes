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
set<char> bl[100005];
vector<ll> szs(100005);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,x,k;
	cin>>n>>x>>k;
	string s;
	cin>>s;
	ll i;
	ll cntr=0;
	for(i=0;i<n;i+=x)
	{
		ll j;
		for(j=i;j<min(i+x, n);j++)
			bl[cntr].insert(s[j]);
		cntr++;
	}
	szs[cntr-1]=1;
	for(i=cntr-2;i>=0;i--)
	{
		if(szs[i+1] == -1 || szs[i+1] > 1e18 / sz(bl[i+1]))
			szs[i]=-1;
		else
			szs[i]=szs[i+1]*sz(bl[i+1]);
	}
	for(i=0;i<cntr;i++)
	{
		ll frst=*bl[i].begin();
		if(szs[i]==-1)
		{
			cout<<frst;
			continue;
		}
		ll ind=(k-1)/szs[i];
		k-=ind*szs[i];
		ll j=0;
		auto it=bl[i].begin();
		for(it=bl[i].begin();it!=bl[i].end();it++)
		{
			if(j==ind)
				break;
			j++;
		}
		cout<<*it;
	}
	cout<<endl;
	// for(i=0;i<cntr;i++)
	// 	cout<<szs[i]<<" ";
	// cout<<endl;

	return 0;
}