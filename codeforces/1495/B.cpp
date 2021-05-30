#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define lli long long int
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
typedef pair<lli, lli>	pl;
typedef vector<int>		vi;
typedef vector<lli>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
void solve(){
    int i,j;
    int n;
    cin>>n;
    int a[n],pref[n+1],suff[n+1],curr,count=0,mx=0,ans;
    bool flag=false;
    fo(i,n){
        cin>>a[i];
    }
    fo(i,n){
        pref[i]=1;
        j=i+1;
        curr=1;
        while(j<n && a[j]>a[j-1]){
            curr++;
            pref[j]=curr;
            j++;
        }
        i=j-1;
    }
    for(i=n-1;i>=0;i--){
        suff[i]=1;
        j=i-1;
        curr=1;
        while(j>=0 && a[j]>a[j+1]){
            curr++;
            suff[j]=curr;
            j--;
        }
        i=j+1;
    }
    mx=max(*max_element(pref,pref+n),*max_element(suff,suff+n));
    fo(i,n){
        if(pref[i]==mx || suff[i]==mx){
            count++;
        }
        if(pref[i]==mx && suff[i]==mx){
            count++;
            flag=true;
        }
    } 
    if(count==2 && flag && mx%2==1){
        cout<<"1\n";
    }   
    else{
        cout<<"0\n";
    }

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

