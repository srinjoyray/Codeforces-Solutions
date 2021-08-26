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
bool prime(int n){
    int i;
    fo2(i,2,n-1){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
void solve(){
    int i,j;
    int n,pos=-1,pos2=-1,num;
    cin>>n;
    string s,ans,temp;
    cin>>s;
    map<char,int> mapp;
    
    fo(i,n){
        if(s[i]!='3' && s[i]!='5' && s[i]!='7' && s[i]!='2'){
            cout<<"1\n";
            cout<<s[i]<<nl;
            return;
        }
        if(s[i]=='2'){
            pos=i;
        }
        if(s[i]=='5'){
            pos2=i;
        }
        mapp[s[i]]++;
    }
    // deb(pos);
    if(pos==0){
        fo(i,n){
            if(s[i]=='5' || s[i]=='7'){
                cout<<"2\n";
                cout<<s[pos]<<s[i]<<nl;
                return;
            }
        }
    }
    if(pos>0){
        cout<<"2\n";
        cout<<s[pos-1]<<s[pos]<<nl;
        return;
    }
    if(pos2>0){
        cout<<"2\n";
        cout<<s[pos2-1]<<s[pos2]<<nl;
        return;
    }
    // if(mapp['3']>=2){
    //     cout<<"2\n";
    //     cout<<"33\n";
    //     return;
    // }
    // if(mapp['5']>=2){
    //     cout<<"2\n";
    //     cout<<"55\n";
    //     return;
    // }
    // if(mapp['7']>=2){
    //     cout<<"2\n";
    //     cout<<"77\n";
    //     return;
    // }
    fo(i,n){
        fo2(j,i+1,n-1){
            temp="";
            temp.pb(s[i]);
            temp.pb(s[j]);
            num=stoi(temp);
            // deb(num);
            if(!prime(num)){
                cout<<"2\n";
                cout<<temp<<nl;
                return;
            }
        }
    }
    cout<<n<<nl;
    cout<<s<<nl;
    
    


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

