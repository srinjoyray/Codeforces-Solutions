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
    int a[2*n],count=0,req,temp,ans;
    fo(i,2*n){
        cin>>a[i];
        a[i]--;
        count+=a[i];
    }

    vi l,r;
    fo(i,2*n){
        if(i<n){
            l.pb(a[i]);
        }
        else{
            r.pb(a[i]);
        }
    }
    reverse(all(l));
    if(count==n){
        cout<<"0\n";
        return;
    }
    if(count<n){
        // just inter-changing 1 & 0 as i want occurence of 1> occurence of 0 
        fo(i,n){
            l[i]=1-l[i];
            r[i]=1-r[i];
        }
        
    }
    count=abs(count-n);
    count*=2;
    fo(i,n){
        if(l[i]==0){
            l[i]=-1;
        }
        if(r[i]==0){
            r[i]=-1;
        }
    }
    /*fo(i,n){
        cout<<l[i]<<" ";
    }cout<<nl;
    fo(i,n){
        cout<<r[i]<<" ";
    }cout<<nl;*/
    // deb(count);
    map<int,int> left,right;
    
    temp=0;
    fo(i,n){
        temp+=l[i];
        if(left[temp]==0){
            left[temp]=i+1;
        }
    }
    temp=0;
    fo(i,n){
        temp+=r[i];
        if(right[temp]==0){
            right[temp]=i+1;
        }
    }
    ans=2*n;
    for(i=1;i<count;i++){
        int p,q;
        p=i;
        q=count-i;
        // deb2(p,q);
        // deb2(left[p],right[q]);
        if(left[p]==0 || right[q]==0){
            continue;
        }
        temp=left[p]+right[q];
        ans=min(ans,temp);
    }
    if(left[count]>0){
        ans=min(ans,left[count]);
    }
    if(right[count]>0){
        ans=min(ans,right[count]);
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

