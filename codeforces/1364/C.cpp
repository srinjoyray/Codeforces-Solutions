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
void solve(){
    int i,j,k;
    int n;
    cin>>n;
    int a[n],b[n],last=-1,start,rem,count,temp;
    fo(i,n){
        cin>>a[i];
    }
    memset(b,-1,sizeof b);
    set<int> se,val;
    set<int>::iterator itr;
    fo(i,n+1){
        val.insert(i);
    }
    i=0;
    while(i<n){
        start=a[i]-1;
        rem=start-last;
        
        if(rem==0){
            j=i;
            while(j<n && a[j]==a[i]){
                se.insert(j);
                j++;
            }
            i=j;
            continue;
        }
        // deb2(start,last);
        count=last+1;
        
        b[i]=count;
       
        count++;
        // deb2(start,count);
        while(count<=start){
            /*for(itr=se.begin();itr!=se.end();itr++){
                cout<<(*itr)<<" ";
            }cout<<nl;*/
            temp=*(--se.end());
            
            if(se.size()==0){
                cout<<"-1\n";
                return;
            }
            
            
            b[temp]=count;
            se.erase(temp);
            count++;
        }
        last=count-1;
        j=i+1;
        while(j<n && a[j]==a[i]){
            se.insert(j);
            j++;
        }
        i=j;
    }
    
    fo(i,n){
        if(b[i]==-1){
            b[i]=1e6;
        }
        cout<<b[i]<<" ";
    }cout<<nl;
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

