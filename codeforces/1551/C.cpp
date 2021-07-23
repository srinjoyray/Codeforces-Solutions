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
bool comp(pair<int,pii> a, pair<int,pii> b){
    if(a.F==b.F){
        return a.S.S<b.S.S;
    }
    return a.F>=b.F;
}
int find(vpii v){
    vector<pair<int,pii>> vp;
    int i,j,n;
    n=v.size();
    float ratio;
    int count=0,total=0,ans=0,diff;
    fo(i,n){
        // ratio=float((float)v[i].F/(float)v[i].S);
        // // deb(ratio);
        // if(ratio>0.5){
        //     ans++;
        //     count+=
        // }
        diff=v[i].F-(v[i].S-v[i].F);



        vp.pb({diff,{v[i]}});
    }
    sort(all(vp),comp);
    // deb(vp.size());
    
    fo(i,n){
        count+=vp[i].S.F;
        total+=vp[i].S.S;
        if(count*2>total){
            ans++;
        }
        else{
            break;
        }
    }
    return ans;
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    string s[n];
    fo(i,n){
        cin>>s[i];
    }
    int freq[n][5],val,ans=0,temp;
    memset(freq,0,sizeof freq);
    fo(i,n){
        fo(j,s[i].size()){
            val=s[i][j]-'a';
            freq[i][val]++;
        }
    }
    
    fo(i,5){
        // deb(i);
        vpii v;
        fo(j,n){
            v.pb({freq[j][i],s[j].size()});
        }
        temp=find(v);
        // deb(temp);
        ans=max(temp,ans);
    }
    cout<<ans<<nl;
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

