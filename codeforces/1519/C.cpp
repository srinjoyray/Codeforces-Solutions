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
    int i,j,k;
    int n;
    cin>>n;
    lli u[n],s[n],temp=0,ans[n+1]={0},rem,upto,size,temp_ans=0;
    fo(i,n){
        cin>>u[i];
    }
    fo(i,n){
        cin>>s[i];
        temp_ans+=s[i];
    }
    map<lli,vector<lli>> mapp;
    map<lli,vector<lli>> pref;
    fo(i,n){
        mapp[u[i]].pb(s[i]);
    }
    fo2(i,1,n){
        sort(all(mapp[i]),greater<int>());
        temp=0;
        fo(j,mapp[i].size()){
            temp+=mapp[i][j];
            pref[i].pb(temp);
        }
    }

    for(auto itr:mapp){
        i=itr.F;
        size=mapp[i].size();
        
        for(j=size;j>=1;j--){
            temp=pref[i][j-1];
            for(k=2*j;k<=size;k+=j){
                temp=pref[i][k-1];
            }
            ans[j]+=temp;
        }

    }
    fo2(i,1,n){
        cout<<ans[i]<<" ";
    }cout<<nl;

    /*fo2(k,1,n){
        ans[k]=0;
        for(auto itr:mapp){
            i=itr.F;
            rem=mapp[i].size()%k;
            upto=mapp[i].size()-rem;
            if(upto>0){
                ans[k]+=pref[i][upto-1];
            }
            if(mapp[i].size()==k){
                mapp[i].clear();
            }
        }
        cout<<ans[k]<<" ";
    }
    cout<<nl;*/
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
    return 0;
}

