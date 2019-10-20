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
	ll n,h,a,b,k;
	cin>>n>>h>>a>>b>>k;
	while(k--)
	{
		ll ta,fa,tb,fb;
		cin>>ta>>fa>>tb>>fb;
		if(ta==tb)
		{
			cout<<abs(fa-fb)<<"\n";
			continue;
		}
		ll aa;
		ll cur;
		if(fa<=b && fa>=a)
			aa=0,cur=fa;
		else if(fa>b)
			aa=fa-b,cur=b;
		else
			aa=a-fa,cur=a;
		aa+=abs(tb-ta);
		aa+=abs(cur-fb);
		cout<<aa<<"\n";
	}
	return 0;
}