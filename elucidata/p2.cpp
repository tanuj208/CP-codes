#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, pair<int, int> > > cost;
vector<int> p(105,-1);
vector<int> c(105,1);

int parent(int v)
{
	if(p[v]==-1)
		return v;
	p[v]=parent(p[v]);
	return p[v];
}

void reset()
{
	int i;
	cost.clear();
	for(i=0;i<=100;i++)
	{
		p[i]=-1,c[i]=1;
	}
	return;
}

// using dsu to detect cycle in graph
bool cycle(int v1,int v2)
{
	if(parent(v1)==parent(v2))
		return true;
	else
	{
		int x1=parent(v1);
		int x2=parent(v2);
		if(c[x1]<=c[x2])
		{
			p[x1]=x2;
			c[x2]+=c[x1];
		}
		else
		{
			p[x2]=x1;
			c[x1]+=c[x2];
		}
		return false;
	}
}

// code starts here
int main()
{
	int t;
	cin>>t;
	// using the prim's algo to find minimum spanning tree
	while(t--)
	{
		int n;
		cin>>n;
		int i,j;
		reset();
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				int val;
				cin>>val;
				cost.push_back(make_pair(val, make_pair(i+1, j+1)));
			}
		}
		// edges are sorted according to their cost
		sort(cost.begin(), cost.end());
		long long ans=0;
		i=0;
		int cnt=0;
		while(true)
		{
			// taking edges as long as they do not from cycle
			if(!cycle(cost[i].second.first, cost[i].second.second))
			{
				ans+=cost[i].first;
				cnt++;
			}
			// if n-1 edges are taken then no more edges are needed (tree is formed)
			if(cnt==n-1)
				break;
			i++;
		}
		cout<<ans<<endl;
	}
	return 0;
}