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
    int n,moves,petya,vasya,count=0;
    cin>>n;
    string s;
    cin>>s;
    moves=n-11;
    petya=moves/2;
    vasya=(moves+1)/2;
    fo(i,n){
        if(s[i]=='8'){
            count++;
            if(count>petya){
                break;
            }
            s[i]='_';
        }
    }
    if(count<=petya){
        cout<<"NO\n";
        return;
    }
    // cout<<s<<nl;
    fo(i,n){
        if(vasya==0){
            break;
        }
        if(s[i]=='_' || s[i]=='8'){
            continue;
        }
        else{
            s[i]='_';
            vasya--;
        }
    }
    // cout<<s<<nl;    
    fo(i,n){
        if(s[i]=='_'){
            continue;
        }
        else{
            if(s[i]=='8'){
                cout<<"YES\n";
                break;
            }
            else{
                cout<<"NO\n";
                break;
            }
        }
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

