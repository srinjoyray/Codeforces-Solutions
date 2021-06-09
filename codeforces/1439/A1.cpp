#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define ll long long int
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
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
void solve(){
    int i,j;
    int n,m;
    cin>>n>>m;
    string s[n];
    fo(i,n){
        cin>>s[i];
    }
    int a[n][m];
    fo(i,n){
        fo(j,m){
            a[i][j]=s[i][j]-'0';
        }
    }
    vpii v;
    fo(i,n-2){
        fo(j,m){
            if(a[i][j]==1){
                if(j==m-1){
                    v.pb({i,j});
                    v.pb({i+1,j});
                    v.pb({i+1,j-1});
                    a[i][j]^=1;
                    a[i+1][j]^=1;
                    a[i+1][j-1]^=1;
                }
                else{
                    v.pb({i,j});
                    v.pb({i+1,j});
                    v.pb({i+1,j+1});
                    a[i][j]^=1;
                    a[i+1][j]^=1;
                    a[i+1][j+1]^=1;
                }
            }
        }
    }
    fo(j,m-2){
        if(a[n-2][j]==1){
            v.pb({n-2,j});
            v.pb({n-2,j+1});
            a[n-2][j]^=1;
            a[n-2][j+1]^=1;
            if(a[n-1][j]==1){
                v.pb({n-1,j});
                a[n-1][j]^=1;
            }
            else{
                v.pb({n-1,j+1});
                a[n-1][j+1]^=1;
            }
        }
        if(a[n-1][j]==1){
            v.pb({n-1,j});
            v.pb({n-1,j+1});
            v.pb({n-2,j+1});
            a[n-1][j]^=1;
            a[n-1][j+1]^=1;
            a[n-2][j+1]^=1;
        }
    }

    int count=1;
    vpii one,zero;
    for(i=n-2;i<n;i++){
        for(j=m-2;j<m;j++){
            if(a[i][j]==1){
                one.pb({i,j});
            }
            else{
                zero.pb({i,j});
            }
        }
    }
    if(one.size()==4){
        vpii curr;
        fo(i,one.size()){
            curr.pb(one[i]);
        }
        fo(i,zero.size()){
            curr.pb(zero[i]);
        }
        v.pb(curr[1]); v.pb(curr[2]); v.pb(curr[3]);
        v.pb(curr[0]); v.pb(curr[1]); v.pb(curr[2]);
        v.pb(curr[0]); v.pb(curr[2]); v.pb(curr[3]);
        v.pb(curr[0]); v.pb(curr[1]); v.pb(curr[3]);
        // 1111 1000
    }
    else if(one.size()==3){
        fo(i,one.size()){
            v.pb(one[i]);
            a[one[i].F][one[i].S]^=1;
        }
    }
    else if(one.size()==2){
        fo(i,zero.size()){
            v.pb(zero[i]);
            a[zero[i].F][zero[i].S]^=1;
        }
        v.pb(one[0]);
        a[one[0].F][one[0].S]^=1;
        fo(i,zero.size()){
            v.pb(zero[i]);
            a[zero[i].F][zero[i].S]^=1;
        }
        v.pb(one[1]);
        a[one[1].F][one[1].S]^=1;
    }
    else if(one.size()==1){
        vpii curr;
        fo(i,one.size()){
            curr.pb(one[i]);
        }
        fo(i,zero.size()){
            curr.pb(zero[i]);
        }

        v.pb(curr[0]); v.pb(curr[1]); v.pb(curr[2]);
        v.pb(curr[0]); v.pb(curr[2]); v.pb(curr[3]);
        v.pb(curr[0]); v.pb(curr[1]); v.pb(curr[3]);
        // 1000 0110    1101    
    }


    /*fo(i,n){
        fo(j,m){
            cout<<a[i][j];
        }cout<<nl;
    }*/
    cout<<v.size()/3<<nl;
    fo(i,v.size()){
        cout<<v[i].F+1<<" "<<v[i].S+1<<" ";
        if(i%3==2){
            cout<<nl;
        }
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}

