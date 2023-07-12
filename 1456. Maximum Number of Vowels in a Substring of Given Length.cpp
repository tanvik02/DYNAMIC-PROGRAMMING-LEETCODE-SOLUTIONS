/*
Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= s.length
*/

Solution:

class Solution {
public:

    bool isVowel( char c ){
        if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ) return true;
        return false;
    }

    int maxVowels(string s, int k) {
        
        int maxi = 0;
        int tmp = 0;

        // count the number of vowels in first k size window 
        for( int i=0 ; i<k ; i++ ){
            if( isVowel(s[i])) tmp++;
        }

        maxi = max( maxi, tmp );

        // add one character and remove one character from the window 
        // if the removed character is vowel -1 from the vowel count 
        // if the added character is vowel +1 in the vowel count 
        for( int i=k ; i<s.size() ; i++ ){

            if( isVowel(s[i-k]) ) tmp -= 1;

            if( tmp < 0 ) tmp = 0;

            if( isVowel(s[i]) ) tmp += 1;

            maxi = max( maxi, tmp );
        }

        return maxi;
    }
};

