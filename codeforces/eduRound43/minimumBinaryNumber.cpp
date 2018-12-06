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
	ll i;
	ll flag=0;
	ll c=0;
	for(i=0;i<n;i++)
	{
		if(s[i]=='1')
			flag=1;
		if(s[i]=='0')
			c++;
	}
	if(flag==0)
	{
		cout<<s<<"\n";
		return 0;
	}
	cout<<"1";
	for(i=0;i<c;i++)
		cout<<"0";
	cout<<endl;
	return 0;
}