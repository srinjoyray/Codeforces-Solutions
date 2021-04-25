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
bool comp1(pl a, pl b){
    if(a.F==b.F){
        return a.S<b.S;
    }
    return a.F<b.F;
}
bool comp2(pl a,pl b){
    if(a.F==b.F){
        return a.S<b.S;
    }
    return a.F>b.F;
}
bool comp3(pl a,pl b){
    if(a.F==b.F){
        return a.S>b.S;
    }
    return a.F>b.F;
}
bool comp4(pl a,pl b){
    if(a.F==b.F){
        return a.S>b.S;
    }
    return a.F<b.F;
}
void solve(){
    int i,j;
    int n;
    vpl v1,v2,v3,v4;
    lli x,y,ans,dist;
    string temp_s,ch;
    cin>>n;
    ans=2*n;
    fo(i,n){
        cin>>x>>y;
        dist=0;
        if(abs(x)>0){
            dist++;
        }
        if(abs(y)>0){
            dist++;
        }
        ans+=2*dist;
        if(x>=0 && y>=0){
            v1.pb({x,y});
        }
        else if(x<0 && y>=0){
            v2.pb({x,y});
        }
        else if(x<=0 && y<0){
            v3.pb({x,y});
        }
        else{
            v4.pb({x,y});
        }
        
    }
    cout<<ans<<nl;
    sort(all(v1),comp1);
    sort(all(v2),comp2);
    sort(all(v3),comp3);
    sort(all(v4),comp4);
    fo(i,v1.size()){
        x=v1[i].F;
        y=v1[i].S;
        if(x>0){
            ch=to_string(x);
            temp_s="1 ";
            temp_s+=ch;
            temp_s+=" R";
            cout<<temp_s<<nl;  
        }
        if(y>0){
            ch=to_string(y);
            temp_s="1 ";
            temp_s+=ch;
            temp_s+=" U";
            cout<<temp_s<<nl;
           
        }
        cout<<"2\n";
        if(x>0){
            ch=to_string(x);
            temp_s="1 ";
            temp_s+=ch;
            temp_s+=" L";
            cout<<temp_s<<nl;
        }
        if(y>0){
            ch=to_string(y);
            temp_s="1 ";
            temp_s+=ch;
            temp_s+=" D";
            cout<<temp_s<<nl;
        }
        cout<<"3\n";
    }
    fo(i,v2.size()){
        x=abs(v2[i].F);
        y=abs(v2[i].S);
        if(x>0){
            ch=to_string(x);
            temp_s="1 ";
            temp_s+=ch;
            temp_s+=" L";
            cout<<temp_s<<nl;  
        }
        if(y>0){
            ch=to_string(y);
            temp_s="1 ";
            temp_s+=ch;
            temp_s+=" U";
            cout<<temp_s<<nl;
           
        }
        cout<<"2\n";
        if(x>0){
            ch=to_string(x);
            temp_s="1 ";
            temp_s+=ch;
            temp_s+=" R";
            cout<<temp_s<<nl;
        }
        if(y>0){
            ch=to_string(y);
            temp_s="1 ";
            temp_s+=ch;
            temp_s+=" D";
            cout<<temp_s<<nl;
        }
        cout<<"3\n";
    }
    fo(i,v3.size()){
        x=abs(v3[i].F);
        y=abs(v3[i].S);
        if(x>0){
            ch=to_string(x);
            temp_s="1 ";
            temp_s+=ch;
            temp_s+=" L";
            cout<<temp_s<<nl;  
        }
        if(y>0){
            ch=to_string(y);
            temp_s="1 ";
            temp_s+=ch;
            temp_s+=" D";
            cout<<temp_s<<nl;
           
        }
        cout<<"2\n";
        if(x>0){
            ch=to_string(x);
            temp_s="1 ";
            temp_s+=ch;
            temp_s+=" R";
            cout<<temp_s<<nl;
        }
        if(y>0){
            ch=to_string(y);
            temp_s="1 ";
            temp_s+=ch;
            temp_s+=" U";
            cout<<temp_s<<nl;
        }
        cout<<"3\n";
    }
    fo(i,v4.size()){
        x=abs(v4[i].F);
        y=abs(v4[i].S);
        if(x>0){
            ch=to_string(x);
            temp_s="1 ";
            temp_s+=ch;
            temp_s+=" R";
            cout<<temp_s<<nl;  
        }
        if(y>0){
            ch=to_string(y);
            temp_s="1 ";
            temp_s+=ch;
            temp_s+=" D";
            cout<<temp_s<<nl;
           
        }
        cout<<"2\n";
        if(x>0){
            ch=to_string(x);
            temp_s="1 ";
            temp_s+=ch;
            temp_s+=" L";
            cout<<temp_s<<nl;
        }
        if(y>0){
            ch=to_string(y);
            temp_s="1 ";
            temp_s+=ch;
            temp_s+=" U";
            cout<<temp_s<<nl;
        }
        cout<<"3\n";
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

