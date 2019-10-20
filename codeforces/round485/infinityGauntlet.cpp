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
	vector<ll> s(10,0);
	ll i;
	for(i=0;i<n;i++)
	{
		string x;
		cin>>x;
		if(x=="red")
			s[4]=1;
		if(x=="purple")
			s[0]=1;
		if(x=="green")
			s[1]=1;
		if(x=="blue")
			s[2]=1;
		if(x=="orange")
			s[3]=1;
		if(x=="yellow")
			s[5]=1;
	}
	cout<<6-n<<endl;
	if(s[0]==0)
		cout<<"Power\n";
	if(s[1]==0)
		cout<<"Time\n";
	if(s[2]==0)
		cout<<"Space\n";
	if(s[3]==0)
		cout<<"Soul\n";
	if(s[4]==0)
		cout<<"Reality\n";
	if(s[5]==0)
		cout<<"Mind\n";
	return 0;
}