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
	ll i,cnt=0;
	for(i=0;i<n;i++)
	{
		if(s[i]=='8')
			cnt++;
	}
	ll ph=n/11;
	if(cnt>=ph)
		cout<<ph<<endl;
	else
		cout<<cnt<<endl;
	return 0;
}