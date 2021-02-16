#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define lli long long int
#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define tr(it,a) for(auto it=a.begin(); it!=a.end();it++)
#define PI 3.141592653589793238
#define mod 1e9+7
bool comp(const pair<int,int> &a,const pair<int,int> &b){
    if(a.F==b.F){
        return a.S<=b.S;
    }
    return a.F<b.F;
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    vector<lli> v;
    vector<pair<lli,lli>> a;
    lli temp,sum=0,flag=0;
    fo(i,n){
        cin>>temp;
        a.pb(mp(temp,i+1));
    }
    sort(a.begin(),a.end(),comp);
    
    for(i=0;i<a.size();i++){
        sum+=a[i].F;
        if(i==a.size()-1){
            v.pb(a[i].S);
            break;
        }
        if(sum>=a[i+1].F){
            v.pb(a[i].S);
        }
        else{
            v.clear();
        }
    }
    sort(v.begin(),v.end());
    cout<<v.size()<<endl;
    fo(i,v.size()){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

