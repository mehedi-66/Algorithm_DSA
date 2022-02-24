/*
    palindrome

    if simple and reverse is same order then

 */

 #include<bits/stdc++.h>
 using namespace std;


 // it takes extra space O(n)
 // time O(n)
 int isPalindrome(string s)
 {
     string rev = s;

     int start = 0;
     int end = s.size() - 1;

     while(start <= end)
     {
         swap(rev[start++], rev[end--]);
     }

     for(int i = 0; i < s.size(); i++)
     {
         if(s[i] != rev[i])
         {
             return false;
         }
     }

     return true;
 }

 // Approach 2 not take extra space ...

 int isPalindromeApproach2(string s)
 {
     int start = 0;
     int end = s.size() - 1;

     while(start <= end)
     {
         if(s[start] != s[end])
         {
             return false;
         }
         start++;
         end--;
     }

     return true;
 }


 int main()
 {
    string s = "abaaba";
    // output: false / 0
    cout << isPalindrome(s) << endl;

    cout << "Without Extra space: " << isPalindromeApproach2(s) << endl;

    return 0;
 }
