#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

ll val(char c)
{
	return (ll)c-(ll)'a';
}

vector<ll> p(30,-1);

ll parent(ll x)
{
	if(p[x]==-1 || p[x]==x)
		return x;
	p[x]=parent(p[x]);
	return p[x];
}

bool dsu(ll v1,ll v2)
{
	ll x1=parent(v1);
	ll x2=parent(v2);
	if(x1==x2)
		return false;
	p[x1]=x2;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,i;
	cin>>n;
	string s1,s2;
	cin>>s1>>s2;
	vector<pair<char,char> > ans;
	for(i=0;i<sz(s1);i++)
	{
		if(dsu(val(s1[i]),val(s2[i]))==true)
			ans.pb(mp(s1[i],s2[i]));
	}
	cout<<sz(ans)<<endl;
	for(i=0;i<sz(ans);i++)
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	return 0;
}