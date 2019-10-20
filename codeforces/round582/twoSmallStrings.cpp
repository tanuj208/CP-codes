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
	ll n;
	cin>>n;
	string s,t;
	cin>>s>>t;
	cout<<"YES\n";
	string A,B,C;
	A=s[0];
	if(s[0]==s[1])
	{
		if(A=="a")
			B="b",C="c";
		else if(A=="b")
			B="c",C="a";
		else
			B="a",C="b";
	}
	else
	{
		B=s[1];
		if((A=="a" && B=="b") || (A=="b" && B=="a"))
			C="c";
		else if((A=="b" && B=="c") || (A=="c" && B=="b"))
			C="a";
		else
			C="b";
	}
	ll i;
	if(s[0]==s[1])
	{
		string s1=A+B;
		string s2=B+C;
		string s3=C+A;
		if(t==s1 || t==s2 || t==s3)
		{
			for(i=0;i<n;i++)
				cout<<A<<C<<B;
			cout<<endl;
		}
		else
		{
			for(i=0;i<n;i++)
				cout<<A<<B<<C;
			cout<<endl;
		}
	}
	else
	{
		string s1=A+C;
		string s2=C+B;
		string s3=B+A;
		if(t==s1)
		{
			for(i=0;i<n;i++)
				cout<<C;
			for(i=0;i<n;i++)
				cout<<B;
			for(i=0;i<n;i++)
				cout<<A;
			cout<<endl;
		}
		else if(t==s2)
		{
			for(i=0;i<n;i++)
				cout<<B;
			for(i=0;i<n;i++)
				cout<<A;
			for(i=0;i<n;i++)
				cout<<C;
			cout<<endl;
		}
		else if(t==s3)
		{
			for(i=0;i<n;i++)
				cout<<B;
			cout<<C;
			for(i=0;i<n;i++)
				cout<<A;
			for(i=1;i<n;i++)
				cout<<C;
			cout<<endl;
		}
		else
		{
			for(i=0;i<n;i++)
				cout<<A<<C<<B;
			cout<<endl;
		}
	}
	return 0;
}