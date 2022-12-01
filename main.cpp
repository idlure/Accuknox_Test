
#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<int,pair<set<int>,int>>mp;//mp is log of resturant
    int n;
    cout<<"enter the number of items in food menu"<<endl; //resturant should provide number of items in menu
    cin>>n;
    cout<<"enter the food menu ids"<<endl;
    for(int i=0;i<n;i++)
    {
        int p;
        cin>>p;
        set<int>s;
        mp[p]={s,0};
    }
    //now customer can enter the eater_id and foodmenu_id which will be saved in this logofresturant
   
    cout<<"enter the number of eaters"<<endl;
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int p,f;
        cout<<"enter the eater_id and foodmenu_id"<<endl;
        cin>>p>>f;
        if(mp[f].first.find(p)!=mp[f].first.end())
        cout<<"error same eater with same food";
        else{
            int c=mp[f].second;
            c++;
            set<int> s=mp[f].first;
            s.insert(p);
            mp[f]={s,c};
        }
    }
    // for(auto x:mp)
    // {
    //     cout<<x.second.second<<endl;
    // }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>ans;
    for(auto i:mp)
    {
        if(ans.size()>3 && ans.top().first<i.second.second) // this works if frequency is repeated
        ans.pop();
        else if(ans.size()<3)
        ans.push({i.second.second,i.first});
    }
    //the top 3 food menu ids are(if n >3 else it will return 0's after n ids)
    // if all food items are ordered once then it returns last ordered food items
    for(int i=0;i<min(n,3);i++)
    {
        cout<<ans.top().second<<endl;
        ans.pop();
    }
    return 0;
}
