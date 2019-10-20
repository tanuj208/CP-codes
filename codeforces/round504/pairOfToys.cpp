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
	ll n,k;
	cin>>n>>k;
	if(n>=k-1)
	{
		if(k%2==1)
			cout<<(k-1)/2<<endl;
		else
			cout<<(k/2)-1<<endl;
		return 0;
	}
	ll x;
	if(k%2==0)
		x=k/2+1;
	else
		x=(k+1)/2;
	if(n-x+1<=0)
	{
		cout<<"0\n";
		return 0;
	}
	cout<<n-x+1<<endl;
	return 0;
}