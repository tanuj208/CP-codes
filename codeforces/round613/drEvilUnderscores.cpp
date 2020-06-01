#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()
#define all(a) a.begin(), a.end()
#define ff first
#define ss second
#define endl "\n"

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
//K-th smallest
//cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;

// priority_queue <ll,vector<ll>,greater<ll> > p;

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

typedef struct s{
	struct s* left;
	struct s* right;
}node;

node *create()
{
	node* tmp= new node();
	tmp->left=NULL;
	tmp->right=NULL;
	return tmp;
}

node* insert(node* root, ll val)
{
	vector<ll> tmp;
	while(val!=0)
	{
		tmp.pb(val%2);
		val/=2;
	}
	while(sz(tmp)!=35)
		tmp.pb(0);
	reverse(all(tmp));
	ll i;
	node *trav=root;
	for(i=0;i<sz(tmp);i++)
	{
		// cout<<tmp[i]<<" ";
		if(tmp[i]==0)
		{
			if(root->left==NULL)
				root->left=create();
			root=root->left;
		}
		else
		{
			if(root->right==NULL)
				root->right=create();
			root=root->right;
		}
	}
	// cout<<endl;
	return trav;
}

ll get_ans(node* root, ll cur)
{
	if(cur==0)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return 0;
	if(root->left==NULL)
		return get_ans(root->right, cur/2);
	if(root->right==NULL)
		return get_ans(root->left, cur/2);
	ll x1=get_ans(root->left, cur/2);
	ll x2=get_ans(root->right, cur/2);
	// cout<<cur<<" "<<x1<<" "<<x2<<endl;
	return cur+min(x1, x2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i;
	node* root=create();
	for(i=0;i<n;i++)
	{
		ll val;
		cin>>val;
		root=insert(root, val);
	}
	ll cur=(ll)1<<34;
	cout<<get_ans(root, cur)<<endl;
	return 0;
}