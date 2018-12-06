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
	ll n,p;
	cin>>n>>p;
	string s;
	cin>>s;
	ll i,j;
	ll ansIsNo=1;
	char ans[2005];
	for(i=0;i<n;i++)
	{
		j=i+p;
		while(j<sz(s))
		{
			if((s[j-p]=='0' && s[j]=='1') || (s[j-p]=='1' && s[j]=='0'))
			{
				ansIsNo=0;
				break;
			}
			if(s[j-p]=='.' && s[j]=='.')
			{
				s[j-p]='0';
				s[j]='1';
				ansIsNo=0;
				break;
			}
			if(s[j-p]=='.')
			{
				if(s[j]=='1')
					s[j-p]='0';
				else
					s[j-p]='1';
				ansIsNo=0;
				break;
			}
			if(s[j]=='.')
			{
				if(s[j-p]=='1')
					s[j]='0';
				else
					s[j]='1';
				ansIsNo=0;
				break;
			}
			j+=p;
		}
	}
	if(ansIsNo==1)
	{
		cout<<"No\n";
		return 0;
	}
	for(i=0;i<sz(s);i++)
	{
		if(s[i]=='.')
			cout<<'1';
		else
			cout<<s[i];
	}
	cout<<endl;
	return 0;
}