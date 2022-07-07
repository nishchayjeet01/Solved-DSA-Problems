class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="")
        return 0;
		
        queue<char> q;
        vector<int> v(256,0);
        int ans = 1, cnt = 0, i=0;
    
        while(i<s.size()){
            if(v[s[i]]==0){ //If new character is visited
            v[s[i]]++; //increment the value for the character
            q.push(s[i]); //add the character into the queue
            cnt++;
            i++;
            }
            
            else{//If repeated character is visited
            ans = max(ans,cnt); //store the cnt if it is maximum
                while(q.front() != s[i]){ //pop the queue until the repeated character is popped
                v[q.front()]--; //decrement the value in the map
                cnt--;
                q.pop();
                }
                v[q.front()]--;  //decrement the value in the map
                cnt--; //decrement the cnt;
                q.pop(); //pop the repeated character also
            }
        }
    
        int size = q.size();
        ans = max(ans,size);
        return ans;
    }
};