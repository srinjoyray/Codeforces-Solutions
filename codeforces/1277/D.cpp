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
    int n;
    cin>>n;
    string s[n],temp;
    vi v[2],ans;
    int c0=0,c1=0,gap,count;
    map<string,int> mapp;
    fo(i,n){
        cin>>s[i];
        mapp[s[i]]++;
        if(s[i][0]=='0' && s[i][s[i].size()-1]=='0'){
            c0++;
        }
        if(s[i][0]=='0' && s[i][s[i].size()-1]=='1'){
            v[0].pb(i+1);
        }
        if(s[i][0]=='1' && s[i][s[i].size()-1]=='0'){
            v[1].pb(i+1);
        }
        if(s[i][0]=='1' && s[i][s[i].size()-1]=='1'){
            c1++;
        }
    }

    if((v[0].size()+v[1].size())==0 && c0>0 && c1>0){
        cout<<"-1\n";
        return;
    }

    gap=v[0].size()-v[1].size();
    gap=abs(gap);
    count=gap/2;
    // deb2(v[0].size(),v[1].size());
    // deb2(gap,count);
    if(v[0].size()>=v[1].size()){
        fo(i,v[0].size()){
            if(ans.size()==count){
                break;
            }
            temp=s[v[0][i]-1];
            reverse(all(temp));
            // deb(temp);
            if(mapp[temp]>0){
                continue;
            }
            mapp[temp]++;
            ans.pb(v[0][i]);
        }
    }
    else{
        fo(i,v[1].size()){
            if(ans.size()==count){
                break;
            }
            temp=s[v[1][i]-1];
            reverse(all(temp));
            if(mapp[temp]>0){
                continue;
            }
            mapp[temp]++;
            ans.pb(v[1][i]);
        }
    }
    if(ans.size()!=count){
        cout<<"-1\n";
        return;
    }
    cout<<ans.size()<<nl;
    fo(i,ans.size()){
        cout<<ans[i]<<" ";
    }cout<<nl;

    /*
    0-00
    1-01
    2-10
    3-11
    */
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

