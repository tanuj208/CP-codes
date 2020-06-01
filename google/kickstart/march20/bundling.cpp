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

typedef struct s{
	int len = 0;
	struct s* ptr[26];
}node;

node* new_node(ll x)
{
	node* nnode = new node();
	nnode->len = x;
	ll i;
	for(i=0;i<26;i++)
		nnode->ptr[i] = NULL;
	return nnode;
}

node* add_str(node* root, string s)
{
	ll i;
	node* tmp = root;
	for(i=0;i<sz(s);i++)
	{
		tmp->len++;
		ll x = s[i] - 'A';
		if(tmp->ptr[x] == NULL)
			tmp->ptr[x] = new_node(0);
		tmp = tmp->ptr[x];
	}
	tmp->len++;
	return root;
}

void print(node* root)
{
	node* tmp = root;
	ll i;
	for(i=0;i<26;i++)
	{
		if(tmp->ptr[i]!=NULL)
		{
			cout<<(char)('A'+i)<<endl;
			print(root->ptr[i]);
		}
	}
}

pii get_score(node* root, ll k, ll depth) // score and strings used
{
	if(root->len < k)
		return mp(0, 0);
	ll i;
	ll score = 0;
	ll strs_used = 0;
	for(i=0;i<26;i++)
	{
		if(root->ptr[i]==NULL)
			continue;
		pii tmp = get_score(root->ptr[i], k, depth+1);
		score += tmp.ff;
		strs_used += tmp.ss;
	}
	root->len -= strs_used;
	ll tmp = root->len / k;
	score += depth * tmp;
	strs_used += k * tmp;
	root->len -= k * tmp;
	return mp(score, strs_used);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	for(ll z=1;z<=t;z++)
	{
		cout<<"Case #"<<z<<": ";
		ll n,k;
		cin>>n>>k;
		node* root = new_node(0);
		ll i;
		for(i=0;i<n;i++)
		{
			string s;
			cin>>s;
			root = add_str(root, s);
		}
		pii tmp = get_score(root, k, 0);
		cout<<tmp.ff<<endl;
	}
	return 0;
}