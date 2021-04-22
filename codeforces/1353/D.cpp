#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define lli long long int
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
typedef pair<lli, lli>	pl;
typedef vector<int>		vi;
typedef vector<lli>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;

void solve(){
    int i,j;
    int n;
    cin>>n;
 
    int a[n+1],mx,pos,l,r,mid,size,temp;
    vector<pair<int,int>> v;
    map<int,vector<int>> mapp;
    v.pb({1,n});
    mapp[n].pb(1);
    j=1;
    size=n;
    while(j<=n){
        while(mapp[size].size()==0){
            size--;
        }
        sort(all(mapp[size]));
        fo(i,mapp[size].size()){
            l=mapp[size][i];
            r=l+size-1;
            if((r-l+1)%2==1){
                mid=(l+r)/2;
            }
            else{
                mid=(l+r-1)/2;
            }
            a[mid]=j;j++;
            temp=mid-l;
            if(temp>=1){
                mapp[temp].pb(l);
            }
            temp=r-mid;
            if(temp>=1){
                mapp[temp].pb(mid+1);
            }
        }
        size--;

    }
    /*while(j<=n){
        mx=0;
        pos=-1;
        fo(i,v.size()){
            if(v[i].S>mx){
                pos=i;
                mx=v[i].S;
            }
            else if(v[i].S==mx){
                if(v[i].F<v[pos].F){
                    pos=i;
                }
            }
        }
        l=v[pos].F;
        r=l+mx-1;
        v.erase(v.begin()+pos);
        if(mx%2==1){
            mid=(l+r)/2;
            a[mid]=j;
            j++;
            if(l!=mid){
                v.pb({l,mid-l});
            }
            if(mid!=r){
                v.pb({mid+1,r-mid});
            }
        }
        else{
            mid=(l+r-1)/2;
            a[mid]=j;
            j++;
            if(l!=mid){
                v.pb({l,mid-l});
            }
            if(mid!=r){
                v.pb({mid+1,r-mid});
            }
        }
        
    }*/
    fo2(i,1,n){
        cout<<a[i]<<" ";
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
    return 0;
}

