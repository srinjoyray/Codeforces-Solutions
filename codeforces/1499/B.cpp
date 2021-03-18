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
    string s,temp;
    cin>>s;
    int n,last=0;
    bool flag=true;
    n=s.size();
    temp=s;
    fo(i,n){
        if(temp[i]=='1' && last==0){
            temp[i]='0';
            i++;
            if(i<n && temp[i]=='1'){
                last=1;
            }
        }
        else if(temp[i]=='0' && last==1){
            temp[i]='1';
            i++;
        }
    }
    fo2(i,1,n-1){
        if(temp[i]<temp[i-1]){
            flag=false;
            break;
        }
    }
    // deb(temp);
    if(flag){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
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

