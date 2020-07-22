#include <vector>
#include<iostream>
using namespace std;



struct No
{
    vector<float> noPoint;
    int layer;//x->0 and y->1
    No *nextNoRigth;
    No *nextNoLeft;
    No(void): nextNoRigth(NULL), nextNoLeft(NULL)
    {
    }
};

vector<float> choosetheponintToBalanceKDtree(vector<vector<float>> cloud);
void createKDtree(vector<vector<float>> points, bool dim);
void insertPointAtTree(vector<float> point, bool deleteNo);
vector<vector<float>> searchNearestNeighbors(vector<float> target, float tolerance);
void goThrougthTheTree(No *no, vector<float> target, float tolerance, vector<vector<float>> &NearestNeighbors);
vector<vector<vector<float>>*> clustersTree(vector<vector<float>> points, float distanceTol, int minpoints);
vector<vector<float>> *clusteringTree(vector<float> point, vector<vector<float>> points, vector<bool>& processed, float distanceTol, int &minpoints, bool deleteClusters);
void deleteNos(void);
void deleteClusters(void);