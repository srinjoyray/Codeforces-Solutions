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
vi find(int a[],int n){
    map<int,int> vis;
    vi v,ans;
    int i,j,rem=n,last;
    fo(i,n){
        vis[a[i]]=1;
        if(a[i]>1 && vis[a[i]-1]==0){
           
            v.pb(i);
            rem-=i;
            if(i>0){
                // ans.pb(i);
            }

            j=i+1;
            while(a[j]==a[j-1]+1){
                j++;
            }
            v.pb(j-i);
            rem-=(j-i); 
            // ans.pb(j-i);

            while(a[j]!=a[i]-1){
                j++;
            }
            last=n-j-1;
            rem-=last;
            v.pb(rem);
            // ans.pb(rem);

            v.pb(last);
            if(last>0){
                // ans.pb(last);
            }

            break;
        }
    }
    // fo(i,n){
    //     cout<<a[i]<<" ";
    // }cout<<nl;
    // deb(v.size());
    // deb2(v[0],v[1]);
    // deb2(v[2],v[3]);
    // fo(i,v.size()){
    //     cout<<v[i]<<"@";    
    // }cout<<nl;
    vi v1,v2,v3,v4;
    i=0;
    fo(i,n){
        if(i<v[0]){
            v1.pb(a[i]);
        }
        else if(i<v[0]+v[1]){
            v2.pb(a[i]);
        }
        else if(i<v[0]+v[1]+v[2]){
            v3.pb(a[i]);
        }
        else{
            v4.pb(a[i]);
        }
        // deb(a[i]);
    }
    fo(i,v.size()){
        if(v[i]>0){
            ans.pb(v[i]);
        }
    }

    v.clear();
    fo(i,v4.size()){
        v.pb(v4[i]);
    }
    fo(i,v3.size()){
        v.pb(v3[i]);
    }
    fo(i,v2.size()){
        v.pb(v2[i]);
    }
    fo(i,v1.size()){
        v.pb(v1[i]);
    }
    // deb(v.size());
    // deb(v[2]);
  
    fo(i,n){
        a[i]=v[i];
    }
    // fo(i,n){
    //     cout<<a[i]<<" ";
    // }cout<<nl;

    // fo(i,ans.size()){
    //     cout<<ans[i]<<"#";
    // }cout<<nl;
    return ans;
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    int a[n];
    fo(i,n){
        cin>>a[i];
    }
    vector<vi> ans;
    while(!is_sorted(a,a+n)){
        vi v;
        v=find(a,n);
        ans.pb(v);
    }
    cout<<ans.size()<<nl;
    fo(i,ans.size()){
        cout<<ans[i].size()<<" ";
        fo(j,ans[i].size()){
            cout<<ans[i][j]<<" ";
        }
        cout<<nl;
    }

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
    
}

