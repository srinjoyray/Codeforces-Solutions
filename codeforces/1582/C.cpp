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
int find(string s,char ch){
    int count=0,i,j,n;
    n=s.size();
    i=0;
    j=n-1;
    while(i<j){
        if(s[i]==s[j]){
            i++;
            j--;
        }
        else if(s[i]==ch){
            count++;
            i++;
        }
        else if(s[j]==ch){
            count++;
            j--;
        }
    }
    return count;
}
void solve(){
    int i,j;
    string s,s1,s2,r1,r2;
    int n,temp,ans=1e6;
    cin>>n;
    cin>>s;
    
    char ch1,ch2;
    n=s.size();
    i=0;
    j=n-1;
    while(i<j){
        if(s[i]==s[j]){
            i++;
            j--;
        }
        else{
            ch1=s[i];
            ch2=s[j];
            break;
        }
    }

    fo(i,n){
        if(s[i]!=ch1){
            s1.pb(s[i]);
        }
        if(s[i]!=ch2){
            s2.pb(s[i]);
        }
    }
    // deb2(s1,s2);
    r1=s1;
    r2=s2;
    reverse(all(r1));
    reverse(all(r2));
    
    // deb2(s1,r1);

    if(s1!=r1 && s2!=r2){
        cout<<"-1\n";
        return;
    }    

    if(s1==r1){
        temp=find(s,ch1);
        ans=min(ans,temp);
    }
    if(s2==r2){
        temp=find(s,ch2);
        ans=min(ans,temp);
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

