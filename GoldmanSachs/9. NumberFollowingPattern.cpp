#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        string x = "";
        int i=0,j=0;
        int count=1;
        while(i<=S.size()){
            if(S[i]=='I' || i==S.size()){
                while(count>=1){
                    if(count<=j) break;
                    char ch = count + '0';
                    x.push_back(ch);
                    count--;
                }
                j = i+1;
                count = i+1;
            }
            count++;
            i++;
        }
        return x;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
