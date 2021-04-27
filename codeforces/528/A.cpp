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
vector<lli> getMaxArea(lli w, lli h, vector<bool> isVertical, vector<lli> distance) {
    lli remove,temp,left,right;
    vector<lli> ans;
    set<lli> x,y;
    multiset<lli> x_all,y_all;
    set<lli>::iterator it;
    multiset<lli>::iterator itr;
    x.insert(0);
    x.insert(w);
    y.insert(0);
    y.insert(h);
    x_all.insert(w);
    y_all.insert(h);
    
    for(int i=0;i<isVertical.size();i++){
        if(isVertical[i]==1){
            it= x.lower_bound(distance[i]);
            right=*it;
            it--;
            left=*it;
            remove=right-left;
            itr=x_all.find(remove);
            x_all.erase(itr);
            x_all.insert(right-distance[i]);
            x_all.insert(distance[i]-left);
            x.insert(distance[i]);
        }
        else{
            it= y.lower_bound(distance[i]);
            right=*it;
            it--;
            left=*it;
            remove=right-left;
            itr=y_all.find(remove);
            y_all.erase(itr);
            y_all.insert(right-distance[i]);
            y_all.insert(distance[i]-left);
            y.insert(distance[i]);
        }
        temp=(*x_all.rbegin()) * (*y_all.rbegin());
        ans.push_back(temp);
        // deb(temp);
    }
    return ans;
}

void solve(){
    int i,j;
    lli w,h,n;
    cin>>w>>h>>n;
    vector<bool> flag;
    vector<lli> dist;
    lli temp;
    char ch;
    vector<lli> ans;
    fo(i,n){
        cin>>ch>>temp;
        dist.pb(temp);
        if(ch=='V'){
            flag.pb(true);
        }
        else{
            flag.pb(false);
        }
    }
    ans=getMaxArea(w,h,flag,dist);
    fo(i,ans.size()){
        cout<<ans[i]<<nl;
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

