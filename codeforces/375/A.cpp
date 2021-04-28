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
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define tr(it,a) for(auto it=a.begin(); it!=a.end();it++)
#define nl '\n'
#define PI 3.1415926535897932384626
#define mod 1000000007
typedef pair<int, int>	pii;
typedef pair<lli, lli>	pl;
typedef vector<int>		vi;
typedef vector<lli>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
void solve(){
    int i,j;
    string s,zero,non,req,ans;
    lli rem=0,dig,temp;
    bool flag[4];
    fo(i,4){
        flag[i]=false;
    }
    cin>>s;
    fo(i,s.size()){
        if(!flag[0] && s[i]=='1'){
            req.pb(s[i]);
            flag[0]=true;
        }
        else if(!flag[1] && s[i]=='6'){
            req.pb(s[i]);
            flag[1]=true;
        }
        else if(!flag[2] && s[i]=='8'){
            req.pb(s[i]);
            flag[2]=true;
        }
        else if(!flag[3] && s[i]=='9'){
            req.pb(s[i]);
            flag[3]=true;
        }
        else if(s[i]=='0'){
            zero.pb(s[i]);
        }
        else{
            non.pb(s[i]);
        }
    }
    ans=non;
    sort(all(req));
    fo(i,ans.size()){
        dig=ans[i]-'0';
        rem=(rem*10+dig)%7;
    }
    do{
        temp=rem;
        fo(i,req.size()){
            dig=req[i]-'0';
            temp=(temp*10 + dig)%7;
        }
        if(temp==0){
            break;
        }
    }while(next_permutation(all(req)));
    ans+=req+zero;
    cout<<ans<<nl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

