#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod= 1000000007;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	ll qq;
	for(qq=1;qq<=t;qq++)
	{
		ll n;
		cin>>n;
		string s[5];
		cin>>s[0]>>s[1]>>s[2];
		cout<<"Case #"<<qq<<": ";
		ll done=0;
		if(s[2][n-1]=='#' || s[0][0]=='#' || n%2==1)
		{
			cout<<"0\n";
			continue;
		}
		ll i;
		for(i=0;i<n;i++)
		{
			if(s[1][i]=='#')
			{
				cout<<"0\n";
				done=1;
				break;
			}
		}
		if(done==1)
			continue;
		ll ansa=1,ansb=0;
		for(i=0;i<n-2;i+=2)
		{
			ll tmpa=0;
			ll tmpb=0;
			ll flg1=0;
			ll flg2=0;
			if(s[0][i+1]!='#' && s[0][i+2]!='#')
				tmpa=(ansa+ansb)%mod;
			if(s[2][i+1]!='#' && s[2][i+2]!='#')
				tmpb=(ansa+ansb)%mod;
			ansa=tmpa;
			ansb=tmpb;
		}
		cout<<(ansa+ansb)%mod<<"\n";
	}
	return 0;
}