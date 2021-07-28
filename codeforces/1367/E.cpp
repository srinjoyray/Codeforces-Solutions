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
bool check(int val,string s,int n,int k){
    // deb(val);
    int  freq[26]={0},i,j,ans=0;
    fo(i,n){
        freq[s[i]-'a']++;
    }
    multiset<int> se,s2;
    fo(i,26){
        se.insert(freq[i]);
    }
    int cnt=0;
    map<int,int> vis;
    fo2(i,1,val){
        if(vis[i]==1){
            continue;
        }
        j=i;
        cnt=0;
        while(true){
            if(vis[j]==1){
                break;
            }
            vis[j]=1;
            cnt++;
            j+=k;
            if(j>val){
                j%=val;
            }
        }
        s2.insert(cnt);      
    }

    while(s2.size()){
        cnt=*s2.rbegin();
        s2.erase(--s2.end());
        // deb2(cnt,*se.rbegin());
        if(*se.rbegin()<cnt){
            return false;
        }
        se.insert(*se.rbegin()-cnt);
        se.erase(--se.end());
    }
    
    return true;
}
void solve(){
    int i,j;
    int n,k,temp_k;
    cin>>n>>k;
    string s;
    cin>>s;
    // deb(s);
    if(k==0){
        cout<<n<<nl;
        return;
    }
    int ans=0;
    // deb2(n,k);
    for(i=n;i>=1;i--){
        temp_k=k%i;
        if(temp_k==0){
            ans=i;
            break;
        }
        if(check(i,s,n,temp_k)){
            ans=i;
            break;
        }
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

