Khaled has an array A of N elements. It is guaranteed that N is even. He wants to choose at most N/2 elements from array A. It is not necessary to choose consecutive elements.  Khaled is interested in XOR of all the elements he chooses. Here, XOR denotes the bitwise XOR operation. 

   For example:

If A=[2,4,6,8], then khaled can choose the subset [2,4,8] to achieve XOR=(2 XOR 4 XOR 8)=14.
Khaled wants to maximize the XOR of all the elements he chooses. Your task is to help khaled to find the max XOR of a subset that he can achieve by choosing at most N/2 elements?

   Input format:

The first line contains an integer, N, denoting the number of elements in A.
Each line i of the N subsequent lines(where 0<=i<=N) contains an integer describing Ai.
   Constraints 

1<=N<=120
1<=A[i]<=10^6

#include<bits/stdc++.h>
using namespace std;

int main ()
{
  int n;
  cin >> n;
  
  int arr[n];
  
  for (int i = 0; i < n; i++) cin >> arr[i];
  
  int M = 1 << 20;
  int dp[M];
  char res[M];
  
  for (int i = 1; i < M; i++)
    dp[i] = INT_MAX;
  
  for (int i = 0; i < n; i++)
    {
      if (arr[i] == 0)
	   continue;
      
      for (int j = 0; j < M; j++)
	    res[j] = 0;
      
      for (int k = 0; k < M; k++) { if (res[k] == 1) continue; if (dp[k] > dp[k ^ arr[i]])
	       dp[k] = dp[k ^ arr[i]] + 1;
	  
         else if (dp[k ^ arr[i]] > dp[k])
	       dp[k ^ arr[i]] = dp[k] + 1;
	     
	     res[k ^ arr[i]] = 1;
	      
	  }
    }
  
 int j = M - 1, k = n >> 1;
  
  while (dp[j] > k)
    j--;
  
  cout << j;
  
  return 0;

}
