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
    int n,x;
    cin>>n>>x;
    lli a[n],sa[n],b[n],val,pos,ans=INT64_MAX,count,temp,store_x;
    bool flag=true;
    fo(i,n){
        cin>>a[i];
        sa[i]=a[i];
    }
    fo2(i,1,n-1){
        if(a[i]<a[i-1]){
            flag=false;
            break;
        }
    }
    if(flag){
        cout<<"0\n";
        return;
    }
    store_x=x;
    /*sort(b,b+n);
    if(b[n-1]>x){
        b[n-1]=x;
        sort(b,b+n);
    }
    else{
        cout<<"-1\n";
        return;
    }*/
    fo(i,n){
        // deb2(a[i],b[i]);
    }
    fo(j,n){
        // deb2(a[j],store_x);
        fo(i,n){
            a[i]=sa[i];
        }
        if(a[j]<=store_x){
            continue;
        }
        fo(i,n){
            if(i==j){
                b[i]=store_x;
            }
            else{
                b[i]=a[i];
            }
        }
        sort(b,b+n);
        x=store_x;
        flag=false;
        count=0;
        if(j==2){
            fo(i,n){
                // deb2(a[i],b[i]);
            }
        }
        fo(i,n){
            if(a[i]==b[i]){
                continue;
            }
            val=b[i];
            if(val>a[i]){
                flag=true;
                break;
            }
            // if(j==2){
            //     deb2(val,x);
            // }
            if(val==x){
                // deb(a[i]);
                x=a[i];
                a[i]=val;
                count++;
                // deb(x);
                continue;
            }
            if(val<x){
                flag=true;
                break;
            }
            pos=find(a+i,a+n,val)-a;
            temp=a[i];
            a[i]=a[pos];
            a[pos]=x;
            x=temp;
            count+=2;
        }
        // deb(flag);
        // deb2(j,count);
        if(flag==false){
            ans=min(ans,count);
        }
    }
    /*fo(i,n){
        if(a[i]==b[i]){
            continue;
        }
        val=b[i];
        if(val==x){
            x=a[i];
            a[i]=val;
            ans++;
            continue;
        }
        if(val<x){
            flag=true;
            break;
        }
        pos=find(a+i,a+n,val)-a;
        temp=a[i];
        a[i]=a[pos];
        a[pos]=x;
        x=temp;
        ans+=2;
    }*/
    if(ans==INT64_MAX){
        cout<<"-1\n";
        return;
    }
    else{
        cout<<ans<<nl;
    }

    
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

