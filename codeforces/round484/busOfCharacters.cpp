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
	vector<pii> w;
	ll i,val;
	for(i=0;i<n;i++)
	{
		cin>>val;
		w.pb(mp(val,i+1));
	}
	sort(w.begin(),w.end());
	string s;
	cin>>s;
	ll j;
	set<ll> x;
	j=0;
	for(i=0;i<2*n;i++)
	{
		if(s[i]=='0')
		{
			cout<<w[j].second<<" ";
			x.insert(j);
			j++;
		}
		else
		{
			auto it=x.end();
			it--;
			ll k=(*it);
			x.erase(it);
			cout<<w[k].second<<" ";
		}
	}
	cout<<endl;
	return 0;
}