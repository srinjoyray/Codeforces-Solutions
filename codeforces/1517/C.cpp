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
int a[501][501];
int count1;
void func(int val,int i,int j,int n){
    if(count1==val){
        return;
    }
    a[i][j]=val;
    count1++;
    if(j>0 && a[i][j-1]==0){
        func(val,i,j-1,n);
    }
    if(count1==val){
        return;
    }
    if(i<n-1 && a[i+1][j]==0){
        func(val,i+1,j,n);
    }

}
void solve(){
    int i,j,k,q;
    int n;
    cin>>n;
    // deb(n);
    int p[n],val,temp=0,rem;
    bool flag=false;
    fo(i,n){
        cin>>p[i];
    }
    memset(a,0,sizeof(a));
    fo(i,n){
        count1=0;
        func(p[i],i,i,n);
        if(count1!=p[i]){
            flag=true;
            break;
        }
    }
    /*fo(i,n){
        val=p[i];
        count=0;
        k=i;
        while(true){
            j=i;
            temp=0;
            q=j;
            rem=val-count;
            while(q>=0 && a[k][q]==0){
                temp++;
                q--;
            }
            while(count<val && j>=0 && a[k][j]==0){
                a[k][j]=val;
                j--;
                count++;
            }
            if(count==val){
                break;
            }
            for(q=j+1;q<=i;q++){

            }
            // deb2(count,temp);
            if(rem>=temp){
                while(count<val && j>=0 && a[k][j]==0){
                    a[k][j]=val;
                    j--;
                    count++;
                }
            }
            else{
                j=q+1;
                while(count<val){
                    a[k][j]=val;
                    j++;
                    count++;
                }
            }
            
            if(count==val){
                break;
            }
            j++;
            q=k+1;
            while(count<val && a[q][j]==0){
                deb2(q,j);
                a[q][j]=val;
                q++;
                count++;
                if(q==n){
                    q=k+1;
                    j++;
                }
            }
            if(count==val){
                break;
            }
            k++;
        }
        if(count!=val){
            // deb(val);
            flag=true;
            break;
        }
    }*/
    if(flag){
        cout<<"-1\n";
        return;
    }
    fo(i,n){
        fo(j,i+1){
            cout<<a[i][j]<<" ";
        }
        cout<<nl;
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
    return 0;
}

