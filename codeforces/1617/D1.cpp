#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fo(i,n) for(i=0;i<n;i++)
#define fo2(i,start,end) for(i=start;i<=end;i++)
#define rfo(i,n) for(i=n-1;i>=0;i--)
#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define ll long long
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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

const int N=1e6+10;
int ask(int a,int b,int c){
    int ans;
    cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
    cin>>ans;
    return ans;
}
void solve(){
    int i,j;
    int n;
    cin>>n;

    int a[n+1],ans[n+1],temp,count=2;
    vi v;
    bool flag=false;
    memset(a,-1,sizeof a);
    fo2(i,3,n){
        a[i]=ask(1,2,i);

        if(i==3){
            count=2;
        }
        else{
            if(a[i]!=a[i-1]){
                flag=true;
            }
            count++;
            if(count>2*n/3 && flag==false){
                break;
            }
        }
    }
    // fo2(i,3,n){
    //     cout<<a[i]<<" ";
    // }cout<<nl;
   
    if(flag){
        int pos1,pos2;
        fo2(i,3,n){
            ans[i]=a[i];
            if(a[i]==0){
                pos1=i;
            }
            if(a[i]==1){
                pos2=i;
            }
        }

        ans[1] = ask(1,pos1,pos2);
        ans[2] = ask(2,pos1,pos2);

    }
    else{
        int pos1,pos2;

        ans[1] = a[3];
        ans[2] = a[3];

        pos1=1;
        pos2=0;

        for(j=3;j<=n-2;j+=3){
            temp=ask(j,j+1,j+2);

            if(temp!=a[3]){
                if(ask(j,j+1,1) != a[3]){
                    pos2=j;
                }
                else{
                    pos2=j+2;
                }

                break;
            }
        }
        if(pos2==0){
            for(j=4;j<=n-2;j+=3){
                temp=ask(j,j+1,j+2);

                if(temp!=a[3]){
                    if(ask(j,j+1,1) != a[3]){
                        pos2=j;
                    }
                    else{
                        pos2=j+2;
                    }

                    break;
                }
            }
        }
        ans[pos2] = 1-a[3];

        fo2(i,3,n){
            if(i==pos2){
                continue;
            }
            temp= ask(pos1,pos2,i);
            ans[i]=temp;
        }

    }

    fo2(i,1,n){
        if(ans[i]==0){
            v.pb(i);
        }
    }

    cout<<"! "<<v.size()<<" ";
    fo(i,v.size()){
        cout<<v[i]<<" ";
    }cout<<endl;

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

