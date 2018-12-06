#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,i;
	cin>>n;
	// ll N=n-1;
	ll ans=0;
	// ans+=(N+1)/2;
	// ans+=((N+1)/4)*2;
	ans=n/2;
	i=1;
	ll x=4;
	while(x!=0)
	{
		x=(n+2*i-1)/(4*i);
		i*=2;
		ans+=(x*i);
		// n=n/2;
		// ans+=n*i;
	}
	cout<<ans<<endl;
	// ans+=(N+1)/2;
	// while((N+1)!=0)
	// {
	// 	N=N/2;
	// 	ans+=N*2;
	// }
	// while(n!=0)
	// {
	// 	n=n/2;
	// 	ans+=n*2;
	// }
	// ans+=(N/2)*2;
	// ans+=(N/4)*2;
	return 0;
}