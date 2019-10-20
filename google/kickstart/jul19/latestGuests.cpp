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

void printPos(vector<ll> pos[], ll n)
{
	ll i,j;
	for(i=0;i<n;i++)
	{
		cout<<i<<" ";
		for(j=0;j<sz(pos[i]);j++)
			cout<<pos[i][j]<<"  ";
		cout<<endl;
	}
	// cout<<endl;
}

void printPos2(pair<ll, vector<ll> > pos[], ll n)
{
	ll i,j;
	for(i=0;i<n;i++)
	{
		cout<<i<<" "<<pos[i].ff<<"    ";
		for(j=0;j<sz(pos[i].ss);j++)
			cout<<pos[i].ss[j]<<"  ";
		cout<<endl;
	}
	// cout<<endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t,z;
	cin>>t;
	for(z=1;z<=t;z++)
	{
		cout<<"Case #"<<z<<": ";
		ll n,g,m;
		cin>>n>>g>>m;
		vector<ll> cglist[n+5], acglist[n+5];
		ll i;
		for(i=0;i<g;i++)
		{
			ll h;
			char c;
			cin>>h>>c;
			if(c=='C')
				cglist[(h-1+m)%n].pb(i);
			else
				acglist[(h-1-m+n*n)%n].pb(i);
		}
		pair<ll, vector<ll> > cl[n+5], acl[n+5]; // time and guest list
		vector<ll> tmp;
		for(i=0;i<n;i++)
			cl[i]=mp(-1, tmp), acl[i]=mp(-1, tmp);
		for(i=n-1;i>=0;i--)
		{
			if(sz(cl[i].ss)!=0)
				break;
			if(sz(cglist[i])==0)
				continue;
			ll time=m;
			cl[i]=mp(time, cglist[i]);
			ll x=i;
			for(i=(i-1+n)%n;i>=0;i=(i-1+n)%n)
			{
				if(i==x)
					break;
				time--;
				if(sz(cglist[i])==0)
					cl[i]=mp(time, cl[x].ss);
				else
				{
					i++;
					break;
				}
			}
		}

		for(i=0;i<n;i++)
		{
			if(sz(acl[i].ss)!=0)
				break;
			if(sz(acglist[i])==0)
				continue;
			ll time=m;
			acl[i]=mp(time, acglist[i]);
			ll x=i;
			for(i=(i+1)%n;i<n;i=(i+1)%n)
			{
				// if(x==4)
				// 	cout<<i<<"    f";
				if(i==x)
					break;
				time--;
				if(sz(acglist[i])==0)
					acl[i]=mp(time, acl[x].ss);
				else
				{
					i--;
					break;
				}
			}
		}
		// printPos2(cl, n);
		// printPos2(acl, n);
		ll ans[g+5]={0};
		for(i=0;i<n;i++)
		{
			if(cl[i].ff>=0)
			{
				if(acl[i].ff>=0)
				{
					if(acl[i].ff==cl[i].ff)
					{
						for(ll j=0;j<sz(cl[i].ss);j++)
							ans[cl[i].ss[j]]++;
						for(ll j=0;j<sz(acl[i].ss);j++)
							ans[acl[i].ss[j]]++;
					}
					else if(acl[i].ff > cl[i].ff)
						for(ll j=0;j<sz(acl[i].ss);j++)
							ans[acl[i].ss[j]]++;
					else
						for(ll j=0;j<sz(cl[i].ss);j++)
							ans[cl[i].ss[j]]++;
				}
				else
					for(ll j=0;j<sz(cl[i].ss);j++)
						ans[cl[i].ss[j]]++;
			}
			else if(acl[i].ff>=0)
				for(ll j=0;j<sz(acl[i].ss);j++)
					ans[acl[i].ss[j]]++;
		}
		for(i=0;i<g;i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}