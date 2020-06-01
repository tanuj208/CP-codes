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

void print_mat(vector<vector<ll>> mat)
{
	ll i,j;
	for(i=0;i<sz(mat);i++)
	{
		for(j=0;j<sz(mat[i]);j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	vector<vector<ll>> mat;
	ll i,j;
	for(i=0;i<n;i++)
	{
		vector<ll> tmp;
		for(j=0;j<n;j++)
		{
			ll val;
			cin>>val;
			tmp.pb(val);
		}
		mat.pb(tmp);
	}
	ll q;
	cin>>q;
	vector<pair<pii,ll>> t1, t2;
	while(q--)
	{
		ll x,a,b,c;
		cin>>x>>a>>b>>c;
		if(x==1)
			t1.pb(mp(mp(a,b), c));
		else
			t2.pb(mp(mp(a,b), c));
	}
	sort(all(t1));
	sort(all(t2));
	set<pii> tmp;
	j=0;
	ll curx=0;
	for(i=1;i<=n;i++)
	{
		while(j<sz(t1) && t1[j].ff.ff==i)
		{
			curx^=t1[j].ss;
			tmp.insert(mp(t1[j].ff.ss, t1[j].ss));
			j++;
		}
		while(!tmp.empty() && tmp.begin()->first < i)
		{
			curx^=tmp.begin()->second;
			tmp.erase(tmp.begin());
		}
		ll k;
		for(k=0;k<n;k++)
			mat[i-1][k]^=curx;
	}

	tmp.clear();
	j=0;
	curx=0;
	for(i=1;i<=n;i++)
	{
		while(j<sz(t2) && t2[j].ff.ff==i)
		{
			curx^=t2[j].ss;
			tmp.insert(mp(t2[j].ff.ss, t2[j].ss));
			j++;
		}
		while(!tmp.empty() && tmp.begin()->first < i)
		{
			curx^=tmp.begin()->second;
			tmp.erase(tmp.begin());
		}
		ll k;
		for(k=0;k<n;k++)
			mat[k][i-1]^=curx;
	}
	ll ans=0;
	for(i=0;i<n;i++)
		ans+=mat[i][i];
	// print_mat(mat);
	cout<<ans<<endl;
	return 0;
}