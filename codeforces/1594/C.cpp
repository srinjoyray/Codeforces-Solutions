#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define ll long long
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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

const int N=1e6+10;
bool prime[N + 1];
void sieveOfEratosthenes()
{
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= N; p++)
    {
        if (prime[p] == true){
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
    prime[0]=false; prime[1]=false;
}

int spf[N];
set<int> se;
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<N; i++)
        spf[i] = i;

    for (int i=4; i<N; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<N; i++){
        if (spf[i] == i){
            for (int j=i*i; j<N; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    char ch;
    cin>>ch;
    string s;
    
    cin>>s;
    map<ll,ll> mapp;
    fo(i,s.size()){
        if(s[i]!=ch){
            break;
        }
        if(i==s.size()-1){
            cout<<"0\n";
            return;
        }
    }
    vi v;
    ll val,temp,cnt=0;
    fo(i,s.size()){
        if(s[i]!=ch){
            v.pb(i+1);
        }
    }
    // fo(i,v.size()){
    //     cout<<v[i]<<" ";
    // }cout<<nl;

    for(i=1;i<=n;i++){
        for(j=i;j<=n;j+=i){
            // cnt++;
            if(s[j-1]!=ch){
                break;
            }
        }
        if(j>n){
            cout<<"1\n";
            cout<<i<<nl;
            return;
        }
    }
    // deb(cnt);

    // fo(i,v.size()){
    //     val=v[i];
    //     while(spf[val]>1){
    //         temp=spf[val];
    //         // deb(temp);
    //         mapp[temp]++;
    //         while(val%temp==0){
    //             val/=temp;
    //         }
    //     }
    //     // deb(val);
    //     if(val>1){
    //         mapp[val]++;
    //     }
    // }
    // for(auto it : se){
    //     if(it>n){
    //         break;
    //     }
    //     if(mapp[it]==0){
    //         cout<<"1\n";
    //         cout<<it<<nl;
    //         return;
    //     }
    // }
    
    cout<<"2\n";
    cout<<n-1<<" "<<n<<nl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    cin>>t;
    sieveOfEratosthenes();
    sieve();
    for(int i=2;i<N;i++){
        if(prime[i]){
            se.insert(i);
        }
    }
    while(t--){
        solve();
    }
    // for(auto it : se){
    //     cout<<it<<" ";
    // }cout<<nl;
}

