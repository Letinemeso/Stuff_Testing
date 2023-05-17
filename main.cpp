#include <iostream>
#include <iomanip>
#include <map>

#include <thread>

#include <functional>

#include <Data_Structures/Map.h>
#include <Data_Structures/Vector.h>
#include <Stuff/Stopwatch.h>

#include <Stuff/Function_Wrapper.h>

#include <Graph/Pathfinder.h>
#include <vector>

LGL::Graph construct_graph(std::vector<std::vector<char>> field)
{
    LGL::Graph result;
    result.allocate_nodes(field.size() * field[0].size());

    auto calculate_index = [field](int x, int y)->int
    {
        unsigned int width = field.size();
        unsigned int height = field[0].size();

        if(x < 0 || x >= width || y < 0 || y >= height)
            return -1;

        return x * height + y;
    };

    auto link_with_surrounding = [&](int x, int y)
    {
        int index = calculate_index(x, y);
        if(index != -1)
        {
            if(field[x][y] == 0)
                return;
        }

        int left = calculate_index(x - 1, y);
        int right = calculate_index(x + 1, y);
        int top = calculate_index(x, y + 1);
        int bottom = calculate_index(x, y - 1);

        if(left != -1)
        {
            if(field[x - 1][y] == 1)
                result.link_nodes(index, left, 10, false);
        }

        if(right != -1)
        {
            if(field[x + 1][y] == 1)
                result.link_nodes(index, right, 10, false);
        }

        if(top != -1)
        {
            if(field[x][y + 1] == 1)
                result.link_nodes(index, top, 10, false);
        }

        if(bottom != -1)
        {
            if(field[x][y - 1] == 1)
                result.link_nodes(index, bottom, 10, false);
        }
    };

    for(int x=0; x<(int)field.size(); ++x)
    {
        for(int y=0; y<(int)field[0].size(); ++y)
        {
            link_with_surrounding(x, y);
        }
    }

    return result;
}

int main()
{
    std::vector<std::vector<char>> field =
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 0, 0, 1, 1, 1},
        {1, 1, 1, 0, 1, 0, 1, 1, 1, 1},
        {1, 0, 1, 0, 1, 0, 1, 1, 1, 1},
        {1, 0, 1, 1, 1, 1, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };

    LGL::Graph graph = construct_graph(field);

    LGL::Pathfinder pathfinder(&graph,
                               [field](unsigned int _id_1, unsigned int _id_2)
    {
        unsigned int width = field.size();
        unsigned int height = field[0].size();

        int x1 = _id_1 / height;
        int y1 = _id_1 & height;

        int x2 = _id_2 / height;
        int y2 = _id_2 & height;

        return abs(x1 - x2) + abs(y1 - y2);
    });

    pathfinder.process(0, 99);

    for(unsigned int i=0; i<pathfinder.path_result().size(); ++i)
    {
        std::cout << pathfinder.path_result()[i] << " ";

        unsigned int width = field.size();
        unsigned int height = field[0].size();

        int x = pathfinder.path_result()[i] / height;
        int y = pathfinder.path_result()[i] % height;

        field[x][y] = '.';
    }
    std::cout << "\n\n";

    unsigned int width = field.size();
    unsigned int height = field[0].size();

    for(unsigned int x=0; x<width + 2; ++x)
        std::cout << "##";
    std::cout << "\n";
    for(unsigned int y=0; y < height; ++y)
    {
        std::cout << "# ";
//        for(int y=height - 1; y >= 0; --y)
        for(unsigned int x=0; x<width; ++x)
        {
            if(field[y][x] == 1)
                field[y][x] = ' ';
            if(field[y][x] == 0)
                field[y][x] = '#';

            std::cout << field[y][x] << ' ';
        }
        std::cout << " #\n";
    }
    for(unsigned int x=0; x<width + 2; ++x)
        std::cout << "##";
    std::cout << "\n";
    std::cout << "\n";

	return 0;
}
