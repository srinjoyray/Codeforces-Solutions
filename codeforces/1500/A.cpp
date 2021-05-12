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
#define N 3000000
bool comp(pl a,pl b){
    if(a.F==b.F){
        return a.S<b.S;
    }
    return a.F<b.F;
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    lli a[n],temp,count=0,val,mx=0;
    map<lli,vl> freq;
    map<lli,vpl> mapp; 
    bool flag=false;
    vpl v;
    fo(i,n){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    fo(i,n){
        freq[a[i]].pb(i+1);
        if(freq[a[i]].size()==1){
            v.pb({a[i],i+1});
        }
    }
    fo2(i,1,mx){
        if(freq[i].size()>=4){
            cout<<"YES\n";
            fo(j,4){
                cout<<freq[i][j]<<" ";
            }cout<<nl;
            return;
        }
        if(freq[i].size()>=2){
            count++;
            if(count==2){
                cout<<"YES\n";
                cout<<freq[val][0]<<" "<<freq[i][1]<<" ";
                cout<<freq[i][0]<<" "<<freq[val][1]<<nl;
                return;
            }
            val=i;
        }
    }
    sort(all(v),comp);
    if(count==1){
        i=0;
        j=v.size()-1;
        while(i<j){
            temp=v[i].F+v[j].F;
            if(temp==val*2){
                cout<<"YES\n";
                cout<<freq[val][0]<<" "<<freq[val][1]<<" ";
                cout<<v[i].S<<" "<<v[j].S<<nl;
                return;
            }
            else if(temp<val*2){
                i++;
            }
            else{
                j--;
            }
        }
    }

    fo(i,v.size()){
        fo2(j,i+1,v.size()-1){
            temp=v[i].F+v[j].F;
            mapp[temp].pb({v[i].S,v[j].S});
            if(mapp[temp].size()>=2){
                cout<<"YES\n";
                cout<<mapp[temp][0].F<<" "<<mapp[temp][0].S<<" ";
                cout<<mapp[temp][1].F<<" "<<mapp[temp][1].S<<nl;
                return;
            }
        }
    }
    cout<<"NO\n";
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

