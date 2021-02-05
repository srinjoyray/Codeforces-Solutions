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
#define tr(it,a) for(auto it=a.begin(); it!=a.end();it++)
#define PI 3.141592653589793238
#define mod 1e9+7

void solve()
{   int i,j;
    int x,y,left=0,right=0,up=0,down=0,n,l=0,r=0,u=0,d=0;
    cin>>x>>y;
    string s;
    cin>>s;
    n=s.size();
    if(x>=0)
        right=x;
    else    
        left=-x;
    if(y>=0)
        up=y;
    else
        down=-y;
    fo(i,n){
        if(s[i]=='U')
            u++;
        else if(s[i]=='D')
            d++;
        else if(s[i]=='L')
            l++;
        else if(s[i]=='R')
            r++;            
    }
    if(u>=up && l>=left && d>=down && r>=right)
        cout<<"YES\n";
    else    
        cout<<"NO\n";

}

int main()
{   ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

