// { Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	
    int n=s.size();
    vector<int>res(n,0);
    int i=1,len=0;
    while(i<n)
    {
        if(s[i]==s[len])
        {
            len++;
            res[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len=res[len-1];
            }
            else
            {
                res[i]=0;
                i++;
            }
        }
    }
	    return res[n-1];
	}
};

// { Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends