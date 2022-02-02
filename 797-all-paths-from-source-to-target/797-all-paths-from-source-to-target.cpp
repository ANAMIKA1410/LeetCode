class Solution {
public:
    void sourceToTarget(vector<vector<int>>&graph, int currentNode,vector<bool>visited,int n , vector<int>&currentPath,vector<vector<int>>&answer){
        if(currentNode == n-1){
            // currentPath.push_back(currentNode);
            answer.push_back(currentPath);
            // currentPath.pop_back();
            return;
        }
        
        if(visited[currentNode] == true){
            return;
        }
        
        visited[currentNode] = true;
        // currentPath.push_back(currentNode);
        
        for(auto neighbour : graph[currentNode]){
            currentPath.push_back(neighbour);
            sourceToTarget(graph,neighbour,visited,n,currentPath,answer);
            currentPath.pop_back();
        }
        
        visited[currentNode] = false;
        // currentPath.pop_back();
        return;
    }
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>answer;
        vector<int>currentPath;
        currentPath.push_back(0);
        int n = graph.size();
        vector<bool> vis(n);
        sourceToTarget(graph,0,vis,n,currentPath,answer);
        return answer;
        }
};