#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
//K-th smallest
//cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;


typedef long long ll;
typedef pair<ll,ll> pii;

ll mod=1000000007;

ll power(ll x, ll y) 
{
	ll temp;
	if( y == 0)
		return 1;
	temp = power(x, y/2);
	if (y%2 == 0)
		return (temp*temp)%mod;
	else
		return (((x*temp)%mod)*temp)%mod; 
}

typedef struct xx{
	struct xx *ptr[2];
	ll end;
	ll cnt;
	struct xx *p;
	char c;
	struct xx *sfxLnk;
}node;

node *nnode(char c, node *p)
{
	node *tmp=(node*)malloc(sizeof(node));
	tmp->end=-1;
	tmp->cnt=0;
	tmp->c=c;
	tmp->p=p;
	tmp->sfxLnk=NULL;
	ll i;
	for(i=0;i<2;i++)
		tmp->ptr[i]=NULL;
	return tmp;
}

ll val(char c)
{
	if(c=='.')
		return 0;
	else
		return 1;
}

node *insert(node *root, string s)
{
	ll i;
	node *tmp=root;
	for(i=0;i<sz(s);i++)
	{
		ll x=val(s[i]);
		if(root->ptr[x]==NULL)
			root->ptr[x]=nnode(s[i], root);
		root=root->ptr[x];
	}
	root->cnt++;
	root->end=sz(s);
	// cout<<sz(s)<<endl;
	root=tmp;
	return root;
}

node *suffix(node *root)
{
	ll i,j;
	root->sfxLnk=root;
	for(i=0;i<2;i++)
		if(root->ptr[i]!=NULL)
			root->ptr[i]->sfxLnk=root;
	queue<node *> q;

	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			if(root->ptr[i]!=NULL && root->ptr[i]->ptr[j]!=NULL)
				q.push(root->ptr[i]->ptr[j]);

	while(!q.empty())
	{
		node *temp=q.front();
		q.pop();
		for(i=0;i<2;i++)
			if(temp->ptr[i]!=NULL)
				q.push(temp->ptr[i]);
		node *par=temp->p;
		char c=temp->c;
		while(true)
		{
			ll x=val(c);
			if(par->sfxLnk->ptr[x]!=NULL)
			{
				temp->sfxLnk=par->sfxLnk->ptr[x];
				break;
			}
			par=par->sfxLnk;
			if(par==root)
			{
				temp->sfxLnk=root;
				break;
			}
		}
	}
	return root;
}

void searchString(string s, node *root, vector<ll> ans)
{
	ll i;
	node *head=root;
	for(i=0;i<sz(s);i++)
	{
		ll x=val(s[i]);

		while(root->ptr[x]==NULL && root->p!=NULL)
			root=root->sfxLnk;
		if(root->ptr[x]==NULL)
			break;
		root=root->ptr[x];
		ans[i]=root->cnt;

		node *temp=root;
		while(temp->sfxLnk!=head)
		{
			temp=temp->sfxLnk;
			if(i==12)
				cout<<temp->end<<endl;
			if(temp->end!=-1)
				ans[i]+=ans[i-temp->end];
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll d;
	cin>>d;
	map<char,string> dict;
	dict['A']=".-";
	dict['B']="-...";
	dict['C']="-.-.";
	dict['D']="-..";
	dict['E']=".";
	dict['F']="..-.";
	dict['G']="--.";
	dict['H']="....";
	dict['I']="..";
	dict['J']=".---";
	dict['K']="-.-";
	dict['L']=".-..";
	dict['M']="--";
	dict['N']="-.";
	dict['O']="---";
	dict['P']=".--.";
	dict['Q']="--.-";
	dict['R']=".-.";
	dict['S']="...";
	dict['T']="-";
	dict['U']="..-";
	dict['V']="...-";
	dict['W']=".--";
	dict['X']="-..-";
	dict['Y']="-.--";
	dict['Z']="--..";
	while(d--)
	{
		node *root = nnode('0', NULL);
		string s;
		ll n,i;
		cin>>s>>n;
		vector<ll> ans(10005,0);
		vector<string> t;
		for(i=0;i<n;i++)
		{
			string x;
			cin>>x;
			string tmp="";
			for(ll j=0;j<sz(x);j++)
				tmp+=dict[x[j]];
			t.pb(tmp);
			root=insert(root, tmp);
		}
		root=suffix(root);
		searchString(s, root, ans);
		cout<<ans[n-1]<<"\n";
	}
	return 0;
}