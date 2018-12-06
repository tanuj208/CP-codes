#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

bool cmp(pair<string,ll> a, pair<string,ll> b)
{
	ll i;
	string x=a.first,y=b.first;
	for(i=0;i<min(sz(x),sz(y));i++)
	{
		if(x[i]>='0' && x[i]<='9' && (y[i]<'0' || y[i]>'9'))
			return true;
		else if(y[i]>='0' && y[i]<='9' && (x[i]<'0' || x[i]>'9'))
			return false;
		else if(x[i]<y[i])
			return true;
		else if(x[i]>y[i])
			return false;
	}
	if(sz(x)<sz(y))
		return true;
	else if(sz(y)<sz(x))
		return false;
}
string f[100005],l[100005],c[100005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	set<string> tmp;
	map<string,ll> x;
	ll i;
	for(i=0;i<n;i++)
	{
		cin>>f[i]>>l[i]>>c[i];
		string temp=f[i]+" "+l[i]+","+c[i];
		if(tmp.find(temp)==tmp.end())
		{
			tmp.insert(temp);
			x[c[i]]++;
		}
	}
	vector<pair<string,ll> > ans;
	for(auto it=x.begin();it!=x.end();it++)
		ans.pb(mp(it->first,it->second));
	sort(ans.begin(),ans.end(),cmp);
	for(i=0;i<sz(ans);i++)
		cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	return 0;
}