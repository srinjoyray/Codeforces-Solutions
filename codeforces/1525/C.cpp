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
    lli n,m;
    
    cin>>n>>m;
    string s[n];
    lli x[n],temp;
    vpl odd,even;
    fo(i,n){
        cin>>x[i];
    }
    map<lli,lli> mapp;
    fo(i,n){
        cin>>s[i];
    }
    fo(i,n){
        if(s[i][0]=='L'){
            temp=0;
        }
        else{
            temp=1;
        }
        if(x[i]%2==0){
            even.pb({x[i],temp});
        }
        else{
            odd.pb({x[i],temp});
        }
    }
    sort(all(even));
    sort(all(odd));
    /*fo(i,even.size()){
        deb2(even[i].F,even[i].S);
    }cout<<nl;*/
    /*fo(i,odd.size()){
        deb2(odd[i].F,odd[i].S);
    }cout<<nl;*/

    vector<lli> l,r;
    lli val;
    vpl group;
    fo(i,even.size()){
        if(even[i].S==0){
            if(r.size()>0){
                temp=r[r.size()-1];
                r.erase(r.end()-1);
                val=abs(temp-even[i].F)/2;
                mapp[temp]=val;
                mapp[even[i].F]=val;
                // group.pb({temp,even[i].F});
            }
            else{
                l.pb(even[i].F);
            }
        }
        else if(even[i].S==1){
            r.pb(even[i].F);
        }
    }
    // deb2(l.size(),r.size());
    i=0; j=r.size()-1;
    // deb2(i,j);
    temp=l.size();
    temp--;
    // deb(temp);
    
    // deb2(i,j);
    while(i<temp){
        
        val=l[i]+abs(l[i+1]-l[i])/2;
        mapp[l[i]]=val;
        mapp[l[i+1]]=val;
        i+=2;
        
    }
    while(j>0){
        
        val=m-r[j]+abs(r[j]-r[j-1])/2;
        mapp[r[j]]=val;
        mapp[r[j-1]]=val;
        j-=2;
    }
    // deb2(i,j);
    if(i==temp && j==0){
        val=(2*(m-r[j])+abs(r[j]-l[i]) + 2*(l[i]))/2;
        mapp[l[i]]=val;
        mapp[r[j]]=val;
    }
    else if(i==temp){
        mapp[l[i]]=-1;
    }
    else if(j==0){
        mapp[r[j]]=-1;
    }
    

    l.clear(); r.clear();
    fo(i,odd.size()){
        if(odd[i].S==0){
            if(r.size()>0){
                temp=r[r.size()-1];
                r.erase(r.end()-1);
                val=abs(temp-odd[i].F)/2;
                mapp[temp]=val;
                mapp[odd[i].F]=val;
                // group.pb({temp,even[i].F});
            }
            else{
                l.pb(odd[i].F);
            }
        }
        else if(odd[i].S==1){
            r.pb(odd[i].F);
        }
    }
    // deb2(l.size(),r.size());
    i=0; j=r.size()-1;
    temp=l.size();
    temp--;
    while(i<temp){
        val=l[i]+abs(l[i+1]-l[i])/2;
        mapp[l[i]]=val;
        mapp[l[i+1]]=val;
        i+=2;
    }
    while(j>0){
        val=m-r[j]+abs(r[j]-r[j-1])/2;
        mapp[r[j]]=val;
        mapp[r[j-1]]=val;
        j-=2;
    }
    if(i==temp && j==0){
        val=(2*(m-r[j])+abs(r[j]-l[i]) + 2*(l[i]))/2;
        mapp[l[i]]=val;
        mapp[r[j]]=val;
    }
    else if(i==temp){
        mapp[l[i]]=-1;
    }
    else if(j==0){
        mapp[r[j]]=-1;
    }


    vl ans;
    fo(i,n){
        // deb(x[i]);
        temp=mapp[x[i]];
        // deb(temp);
        ans.pb(temp);
    }
    fo(i,ans.size()){
        cout<<ans[i]<<" ";
    }cout<<nl;
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

