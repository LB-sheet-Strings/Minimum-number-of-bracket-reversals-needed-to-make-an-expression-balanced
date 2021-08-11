/*
efficient solution solve the problem in O(1) i.e. constant space. Since the expression only contains one 
type of brackets, the idea is to maintain two variables to keep count of left bracket as well as right bracket 
as we did in Length of the longest valid substring. If the expression has balanced brackets, then we decrement 
left variable else we increment right variable.Then all we need to return is ceil(left/2) + ceil(right/2).

Time Complexity: O(n) 

Auxiliary Space: O(1)

DRY RUN:

left bracket count=LC
Right bracket count=RC

   }{{}}{{{  
      
LC 


*/

#include<bits/stdc++.h>
using namespace std;

int countMinReversals(string expr)
{
	int len = expr.length();
   
    // Expressions of odd lengths cannot be balanced.Ekhaad bracket jyada hoga usme
    if (len % 2 != 0) 
	{
        return -1;
	}
	
	int left_brace = 0, right_brace = 0;
    int ans;
    
    for (int i = 0; i < len; i++)
    {
    	if (expr[i]=='{') 
		{
            left_brace++;
        }
	}
	// Else if left bracket is 0 then we find
        // unbalanced right bracket and increment
        // right bracket or if the expression
        // is balanced then we decrement left
        else {
            if (left_brace == 0) {
                right_brace++;
            }
            else {
                left_brace--;
            }
        }
    }
    ans = ceil(left_brace / 2.0) + ceil(right_brace / 2.0);
    return ans;
	
}

//Driver program to test above function
int main()
{
   string expr = "}}{{";
   cout << countMinReversals(expr);
   return 0;
}
