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

void printvc(vector<pii> x)
{
	cout<<"Prining vector\n";
	ll i;
	for(i=0;i<sz(x);i++)
		cout<<x[i].ff<<" "<<x[i].ss<<endl;
	cout<<"Done"<<endl;
}

void printans(vector<ll> a)
{
	cout<<"Printing a\n";
	ll i;
	for(i=0;i<sz(a);i++)
		cout<<a[i]<<" ";
	cout<<endl;
	cout<<"Done\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	vector<ll> a;
	ll i;
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a.pb(val);
	}
	ll q;
	cin>>q;
	ll z=1;
	vector<pii> q1(q+2, mp(-1,-1)); // element idx, val changed
	vector<pii> q2; // value changed, query no
	for(z=1;z<=q;z++)
	{
		ll xx;
		cin>>xx;
		if(xx==1)
		{
			ll p,X;
			cin>>p>>X;
			q1[z]=mp(p,X);
		}
		else
		{
			ll X;
			cin>>X;
			q2.pb(mp(X, z));
		}
	}
	sort(all(q2));
	reverse(all(q2));
	// printvc(q1);
	// printvc(q2);
	ll st=1;
	for(i=0;i<sz(q2);i++)
	{
		// printans(a);
		if(i!=0 && q2[i].ss <= st)
			continue;
		if(i==0)
		{
			for(ll j=0;j<n;j++)
				if(a[j]<q2[i].ff)
					a[j]=q2[i].ff;
		}
		for(ll j=st;j<q2[i].ss;j++)
		{
			if(q1[j].ff==-1 && q1[j].ss==-1)
				continue;
			if(q1[j].ss < q2[i].ff)
				a[q1[j].ff-1]=q2[i].ff;
			else
				a[q1[j].ff-1]=q1[j].ss;
		}
		st=q2[i].ss;
	}
	for(ll j=st;j<=q;j++)
	{
		if(q1[j].ff==-1 && q1[j].ss==-1)
			continue;
		a[q1[j].ff-1]=q1[j].ss;
	}
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}