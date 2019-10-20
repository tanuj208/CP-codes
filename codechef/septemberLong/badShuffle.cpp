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
	ll n,i;
	cin>>n;
	if(n==1)
	{
		cout<<"1\n1\n";
		return 0;
	}
	ll mid=n/2+1;
	for(i=2;i<mid;i++)
		cout<<i<<" ";
	cout<<"1 ";
	for(i=mid+1;i<=n;i++)
		cout<<i<<" ";
	cout<<mid<<endl;
	cout<<n<<" ";
	for(i=1;i<n;i++)
		cout<<i<<" ";
	cout<<endl;
	return 0;
}