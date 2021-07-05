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
int to_decimal(string s){
    reverse(all(s));
    int i,ans=0;
    fo(i,s.size()){
        if(s[i]=='1'){
            ans+=pow(2,i);
        }
    }
    return ans;
}
string to_binary(int n){
    // deb(n);
    int binaryNum[20]={0};
    string s;
    int i=0,j;
    while(n>0){
        binaryNum[i] = n % 2;
        n=n/2;
        i++;
    }
    fo(j,20){
        s.pb(binaryNum[j]+'0');
    }
    reverse(all(s));
    return s;
}

void solve(){
    int i,j;
    int n;
    cin>>n;

    int xor1,xor2,and1,and2,or1,val,temp;
    vi v;

    cout<<"XOR 1 2"<<endl;
    cin>>xor1;
    cout<<"XOR 1 3"<<endl;
    cin>>xor2;

    cout<<"OR 2 3"<<endl;
    cin>>or1;

    cout<<"AND 1 2"<<endl;
    cin>>and1;
    cout<<"AND 1 3"<<endl;
    cin>>and2;

    string s_val,s_xor1,s_xor2,s_and1,s_and2,s_or;

    s_xor1=to_binary(xor1);
    s_xor2=to_binary(xor2);
    s_or=to_binary(or1);
    s_and1=to_binary(and1);
    s_and2=to_binary(and2);

    // deb(s_xor1);
    fo(i,20){
        if(s_or[i]=='1'){
            if(s_xor1[i]==s_xor2[i]){
                if(s_xor1[i]=='1'){
                    s_val.pb('0');
                }
                else{
                    s_val.pb('1');
                }
            }
            else if(s_and1[i]=='1' || s_and2[i]=='1'){
                s_val.pb('1');
            }
            else{
                s_val.pb('0');
            }
        }
        else{
            if(s_xor1[i]=='1'){
                s_val.pb('1');
            }
            else{
                s_val.pb('0');
            }
        }
    }

    val=to_decimal(s_val);
    v.pb(val);
    temp=val^xor1;
    v.pb(temp);
    temp=val^xor2;
    v.pb(temp);

    for(i=3;i<n;i++){
        cout<<"XOR 1 "<<i+1<<endl;
        cin>>temp;
        v.pb(val^temp);
    }

    cout<<"! ";
    fo(i,v.size()){
        cout<<v[i]<<" ";
    }cout<<endl;
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

