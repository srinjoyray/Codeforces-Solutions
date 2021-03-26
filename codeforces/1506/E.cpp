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
#define nl '\n'
#define PI 3.141592653589793238
#define mod 1000000007

void solve(){
    int i,j,k;
    int n;
    cin>>n;
    lli q[n],a[n]={0},present[n+1]={0};
    vector<lli> left;
    fo(i,n){
        cin>>q[i];
    }
    a[0]=q[0];
    present[q[0]]=1;
    for(i=1;i<n;i++){
        if(q[i]!=q[i-1]){
            a[i]=q[i];
            present[q[i]]=1;
        }
    }
    fo2(i,1,n){
        if(present[i]==0){
            left.pb(i);
        }
    }
    
    if(left.size()==0){
        fo(i,n){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        fo(i,n){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        return;
    }
    /*fo(j,left.size()){
        cout<<left[j]<<" ";
    }
    cout<<endl;*/

    j=0;
    fo(i,n){
        if(a[i]>0){
            cout<<a[i]<<" ";
        }
        else{
            cout<<left[j]<<" ";
            j++;
        }
    }
    cout<<endl;
    j=0;
    
    fo(i,n){
        if(a[i]>0){
            cout<<a[i]<<" ";
            while(j<left.size() && left[j]<a[i] ){
                j++;
            }
            j--;
            if(j<0){
                j=0;
            }
            // deb(j);
        }
        else{
            cout<<left[j]<<" ";
            left.erase(left.begin()+j);
            j--;
            while(j>0 && left[j]>=q[i]){
                j--;
            }
            if(j<0){
                j=0;
            }
            // deb(j);
        }
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

