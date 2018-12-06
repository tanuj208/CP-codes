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
	ll n,m;
	cin>>n>>m;
	ll i;
	ll temp=1;
	for(i=1;i<=n;i++)
	{
		temp*=2;
		if(temp>m)
		{
			cout<<m<<endl;
			return 0;
		}
	}
	cout<<m%temp<<endl;
	return 0;
}