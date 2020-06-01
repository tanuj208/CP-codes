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

map<ll,ll> a;
set<pii> x;

void fill_rect(ll n,ll m)
{
	cout<<n*m<<endl;
	cout<<n<<" "<<m<<endl;
	ll rec[n+4][m+4];
	ll i,j;
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++)
			rec[i][j]=-1;
	ll curi=0, curj=0;
	for(auto it=x.rbegin();it!=x.rend();it++)
	{
		while(rec[curi][curj]!=-1)
		{
			curj++;
			if(curj==m)
			{
				curi++;
				curj=0;
			}
		}
		ll num=it->second;
		ll cnt=it->first;
		ll tmpi=curi;
		ll tmpj=curj;
		while(cnt--)
		{
			rec[tmpi][tmpj]=num;
			tmpi++;
			tmpj++;
			if(tmpi==n)
				tmpi=0;
			if(tmpj==m)
				tmpj=0;
		}
		curj++;
		if(curj==m)
		{
			curj=0;
			curi++;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			cout<<rec[i][j]<<" ";
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
	ll i,j;
	vector<ll> facs[n+5];
	vector<ll> nearest_fac(n+5);
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j+=i)
			facs[j].pb(i);

	for(i=1;i<=n;i++)
	{
		sort(all(facs[i]));
		for(j=sz(facs[i])-1;j>=0;j--)
		{
			ll xx=facs[i][j];
			if(xx<=sqrt(i))
			{
				nearest_fac[i]=xx;
				break;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		a[val]++;
	}
	for(auto it=a.begin();it!=a.end();it++)
		x.insert(mp(it->ss, it->ff));

	for(i=n;i>=1;i--)
	{
		auto it=x.rbegin();
		ll cnt=it->ff;
		ll no=it->ss;
		if(cnt <= nearest_fac[i])
		{
			fill_rect(nearest_fac[i], i/nearest_fac[i]);
			break;
		}
		auto it2=x.end();
		it2--;
		x.erase(it2);
		x.insert(mp(cnt-1, no));
	}

	return 0;
}