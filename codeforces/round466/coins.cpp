#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
#define lp(var,start,end) for(ll var=start;var<end;++var)
#define sz(a) (int)(a).size()

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k,a,b;
	cin>>n>>k>>a>>b;
	if(k==1)
	{
		cout<<(n-1)*a<<endl;
		return 0;
	}
	ll coins=0;
	coins+=(a*(n%k));
	n=n-n%k;
	while(n!=1 && n>=k)
	{
		if(b>a*(n-(n/k)))
			coins+=a*(n-(n/k));
		else
			coins+=b;
		n=n/k;
		if(n<k)
			break;
		coins+=(a*(n%k));
		n=n-n%k;
	}
	if(n==1)
		cout<<coins<<endl;
	else
		cout<<coins+(a*(n-1))<<endl;
	return 0;
}