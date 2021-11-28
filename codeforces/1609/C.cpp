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
    prime[0]=false; prime[1]=true;
}
ll find(vl v){
    ll i,j,n,len,ans=0,temp,l,r,left,right;
    n=v.size();
    
    // fo(i,n){
    //     cout<<v[i]<<" ";
    // }cout<<nl;
    
    fo(i,n){
        if(v[i]>1){
            j=i-1;
            while(j>=0 && v[j]==1){
                j--;
            }
            l=j+1;

            j=i+1;
            while(j<n && v[j]==1){
                j++;
            }
            r=j-1;

            left=i-l;
            right=r-i;
            // deb2(left,right);
            
            temp=left*right;
            temp+=(left+right);
            ans+=temp;
            // deb(ans);
        }
    }
    // deb(ans);
    
    return ans;
}
ll calc(vl v){
    ll i,j,n,ans=0,temp;
    
    n=v.size();
    vl v1;

    // fo(i,n){
    //     cout<<v[i]<<" ";
    // }cout<<nl;
    fo(i,n){
        if(prime[v[i]]){
            v1.pb(v[i]);
        }
        else{
            if(v1.size()>0){
                temp=find(v1);
                ans+=temp;
            }
            v1.clear();
        }
    }
    if(v1.size()>0){
        temp=find(v1);
        ans+=temp;
    }

    return ans;
}
void solve(){
    int i,j;
    ll n,e;
    cin>>n>>e;
    ll a[n],temp,ans=0;
    fo(i,n){
        cin>>a[i];
    }
    fo(i,e){
        vl v,v1;
        j=i;
        while(j<n){
            v.pb(a[j]);
            j+=e;
        }
        temp=calc(v);
        // deb(temp);
        ans+=temp;
    }

    cout<<ans<<nl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    cin>>t;
    sieveOfEratosthenes();
    while(t--){
        solve();
    }
    
}

