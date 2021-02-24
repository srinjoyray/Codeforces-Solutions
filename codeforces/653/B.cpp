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
#define tr(it,a) for(auto it=a.begin(); it!=a.end();it++)
#define nl '\n'
#define PI 3.141592653589793238
#define mod 1e9+7
map<string,string>m;
bool check(string s){
    string temp;
    // deb(s);
    while(s.size()>1){
        temp=s[0];
        temp+=s[1];
        if(m[temp][0]>='a' && m[temp][0]<='f'){
            s.erase(0,2);
            s=m[temp]+s;
        }
        else{
            break;
        }
    }
    if(s.size()==1 && s[0]=='a'){
        return true;
    }
    return false;
}
void solve(){
    int i,j;
    int n,q,a,b,c,d,e,f,count=0;
    cin>>n>>q;
    
    string s1,s2,temp;
    char ch;
    while(q--){
        cin>>s1>>s2;
        m[s1]=s2;
    }
    
    fo(i,n){
        fo(j,6){

        }
    }

    fo2(a,0,n){
        fo2(b,0,n){
             fo2(c,0,n){
                  fo2(d,0,n){
                       fo2(e,0,n){
                            fo2(f,0,n){
                                if((a+b+c+d+e+f)!=n){
                                    continue;
                                }
                                temp="";
                                for(i=1;i<=a;i++){
                                    temp+='a';
                                }
                                for(i=1;i<=b;i++){
                                    temp+='b';
                                }
                                for(i=1;i<=c;i++){
                                    temp+='c';
                                }
                                for(i=1;i<=d;i++){
                                    temp+='d';
                                }
                                for(i=1;i<=e;i++){
                                    temp+='e';
                                }
                                for(i=1;i<=f;i++){
                                    temp+='f';
                                }
                                do{
                                    if(check(temp)){
                                        count++;
                                        // deb(temp);
                                    }
                                }while(next_permutation(temp.begin(), temp.end())); 
                                
                            }
                       }
                  }
             }
        }
    }
    cout<<count<<endl;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

