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
#define mod 1e9+7

void solve(){
    int i,j;
    string s;
    cin>>s;
    int a=0,b=0,c=0,n,temp;
    char ch;
    n=s.size();
    fo(i,n){
        if(s[i]=='A'){
            a++;
        }
        else if(s[i]=='B'){
            b++;
        }
        else if(s[i]=='C'){
            c++;
        }
    }
    ch=s[0];
    // deb(ch);
    if(a==b+c){
        temp=0;
        fo(i,n){
            if(s[i]=='A'){
                temp++;
            }
            else{
                temp--;
            }
            if(temp<0 && ch=='A'){
               break;
            }
            if(temp>0 && ch!='A'){
                break;
            }
        }
        if(temp==0){
            cout<<"YES\n";
            return;
        }
    }
    if(b==a+c){
        temp=0;
        fo(i,n){
            if(s[i]=='B'){
                temp++;
            }
            else{
                temp--;
            }
            if(temp<0 && ch=='B'){
                break;
            }
            if(temp>0 && ch!='B'){
                break;
            }
        }
        if(temp==0){
            cout<<"YES\n";
            return;
        }
    }
    if(c==a+b){
        temp=0;
        fo(i,n){
            if(s[i]=='C'){
                temp++;
            }
            else{
                temp--;
            }
            if(temp<0 && ch=='C'){
                break;
            }
            if(temp>0 && ch!='C'){
                break;
            }
        }
        if(temp==0){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
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

