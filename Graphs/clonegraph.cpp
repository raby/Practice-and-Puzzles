/*

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    
    map<UndirectedGraphNode*,UndirectedGraphNode*> isInGraph;
    map<UndirectedGraphNode*,short> visited;
    stack<UndirectedGraphNode*> s;
    
    isInGraph.clear();
    visited.clear();
    
    UndirectedGraphNode* root = new UndirectedGraphNode(node->label);
    isInGraph[node] = root;
    s.push(node);
    while(!s.empty())
    {
        UndirectedGraphNode* t = s.top();
        s.pop();
        if(visited[t]==0)
        {
            visited[t]++;
            for(int i=0; i<t->neighbors.size(); i++)
            {
               if(isInGraph[t->neighbors[i]]!=NULL)
                    isInGraph[t]->neighbors.push_back(isInGraph[t->neighbors[i]]);
               else if(isInGraph[t->neighbors[i]]==NULL)
               {
                    UndirectedGraphNode *k = new UndirectedGraphNode( t->neighbors[i]->label );
                    isInGraph[t]->neighbors.push_back( k );
                    isInGraph[ t->neighbors[i] ] = k;
                    s.push(t->neighbors[i]);
               }
            }
        }
    }
    
    return root;
}
