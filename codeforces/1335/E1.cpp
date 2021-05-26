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
    int i,j,x;
    int n;
    cin>>n;
    int a[n],temp,l,r;
    fo(i,n){
        cin>>a[i];
    }
    int pref[201][n+1],freq[201]={0};
    int copy_freq[201]={0},ans=1;
    memset(pref,0,sizeof(pref));
    multiset<int,greater<int>> se,copy_se;
    multiset<int>::iterator itr;
    fo2(i,1,n){
        temp=a[i-1];
        fo2(j,1,200){
            pref[j][i]=pref[j][i-1];
            if(temp==j){
                pref[j][i]++;
            }
        }
        freq[temp]++;
    }
    temp=0;
    fo2(i,1,200){
        if(freq[i]>0){
            se.insert(freq[i]);
        }
        temp=max(temp,freq[i]);
    }
    ans=temp;
    fo2(i,1,200){
        copy_freq[i]=freq[i];
    }
    copy_se=se;
    
    fo2(x,1,200){
        // deb(x);
        fo2(i,1,200){
            freq[i]=copy_freq[i];
        }
        set<int> left;
        set<int,greater<int>>right;
        int start,end,count;
        fo(i,n){
            if(a[i]==x){
                left.insert(i);
                right.insert(i);
            }
        }
        i=0;
        j=n-1;
        count=0;
        se=copy_se;
        if(left.size()<=1){
            continue;
        }
        while(i<j){
            start=*left.begin();
            end=*right.begin();
            left.erase(left.begin());
            right.erase(right.begin());
            if(start>=end){
                break;
            }
            count++;
            // for(itr=se.begin();itr!=se.end();itr++){
            //     cout<<(*itr)<<"#";
            // }cout<<nl;
            while(i<=start){
                temp=freq[a[i]];
                // deb2(temp,i);
                se.erase(se.lower_bound(temp));
                se.insert(temp-1);
                freq[a[i]]--;
                i++;
            }
            // for(itr=se.begin();itr!=se.end();itr++){
            //     cout<<(*itr)<<"@";
            // }cout<<nl;
            while(j>=end){
                temp=freq[a[j]];
                // deb2(temp,j);
                se.erase(se.lower_bound(temp));
                se.insert(temp-1);
                freq[a[j]]--;
                j--;
            }
            // for(itr=se.begin();itr!=se.end();itr++){
            //     cout<<(*itr)<<"*";
            // }cout<<nl;
            // deb2(start,end);
            // deb2(i,j);
            // deb(count);
            temp=2*count+(*se.begin());
            ans=max(ans,temp);
        }    
            
    }
    cout<<ans<<nl;
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

