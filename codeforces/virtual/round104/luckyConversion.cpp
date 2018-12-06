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
	string a,b;
	cin>>a>>b;
	ll i;
	ll ans=0;
	ll cnta=0,cntb=0;
	for(i=0;i<sz(a);i++)
	{
		if(a[i]=='4')
			cnta++;
		if(b[i]=='4')
			cntb++;
	}
	if(cnta>=cntb)
	{
		for(i=0;i<sz(a);i++)
		{
			if(cnta==cntb)
				break;
			if(a[i]=='4' && b[i]=='7')
			{
				a[i]='7';
				cnta--;
				ans++;
			}
		}
	}
	else
	{
		for(i=0;i<sz(b);i++)
		{
			if(cnta==cntb)
				break;
			if(b[i]=='4' && a[i]=='7')
			{
				b[i]='7';
				cntb--;
				ans++;
			}
		}
	}
	for(i=0;i<sz(a);i++)
		if(a[i]=='4' && b[i]=='7')
			ans++;
	cout<<ans<<endl;
	return 0;
}