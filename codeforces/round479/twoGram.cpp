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
	string s;
	cin>>s;
	ll i,j;
	ll ans=1;
	string ansString="";
	ll temp=1;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(s[i]==s[j] && s[i+1]==s[j+1])
				temp++;
		}
		if(ans<=temp)
		{
			ans=temp;
			ansString="";
			ansString+=s[i];
			ansString+=s[i+1];
		}
		temp=1;
	}
	cout<<ansString<<endl;
	return 0;
}