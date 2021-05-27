#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define lli long long int
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
typedef pair<lli, lli>	pl;
typedef vector<int>		vi;
typedef vector<lli>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
void solve(){
    int i,j;
    int n;
    cin>>n;
    ll h,w,pos,start,mn,val,temp_mn,temp_val;
    map<pl,vl> mapp;
    map<pl,ll> store;
    ll ans[n]={0};
    vpl v;
    fo(i,n){
        cin>>h>>w;
        mapp[{min(h,w),max(h,w)}].pb(i);
        store[{min(h,w),max(h,w)}]=i;
        v.pb({min(h,w),max(h,w)});
    }
    sort(all(v));
    fo(i,v.size()){
        // deb2(v[i].F,v[i].S);
    }
    mn=INT64_MAX;
    j=0;
    fo(i,n){
        // deb(i);
        if(i>0 && v[i].F>v[i-1].F){
            while(j<i){
                if(v[j].S<mn){
                    mn=v[j].S;
                    pos=store[v[j]];
                    val=pos;
                }
                j++;
            }
        }
        // deb2(i,j);
        pos=mapp[v[i]][0];
        // deb(pos);
        mapp[v[i]].erase(mapp[v[i]].begin());
        
        if(mn>=v[i].S){    
            ans[pos]=-1;
        }
        else{
            ans[pos]=val+1;
        }
    }
    /*fo(i,n){
        j=i;
        while(j<n && v[i].F==v[j].F){
            if(v[j].S<mn){
                mn=v[j].S;
                val=mapp[v[j]][0];
            }
            j++;
        }
        i=j;
        break;
    }
      
    while(i<n){
        
        j=i;
        temp_mn=mn;
        temp_val=val;
        // deb2(mn,val);
        while(j<n && v[j].F==v[i].F){
            
            if(v[j].S>temp_mn){
                pos=mapp[v[j]][0];
                
                ans[pos]=temp_val+1;
                // deb2(pos,temp_val);
            }
            if(v[j].S<temp_mn){
                mn=v[j].S;
                pos=mapp[v[j]][0];
                val=pos;
            }
            j++;
        }
        // deb(j);
        i=j;
    }*/
    fo(i,n){
        if(ans[i]==0){
            ans[i]=-1;
        }
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
    cin>>t;
    while(t--){
        solve();
    }
}

