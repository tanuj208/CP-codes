#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;
string s[5];

bool f(ll i,ll j)
{
	if(j>=2 && s[i][j-2]=='x' && s[i][j-1]=='x')
		return true;
	if(j>=1 && j<sz(s[0])-1 && s[i][j-1]=='x' && s[i][j+1]=='x')
		return true;
	if(j<sz(s[0])-2 && s[i][j+1]=='x' && s[i][j+2]=='x')
		return true;
	if(i>=2 && s[i-1][j]=='x' && s[i-2][j]=='x')
		return true;
	if(i>=1 && i<=2 && s[i-1][j]=='x' && s[i+1][j]=='x')
		return true;
	if(i<=1 && s[i+1][j]=='x' && s[i+2][j]=='x')
		return true;
	if(j>=2 && i>=2 && s[i-1][j-1]=='x' && s[i-2][j-2]=='x')
		return true;
	if(j>=1 && i>=1 && j<sz(s[0])-1 && i<=2 && s[i-1][j-1]=='x' && s[i+1][j+1]=='x')
		return true;
	if(j<sz(s[0])-2 && i<=1 && s[i+1][j+1]=='x' && s[i+2][j+2]=='x')
		return true;
	if(j>=2 && i<=1 && s[i+1][j-1]=='x' && s[i+2][j-2]=='x')
		return true;
	if(j>=1 && i<=2 && i>=1 && j<sz(s[0])-1 && s[i+1][j-1]=='x' && s[i-1][j+1]=='x')
		return true;
	if(j<sz(s[0])-2 && i>=2 && s[i-1][j+1]=='x' && s[i-2][j+2]=='x')
		return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>s[0]>>s[1]>>s[2]>>s[3];
	ll i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<sz(s[i]);j++)
		{
			if(s[i][j]=='.')
			{
				s[i][j]='x';
				bool tmp=f(i,j);
				if(tmp==true)
				{
					cout<<"YES\n";
					return 0;
				}
				s[i][j]='.';
			}
			else if(s[i][j]=='x')
			{
				bool tmp=f(i,j);
				if(tmp==true)
				{
					cout<<"YES\n";
					return 0;
				}
			}
		}
	}
	cout<<"NO\n";
	return 0;
}