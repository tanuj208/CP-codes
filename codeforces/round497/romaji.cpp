#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

bool isVowel(char c)
{
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
		return true;
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	ll last=0;
	ll i;
	for(i=0;i<sz(s);i++)
	{
		if(last==1 && isVowel(s[i])==false)
		{
			cout<<"NO\n";
			return 0;
		}
		if(isVowel(s[i])==true || s[i]=='n')
			last=0;
		else
			last=1;
	}
	if(isVowel(s[sz(s)-1])==false && s[sz(s)-1]!='n')
		cout<<"NO\n";
	else
		cout<<"YES\n";
	return 0;
}