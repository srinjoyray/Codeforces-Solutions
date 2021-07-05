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
int AND(int i, int j) {
	cout << "AND " << i << " " << j << endl;
	fflush(stdout);
	int x;
	cin >> x;
	return x;
}
 
int OR(int i, int j) {
	cout << "OR " << i << " " << j << endl;
	fflush(stdout);
	int x;
	cin >> x;
	return x;
}
 
int XOR(int i, int j) {
	cout << "XOR " << i << " " << j << endl;
	fflush(stdout);
	int x;
	cin >> x;
	return x;
}
void solve(){
    int i,j;
    int n;
    cin>>n;
    vi v(n+1);
    map<int,int> freq;
    bool flag=false;
    for(i=2;i<=n;i++){
        v[i]=XOR(1,i);
        if(v[i]==0){
            flag=true;
        }
        freq[v[i]]++;
    }

    if(freq.size()==n-1 && !flag){
        int index,index2;
        for(i=2;i<=n;i++){
            if(v[i]==n-1){
                index=i;
                break;
            }
        }
        index2= index==2 ? 3: 2;
        int X13,X12,X23,A12,A13,A23;
        X12=v[index2];
        X13=v[index];
        X23=v[index]^v[index2];
        A12=AND(1,index2);
        A23=AND(index2,index);
        A13=0;

        int p,q,r;
        p=X12+2*A12;
        q=X13+2*A13;
        r=X23+2*A23;

        v[1]=(p+q-r)/2;
    }
    else{
        int val=0;
        for(auto x : freq){
            if(x.S>1){
                val=x.F;
                break;
            }
        }
        int index1=-1,index2=-1,temp;
        for(i=2;i<=n;i++){
            if(v[i]==val && index1==-1){
                index1=i;
            }
            else if(v[i]==val){
                index2=i;
                break;
            }
        }
        if(index2==-1){
            index2=1;
        }
        temp=AND(index1,index2);
        v[1]=temp^v[index1];
    }

    for(i=2;i<=n;i++){
        v[i]=v[i]^v[1];
    }

    cout<<"! ";
    for(i=1;i<=n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
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

