#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

string a,b;
vector<ll> countt(15,0);

// string flag1(string ans,ll i)
// {
// 	ll j=b[i]-1;
// 	while(countt[j-'0']>0 && j>=0)
// 		j--;
// 	ans+=j-'0';
// 	countt[j-'0']--;
// 	return maxAns(ans,i+1);
// }

string maxAns(string ans,ll i)
{
	for(i=9;i>=0;i--)
		while(countt[i]--)
			ans+=i+'0';
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>a>>b;
	ll i;
	for(i=0;i<sz(a);i++)
		countt[a[i]-'0']++;
	string ans="";
	if(sz(b)>sz(a))
	{
		cout<<maxAns("",0)<<"\n";
		return 0;
	}
	ll flag=0,j;
	for(i=0;i<sz(b);i++)
	{
		if(flag==1)
		{
			cout<<maxAns(ans,i)<<endl;
			return 0;
		}
		if(flag==0)
		{
			if(countt[b[i]-'0']>0)
			{
				countt[b[i]-'0']--;
				ans+=b[i];
			}
			else
			{
				while(i>=0)
				{
					j=b[i]-1;
					while(countt[j-'0']==0 && (j-'0')>=0)
						j--;
					if(j-'0'==-1)
					{
						i--;
						countt[ans[i]-'0']++;
						ans=ans.substr(0,sz(ans)-1);
						continue;
					}
					ans+=j;
					countt[j-'0']--;
					flag=1;
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}