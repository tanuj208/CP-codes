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
	int n,k;
	cin>>n>>k;
	int a[105];
	int i;
	int ans=0;
	for(i=0;i<n;++i)
		cin>>a[i];
	int score=a[k-1];
	for(i=0;i<n;++i)
	{
		if(a[i]>=score && a[i]>0)
			ans++;
		else
			break;
	}
	cout<<ans<<endl;
	return 0;
}