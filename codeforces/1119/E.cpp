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

/*void SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true){
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}*/

/*#define MAXN   100001
int spf[MAXN];
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;

    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++){
        if (spf[i] == i){
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}*/

/*FFT IMPLEMENTATION

typedef complex<double> base;  // stl complex class
const double PI = acos(-1);

void fft (vector<base> & a, bool invert) {
	int n = (int) a.size();

	if (n == 1) return;

	vector<base> y0 (n / 2), y1 (n / 2);   // y0 and y1
	
	for (int i = 0, j = 0; i < n; i += 2, ++j) {        // initialisation of the vectors
		y0[j] = a[i];
		y1[j] = a[i + 1];
	}
	
	fft (y0, invert);
	fft (y1, invert);
	
	double ang = 2 * PI / n * (invert ? -1 : 1);   // setting angle acc. to invert or non invert
	base w(1), wn (cos(ang), sin(ang));   // setting wn for use and initialising w to 1
	
	for (int k = 0; k < n / 2; ++k) {

		a[k] = y0[k] + w * y1[k];                  // y(k)
		a[k + n / 2] = y0[k] - w * y1[k];         // y(k+n/2)
		
		 // if we are doing inverse fft, we have to divide by n at each step
		if (invert)                            
			a[k] /= 2, a[k + n / 2] /= 2;

		w *= wn;            // changing wn (from 1 to i, -1, -i etc) depending on the choice of w
	}
}

void multiply (const vector<int> & a, const vector<int> & b, vector<int> & res)
{
	vector<base> fx (a.begin(), a.end()), fy (b.begin(), b.end()) , hx;
	
	size_t n = 1;
	
	while (n < max (a.size(), b.size())) n <<= 1;  // finding power of 2, i.e size of hx 
	n <<= 1;

	fx.resize (n), fy.resize (n), hx.resize(n);
	
	// finding fft of fx and gx and then multiplying each term of both to obtain
	// fft of hx
	
	fft (fx, false), fft (fy, false);

	for (size_t i = 0; i < n; ++i)
		hx[i] = fx[i] * fy[i];

	fft (hx, true);  // inverse fft of hx
	res.resize (n);

	// storing the result coeficients
	for (size_t i = 0; i < n; ++i)
		res[i] = int (hx[i].real() + 0.5);

}

// Sample Testing
// f(x) = 1 + x + x^2 =[1,1,1]
// g(x) = 1+3x =[1,3]
// multiply(fx,gx,res);
// h(x) = 1+ 4x + 4x^2 + 3x^3 =[1,4,4,3]

*/
void solve(){
    int i,j;
    int n;
    cin>>n;
    ll a[n];
    fo(i,n){
        cin>>a[i];
    }
    ll carry=0,p,q,ans=0,rem;
    fo(i,n){
        p=a[i]/2;
        q=a[i]%2;
        if(carry>=p){
            ans+=p;
            carry-=p;
            carry+=q;
        }
        else{
            ans+=carry;
            rem=a[i]-(carry)*2;
            ans+=rem/3;
            carry=rem%3;
        }
    }
    cout<<ans<<nl;
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

