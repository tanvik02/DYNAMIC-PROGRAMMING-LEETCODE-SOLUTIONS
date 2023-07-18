/*
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
 

Constraints:

2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0
*/
Solution:
class Solution {
public:
    
	// if 2 consecutive asteroids are of same parity, they will keep moving in same direction without collision
    bool sameParity(int a, int b){
        if((a<0 && b<0) || (a>0 && b>0)) return true;
        return false;
    }
    
    vector<int> asteroidCollision(vector<int>& v) {
        int n=v.size();
        
        stack<int> st;
        
        for(int i=0;i<n;i++){
            if(st.size()==0 || sameParity(st.top(),v[i]) || (st.top()<0 && v[i]>0)){
                st.push(v[i]); // no collision
            }else{
                while(st.size()>0 && st.top()>0 && st.top() < abs(v[i])) st.pop(); // currect asteroid destroying existing
                
                if(st.size()==0 || st.top()<0){
                    st.push(v[i]);
                }else if(st.top() == abs(v[i])){
                    st.pop(); 
                }
            }
        }
        
        vector<int> ans;
        while(st.size()>0){
            int x=st.top();
            ans.push_back(x);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
