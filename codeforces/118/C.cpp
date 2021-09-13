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
bool comp(pii a, pii b){
    if(a.F==b.F){
        return a.S>b.S;
    }
    return a.F<b.F;
}
void solve(){
    int i,j;
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vpii v;
    multiset<int> s1,s2;
    int dig,cnt,mn,temp,rem;
    mn=n*10;
    string ans,temp_s;
    ans=s;
    temp_s=s;
    fo(i,10){
        v.clear();
        s1.clear();
        s2.clear();
        cnt=0;
        // deb(i);
        fo(j,n){
            dig=s[j]-'0';
            // deb(dig);
            if(dig==i){
                cnt++;
            }
            else{
                v.pb({abs(i-dig),dig});
            }
        }
        // deb(cnt);
        sort(all(v),comp);
        if(cnt>=k){
            cout<<"0\n";
            cout<<s<<nl;
            return;
        }
        rem=k-cnt;
        temp=0;
        fo(j,rem){
            temp+=v[j].F;
            // deb2(v[j].F,v[j].S);
            if(v[j].S<i){
                s1.insert(v[j].S);
            }
            else{
                s2.insert(v[j].S);
            }
        }
        // for(auto p : s1){
        //     cout<<p<<"@";
        // }cout<<nl;
        // for(auto p : s2){
        //     cout<<p<<"#";
        // }cout<<nl;

        temp_s=s;
        fo(j,n){
            dig=temp_s[j]-'0';
            if(s2.find(dig)!=s2.end()){
                temp_s[j]='0'+i;
                s2.erase(s2.find(dig));
            }
        }
        for(j=n-1;j>=0;j--){
            dig=temp_s[j]-'0';
            if(s1.find(dig)!=s1.end()){
                temp_s[j]='0'+i;
                s1.erase(s1.find(dig));
            }
        }
        // deb2(temp,temp_s);
        if(temp<mn){
            ans=temp_s;
            mn=temp;
        }
        else if(temp==mn){
            ans=min(ans,temp_s);
        }
    }

    cout<<mn<<nl;
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
}