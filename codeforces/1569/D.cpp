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
    int n,m,k;
    cin>>n>>m>>k;
    int x[n],y[m];
    set<int> s1,s2,m1,m2;
    fo(i,n){
        cin>>x[i];
        s1.insert(x[i]);
    }
    fo(i,m){
        cin>>y[i];
        s2.insert(y[i]);
    }
    pii p[k];
    vi v1,v2;
    map<int,vi> mp1,mp2;
    fo(i,k){
        cin>>p[i].F>>p[i].S;
        // deb2(p[i].F,p[i].S);
        if(s1.find(p[i].F)!=s1.end() && s2.find(p[i].S)!=s2.end()){
            continue;
        }
        if(s1.find(p[i].F)!=s1.end()){
            v1.pb(p[i].S);
            mp1[p[i].F].pb(p[i].S);
            m1.insert(p[i].F);
        }
        else{
            v2.pb(p[i].F);
            mp2[p[i].S].pb(p[i].F);
            m2.insert(p[i].S);
        }
    }

    // v1-> ||

    sort(all(v1));
    sort(all(v2));
    
    ll count=0,curr=-1,temp=0,ans=0,minus=0;
    fo(i,v1.size()){
        if(v1[i]>curr){
            temp+=(count*(count-1))/2;
            count=1;
            if(s2.upper_bound(v1[i])!=s2.end()){
                curr=*s2.upper_bound(v1[i]);
            }
            else{
                curr=1e6+10;
            }
        }
        else if(v1[i]<curr){
            count++;
        }
    }
    temp+=(count*(count-1))/2;
    ans+=temp;
    // deb(ans);

    count=0;curr=-1;temp=0;
    fo(i,v2.size()){
        // deb(v2[i]);
        if(v2[i]>curr){
            temp+=(count*(count-1))/2;
            count=1;
            if(s1.upper_bound(v2[i])!=s1.end()){
                curr=*s1.upper_bound(v2[i]);
            }
            else{
                curr=1e6+10;
            }
        }
        else if(v2[i]<curr){
            count++;
        }
    }
    temp+=(count*(count-1))/2;
    ans+=temp;    
    // deb(temp);

    for(auto it : m1){
        v1.clear();
        for(auto itr : mp1[it]){
            v1.pb(itr);
            // deb(itr);
        }
        // deb(v1.size());
        // fo(i,v1.size()){
        //     cout<<v1[i]<<" ";
        // }cout<<nl;
        sort(all(v1));
        count=0;curr=-1;temp=0;
        fo(i,v1.size()){
            // deb(v1[i]);
            if(v1[i]>curr){
                temp+=(count*(count-1))/2;
                count=1;
                if(s2.upper_bound(v1[i])!=s2.end()){
                    curr=*s2.upper_bound(v1[i]);
                }
                else{
                    curr=1e6+10;
                }
            }
            else if(v1[i]<curr){
                count++;
            }
            // deb2(curr,temp);
        }
        temp+=(count*(count-1))/2;
        minus+=temp;

        // deb2(it,temp);
    }

    for(auto it : m2){
        v2.clear();
        for(auto itr : mp2[it]){
            v2.pb(itr);
        }
        // deb(v2.size());
        sort(all(v2));
        // fo(i,v2.size()){
        //     cout<<v2[i]<<" ";
        // }cout<<nl;
        count=0;curr=-1;temp=0;
        fo(i,v2.size()){
            // deb(v2[i]);
            if(v2[i]>curr){
                temp+=(count*(count-1))/2;
                count=1;
                if(s1.upper_bound(v2[i])!=s1.end()){
                    curr=*s1.upper_bound(v2[i]);
                }
                else{
                    curr=1e6+10;
                }
            }
            else if(v2[i]<curr){
                count++;
            }
        }
        temp+=(count*(count-1))/2;
        minus+=temp;    

        // deb2(it,temp);
    }

    ans-=minus;
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

