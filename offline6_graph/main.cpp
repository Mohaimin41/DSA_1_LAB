#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

#include "graph.h"

std::vector<node> build_graph(int *jumps, int total_squares, int dice_sides);

void print_shortest_path(std::stack<int> path);

void print_unreachables(std::vector<int> unreachable_list);

int main()
{
    std::ifstream inputFileStream ("inputF.txt");
    std::ofstream outputFileStream("output1.txt", std::ios::out);

    // Backup streambuffers of cin cout
    std::streambuf* stream_buffer_cout = std::cout.rdbuf();
    std::streambuf* stream_buffer_cin = std::cin.rdbuf();

    std::streambuf* stream_buffer_file_in = inputFileStream.rdbuf();
    std::streambuf* stream_buffer_file_out = outputFileStream.rdbuf();

    //redirection part
    std::cin.rdbuf(stream_buffer_file_in);
    std::cout.rdbuf(stream_buffer_file_out);

    int test_cases;

    std::cin >> test_cases;

    while (test_cases--)
    {
        int dice_sides, square_num, ladders, snakes;

        std::cin >> dice_sides >> square_num;

        int jumps[square_num + 1] = {0};

        std::cin >> ladders;

        for (int idx = 0; idx < ladders; idx++)
        {
            int from, to;
            std::cin >> from >> to;
            jumps[from] = to;
        }

        std::cin >> snakes;

        for (int idx = 0; idx < snakes; idx++)
        {
            int from, to;
            std::cin >> from >> to;
            jumps[from] = to;
        }

        std::vector<node> board = build_graph(jumps, square_num, dice_sides);

        // for (auto n: jumps)
        //     std::cout << n << " ";
        // std::cout << "\n";

        // std::cout << "board size: " << board.size() << "\n";

        bfs(board, 1);

        std::cout << dice_roll(board, square_num, dice_sides, jumps) << "\n";

        std::stack<int> solve_path = shortest_Path_from_root(board, square_num);

        print_shortest_path(solve_path);

        print_unreachables(unreachable_vertices(board));

        // int cnt = -1;
        // for (auto vertex: board)
        // {
        //     std::cout << ++cnt <<" col: " << vertex.color << " " << vertex.dist_from_src << ", parent: " << vertex.parent << " adj: ";
        //     for (auto adj: vertex.adj_nodes)
        //         std:: cout << adj << " ";
        //     std::cout << "\n";
        // }
    }

    std::cin.rdbuf(stream_buffer_cin);
    std::cout.rdbuf(stream_buffer_cout);

    outputFileStream.close();
    inputFileStream.close();

    return 0;
}

void print_shortest_path(std::stack<int> path)
{
    if (path.empty())
    {
        std::cout << "No solution\n";
    }
    else
    {
        while (path.size() > 1)
        {
            std::cout << path.top() << " -> ";
            path.pop();
        }
        std::cout << path.top() << "\n";
    }
}

void print_unreachables(std::vector<int> unreachable_list)
{
    if (unreachable_list.empty())
    {
        std::cout << "All reachable";
    }
    else
    {
        for (auto vertices : unreachable_list)
        {
            std::cout << vertices << " ";
        }
    }
    std::cout << "\n";
}

std::vector<node> build_graph(int *jumps, int total_squares, int dice_sides)
{
    std::vector<node> nodes_list(total_squares + 1);

    for (int idx = 1; idx <= total_squares; idx++)
    {
        if (jumps[idx])
        {
            nodes_list[idx].adj_nodes.push_back(jumps[idx]);
        }
        else
        {
            for (int nxt_nodes = 1; nxt_nodes <= dice_sides && idx + nxt_nodes <= total_squares; nxt_nodes++)
            {
                nodes_list[idx].adj_nodes.push_back(idx + nxt_nodes);
            }
        }
    }

    return nodes_list;
}