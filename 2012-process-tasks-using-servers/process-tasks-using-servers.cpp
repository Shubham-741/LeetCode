class Solution {
public:

    typedef pair<int,int>P;
    typedef tuple<long, int,int>T;

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        int n = servers.size();
        int m = tasks.size();

        priority_queue<P, vector<P>, greater<P>>free; // {wt,idx}
        priority_queue<T, vector<T>, greater<T>>busy; // {finTime, wt, idx}

        for(int i = 0; i<n; i++){
            free.push({servers[i], i});
        }

        vector<int>result(m);


        for(int i = 0; i<m; i++){

            while(!busy.empty() && get<0>(busy.top()) <= i){
                auto [finTime, wt, idx] = busy.top();
                busy.pop();
                free.push({wt,idx});
            }

            if(free.empty()){
                auto[finTime, wt, idx] = busy.top();
                busy.pop();
                result[i] = idx;
                busy.push({finTime+tasks[i], wt, idx});
            }
            else{
                auto[wt, idx] = free.top();
                free.pop();
                result[i] = idx;
                busy.push({i+tasks[i], wt, idx});
            }
        }

        return result;
        
    }
};