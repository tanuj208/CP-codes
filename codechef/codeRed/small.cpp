#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
#define lp(var,start,end) for(ll var=start;var<end;++var)
#define sz(a) (int)(a).size()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    ll i,val;
    set <ll> a;
    for(i=0;i<n;i++)
    {
        // cout<<a.size()<<endl;
        cin>>val;
        a.insert(val);
        auto it=a.find(val);
        if(it==a.begin())
        {
            cout<<"-1\n";
            continue;
        }
        it--;
        cout<<*it<<"\n";
    }
    return 0;
}
        