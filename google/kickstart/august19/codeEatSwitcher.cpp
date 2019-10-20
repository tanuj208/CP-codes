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

bool cmp(pii a, pii b)
{
	return (a.ff*b.ss >= a.ss*b.ff);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	ll z;
	for(z=1;z<=t;z++)
	{
		cout<<"Case #"<<z<<": ";
		ll d,s;
		cin>>d>>s;
		vector<pii> ts;
		ll i;
		ll tot_cod=0;
		for(i=0;i<s;i++)
		{
			ll c,e;
			cin>>c>>e;
			ts.pb(mp(e,c));
			tot_cod+=c;
		}
		sort(all(ts), cmp);
		vector<pii> an;
		an.pb(mp(tot_cod, 0));
		for(i=0;i<s;i++)
		{
			ll ee=ts[i].ff;
			ll cc=ts[i].ss;
			an.pb(mp(an[i].ff-cc, an[i].ss+ee));
		}

		sort(all(an));
		string ans;

		for(i=0;i<d;i++)
		{
			ll a,b;
			cin>>a>>b;
			ll idx=upper_bound(all(an), mp(a, b))-an.begin();
			idx--;
			// if(i==2)
			// 	cout<<idx<<endl;
			if(an[idx].ff>=a && an[idx].ss>=b)
			{
				ans+="Y";
				continue;
			}
			if(idx==s)
			{
				ans+="N";
				continue;
			}
			if(an[idx+1].ff>=a && an[idx+1].ss>=b)
			{
				ans+="Y";
				continue;
			}
			ll num=a-an[idx].ff;
			ll den=an[idx+1].ff-an[idx].ff;
			ll xx=__gcd(num, den);
			num/=xx;
			den/=xx;

			ll nnum=(an[idx].ss-an[idx+1].ss)*num;
			ll dden=den;
			xx=__gcd(nnum,dden);
			nnum/=xx;
			dden/=xx;

			nnum = dden*an[idx].ss-nnum;
			xx=__gcd(nnum, dden);
			nnum/=xx;
			dden/=xx;

			if(nnum>=dden*b)
				ans+="Y";
			else
				ans+="N";
			// if(i==2)
			// 	cout<<a<<" "<<b<<" "<<nnum<<" "<<dden<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}