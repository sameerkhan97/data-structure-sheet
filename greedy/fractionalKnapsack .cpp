/*Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item
Example 1:
Input:N = 3, W = 50
values[] = {60,100,120}
weight[] = {10,20,30}
Output: 240.00
Explanation:Total maximum value of item
we can have is 240.00 from the given
capacity of sack. */


bool comp(Item a, Item b) {
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2; 
}
// function to return fractionalweights
double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code here
    
    sort(arr, arr + n, comp); 
    
    int curWeight = 0; 
    double finalvalue = 0.0; 
 
    
    for (int i = 0; i < n; i++) {
       
        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }
 

        else {
            int remain = W - curWeight;
            finalvalue += (arr[i].value / (double)arr[i].weight) * (double)remain;
            break;
        }
    }
 
    return finalvalue;
    
}