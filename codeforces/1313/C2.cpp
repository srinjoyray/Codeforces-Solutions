#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define ll long long int
#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define tr(it,a) for(auto it=a.begin(); it!=a.end();it++)
#define nl '\n'
#define PI 3.1415926535897932384626
#define mod 1000000007
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
void solve(){
    int i,j;
    int n;
    cin>>n;
    ll a[n];
    fo(i,n){
        cin>>a[i];
    }
    ll pref[n+1]={0},suff[n+1]={0};
    set<ll,greater<int>> se;
    map<ll,ll> mapp;
    ll pos;
    fo(i,n){
        while(se.size() && *se.begin()>a[i]){
            se.erase(se.begin());
        }
        if(se.size()==0){
            pos=0;
        }
        else{
            pos=mapp[*se.begin()];
        }
        pref[i+1]=pref[pos]+(i-pos+1)*a[i];
        se.insert(a[i]);
        mapp[a[i]]=i+1;
    }

    // fo(i,n+1){
    //     cout<<pref[i]<<" ";
    // }cout<<nl;

    se.clear();
    mapp.clear();

    for(i=n-1;i>=0;i--){
        while(se.size() && *se.begin()>a[i]){
            se.erase(se.begin());
        }
        if(se.size()==0){
            pos=n;
        }
        else{
            pos=mapp[*se.begin()];
        }
        // deb2(i,pos);
        suff[i]=suff[pos]+(pos-i)*a[i];
        se.insert(a[i]);
        mapp[a[i]]=i;
        /*for(auto itr=se.begin();itr!=se.end();itr++){
            cout<<(*itr)<<" "<<mapp[*itr]<<nl;
        }*/
    }

    // fo(i,n+1){
    //     cout<<suff[i]<<" ";
    // }cout<<nl;

    ll node=-1,mx=0,temp;

    fo2(i,1,n){
        ll prev,next;
        if(i>1 && a[i-1]<a[i-2]){
            continue;
        }
        if(i<n && a[i-1]<a[i]){
            continue;
        }

        prev=pref[i-1];
        next=suff[i];
        
        temp=prev+next+a[i-1];

        if(temp>mx){
            mx=temp;
            node=i-1;
        }
    }

    // deb(node);
    ll ans[n],curr;
    ans[node]=a[node];
    curr=a[node];
    for(i=node+1;i<n;i++){
        curr=min(curr,a[i]);
        ans[i]=curr;
    }
    curr=a[node];
    for(i=node-1;i>=0;i--){
        curr=min(curr,a[i]);
        ans[i]=curr;
    }

    fo(i,n){
        cout<<ans[i]<<" ";
    }cout<<nl;
}   

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}

