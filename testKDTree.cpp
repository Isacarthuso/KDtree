#include"KDtree.hpp"

int main()
{
    vector<vector<float>> NN;
    std::vector<std::vector<float>> points = { {-6.2,7}, {-6.3,8.4}, {-5.2,7.1}, {-5.7,6.3}, {7.2,6.1}, {8.0,5.3}, {7.2,7.1}, {0.2,-7.1}, {1.7,-6.9}, {-1.2,-7.2}, {2.2,-8.9} };
    //std::vector<std::vector<float>> points = { {-6.2,7}, {-6.3,8.4}, {-5.2,7.1} };
    createKDtree(points);
    NN = searchNearestNeighbors({ -7,6 }, 3);

    for (int i = 0; i < NN.size(); i++)
    {
        cout << "NN: " << NN[i][0] << endl;
    }
    return 0;
}