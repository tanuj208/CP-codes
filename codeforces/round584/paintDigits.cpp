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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		string d;
		cin>>d;
		ll i;
		string lbl=d;
		char lbl1Max='@';
		char lbl2Max='@';
		for(i=1;i<n;i++)
		{
			if(d[i]>=d[i-1])
			{
				lbl[i-1]='1';
				lbl1Max=d[i-1];
			}
			else
			{
				lbl[i-1]='2';
				lbl2Max=d[i-1];
				break;
			}
		}
		if(lbl2Max=='@')
		{
			lbl[n-1]='1';
			cout<<lbl<<endl;
			continue;
		}
		ll cntr=i-2;
		lbl1Max=d[i];
		lbl[i]='1';
		i++;
		bool ans=true;
		for(;i<n;i++)
		{
			if(d[i]>=lbl2Max)
			{
				lbl[i]='2';
				lbl2Max = max(lbl2Max, d[i]);
			}
			else if(d[i]>=lbl1Max)
			{
				lbl[i]='1';
				lbl1Max=max(lbl1Max, d[i]);
			}
			else
			{
				ans=false;
				break;
			}
		}
		if(!ans)
		{
			cout<<'-'<<endl;
			continue;
		}
		// cout<<lbl<<endl;
		// cout<<cntr<<endl;
		char lbl1Mn=d[cntr+2];
		char lbl2Mn=d[cntr+1];
		for(i=cntr;i>=0;i--)
		{
			if(d[i]<=lbl1Mn)
				lbl[i]='1';
			else
				lbl[i]='2';
		}
		string check="";
		for(i=0;i<n;i++)
			if(lbl[i]=='1')
				check+=d[i];
		for(i=0;i<n;i++)
			if(lbl[i]=='2')
				check+=d[i];
		// cout<<check<<endl;
		for(i=1;i<n;i++)
		{
			if(check[i]<check[i-1])
			{
				ans=false;
				break;
			}
		}
		if(ans)
			cout<<lbl<<endl;
		else
			cout<<"-"<<endl;
	}
	return 0;
}