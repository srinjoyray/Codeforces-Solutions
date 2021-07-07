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

/*string to_binary(int n){
    int binaryNum[32]={0};
    string s;
    int i=0,j;
    while(n>0){
        binaryNum[i] = n % 2;
        n=n/2;
        i++;
    }
    fo(j,32){
        s.pb(binaryNum[j]+'0');
    }
    reverse(all(s));
    return s;
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
double find(double c,double m,double p,double v,double count){
    double ans=0,tempC,tempM,tempP,temp;
    // deb2(c,m);
    // deb2(p,v);
    // deb(count);
    temp=p*(count+1);
    if(count==0){
        // deb(temp);
    }
    ans+=temp;
    if(c>0){
        tempC=c;
        tempM=m;
        tempP=p;
        // deb2(tempC,v);
        if(tempC<=v){
            if(tempM>0){
                tempM+=tempC/2;
                tempP+=tempC/2;
            }
            else{
                tempP+=tempC;
            }
            tempC=0;
            // deb(tempC);
        }
        else if(tempC>v){
            tempC-=v;
            if(tempM>0){
                tempM+=v/2;
                tempP+=v/2;
            }
            else{
                tempP+=v;
            }
            if(tempC<1e-10){
                tempC=0;
            }
            // deb(tempC);
        }
        
        // deb(tempC);
        temp=c*find(tempC,tempM,tempP,v,count+1);
        if(count==0){
            // deb2(tempC,tempM);
            // deb(temp);
        }
        ans+=temp;
    }
    if(m>0){
        tempC=c;
        tempM=m;
        tempP=p;
        if(tempM>v){
            tempM-=v;
            if(tempC>0){
                tempC+=v/2;
                tempP+=v/2;
            }
            else{
                tempP+=v;
            }
            if(tempM<1e-10){
                tempM=0;
            }
        }
        else{
           if(tempC>0){
                tempC+=tempM/2;
                tempP+=tempM/2;
            }
            else{
                tempP+=tempM;
            }
            tempM=0;
        }
        // deb(m);
        
        temp=m*find(tempC,tempM,tempP,v,count+1);
        if(count==0){
            // deb2(tempC,tempM);
            // deb(temp);
        }
        ans+=temp;
    }
    return ans;
}

void solve(){
    int i,j;
    double c,m,p,v,ans=0;
    cin>>c>>m>>p>>v;
    ans=find(c,m,p,v,0);
    cout<<fixed<<setprecision(12);
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

