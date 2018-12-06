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
	ll x,y;
	cin>>x>>y;
	if(x==y || (x==2 && y==4) || (x==4 && y==2))
	{
		cout<<"=\n";
		return 0;
	}
	if(x==1)
	{
		cout<<"<\n";
		return 0;
	}
	if(y==1)
	{
		cout<<">\n";
		return 0;
	}
	if(x==3 && y==2)
	{
		cout<<">\n";
		return 0;
	}
	if(x==2 && y==3)
	{
		cout<<"<\n";
		return 0;
	}
	if(x>y)
		cout<<"<\n";
	else
		cout<<">\n";
	return 0;
}