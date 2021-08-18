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
map<int,int> freq;
set<int> se;
string fill(string s,int n,int val){
    int i,rem;
    rem=n-s.size();
    fo(i,rem){
        s.pb(val+'0');
    }
    return s;
}
void solve(){
    int i,j;
    int n,k,dig,val;
    cin>>n>>k;
    string s;
    s=to_string(n);
    dig=s.size();
    
    if(k==1){
        fo(i,dig){
            if(s[i]>s[0]){
                val=s[0]-'0'+1;
                fo(j,dig){
                    cout<<val;
                }
                cout<<nl;
                return;
            }
            if(s[i]<s[0]){
                break;
            }
        }
        fo(j,dig){
            cout<<s[0];
        }
        cout<<nl;
        return;
    }
    
    int temp;
    string ans="";
    se.clear();
    freq.clear();
    fo(i,dig){
        temp=s[i]-'0';
        if(se.size()==k && freq[temp]==0){
            if(temp<*se.rbegin()){
                val=*se.upper_bound(temp);
                ans.pb(val+'0');
                ans=fill(ans,dig,*se.begin());
                break;
            }
            // deb(i);
            for(j=i-1;j>=0;j--){
                ans.pop_back();
                
                // deb2(j,ans);
                temp=s[j]-'0';
                freq[temp]--;
                if(freq[temp]==0){
                    se.erase(temp);
                }
                // deb2(se.size(),freq[temp]);
                
                if(se.size()<k && temp<9){
                    val=temp+1;
                    ans.pb(val+'0');
                    se.insert(val);
                    
                    if(se.size()<k){
                        ans=fill(ans,dig,0);
                    }
                    else{
                        ans=fill(ans,dig,*se.begin());
                    }
                    break;
                }
                if(se.upper_bound(temp)!=se.end()){
                    val=*se.upper_bound(temp);
                    // deb(val);
                    
                    ans.pb(val+'0');
                    if(se.size()==k){
                        ans=fill(ans,dig,*se.begin());
                    }
                    else{
                        ans=fill(ans,dig,0);
                    }
                    break;
                }

                
                
            }

            break;
        }   


        if(freq[temp]==0){
            se.insert(temp);
        } 
        freq[temp]++;
        ans.pb(s[i]);
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

