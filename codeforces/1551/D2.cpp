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
pair<char,char> find(set<char> se){
    int i=0;
    set<char> s;
    pair<char,char> p;
    fo(i,26){
        if(se.find('a'+i)==se.end()){
            s.insert('a'+i);
        }
    }
    p.F=*s.begin();
    p.S=*s.rbegin();
    return p;
}
void print (char a[500][500],int n,int m){
    int i,j;
    for(i=0;i<n-1;i+=2){
        for(j=0;j<m-1;j+=2){
            set<char> se;
            if(j>0){
                se.insert(a[i][j-1]);
                se.insert(a[i+1][j-1]);
            }
            if(i>0){
                se.insert(a[i-1][j]);
                se.insert(a[i-1][j+1]);
            }
            pair<char,char> p=find(se);
            if(a[i][j]=='H'){
                a[i][j]=p.F;
                a[i][j+1]=p.F;
                a[i+1][j]=p.S;
                a[i+1][j+1]=p.S;
            }
            else{
                a[i][j]=p.F;
                a[i+1][j]=p.F;
                a[i][j+1]=p.S;
                a[i+1][j+1]=p.S;
            }
        }
    }
    if(n%2==1){
        for(j=0;j<m-1;j+=2){
            set<char> se;
            if(n>1){
                se.insert(a[n-2][j]);
                se.insert(a[n-2][j+1]);
            }
            if(j>0){
                se.insert(a[n-1][j-1]);
            }
            pair<char,char> p=find(se);
            a[n-1][j]=p.F;
            a[n-1][j+1]=p.F;
        }
    }

    if(m%2==1){
        for(i=0;i<n-1;i+=2){
            set<char> se;
            if(m>1){
                se.insert(a[i][m-2]);
                se.insert(a[i+1][m-2]);
            }
            if(i>0){
                se.insert(a[i-1][m-1]);
            }
            pair<char,char> p=find(se);
            a[i][m-1]=p.F;
            a[i+1][m-1]=p.F;
        }
    }

    // fo(i,n){
    //     fo(j,m){
    //         cout<<a[i][j];
    //     }
    //     cout<<nl;
    // }
}

void solve(){
    int i,j;
    int n,m,k,hor,vert;
    cin>>n>>m>>k;
    hor=k;
    vert=(m*n)/2-k;
    if(n%2==1){
        hor-=m/2;
    }
    if(m%2==1){
        vert-=n/2;
    }
    if(hor>=0 && vert>=0 && hor%2==0 && vert%2==0){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
        return ;
    }

    hor=k;
    vert=(m*n)/2-k;

    char a[500][500];
    char ch1='a',ch2='a'+13;
    fo(i,n){
        fo(j,m){
            a[i][j]='V';
        }
    }
    if(n%2==1){
        fo(j,m){
            a[n-1][j]='H';
        }
        hor-=m/2;
    }
    if(m%2==1){
        fo(i,n){
            a[i][m-1]='V';
        }
        vert-=n/2;
    }

    for(i=0;i<n-1;i+=2){
        if(hor==0){
            break;
        }
        for(j=0;j<m-1;j+=2){
            if(hor==0){
                break;
            }
            a[i][j]='H';
            a[i][j+1]='H';
            a[i+1][j]='H';
            a[i+1][j+1]='H';
            hor-=2;
        }
    }
    print(a,n,m);
    fo(i,n){
        fo(j,m){
            cout<<a[i][j];
        }cout<<nl;
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
    
}

