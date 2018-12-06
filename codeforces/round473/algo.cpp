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
	if(n<=5)
		cout<<"-1\n";
	else
	{
		cout<<"1 2\n1 3\n1 4\n3 5\n3 6\n";
		for(i=0;i<n-6;i++)
			cout<<"3 "<<i+7<<"\n";
	}
	for(i=2;i<=n;i++)
		cout<<"1 "<<i<<"\n";
	return 0;
}