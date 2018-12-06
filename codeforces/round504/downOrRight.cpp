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
	ll n;
	cin>>n;
	ll curRow=1;
	ll curCol=1;
	ll rrow=n;
	ll ccol=n;
	vector<char> ans(1005,'!');
	ll l=1;
	ll e=2*n-2;
	ll i;
	while(1)
	{
		if(ans[e]!='!')
		{
			cout<<"! ";
			for(i=1;i<=2*n-2;i++)
				cout<<ans[i];
			cout<<endl;
			exit(0);
		}
		if(curRow==n)
		{
			cout<<"! ";
			for(i=1;i<=2*n-2;i++)
			{
				if(ans[i]=='!')
					cout<<'R';
				else
					cout<<ans[i];
			}
			cout<<endl;
			exit(0);
		}
		if(curCol==n)
		{
			cout<<"! ";
			for(i=1;i<=2*n-2;i++)
			{
				if(ans[i]=='!')
					cout<<'D';
				else
					cout<<ans[i];
			}
			cout<<endl;
			exit(0);
		}
		if(n-curRow-1+n-curCol>=n-1)
		{
			cout<<"? "<<curRow+1<<" "<<curCol<<" "<<n<<" "<<n<<endl;
			cout.flush();
			string s;
			cin>>s;
			if(s=="YES")
			{
				ans[l]='D';
				curRow++;
			}
			else
			{
				ans[l]='R';
				curCol++;
			}
			l++;
		}
		else
		{
			if(ccol-1>=curCol)
			{
				cout<<"? 1 1 "<<rrow<<" "<<ccol-1<<endl;
				cout.flush();
				string s;
				cin>>s;
				if(s=="YES")
				{
					ans[e]='R';
					ccol--;
				}
				else
				{
					ans[e]='D';
					rrow--;
				}
			}
			else
			{
				cout<<"? 1 1 "<<rrow-1<<" "<<ccol<<endl;
				cout.flush();
				string s;
				cin>>s;
				if(s=="YES")
				{
					ans[e]='D';
					rrow--;
				}
				else
				{
					ans[e]='R';
					ccol--;
				}
			}
			e--;
		}
	}
	return 0;
}