#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int >v;
    
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            v.push_back(i);
            break;
        }
        

    }
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            int j=i+1;
            if(arr[j]==x){
                j++;
                
            }
            else{
                v.push_back(j-1);
            }
        }
        
    }
    if(v.size()==0){
        return {-1,-1};
    }

        
    return v;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends