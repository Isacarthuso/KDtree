#include"KDtree.hpp"

int main()
{
    vector<vector<vector<float>>*> Clusters;
    vector<vector<float>> NN;


    //2D
    std::vector<std::vector<float>> points = { {-6.2,7}, {-6.3,8.4}, {-5.2,7.1}, {-5.7,6.3}, {7.2,6.1}, {8.0,5.3}, 
                                               {7.2,7.1}, {0.2,-7.1}, {1.7,-6.9}, {-1.2,-7.2}, {2.2,-8.9} };
    
    //***************************************************************************************************************

    //3D
    //vector<vector<float>> points = { {6,5,2}, {1,8,9}, {7,1,1}, {7,8,7}, {7,3,6}, {2,1,4}, {1,4,1}, {8,7,3},
    //                                          {6,2,8}, {2,8,6}, {9,1,4}, {2,8,3}, {8,1,4}, {9,4,1}, {7,2,0}};
    //***************************************************************************************************************

    //dimension = 0 -> 2D and dimension = 1 -> 3D
    createKDtree(points,0);
    
    //Nearest Neighbors
    //2D
    NN = searchNearestNeighbors({ -7,6 }, 3);
    //3D
    //NN = searchNearestNeighbors({ 1,2,3 }, 8);

    for (int i = 0; i < NN.size(); i++)
    {
        cout << "NN: " << NN[i][0] << endl;
    }

    //Euclidean Clustering
    Clusters = clustersTree(points, 3);
    for (int i = 0; i < Clusters.size(); i++)
        cout << "Clusters Address: " << Clusters[i] << endl;

    return 0;
}