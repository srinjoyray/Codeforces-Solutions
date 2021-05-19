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
    int n;
    cin>>n;
    lli a[n],t[n];
    vpl v;
    fo(i,n){
        cin>>a[i];
    }
    fo(i,n){
        cin>>t[i];
    }
    fo(i,n){
        v.pb({a[i],t[i]});
    }
    sort(all(v));
    fo(i,v.size()){
        // deb2(v[i].F,v[i].S);
    }
    lli curr=0,temp,next,gap,ans=0,sum=0;
    multiset<lli,greater<lli>> se;
    multiset<lli,greater<lli>>::iterator itr;
    fo(i,v.size()){
        // deb(i);
        // deb2(i,se.size());
        
        j=i;
        while(j<v.size() && v[i].F==v[j].F){
            se.insert(v[j].S);
            sum+=v[j].S;
            j++;
        }

        /*for(itr=se.begin();itr!=se.end();itr++){
            cout<<(*itr)<<"@";
        }cout<<nl;*/
        // temp=j-i;
        i=j-1;
        // curr+=temp;
        if(se.size()==1){
            sum-=(*se.begin());
            se.erase(se.begin());
            continue;
        }
        if(i==v.size()-1){
            j=0;
            // deb(se.size());
            while(se.size()>0){
                ans+=j*(*se.begin());
                se.erase(se.begin());
                j++;
            }
            break;
        }
        gap=v[i+1].F-v[i].F;
        // deb(gap);
        temp=se.size();
        fo(j,gap){
            if(se.size()==0){
                break;
            }
            ans+=j*(*se.begin());
            sum-=(*se.begin());
            se.erase(se.begin());
        }
        // for(itr=se.begin();itr!=se.end();itr++){
        //     ans+=gap*(*itr);
        // }
        ans+=gap*sum;
        // deb(ans);
    }
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

