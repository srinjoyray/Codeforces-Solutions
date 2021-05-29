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
ll merge(ll arr[],ll temp[],ll left,ll mid,ll right){
    ll i,j,k,inv_count=0;
    i=left;
    j=mid;
    k=left;
    while(i<=mid-1 && j<=right){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
            inv_count+=(mid-i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++]; 
    for(i=left;i<=right;i++){
        arr[i]=temp[i];
    }       
    return inv_count;
}
ll merge_sort(ll arr[],ll temp[],ll left,ll right){
    ll mid,inv_count=0;
    if(right>left){
        mid=(right+left)/2;
        inv_count+=merge_sort(arr,temp,left,mid);
        inv_count+=merge_sort(arr,temp,mid+1,right);

        inv_count+=merge(arr,temp,left,mid+1,right);
    }
    return inv_count;
}
ll check(ll arr[],ll n){
    ll temp[n];
    return merge_sort(arr,temp,0,n-1);
}

void solve(){
    int i,j;
    string s,rotate="ANOT",temp,ans;
    cin>>s;
    map<char,int> freq,mapp;
    char ch;
    ll mx=0,val,arr[s.size()];
    fo(i,s.size()){
        ch=s[i];
        freq[ch]++;
    }

    do{ 
        // deb(rotate);
        temp="";
        mapp[rotate[0]]=1;
        mapp[rotate[1]]=2;
        mapp[rotate[2]]=3;
        mapp[rotate[3]]=4;
        fo(i,4){
            ch=rotate[i];
            fo(j,freq[ch]){
                temp.pb(ch);
            }
        }
        // deb2(rotate,temp);
        fo(i,s.size()){
            ch=s[i];
            arr[i]=mapp[ch];
            
        }
        
        if(temp=="NNOTA"){
            // deb2(rotate,temp);
            // deb(s);
            // deb2(mapp['A'],mapp['N']);
            // deb2(mapp['O'],mapp['T']);
            
            // fo(i,s.size()){
            //     cout<<arr[i]<<" ";
            // }
        }
        val=check(arr,s.size());
        
        // deb2(temp,val);
        if(val>=mx){
            ans=temp;
            mx=val;
        }
    }while(next_permutation(all(rotate)));

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

