class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int n=points.size();
        for(int i=0;i<n;i++){
            int x1=points[i][0];
            int y1=points[i][1];
            // int x2=points[i+1][0];
            // int y2=points[i+1][1];
            int dist=((x1-0)*(x1-0)+(y1-0)*(y1-0));
            pq.push({dist,{x1,y1}});
        }
        vector<vector<int>>ans;
        vector<int>temp;
        while(k!=0 and pq.empty()==false){
            int a=pq.top().second.first;
            int b=pq.top().second.second;
            temp.push_back(a);
            temp.push_back(b);
            pq.pop();
            ans.push_back(temp);
            temp.clear();
            k--;
        }
        return ans;
    }
};