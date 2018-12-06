#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
map<ll,ll> tmp;
map<ll,string> x;
map<ll,pair<pii,string> > vars;

void compute(ll varname, ll var1, string op, ll var2, ll bit, ll index)
{
	ll a,b;
	if(var1==-1)
		a=bit;
	else if(x.find(var1)!=x.end())
		a=x[var1][index]-(ll)'0';
	else
		a=tmp[var1];
	if(var2==-1)
		b=bit;
	else if(x.find(var2)!=x.end())
		b=x[var2][index]-(ll)'0';
	else
		b=tmp[var2];
	if(op=="XOR")
		tmp[varname]=a^b;
	else if(op=="AND")
		tmp[varname]=a&b;
	else
		tmp[varname]=a|b;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	map<string,ll> names;
	ll i;
	for(i=0;i<n;i++)
	{
		string var,temp,val;
		cin>>var>>temp>>val;
		names[var]=i;
		if(val[0]=='0' || val[0]=='1')
			x[i]=val;
		else
		{
			string op,val2;
			cin>>op>>val2;
			ll aa,bb;
			if(val[0]=='?')
				aa=-1;
			else
				aa=names[val];
			if(val2[0]=='?')
				bb=-1;
			else
				bb=names[val2];
			vars[i]=mp(mp(aa,bb),op);
		}
	}
	string maxans,minans;
	for(i=0;i<m;i++)
	{
		ll zero=0;
		tmp.clear();
		for(auto it=vars.begin();it!=vars.end();it++)
			compute(it->first,(it->second).first.first,(it->second).second,(it->second).first.second,0,i);
		for(auto it=tmp.begin();it!=tmp.end();it++)
			if(it->second==0)
				zero++;
		ll zeros=0;
		tmp.clear();
		for(auto it=vars.begin();it!=vars.end();it++)
			compute(it->first,(it->second).first.first,(it->second).second,(it->second).first.second,1,i);
		for(auto it=tmp.begin();it!=tmp.end();it++)
			if(it->second==0)
				zeros++;
		if(zeros>zero)
			maxans.pb('0'),minans.pb('1');
		else if(zero>zeros)
			maxans.pb('1'),minans.pb('0');
		else
			maxans.pb('0'),minans.pb('0');
	}
	cout<<minans<<endl;
	cout<<maxans<<endl;
	return 0;
}