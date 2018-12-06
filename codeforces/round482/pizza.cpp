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
	n++;
	if(n==1)
	{
		cout<<"0\n";
		return 0;
	}
	if(n%2==0)
		cout<<n/2<<endl;
	else
		cout<<n<<endl;
	return 0;
}