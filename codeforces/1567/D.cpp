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
ll power(ll a,ll n){
    ll res=1;
    while(n){
        if(n%2){
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        n/=2;
    }
    return res;
}
ll digs(ll num){
    ll ans=0;
    while(num){
        ans++;
        num/=10;
    }
    return ans;
}
pl find(ll num){
    string s;
    s=to_string(num);
    ll base,low,p;
    p=s.size()-1;
    base=power(10,p);
    // deb2(base,p);
    if(base!=num){
        return{base,num-base};
    }
    low=base/10;
    return {low,num-low};
}
ll check(ll num){
    string s;
    s=to_string(num);
    if(s[0]=='1'){
        return true;
    }
    return false;
}
void solve(){
    int i,j;
    string s;
    cin>>s;
    ll num,k,sz;
    num=stoll(s);
    cin>>k;
    sz=s.size();

    multiset<ll> v,ans,se,s1;
    ll dig,val,sum,temp;
    val=1;
    for(i=sz-1;i>=0;i--){
        dig=s[i]-'0';
        if(dig>0){
            v.insert(dig*val);
        }
        val*=10;
    }
    // for(auto p : v){
    //     cout<<p<<" ";
    // }cout<<nl;

    if(v.size()>=k){
        sum=0;
        i=0;
        for(auto p : v){       
            if(i<k-1){
                ans.insert(p);
            }
            else{
                sum+=p;
            }
            i++;
        }
        ans.insert(sum);
        for(auto p : ans){
            cout<<p<<" ";
        }
        cout<<nl;
        return;
    }
    
    // for(auto p : v){
    //     cout<<p<<" "; 
    // }cout<<nl;



    while(se.size()+v.size()+s1.size()<k){
        pl p1;
        // deb2(se.size(),v.size());
        if(v.size()==0){
            val=*s1.begin();
            s1.erase(s1.begin());
            // deb(val);
            if(val==1){
                se.insert(val);
                continue;
            }
            p1=find(val);
            v.insert(p1.F);
            v.insert(p1.S);
            // deb2(p1.F,p1.S);
            continue;
        }
        val=*v.begin();
        v.erase(v.begin());
        // deb(val);
        if(val==1){
            se.insert(val);
            continue;
        }
        if(check(val)){
            s1.insert(val);
            continue;
        }
        p1=find(val);
        v.insert(p1.F);
        v.insert(p1.S);
    }

    for(auto p : v){
        cout<<p<<" ";
    }
    for(auto p : s1){
        cout<<p<<" ";
    }
    for(auto p : se){
        cout<<p<<" ";
    }
    cout<<nl;
    
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

