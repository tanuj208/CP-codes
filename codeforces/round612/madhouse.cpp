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

void take_input(multiset<string> &a, ll cnt)
{
	ll i;
	for(i=0;i<cnt;i++)
	{
		string s;
		cin>>s;
		sort(all(s));
		a.insert(s);
	}
}

char new_char(string a, string b)
{
	sort(all(a));
	sort(all(b));
	ll i;
	for(i=0;i<sz(b);i++)
	{
		if(a[i]!=b[i])
			return a[i];
	}
	return a[sz(a)-1];
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	ll n;
	cin>>n;
	cout<<"? 1 "<<n<<endl;
	fflush(stdout);
	multiset<string> a;
	take_input(a, (n*(n+1))/2);

	if(n==1)
	{
		cout<<"! "<<*a.begin()<<endl;
		fflush(stdout);
		return 0;
	}

	cout<<"? 2 "<<n<<endl;
	fflush(stdout);
	multiset<string> b;
	take_input(b, (n*(n-1))/2);

	ll i;
	for(auto it=b.begin();it!=b.end();it++)
	{
		auto it2=a.find(*it);
		if(it2!=a.end())
			a.erase(it2);
	}
	string s="";
	bool start=true;
	vector<string> xx(105);
	for(auto it=a.begin();it!=a.end();it++)
	{
		xx[sz(*it)]=*it;
	}
	for(i=1;i<=n;i++)
	{
		if(start)
		{
			s+=xx[i];
			start=false;
			continue;
		}
		s+=new_char(xx[i], s);
	}
	cout<<"! "<<s<<endl;
	fflush(stdout);
	return 0;
}