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
const int N=1e6+10;

void solve(){
    int i,j;
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    int a[n+1],pref[n+1]={0};
    fo(i,n){
        if(i%2==0){
            if(s[i]=='+'){
                a[i+1]=1;
            }
            else{
                a[i+1]=-1;
            }
        }
        else{
            if(s[i]=='-'){
                a[i+1]=1;
            }
            else{
                a[i+1]=-1;
            }
        }
    }
    fo2(i,1,n){
        pref[i]=pref[i-1]+a[i];
    }
    map<int,set<int>>mapp;
    fo2(i,1,n){
        mapp[pref[i]+pref[i-1]].insert(i);
    }
    // fo2(i,1,n){
    //     cout<<a[i];
    // }cout<<nl;
    while(q--){
        int l,r,c,pos;
        cin>>l>>r;
        if(pref[r]==pref[l-1]){
            cout<<"0\n";
            continue;
        }
        if((r-l+1)%2==0){
            cout<<"2\n";
            cout<<l<<" ";
            l++;
        }
        else{
            cout<<"1\n";
        }
        // [l,x-1][x+1,r]
        // (P[x-1]-P[l-1])-(p[r]-p[x])=0
        // p[x-1]-p[l-1]-p[r]+p[x]=0
        // p[x-1]+p[x]=p[r]+p[l-1]
        // deb2(l,r);
        c=pref[r]+pref[l-1];
        pos=*(mapp[c].lower_bound(l));
        // deb2(c,pos);
        cout<<pos<<nl;
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

