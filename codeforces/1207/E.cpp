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
const int N=1e6;

/*bool prime[N + 1];
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
}*/

/*int spf[N];
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
}*/

/*ll power(ll a,ll n){
    ll res=1;
    while(n){
        if(n%2){
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        n/=2;
    }
    return res;
}*/
string to_binary(int n){
    int binaryNum[7]={0};
    string s;
    int i=0,j;
    while(n>0){
        binaryNum[i] = n % 2;
        n=n/2;
        i++;
    }
    fo(j,7){
        s.pb(binaryNum[j]+'0');
    }
    reverse(all(s));
    return s;
}
int to_decimal(string s){
    int i,ans=0;
    fo(i,14){
        if(s[i]=='1'){
            ans+=pow(2,14-i-1);
        }
    }
    return ans;
}
string binary(int n){
    int binaryNum[14]={0};
    string s;
    int i=0,j;
    while(n>0){
        binaryNum[i] = n % 2;
        n=n/2;
        i++;
    }
    fo(j,14){
        s.pb(binaryNum[j]+'0');
    }
    reverse(all(s));
    return s;
}
void solve(){
    int i,j;
    string s,first,last,fill,t[100],temp_s;
    int left,right,temp;
    s.resize(14);
    fo(i,7){
        fill.pb('0');
    }
    fo(i,100){
        t[i]=to_binary(i+1);
        // deb(t[i]);
    }

    cout<<"? ";
    fo(i,100){
        temp_s=fill+t[i];
        temp=to_decimal(temp_s);
        cout<<temp<<" ";
    }
    cout<<endl;
    cin>>left;

    cout<<"? ";
    fo(i,100){
        temp_s=t[i]+fill;
        temp=to_decimal(temp_s);
        cout<<temp<<" ";
    }
    cout<<endl;
    cin>>right;

    first=binary(left);
    last=binary(right);
    // deb2(first,last);
    int ans;
    fo(i,14){
        if(i<7){
            s[i]=first[i];
        }
        else{
            s[i]=last[i];
        }
    }
    ans=to_decimal(s);
    cout<<"! "<<ans<<endl;

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

