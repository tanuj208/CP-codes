#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
#define l(var,start,end) for(ll var=start;var<end;++var)
#define sz(a) (int)(a).size()

typedef struct node{
	struct node* ptr[26];
	bool end;
}node;

ll val(char a)
{
	return (ll)a-(ll)'a';
}

node* nnode()
{
	node* temp=(node*)malloc(sizeof(node));
	ll i;
	l(i,0,26)
	{
		temp->ptr[i]=NULL;
	}
	temp->end=0;
	return temp;
}

node* insert(node* root,string s)
{
	ll i;
	// cout<<s<<endl;
	if(root==NULL)
		root=nnode();
	node* temp=root;
	l(i,0,sz(s))
	{
		if(temp->ptr[val(s[i])]==NULL)
			temp->ptr[val(s[i])]=nnode();
		temp=temp->ptr[val(s[i])];
	}
	temp->end=1;
	return root;
}

bool query(node* root,string s)
{
	if(root==NULL)
		return 0;
	node* temp=root;
	l(i,0,sz(s))
	{
		if(temp->ptr[val(s[i])]==NULL)
			return 0;
		temp=temp->ptr[val(s[i])];
	} 
	return temp->end;
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	ll n,q;
	cin>>n>>q;
	string s;
	node* root=NULL;
	while(n--)
	{
		cin>>s;
		root=insert(root,s);
		// if(root==NULL)
			// cout<<"1"<<endl;
	}
	while(q--)
	{
		cin>>s;
		cout<<query(root,s)<<endl;	
	}
	return 0;
}