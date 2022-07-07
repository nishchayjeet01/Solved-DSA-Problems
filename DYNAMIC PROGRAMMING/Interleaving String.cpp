class Solution {
public:
    int dp[105][105];
    bool f(string &s1,string &s2,string &s3,int i,int j,int k){
        int n=s1.length();
        int m=s2.length();
        int nm = s3.length();
        if(k==nm) return true;
        if(dp[i][j]>=0) return dp[i][j];
        if(i<n and j<m){
            if(s1[i]==s3[k] and s2[j]==s3[k]){
                return dp[i][j] = f(s1,s2,s3,i+1,j,k+1) or f(s1,s2,s3,i,j+1,k+1); 
            }else if(s1[i]==s3[k]){
                return dp[i][j] = f(s1,s2,s3,i+1,j,k+1);
            }else if(s2[j]==s3[k]){
                return dp[i][j] = f(s1,s2,s3,i,j+1,k+1); 
            }else return dp[i][j] = false;
        }else if(i<n){
            if(s1[i]==s3[k]){
                return dp[i][j] = f(s1,s2,s3,i+1,j,k+1);
            }
            return dp[i][j] = false;
        }else if(j<m){
            if(s2[j]==s3[k]){
                return dp[i][j] = f(s1,s2,s3,i,j+1,k+1); 
            }
            return dp[i][j] = false;
        }
        return dp[i][j] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length();
        int m=s2.length();
        int nm = s3.length();
        if(n+m!=nm) return false;
        memset(dp,-1,sizeof dp);
        return f(s1,s2,s3,0,0,0);
    }
};