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
    string s;
    cin>>s;
    ll n,count=0,temp;
    n=s.size();
    temp=0;
    int store[n];
    fo(i,n){
        store[i]=temp;
        if(s[i]=='?'){
            temp++;
        }
        else{
            temp=0;
        }
    }
    /*fo(i,n){
        cout<<store[i]<<" ";
    }cout<<nl;*/
    int odd,even; 
    fo(i,n){
        j=i;
        odd=-1;
        even=-1;
        while(j<n){
            if(s[j]=='?'){
                j++;
                continue;
            }
            if(j%2==0){
                if(even==-1){
                    even=s[j]-'0';
                }
                else if(even!=s[j]-'0'){
                    break;
                }
            }
            else{
                if(odd==-1){
                    odd=s[j]-'0';
                }
                else if(odd!=s[j]-'0'){
                    
                    break;
                }
            }
            if(odd==even && odd!=-1){
                break;
            }
            j++;
        }
        
        // deb2(i,j);
        temp=j-i;
        // deb2(temp,store[i]);
        count+=((temp)*(temp+1)/2)+store[i]*temp;
        i=j-1;
        // deb(count);
    }
    cout<<count<<nl;
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

