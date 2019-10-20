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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i;
	vector<ll> a;
	vector<ll> degreeOne;
	vector<ll> rem;
	ll buffer=0;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
		if(val==1)
			degreeOne.pb(i+1);
		else
			rem.pb(i+1);
		if(val>2)
			buffer+=val-2;
	}
	if(sz(degreeOne)<=2)
	{
		cout<<"YES "<<n-1<<endl;
		cout<<n-1<<endl;
		if(sz(degreeOne)==0)
		{
			for(i=1;i<n;i++)
				cout<<i<<" "<<i+1<<"\n";
		}
		else if(sz(degreeOne)==1)
		{
			ll x=degreeOne[0];
			cout<<x<<" "<<rem[0]<<"\n";
			for(i=0;i<sz(rem)-1;i++)
				cout<<rem[i]<<" "<<rem[i+1]<<"\n";
		}
		else
		{
			ll x=degreeOne[0];
			ll y=degreeOne[1];
			cout<<x<<" "<<rem[0]<<"\n";
			for(i=0;i<sz(rem)-1;i++)
				cout<<rem[i]<<" "<<rem[i+1]<<"\n";
			cout<<rem[i]<<" "<<y<<endl;
		}
		return 0;
	}
	if(buffer<sz(degreeOne)-2)
	{
		cout<<"NO\n";
		return 0;
	}
	else
	{
		ll j=0;
		cout<<"YES "<<1+sz(rem)<<endl;
		cout<<n-1<<endl;
		cout<<degreeOne[j]<<" "<<rem[0]<<"\n";
		j++;
		for(i=0;i<sz(rem)-1;i++)
		{
			if(j==sz(degreeOne)-1)
			{
				cout<<rem[i]<<" "<<rem[i+1]<<"\n";
				continue;
			}
			ll buf=a[rem[i]-1]-2;
			while(buf!=0 && j<sz(degreeOne)-1)
			{
				cout<<rem[i]<<" "<<degreeOne[j]<<"\n";
				buf--;
				j++;
			}
			cout<<rem[i]<<" "<<rem[i+1]<<"\n";
		}
		ll buf=a[rem[i]-1]-2;
		while(buf!=0 && j<sz(degreeOne)-1)
		{
			cout<<rem[i]<<" "<<degreeOne[j]<<"\n";
			buf--;
			j++;
		}
		cout<<rem[i]<<" "<<degreeOne[j]<<endl;
	}
	return 0;
}