#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;
typedef struct x{
	struct x *ptr[26];
}node;

const ll lt=100005;
ll mod=1000000007;
ll k;
string num,s;

node* nnode()
{
	node* tmp=(node*)malloc(sizeof(node));
	ll i;
	for(i=0;i<26;i++)
		tmp->ptr[i]=NULL;
	return tmp;
}

ll val(char c)
{
	return (ll)c-(ll)'a';
}

node* insert(node* root)
{
	ll i;
	for(i=0;i<sz(s);i++)
	{
		node* tmp=root;
		ll j;
		for(j=i;j<sz(s);j++)
		{
			ll x=val(s[j]);
			if(tmp->ptr[x]==NULL)
				tmp->ptr[x]=nnode();
			tmp=tmp->ptr[x];
		}
	}
	return root;
}

ll calc(node* root,ll b)
{
	ll i;
	ll anss=0;
	for(i=0;i<26;i++)
	{
		if(root->ptr[i]!=NULL)
		{
			if(num[i]=='0')
				b++;
			if(b<=k)
			{
				anss++;
				anss+=calc(root->ptr[i],b);
			}
			if(num[i]=='0')
				b--;
		}
	}
	return anss;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>s>>num;
	cin>>k;
	node* root=nnode();
	root=insert(root);
	ll ans=calc(root,0);
	cout<<ans<<endl;
	return 0;
}