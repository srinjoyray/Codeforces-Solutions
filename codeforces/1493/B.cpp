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
bool invalid(int n){
    if(n==3 || n==4 || n==7 || n==6 || n==9){
        return true;
    }
    return false;
}
int change(int n){
    if(n==2){
        n=5;
    }
    else if(n==5){
        n=2;
    }
    return n;
}
bool check(int x,int y,int h,int m){
    int a,b,c,d;
    // deb2(x,y);
    a=x/10; b=x%10; c=y/10; d=y%10;
    if(invalid(a) || invalid(b) || invalid(c) || invalid(d)){
        return false;
    }
    a=change(a);
    b=change(b);
    c=change(c);
    d=change(d);
    // deb2(a,b);
    // deb2(c,d);
    x=(d*10)+c;
    y=(b*10)+a;
    if(x<h && y<m){
        return true;
    }
    return false;
}
void solve(){
    int i,j;
    int h,m,a,b;
    bool flag=false;
    string s;
    cin>>h>>m;
    cin>>s;
    a=(s[0]-'0')*10 + (s[1]-'0');
    b=(s[3]-'0')*10 + (s[4]-'0');
    // deb2(a,b);
    for(;a<=h;a++){
        if(a==h){
            a=0;
        }
        for(;b<=m;b++){
            if(b==m){
                b=0;
                break;
            }
            if(check(a,b,h,m)){
                flag=true;
            }
            if(flag){
                break;
            }
        }
        if(flag){
            break;
        }
    }
    if(a<10){
        cout<<0;
    }
    cout<<a<<":";
    if(b<10){
        cout<<0;
    }
    cout<<b<<nl;
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

