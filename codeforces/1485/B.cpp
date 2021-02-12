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
#define tr(it,a) for(auto it=a.begin(); it!=a.end();it++)
#define PI 3.141592653589793238
#define mod 1e9+7

void solve(){
    int i,j;
    int n,q;
    lli k;
    cin>>n>>q>>k;
    // deb(n);
    lli a[n],before[n],after[n],prefix[n+1]={0},last,next;
    fo(i,n){
        cin>>a[i];
        // deb(a[i]);
    }
    fo(i,n){
        if(i==0){
            last=0;
        }
        else{
            last=a[i-1];
        }
        if(i==n-1){
            next=k;
        }
        else{
            next=a[i+1];
        }
        before[i]=a[i]-last-1;;
        after[i]=next-a[i]-1;
        if(after[i]==-1){
            after[i]=0;
        }
        prefix[i+1]=prefix[i]+before[i]+after[i];
    }
    fo(i,n){
        // deb2(i,before[i]);    
    }
    fo2(i,1,n){
        // deb2(i,prefix[i]);
    }
    while(q--){
        int l,r;
        lli ans,mid,sub;
        cin>>l>>r;
        sub=before[l-1]+after[r-1];
        mid=prefix[r]-prefix[l-1];
        last=a[l-1]-1;
        next=k-a[r-1];
        ans=last+next;
        // deb(ans);
        ans+=mid-sub;
        cout<<ans<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

