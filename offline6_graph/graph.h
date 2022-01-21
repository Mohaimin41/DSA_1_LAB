#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <limits>

const int inf = std::numeric_limits<int>::max();

typedef struct node_structure
{
    std::string color = "WHITE";
    int parent = 0;
    int dist_from_src = inf;
    std::vector<int> adj_nodes;
} node;

std::vector<int> unreachable_vertices(std::vector<node> nodes_list)
{
    std::vector<int> res;

    int total = nodes_list.size() - 1;

    for (int idx = 1; idx <= total; idx++)
    {
        if (nodes_list[idx].color == "WHITE")
        {
            res.push_back(idx);
        }
    }

    return res;
}

std::stack<int> shortest_Path_from_root(std::vector<node> nodes_list, int dest_node)
{
    std::stack<int> res;

    int curr = dest_node;

    while (curr && nodes_list[curr].color == "BLACK")
    {
        res.push(curr);
        curr = nodes_list[curr].parent;
    }

    return res;
}

int dice_roll(std::vector<node> nodes_list, int dest_node, int dice_sides, int *jumps)
{
    int res = 0;

    if (nodes_list[dest_node].color == "WHITE")
    {
        return -1;
    }

    int curr = dest_node;

    while (curr > 1)
    {
        if (curr - nodes_list[curr].parent <= dice_sides && jumps[nodes_list[curr].parent] != curr)
        {
            res++;
        }

        curr = nodes_list[curr].parent;
    }

    return res;
}

void bfs(std::vector<node> &nodes_list, int src)
{
    nodes_list[src].color = "GREY";
    nodes_list[src].dist_from_src = 0;
    nodes_list[src].parent = 0;

    std::queue<int> bfs_q;
    bfs_q.push(src);

    while (!bfs_q.empty())
    {
        int working_node = bfs_q.front();
        bfs_q.pop();

        for (auto adj_node : nodes_list[working_node].adj_nodes)
        {
            if (nodes_list[adj_node].color == "WHITE")
            {
                nodes_list[adj_node].color = "GREY";
                nodes_list[adj_node].dist_from_src = nodes_list[working_node].dist_from_src + 1;
                nodes_list[adj_node].parent = working_node;
                bfs_q.push(adj_node);
            }
        }

        nodes_list[working_node].color = "BLACK";
    }
}
