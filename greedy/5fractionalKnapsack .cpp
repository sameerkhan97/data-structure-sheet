/*Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item. 

Example 1:
Input: N = 3 , W = 50    ,   values[] = {60,100,120}     ,       weight[] = {10,20,30}
Output: 240.00
Explanation: Total maximum value of item we can have is 240.00 from the given capacity of sack. 

Example 2:
Input: N = 2 , W = 50    ,   values[] = {60,100}         ,       weight[] = {10,20}
Output: 160.00
Explanation: Total maximum value of item we can have is 160.00 from the given capacity of sack. 
*/

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        //making a vector to hold pair of ratio of weughts and values of a index
        vector<pair<double,int>> v(n);
        for(int i=0;i<n;i++){
            v[i].first=(arr[i].value*1.0)/(arr[i].weight*1.0);
            v[i].second=i;
        }
        //sorting the ratio vector in descending order of ratio
        sort(v.begin(),v.end(),greater<pair<double,int>>());
        //to calculate sum weight we can acquire
        int sumW=0;
        //to calculate sum value we can acquire
        double sumval=0;
        for(int i=0;i<n;i++){
            //if the sum of weight for current index doesnt exceed the capacity
            //then add it in sum
            if(sumW+arr[v[i].second].weight<W){
                sumW+=arr[v[i].second].weight;
                sumval+=arr[v[i].second].value;
            }
            //if current weight sum exceed the capacity then caculating how much can we add
            else{
                double x=(W-sumW)*1.0;
                sumval+=x*(v[i].first);
                break;
            }
        }
        return sumval;
    }
};