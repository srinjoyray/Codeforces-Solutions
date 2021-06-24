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
    int i,j;
    int a,b,c,d,n;
    cin>>a>>b>>c>>d;
    n=a+b+c+d;
    string s,odd,even;
    fo(i,a){
        even+='0';
    }
    fo(i,b){
        odd+='1';
    }
    fo(i,c){
        even+='2';
    }
    fo(i,d){
        odd+='3';
    }
    // cout<<even<<" "<<odd<<nl;
    int temp=odd.size()-even.size();
    if(abs(temp)>1){
        cout<<"NO\n";
        return;
    }
    
    if(even.size()>=odd.size()){
        i=0;
        j=0;
        while(j<odd.size()){
            // deb(s);
            // deb2(odd[j],even[i]);
            s.pb(even[i]);
            s.pb(odd[j]);
            
            i++;j++;
        }

        if(i<even.size()){
            s.pb(even[i]);
        }
        
    }
    else{   
        i=0;
        j=0;
        while(i<even.size()){
            s.pb(odd[j]);
            s.pb(even[i]);
            i++;
            j++;
        }
        if(j<odd.size()){
            s.pb(odd[j]);
        }
    }
    // cout<<s<<nl;
    fo(i,s.size()-1){
        if(abs(s[i]-s[i+1])!=1){
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES\n";
    fo(i,s.size()){
        cout<<s[i]<<" ";
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

