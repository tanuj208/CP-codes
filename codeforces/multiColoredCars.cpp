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
	ll n,a;
	cin>>n>>a;
	vector<ll> c;
	ll i,val;
	set<ll> x;
	ll ans=0;
	cin>>val;
	if(val==a)
		ans=-1;
	else
		x.insert(val);
	ll cnt[1000006]={0};
	cnt[val]++;
	ll flag=0;
	for(i=1;i<n;i++)
	{
		cin>>val;
		cnt[val]++;
		if(val!=a && flag==0)
			x.insert(val);
		else if(val==a)
		{
			flag=1;
			set<ll> tmp;
			for(auto it=x.begin();it!=x.end();it++)
			{
				ll x=*it;
				if(cnt[x]>=cnt[a])
					tmp.insert(x);
			}
			x=tmp;
			tmp.clear();
		}
	}
	if(ans==-1 || x.empty())
	{
		cout<<"-1\n";
		return 0;
	}
	auto it=x.begin();
	cout<<*it<<endl;
	return 0;
}