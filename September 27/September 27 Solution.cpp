class Solution {
public:
    double dfs(unordered_map<string, vector<pair<string, double>>>& graph, string &curr, string& target, unordered_map<string, int>& seen, double res)
    {
        if(curr == target)
            return res;

        for(int i = 0; i < graph[curr].size(); i++)
        {
            string node = graph[curr][i].first;
            double val = graph[curr][i].second * res;
            if(seen[node])
                continue;

            seen[node] = 1;
            double res = dfs(graph, node, target, seen, val);
            seen[node] = 0;
            if(res != -1)
                return res;
        }

        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        unordered_map<string, vector<pair<string, double>>> graph;
        for(int i = 0; i < equations.size(); i++)
        {
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }

        unordered_map<string, int> seen;
        vector<double> res;
        for(int i = 0; i < queries.size(); i++)
        {
            string &a = queries[i][0], &b = queries[i][1];

            if(graph.count(a) == 0 || graph.count(b) == 0)
                res.push_back(-1);
            else
                res.push_back(dfs(graph, a, b, seen, 1.0));
        }
        return res;
    }
};
