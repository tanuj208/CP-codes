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
	ll n;
	cin>>n;
	vector<int> p;
	ll val,i,j;
	for(i=0;i<n;i++)
	{
		cin>>val;
		p.pb(val);
	}
	ll pri[5];
	for(i=0;i<5;i++)
		cin>>pri[i];
	// cout<<"hi"<<endl;
	ll points=0;
	ll countt[5]={0};
	for(i=0;i<n;i++)
	{
		// cout<<"hi"<<endl;
		points+=p[i];
		// cout<<points<<endl;
		for(j=4;j>=0;j--)
		{
			if(points>=pri[j])
			{
				ll temp=points/pri[j];
				points-=pri[j]*temp;
				countt[j]+=temp;
			}
		}
	}
	for(i=0;i<5;i++)
		cout<<countt[i]<<" ";
	cout<<"\n"<<points<<"\n";
	return 0;
}