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
    int n,p,k;
    cin>>n>>p>>k;
    int a[n],start,sum,rem,left,temp,count,mx=0,done;
    fo(i,n){
        cin>>a[i];
    }
    sort(a,a+n);
    map<int,set<pii>> mapp;
    set<pii>::iterator itr;
    map<int,int>prev_sum;
    fo(i,k){
        start=i+k-1;
        sum=0;
        temp=1;
        // deb(start);
        while(start<n){
            sum+=a[start];
            mapp[i].insert({sum,temp});
            start+=k;
            temp++;
        }
    }
    left=p;
    fo(i,n){
        if(left<0){
            break;
        } 
        rem=i%k;
        // deb2(i,rem);
        temp=left+prev_sum[rem];
        // deb2(temp,mapp[rem].size());
        /*for(itr=mapp[rem].begin();itr!=mapp[rem].end();itr++){
            // cout<<(*itr).F<<" "<<(*itr).S<<nl;
        }*/
        itr=mapp[rem].upper_bound({temp,0});
        // deb2((*itr).F,(*itr).S);
        if(mapp[rem].size()==0 || mapp[rem].begin()==mapp[rem].upper_bound({temp,n})){
            mx=max(mx,i);
            left-=a[i];
            continue;
        }
        itr=--mapp[rem].upper_bound({temp,n});
        done=i/k;
        // deb((*itr).S);
        if((*itr).S<=done){
            break;
        }
        count=((*itr).S-done)*k;
        count+=i;
        // deb2(i,count);
        mx=max(mx,count);

        prev_sum[rem]+=a[i];
        left-=a[i];
    }
    cout<<mx<<nl;
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

