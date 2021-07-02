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
string convert(string s,int pos,int k){
    string ans,temp,fill;
    map<int,int> mapp;
    int i,j,n,dig,rem;
    n=s.size();
    fo(i,pos+1){
        dig=s[i]-'a';
        mapp[dig]++;
        ans.pb(s[i]);
    }
    // deb(s);
    // deb2(pos,k);
    fo(i,26){
        if(mapp[i]%k!=0){
            fo(j,k-mapp[i]%k){
                temp.pb(i+'a');
            }
        }
    }

    rem=n-temp.size()-ans.size();
    // deb2(ans,temp);
    fo(i,rem){
        fill.pb('a');
    }
    ans+=fill+temp;
    return ans;
}


void solve(){
    int i,j;
    int n,k;
    cin>>n>>k;
    string s,ans;
    cin>>s;
    if(n%k!=0){
        cout<<"-1\n";
        return;
    }
    
    map<int,int> curr;
    set<int> se;
    int pos=n+1,upto,dig,val;
    upto=n/k;
    fo(i,n){
        dig=s[i]-'a';
        
        // deb2(curr.size(),upto);
        if(curr.find(dig)==curr.end() && curr.size()==upto){
            pos=i;
            break;
        }
        // deb2(dig,curr[dig]);
        curr[dig]++;
        if(curr[dig]==k){
            upto--;
            curr.erase(dig);
        }
    }
    // deb(pos);
    if(pos==n+1){
        cout<<s<<nl;
        return;
    }

    map<int,int>mapp,other;
    int last,rem,sum=0;
    val=s[pos]-'a';
    rem=n-pos;
    fo(i,pos+1){
        dig=s[i]-'a';
        if(mapp[dig]%k==0 && dig!=25){
            last=i;
        }
        mapp[dig]++;
    }
    fo(i,26){
        if(mapp[i]==0 || mapp[i]%k==0){
            continue;
        }
        sum+=k-(mapp[i]%k);
    }
    // deb2(sum,rem);
    /*if(sum==rem){
        fo(i,26){
            if(mapp[i]%k==0){
                mapp[i]=0;
            }
        }
    }
    else{
        fo(i,26){
            mapp[i]+=k;
        }
    }*/
    // deb2(val,last);
    // fo(j,26){
    //     if(mapp[j]>0){
    //         deb2(j,mapp[j]);
    //     }
    // }
    for(i=pos;i>=0;i--){
        val=s[i]-'a';
        rem=n-i;
        mapp[val]--;
        // deb2(i,val);
        sum=0;
        
        fo(j,26){
            if(mapp[j]==0 || mapp[j]%k==0){
                continue;
            }
            sum+=k-(mapp[j]%k);
        }
        // deb2(sum,rem);
        if(sum==rem){
            fo(j,26){
                if(mapp[j]>0){
                    // deb2(j,mapp[j]);
                    other[j]=mapp[j]%k;
                }
                else{
                    other[j]=0;
                }
                
            }   
        }
        else{
            fo(j,26){
                other[j]=1;
            }
        }
        fo(j,26){
            if(other[j]>0){
                // deb2(j,other[j]);
            }
        }
        for(j=val+1;j<26;j++){
            // deb2(j,other[j]);
            if(other[j]>0){
                // deb(j);
                s[i]=j+'a';
                break;
            }
        }
        if(j!=26){
            break;
        }
        
    }
    /*for(i=val+1;i<=26;i++){
        if(i==26){
            s[last]++;
            
            ans=convert(s,last,k);
            cout<<ans<<nl;
            return;
        }
        // deb2(i,mapp[i]);
        if(mapp[i]>0){
            s[pos]=i+'a';
            break;
        }
        
    }*/
    ans=convert(s,i,k);
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

