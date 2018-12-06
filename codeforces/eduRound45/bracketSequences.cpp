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
	ll n;
	cin>>n;
	vector<ll> open(300005,0);
	vector<ll> close(300005,0);
	ll valid=0;
	ll i;
	for(i=0;i<n;i++)
	{
		stack<ll> x;
		string s;
		cin>>s;
		ll j;
		ll cl=0;
		for(j=0;j<sz(s);j++)
		{
			if(s[j]=='(')
				x.push(0);
			if(s[j]==')')
			{
				if(!x.empty())
					x.pop();
				else
					cl++;
			}
		}
		ll op=sz(x);
		if(cl==0 && op==0)
			valid++;
		if(cl>0 && op>0)
			continue;
		close[cl]++;
		open[op]++;
	}
	ll ans=0;
	for(i=1;i<=300005;i++)
		ans+=(open[i]*close[i]);
	ans+=(valid*valid);
	cout<<ans<<endl;
	return 0;
}