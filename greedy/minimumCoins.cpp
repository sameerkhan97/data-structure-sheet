void findMin(int V)
{
    int deno[]={1,2,5,10,20,50 ,100,500,1000 };
    int n=9;
    vector<int> ans;
    for(int n=n-1;i>=0;i--)
    {
        //find denomination
        while(V>=deno[i])
        {
            V=V-deno[i];
            ans.push_back(deno[i]);
        }
    }
    for(int i=0;i<ans.size();i++)
        cout<<an[i]<<" ";
}