#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{
    int count=1, n=src.size();
    string ans="";
    ans+=src[0];
    for(int i=0;i<n;i++)
    {
          if(src[i]==src[i+1])
          {
              count++;
          }
          else
          {
              ans+=to_string(count);
              count=1;
              ans+=src[i+1];
          }
    }
    return ans;
} 
