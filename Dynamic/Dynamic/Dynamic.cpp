// Dynamic.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>
using namespace std;

int lis(int A[], int n){
    int *d = new int[n];
    int len = 1;
    for(int i=0; i<n; ++i){
        d[i] = 1;
        for(int j=0; j<i; ++j)
            if(A[j]<=A[i] && d[j]+1>d[i])
                d[i] = d[j] + 1;
        if(d[i]>len) 
            len = d[i];
    }
    delete[] d;
    return len;
}

class Solution {
public:
    string longestPalindrome1(string s) {
       int len = s.length(), max = 1, ss = 0, tt = 0;
       bool flag[100][100]={0};
        for (int i = 0; i < len; i++)
           for (int j = 0; j < len; j++)
                if (i >= j)
                    flag[i][j] = true;
               else
                   flag[i][j] = false;
       for (int j = 1; j < len; j++)
             for (int i = 0; i < j; i++)
             {
                 if (s[i] == s[j])
                 {
                     flag[i][j] = flag[i+1][j-1];
                     if (flag[i][j] == true && j - i + 1 > max)
                     {
                         max = j - i + 1;
                         ss = i;
                         tt = j;
                     }
                 }
                 else flag[i][j] = false;
             }
         return s.substr(ss, max);
     }

    string longestPalindrome(string s) {
        const char*ps = s.c_str();
        int size=s.size();
        string result;
        int maxlen=0;
        for(int i = 0; i < size; ++i)
        {
            for(int j = size-1; j >= i; --j)
            {
                if(isPalindromic(ps, j - i + 1))
                {
                    if(maxlen < (j - i + 1))
                    {
                        maxlen = (j - i + 1);
                        result.assign((char *)ps+i, maxlen);
                    }
                }
            }
        }
        return result;
    }
    
    bool isPalindromic(const char*pc, int size)
    {
        int begin = 0;
        int end = size - 1;
        if(size <=1)
            return true;
        while(begin < end)
        {
            if(pc[begin] != pc[end])
            {
                return false;
            }
            begin++;
            end--;
        }
    }
};

int main(int argc, _TCHAR* argv[])
{
	Solution su;
    string s = "cabba";
    su.longestPalindrome1(s);

    return 0;
}