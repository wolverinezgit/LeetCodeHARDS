class Solution {
public:

int recur(int i,string &s,int k,vector<int> &dp,vector<vector<int>> &palin)
{

    if(i==s.size()||s.size()-i<k)
    return 0;
    int maxi=0;
    if(dp[i]!=-1)
    return dp[i];
    for(int j=i;j<s.size();j++)
    {
        if(j-i+1>=k)
        {
            if(palin[i][j])
             maxi=max(maxi,1+recur(j+1,s,k,dp,palin));
            
        }
        
              maxi=max(maxi,recur(j+1,s,k,dp,palin));
       
    }
    return dp[i]=maxi;

}
    int maxPalindromes(string s, int k) {
        int ans=0;
vector<int> dp(s.size(),-1);
int n=s.size();
vector<vector<int>> palin(s.size(),vector<int> (s.size(),0));
for(int i=0;i<s.size();i++)
{
    palin[i][i]=1;
    int z1=i-1,z2=i+1;
    int ok=1;
    while(z1>=0&&z2<n)
    {
        if(s[z1]==s[z2])
        {
            palin[z1][z2]=ok;
        }
        else
        {
            ok=0;
            palin[z1][z2]=ok;
            break;
        }
        z1--;
        z2++;
    }
    if(i+1<n)
    {
        int z1=i,z2=i+1;
        int ok=1;
        while(z1>=0&&z2<n)
        {
            if(s[z1]==s[z2])
            {
                palin[z1][z2]=ok;
            }
            else
            {
                ok=0;
                palin[z1][z2]=ok;
                
            }
            z1--;
            z2++;
        }
    }
}

for(int i=0;i<s.size();i++)
{
ans=max(ans,recur(i,s,k,dp,palin));
}

    return ans;    
    }
};
