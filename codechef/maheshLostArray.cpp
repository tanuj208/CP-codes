#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	ll i;
	vector<ll> pp;
	pp.pb(1);
	for(i=0;i<15;i++)
		pp.pb(pp[i]*2);
	while(t--)
	{
		ll n;
		cin>>n;
		ll val;
		multiset<ll> x;
		vector<ll> a;
		for(i=0;i<pp[n];i++)
		{
			cin>>val;
			a.pb(val);
		}
		sort(a.begin(),a.end());
		vector<ll> l;
		vector<ll> ans;
		ll cntr=0;
		i=1;
		for(i=1;i<pp[n];i++)
		{
			ll expected = -1;
			ll val=a[i];
			if(sz(x)!=0)
				expected=*x.begin();
			if(val==expected)
				x.erase(x.begin());
			else
			{
				l.pb(val);
				ans.pb(val);
				for(i=0;i<cntr;i++)
				{
					l.pb(l[i]+val);
					x.insert(l[i]+val);
				}
				cntr=sz(l);
			}
		}
		for(i=0;i<n;i++)
			cout<<ans[i]<<" ";
		cout<<"\n";
	}
	return 0;
}