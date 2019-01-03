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
	struct xx *ptr[60];
	struct xx *suffixLink;
	// suffixLink stores last node of prefix where prefix===>largest prefix = largest suffix of given node (current one)
	struct xx *p;
	// p is parent
	char c;
	// c is character by which parent is connected to this node
	ll end;
}node;

node *nnode(node *p, char c)
{
	ll i;
	node * tmp=(node*)malloc(sizeof(node));
	for(i=0;i<60;i++)
		tmp->ptr[i]=NULL;
	tmp->suffixLink=NULL;
	tmp->end=-1;
	tmp->p=p;
	tmp->c=c;
	return tmp;
}

ll val(char c)
{
	return (ll)c-(ll)'A';
}

node *insert(node *head, string s, ll id)
{
	ll i;
	node *tmp=head;
	for(i=0;i<sz(s);i++)
	{
		ll x=val(s[i]);
		if(tmp->ptr[x]==NULL)
			tmp->ptr[x]=nnode(tmp,s[i]);
		tmp=tmp->ptr[x];
	}
	tmp->end=id;
	return head;
}

node* suffix(node *head)
{
	head->suffixLink=head;
	ll i,j;
	for(i=0;i<60;i++)
		if(head->ptr[i]!=NULL)
			head->ptr[i]->suffixLink=head;
	// setting suffixLink for root and its immediate childs to root

	queue<node*> q;
	for(i=0;i<60;i++)
		if(head->ptr[i]!=NULL)
			for(j=0;j<60;j++)
				if(head->ptr[i]->ptr[j]!=NULL)
					q.push(head->ptr[i]->ptr[j]);

	// bfs
	while(!q.empty())
	{
		node *tmp=q.front();
		q.pop();
		for(i=0;i<60;i++)
			if(tmp->ptr[i]!=NULL)
				q.push(tmp->ptr[i]);
		node *pp=tmp->p;
		char c = tmp->c;
		// algo similar to kmp preprocessing algo
		while(true)
		{
			if(pp->suffixLink->ptr[val(c)]!=NULL)
			{
				tmp->suffixLink=pp->suffixLink->ptr[val(c)];
				break;
			}
			pp=pp->suffixLink;
			if(pp==head)
			{
				tmp->suffixLink=pp;
				break;
			}
		}
	}
	return head;
}

vector<bool> ans(1005,false);

void searchString(string s, node* head)
{
	ll i;
	for(i=0;i<sz(s);i++)
	{
		// somewhat similar to kmp searching
		ll x=val(s[i]);
		if(head->end!=-1)
			ans[head->end]=true;

		while(head->ptr[x]==NULL && head->p!=NULL)
			head=head->suffixLink;

		if(head->ptr[x]!=NULL)
		{
			head=head->ptr[x];
			node *tmp=head;
			while(head->c!='0')
			{
				if(head->end!=-1)
					ans[head->end]=true;
				head=head->suffixLink;
			}
			head=tmp;
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll k;
	cin>>k;
	while(k--)
	{
		string s;
		node *root=nnode(NULL,'0');
		cin>>s;
		ll q,i;
		for(i=0;i<=1000;i++)
			ans[i]=false;
		cin>>q;
		map<string,ll> x;
		vector<string> tmp;
		for(i=0;i<q;i++)
		{
			string t;
			cin>>t;
			tmp.pb(t);
			x[t]=i;
			root=insert(root,t,i);
		}
		root=suffix(root);
		searchString(s,root);
		for(i=0;i<q;i++)
		{
			if(ans[i] || ans[x[tmp[i]]])
				cout<<"y\n";
			else
				cout<<"n\n";
		}
	}
	return 0;
}