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

ll n,t;

ll query(ll x)
{
	ll i;
	ll retVal=-1;
	ll cnt1=0,cnt2=0;
	ll last=t;
	for(i=0;i<30;i++)
	{
		cout<<"? "<<x<<" "<<n<<"\n";
		fflush(stdout);
		ll val;
		cin>>val;
		if(last+val==n)
		{
			cnt1++;
			last=val;
			continue;
		}
		if(cnt2==0 && cnt1%2==0)
			retVal=val;
		else if(cnt2==0 && cnt1%2==1)
			retVal=n-val;
		cnt2++;
		last=val;
		if(cnt1%2==0 && cnt2%2==0)
			return retVal;
	}
	return n-t;
}

int main()
{
	ll i,j;
	ll lt=30;
	cin>>n>>t;
	vector<ll> ans(305);
	vector<ll> tmp;
	tmp.pb(-1);
	tmp.pb(n-t);   // no of ones after flipping i to n
	for(i=2;i<=n;i++)
	{
		ll val=query(i);
		tmp.pb(val);
	}
	ll ones=0;
	for(i=2;i<=n;i++)
	{
		if(tmp[i-1]-tmp[i]>0)
			ans[i-1]=0;
		else
		{
			ans[i-1]=1;
			ones++;
		}
	}
	ans[n]=t-ones;
	cout<<"! ";
	for(i=1;i<=n;i++)
		cout<<ans[i];
	cout<<"\n";
	fflush(stdout);
	return 0;
}