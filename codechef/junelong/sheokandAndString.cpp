#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;
typedef struct nn{
	struct nn *a[26];
	ll end;
	ll leastIndex;
}node;

node *nnode()
{
	node *temp=(node*)malloc(sizeof(node));
	ll i;
	for(i=0;i<26;i++)
		temp->a[i]=NULL;
	temp->end=100005;
	temp->leastIndex=100005;
	return temp;
}

node* insert(node* head,string s,ll index)
{
	node *temp=head;
	ll i;
	for(i=0;i<sz(s);i++)
	{
		ll x=(ll)s[i]-(ll)'a';
		if(temp->a[x]==NULL)
		{
			temp->a[x]=nnode();
			temp->a[x]->leastIndex=index;
		}
		temp=temp->a[x];
	}
	temp->end=min(index,temp->end);
	return head;
}

const ll lt=100005;
ll mod=1000000007;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i;
	node *head=nnode();
	head->leastIndex=1;
	for(i=0;i<n;i++)
	{
		string s;
		cin>>s;
		head=insert(head,s,i+1);
	}
	ll q;
	cin>>q;
	while(q--)
	{
		ll r;
		string p;
		cin>>r>>p;
		node *temp=head;
		for(i=0;i<sz(p);i++)
		{
			ll x=(ll)p[i]-(ll)'a';
			if(temp->a[x]!=NULL && temp->a[x]->leastIndex<=r)
			{
				cout<<p[i];
				temp=temp->a[x];
			}
			else
				break;
		}
		while(temp->end>r)
		{
			for(ll j=0;j<26;j++)
			{
				if(temp->a[j]!=NULL && temp->a[j]->leastIndex<=r)
				{
					cout<<(char)((ll)'a'+j);
					temp=temp->a[j];
					break;
				}
			}
		}
		cout<<"\n";
	}
	return 0;
}