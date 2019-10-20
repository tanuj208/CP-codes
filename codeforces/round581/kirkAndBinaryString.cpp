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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	ll n=sz(s);
	vector<ll> lis(n+5), rlis(n), z(n), rz(n), o(n), ro(n);
	ll i;
	ll ze=0,on=0;
	for(i=0;i<n;i++)
	{
		if(s[i]=='0')
			ze++;
		else
			on++;
		z[i]=ze;
		o[i]=on;
	}
	ze=0,on=0;
	for(i=n-1;i>=0;i--)
	{
		if(s[i]=='0')
			ze++;
		else
			on++;
		rz[i]=ze;
		ro[i]=on;
	}
	lis[0]=1;
	rlis[n-1]=1;
	for(i=1;i<n;i++)
	{
		if(s[i]=='1')
			lis[i]=1+lis[i-1];
		else
			lis[i]=max(lis[i-1], z[i]);
	}
	for(i=n-2;i>=0;i--)
	{
		if(s[i]=='0')
			rlis[i]=1+rlis[i+1];
		else
			rlis[i]=max(rlis[i+1], ro[i]);
	}
	ll converted=0;
	for(i=0;i<n;i++)
	{
		if(s[i]=='0')
		{
			z[i]+=converted;
			continue;
		}
		// if(i==10)
		// 	cout<<lis[i-1]<<" "<<z[i-1]<<" "<<converted<<endl;
		if((i==0 || lis[i-1]==z[i-1]) && (i==n-1 || rlis[i+1]==ro[i+1]))
		{
			s[i]='0';
			converted++;
		}
		z[i]+=converted;
	}
	cout<<s<<endl;
	return 0;
}