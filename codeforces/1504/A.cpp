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
    int i,j,pos;
    string s;
    cin>>s;
    int n;
    bool flag=true;
    n=s.size();
    fo(i,n){
        if(s[i]!='a'){
            flag=false;
            break;
        }
    }
    if(flag){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    i=0;j=n-1;
    while(true){
        if(s[i]==s[j] && s[i]=='a'){
            i++;j--;
            continue;
        }
        else if(s[j]!='a'){
            pos=i;
            break;
        }
        else if(s[i]!='a'){
            pos=j+1;
            break;
        }
    }
    fo(i,n){
        if(i==pos){
            cout<<"a";
        }
        cout<<s[i];
        if(i==n-1 && pos==n){
            cout<<"a";
        }
    }
    cout<<nl;

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

