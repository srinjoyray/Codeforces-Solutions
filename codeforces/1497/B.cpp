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
    int i,j;
    int n,m;
    cin>>n>>m;
    lli a[n],count=0,rem[m]={0},temp;
    bool flag=false;
    fo(i,n){
        cin>>a[i];
        a[i]%=m;
        if(a[i]==0){
            flag=true;
        }
        else{
            rem[a[i]]++;
        }
    }
    fo(i,m){
        // deb2(i,rem[i]);
    }
    
    if(flag){
        count++;
    }
    // deb(count);
    i=1; j=m-1;
    while(i<=j){
        if(i==j){
            if(rem[i]>0){
                count++;
            }
            
            break;
        }
        temp=min(rem[i],rem[j]);

        if(temp>0){
            count++;
        }
        // deb2(rem[i],rem[j]);
        rem[i]-=temp;
        rem[j]-=temp;
        if(rem[i]>rem[j] && temp>0){
            rem[i]--;
        }
        else if(rem[j]>rem[i] && temp>0){
            rem[j]--;
        }
        count+=rem[i];
        count+=rem[j];
        // deb2(i,j);
        // deb(count);
        i++;
        j--;
    }
    cout<<count<<endl;
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

