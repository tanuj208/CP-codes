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
	int n,m;
	cin>>n>>m;
	string s[100];
	ll i,j,k;
	for(i=0;i<n;i++)
		cin>>s[i];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(s[i][j]=='#')
			{
				for(k=0;k<n;k++)
				{
					if(s[k][j]=='#' && s[i]!=s[k])
					{
						cout<<"No\n";
						return 0;
					}
				}
			}
		}
	}
	cout<<"Yes\n";
	return 0;
}