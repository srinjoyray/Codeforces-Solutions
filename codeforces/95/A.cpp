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
    int i,j,k;
    int n;
    cin>>n;
    string s,temp,store;
    map<string,int> m;
    fo(i,n){
        cin>>temp;
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        m[temp]++;
    }
    
    cin>>s;
    n=s.size();
    store=s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    int a[n]={0};
    char ch;
    cin>>ch;
    fo(i,n){
        fo2(j,i,n-1){
            temp=s.substr(i,j-i+1);
            if(m[temp]>0){
                for(k=i;k<=j;k++){
                    a[k]=1;
                }
            }
        }
    }
    fo(i,n){
        if(a[i]==1){
            if(s[i]==ch && ch=='a'){
                s[i]='b';
            }
            else if(s[i]==ch && ch!='a'){
                s[i]='a';
            }
            else{
                s[i]=ch;
            }
        }
    }
    /*fo(i,n){
        cout<<a[i]<<" ";
    }cout<<nl;*/
    fo(i,n){
        if(store[i]>='A' && store[i]<='Z'){
            s[i]-=32;
        }
    }
    cout<<s<<nl;
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

