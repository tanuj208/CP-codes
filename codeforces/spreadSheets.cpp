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
	ll i,j;
	string s;
	for(i=0;i<n;i++)
	{
		cin>>s;
		if(s[0]=='R')
		{
			string row="";
			string col="";
			for(j=1;j<sz(s);j++)
			{
				if(s[j]=='C')
					break;
				row+=s[j];
			}
			for(j=j+1;j<sz(s);j++)
				col+=s[j];
			ll c=stoi(col);
			col="";
			while(c!=0)
			{
				col+=(char)('A'+(c%26)-1);
				c/=26;
			}
			reverse(col.begin(),col.end());
			cout<<col<<row<<"\n";
		}
		else
		{
			ll c=0;
			string col="";
			for(j=0;j<sz(s);j++)
			{
				if(s[j]<='9' && s[j]>='0')
					break;
				col+=s[j];
			}
			string row="";
			for(j=j;j<sz(s);j++)
				row+=s[j];
			ll base=1;
			for(j=sz(col)-1;j>=0;j--)
			{
				c+=base*(ll)(col[j]-'A'+1);
				base*=26;
			}
			cout<<"R"<<row<<"C"<<c<<"\n";
		}
	}
	return 0;
}