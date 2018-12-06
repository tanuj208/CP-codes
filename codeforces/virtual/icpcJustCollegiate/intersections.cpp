#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

#include <ext/pb_ds/assoc_container.hpp> // Common file                                                                                                                                                                             
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update                                                                                                                                                 

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;

typedef long long ll;
typedef pair<int,int> pii;

const int lt=100005;
int mod=1000000007;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	pbds A;
	while(t--)
	{
		A.clear();
		int n;
		cin>>n;
		int i;
		int a[n+5],pos[n+5];
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<n;i++)
		{
			int val;
			cin>>val;
			pos[val]=i;
		}
		ll ans=0;
		for(i=0;i<n;i++)
		{
			int x=a[i];
			ans+=sz(A)-A.order_of_key(pos[x]);
			A.insert(pos[x]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}