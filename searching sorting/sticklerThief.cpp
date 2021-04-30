/*Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule 
  when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount
  he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your
  help to find the maximum money he can get if he strictly follows the rule. Each house has a[i] amount of money present in it.

Example 1:
Input: n = 6    a[] = {5,5,10,100,10,5}
Output: 110
Explanation: 5+100+5=110

Example 2:
Input: n = 3    a[] = {1,2,3}
Output: 4
Explanation: 1+3=4      */

class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    ll FindMaxSum(ll arr[], ll n)
    {
        ll sum1 = arr[0];
        ll sum2 = 0;
        ll result;
        for (int i = 1; i < n; i++){
            result = (sum1 > sum2) ? sum1 : sum2;
            sum1 = sum2 + arr[i];
            sum2 = result;
        }
        return ((sum1 > sum2) ? sum1 : sum2);
    }
};