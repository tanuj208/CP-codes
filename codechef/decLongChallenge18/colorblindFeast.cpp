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
	ll q,k;
	cin>>q>>k;
	ll prevAns=0;
	deque<pii> seq;
	if(q<=2000)
	{
		while(q--)
		{
			ll a,b;
			cin>>a>>b;
			b = b ^ prevAns;
			if(a==1)
			{
				ll c;
				cin>>c;
				seq.push_front(mp(b,c));
			}
			else if(a==2)
			{
				ll c;
				cin>>c;
				seq.pb(mp(b,c));
			}
			else
			{
				ll ans=0;
				ll cnt=0;
				for(auto it=seq.begin();it!=seq.end();it++)
				{
					ll color=it->first;
					ll del = it->second;
					if(color > b+k || color < b-k)
						continue;
					cnt+=del;
					ans=max(ans,cnt);
					if(cnt<0)
						cnt=0;
				}
				prevAns=ans;
				cout<<ans<<"\n";
			}
		}
	}
	return 0;
}