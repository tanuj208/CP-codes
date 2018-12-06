#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> p;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef struct xx{
	ll val;
	ll op;
	struct xx *right,*left;
}node;

node* nnode()
{
	node* temp=(node*)malloc(sizeof(node));
	temp->val=-1;
	temp->op=-1;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

ll dfs(node* root, ll depth)
{
	if(depth==0)
	{
		ll x;
		cin>>x;
		root->val=x;
		return x;
	}
	root->left=nnode();
	root->left->op=root->op^1;
	root->right=nnode();
	root->right->op=root->op^1;
	ll a=dfs(root->left,depth-1);
	ll b=dfs(root->right,depth-1);
	if(root->op==1)
		root->val=a|b;
	else
		root->val=a^b;
	return root->val;
}

ll hi;

ll update(node* root, ll x, ll y, ll temp)
{
	if(temp==0)
	{
		root->val=y;
		return y;
	}
	if(x>temp)
	{
		ll a=update(root->right,x-temp,y,temp/2);
		if(root->op==1)
			root->val=(root->left->val)|a;
		else
			root->val=(root->left->val)^a;
		return root->val;
	}
	else
	{
		ll a=update(root->left,x,y,temp/2);
		if(root->op==1)
			root->val=(root->right->val)|a;
		else
			root->val=(root->right->val)^a;
		return root->val;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	hi=1<<n;
	node* root=nnode();
	if(n%2==1)
		root->op=1;
	else
		root->op=0;
	ll temp=dfs(root,n);
	while(m--)
	{
		ll x,y;
		cin>>x>>y;
		cout<<update(root,x,y,hi/2)<<endl;
	}
	//op==1 means or else xor
	return 0;
}