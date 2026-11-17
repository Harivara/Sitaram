## The important difference is that the Fibonacci sequence has a special property (Zeckendorf's theorem) that makes the greedy approach optimal

## When can you use Greedy vs DP?

## Coin system	                           Approach
Fibonacci denominations                  	Greedy
Standard US denominations (1, 5, 10, 25)	Greedy
Arbitrary denominations	                    DP
Unknown coin denominations in interviews	DP is safer


## When to use which?
## Problem	                                              Approach
Divide numbers 1 to N into equal-sum groups	          Greedy / Mathematical
Partition an array into two equal-sum subsets	      Subset Sum DP
Check whether a subset with target sum exists	      Subset Sum DP
Minimum subset sum difference	                      Subset Sum DP
Count subsets with a given sum         	              Subset Sum DP



## Important patterns to recognize
## DP pattern	           Greedy optimization idea
Take / NotTake	             Local optimal selection
Subsequence DP	             Maintain best ending state
Interval DP	                 Sort by ending time
Reachability DP	             Maintain farthest reachable index
State transition DP	         Maintain only necessary states
