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
	ll n;
	cin>>n;
	string moves;
	cin>>moves;
	ll i;
	ll x=0,y=0;
	ll side=0;
	ll coin=0;
	if(moves[0]=='U')
		side=0;
	else
		side=1;
	for(i=0;i<n;i++)
	{
		if(moves[i]=='U')
			y++;
		else
			x++;
		if(side==1 && y>x)
		{
			side=0;
			coin++;
		}
		if(side==0 && x>y)
		{
			side=1;
			coin++;
		}
	}
	cout<<coin<<endl;
	return 0;
}