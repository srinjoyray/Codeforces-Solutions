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

ll merge(int arr[], int temp[], int left, int mid,
          int right)
{
    int i, j, k;
    ll inv_count = 0;
 
    i = left; 
    j = mid; 
    k = left; 
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }
 
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];
 
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}

ll _mergeSort(int arr[], int temp[], int left, int right)
{
    ll mid, inv_count = 0;
    if (right > left) {
        /* Divide the array into two parts and
        call _mergeSortAndCountInv()
        for each of the parts */
        mid = (right + left) / 2;
 
        /* Inversion count will be sum of
        inversions in left-part, right-part
        and number of inversions in merging */
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
 
        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

ll mergeSort(int arr[], int array_size)
{   
    // for(int i=0;i<array_size;i++){
    //     cout<<arr[i]<<" ";
    // }cout<<nl;
    int temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}
 

void solve(){
    int i,j;
    int n,sz;
    cin>>n;
    ll a[n],b[n];
    set<ll> se;
    map<ll,ll> mapp,pref;
    fo(i,n){
        cin>>a[i]>>b[i];
        se.insert(a[i]);
        se.insert(b[i]);
    }
    vl v1;
    int arr[2*n];
    i=0;
    for(auto x : se){
        // deb2(x,i);
        v1.pb(x);
        arr[i]=x;
        mapp[x]=i++;
    }
    sz=i;
    ll curr=0,prev=v1[0]-1;
    fo(i,v1.size()){
        curr+=(v1[i]-prev)-1;
        pref[i]=curr;
        prev=v1[i];
    }
    fo(i,n){
        swap(arr[mapp[a[i]]],arr[mapp[b[i]]]);
    }
    ll pos,count,ans=0;
    fo(i,sz){
        pos=mapp[arr[i]];
        count=abs(pref[i]-pref[pos]);
        ans+=count;
    }
    // deb(ans);
    // fo(i,sz){
    //     cout<<arr[i]<<" ";
    // }cout<<nl;
    count= mergeSort(arr,sz);
    // deb(count);
    ans+=count;
    cout<<ans<<nl;
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
    
}

