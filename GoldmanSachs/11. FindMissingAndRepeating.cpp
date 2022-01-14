#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code hereint *res=new int[2];
       sort(arr,arr+n);
       int x;
       int y;
       for(int i=0;i<n;i++){
           if(arr[i]==arr[i+1]){
               x=arr[i];
           }
           if (binary_search(arr, arr + n, i+1)){
                continue;
            }else{
                y=i+1;
            }
       }
      int *ans = new int[2];
      ans[0] = x;
      ans[1] = y;
      return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
