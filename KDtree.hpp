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

vector<float> choosetheponintToBalanceKDtree(vector<vector<float>> cloud, int region);
void createKDtree(vector<vector<float>> points);
void insertPointAtTree(vector<float> point);







//struct No
//{
//   float NOvalue;
//   int NOdimention; //set x = 0, y = 1, z = 2
//   vector<vector<float>> left;
//   vector<vector<float>> rigth;
//};
//
//void createKDtree(vector<vector<float>> points, int minNopoints);
//No* rootCreator(vector<vector<float>> cloud, int dim);
////side 0 to Rigth 1 to Left
//No* noCreator(No *lastNoAddress, int side, int dim);
//float choosetheponintToBalanceKDtree(vector<vector<float>> cloud, int region);


