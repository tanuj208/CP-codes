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
	ll w,t;
	cin>>t;
	ll i;
	vector<ll> pp;
	pp.pb(1);
	for(i=1;i<=14;i++)
		pp.pb(pp[i-1]*2);
	for(w=1;w<=t;w++)
	{
		ll n,m,p;
		cin>>n>>m>>p;
		vector<string> x;
		for(i=0;i<n;i++)
		{
			string s;
			cin>>s;
			x.pb(s);
		}
		set<string> l;
		for(i=0;i<m;i++)
		{
			string s;
			cin>>s;
			l.insert(s);
		}
		ll ans=LLONG_MAX;
		for(i=0;i<pp[p];i++)
		{
			ll xx=i;
			ll j=0;
			string bitt="";
			for(j=0;j<p;j++)
				bitt+='0';
			j=p-1;
			while(xx!=0)
			{
				bitt[j]=char(xx%2+(ll)'0');
				xx/=2;
				j--;
			}
			if(l.find(bitt)!=l.end())
				continue;
			ll q=0;
			for(j=0;j<n;j++)
				for(ll k=0;k<p;k++)
					if(x[j][k] != bitt[k])
						q++;
			ans=min(ans,q);
		}
		cout<<"Case #"<<w<<": "<<ans<<"\n";
	}
	return 0;
}