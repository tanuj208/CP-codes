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
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		vector<ll> d;
		ll i,val,j;
		for(i=0;i<n;i++)
		{
			cin>>val;
			d.pb(val);
		}
		ll a[1005][1005];
		ll b[1005][1005];
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				cin>>a[i][j];
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				cin>>b[i][j];
		set<ll> tests;
		for(i=0;i<m;i++)
			tests.insert(i);
		for(i=0;i<n;i++)
		{
			if(d[i]==0)
				continue;
			for(j=0;j<m;j++)
				if(b[i][j]==0)
					if(tests.find(j)!=tests.end())
						tests.erase(j);
		}
		ll max_time = 1000000000;
		set<pii> x[1005];
		set<pii> con;
		for(i=0;i<n;i++)
		{
			if(d[i]==1)
				continue;
			ll flag=0;
			ll tmp=-1;
			for(auto it=tests.begin();it!=tests.end();it++)
			{
				j=*it;
				if(b[i][j]==0)
				{
					flag=1;
					break;
				}
			}
			for(auto it=tests.begin();it!=tests.end();it++)
			{
				j=*it;
				if(b[i][j]==0)
					x[i].insert(mp(j,1000000000));
				else
					x[i].insert(mp(j,a[i][j]));
				tmp=max(tmp,a[i][j]);				
			}
			if(flag==1)
				continue;
			tmp--;
			max_time = min(max_time,tmp);
		}
		ll exit=0;
		for(i=0;i<n;i++)
		{
			if(d[i]==0)
				continue;
			for(auto it=tests.begin();it!=tests.end();it++)
			{
				vector<ll> remove;
				j=*it;
				if(a[i][j]>max_time)
				{
					remove.pb(j);
					ll kk=0;
					for(kk=0;kk<n;kk++)
					{
						if(sz(x[kk])==0)
							continue;
						auto it2=x[kk].lower_bound(mp(j,0));
						x[kk].erase(it2);
						if(sz(x[kk])==0)
						{
							exit=1;
							break;
						}
						it2=x[kk].end();
						it2--;
						max_time=min(max_time, it2->second-1);
					}
				}
				ll kk;
				for(kk=0;kk<sz(remove);kk++)
					tests.erase(remove[kk]);

				if(exit==1)
					break;
			}
			if(exit==1)
				break;
		}
		if(exit==1)
		{
			cout<<"NO\n";
			continue;
		}
		if(sz(tests)==0 || max_time<=0)
		{
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		cout<<sz(tests)<<" "<<max_time<<endl;
		for(auto it=tests.begin();it!=tests.end();it++)
			cout<<*it+1<<" ";
		cout<<"\n";
	}
	return 0;
}