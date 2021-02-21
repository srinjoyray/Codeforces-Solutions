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

void solve(){
    int i,j;
    int h,w;
    cin>>h>>w;
    char s[h][w];
    fo(i,h){
        fo(j,w){
            cin>>s[i][j];
        }
    }
    pair<int,int> p={-1,-1};
    int count=0,l,r,u,d,temp,flag=0;
    fo2(i,1,h-2){
        fo2(j,1,w-2){
            if(s[i][j]=='*' && s[i-1][j]=='*' && s[i+1][j]=='*' && s[i][j-1]=='*' && s[i][j+1]=='*'){
                p.first=i;
                p.second=j;
                count++;
            }
        }
    }
    if(count!=1){
        cout<<"NO\n";
        return;
    }
    temp=p.second+1;
    while(s[p.first][temp]=='*' && temp<w){
        s[p.first][temp]='.';
        temp++;
    }
    r=temp-1;
    temp=p.second-1;
    while(s[p.first][temp]=='*' && temp>=0){
        s[p.first][temp]='.';
        temp--;
    }
    l=temp+1;
    temp=p.first-1;
    while(s[temp][p.second]=='*' && temp>=0){
        s[temp][p.second]='.';
        temp--;
    }
    u=temp+1;
    temp=p.first+1;
    while(s[temp][p.second]=='*' && temp<h){
        s[temp][p.second]='.';
        temp++;
    }
    d=temp-1;
    s[p.first][p.second]='.';
    fo(i,h){
        fo(j,w){
            if(s[i][j]=='*'){
                flag=1;
                break;
            }
        }
    }
    if(flag==1){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
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

