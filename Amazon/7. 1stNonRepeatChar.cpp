#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    queue<char>q;
    vector<int>repeat(26,-1);
    string s="";
    for(int i=0;i<A.length();i++){
          
            if(repeat[A[i]-97]==-1){
              q.push(A[i]);
              repeat[A[i]-97]++;
              
            }else{
              if(!q.empty() && A[i]==q.front()){
                q.pop();
              }
               repeat[A[i]-97]++;
            
            while(!q.empty() && repeat[q.front()-97]>0){
             q.pop();   
            }
            }
             if(q.empty()){
               s+="#";
             }else{
               s+=q.front();
             }
            
       }
     return s;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
} 
