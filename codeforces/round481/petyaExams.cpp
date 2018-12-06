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
	ll n,m;
	cin>>n>>m;
	ll i;
	vector<ll> ans(105,-1);
	vector<pii> decl;
	vector<ll> dayOfExam(105,-1);
	vector<ll> exam,days;
	for(i=0;i<m;i++)
	{
		ll s,d,c;
		cin>>s>>d>>c;
		decl.pb(mp(s-1,i));
		exam.pb(d-1);
		dayOfExam[d]=i;
		days.pb(c);
	}
	sort(decl.begin(),decl.end());
	set<pii> declared;
	ll k=0;
	for(i=0;i<n;i++)
	{
		while(k<m && decl[k].first==i)
		{
			ll aa=decl[k].second;
			declared.insert(mp(exam[aa],aa));
			k++;
		}
		ll x=dayOfExam[i+1];
		if(x!=-1 && days[x]==0)
		{
			ans[i]=m+1;
			continue;
		}
		else if(x!=-1 && days[x]>0)
		{
			cout<<"-1\n";
			return 0;
		}
		if(sz(declared)==0)
			ans[i]=0;
		else
		{
			auto it=declared.begin();
			ans[i]=(*it).second+1;
			days[ans[i]-1]--;
			if(days[ans[i]-1]==0)
				declared.erase(it);
		}
	}
	for(i=0;i<n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}