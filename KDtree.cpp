#include"KDtree.hpp"

void createKDtree(vector<vector<float>> points)
{
    vector<float> balancedPoint;
    int dim;

    dim = 0;
    do{
        balancedPoint = choosetheponintToBalanceKDtree(points,0);
        insertPointAtTree(balancedPoint);
        points.erase(points.begin() + balancedPoint[2]);
        //if (dim == 1)
        //    dim = 0;
        //else
        //    dim++;
    } while (!points.empty());
}

void insertNo(No* previousNo, No* currentyNo, vector<float> point)
{
//For layer = 0
    if (previousNo->layer == 0 && point[0] >= previousNo->noPoint[0])
    {
            if (previousNo->nextNoRigth == NULL)
            {
                previousNo->nextNoRigth = currentyNo;
                currentyNo->noPoint = point;
                currentyNo->layer = 1;
                cout << "No Address: " << currentyNo << endl;
                cout << "point x: " << currentyNo->noPoint[0] << endl;
                cout << "point y: " << currentyNo->noPoint[1] << endl;
                cout << "Point Level: " << currentyNo->layer << endl;
                cout << "Previous No: " << previousNo << endl;
                cout << "Previous Rigth No: " << previousNo->nextNoRigth << endl;
                cout << "Previous Left No: " << previousNo->nextNoLeft << endl;
                cout << "-----------------------------------------------------: " << endl;

            }
            else
            {
                insertNo(previousNo->nextNoRigth, currentyNo, point);
            }
    }

    if (previousNo->layer == 0 && point[0] < previousNo->noPoint[0])
    {
        if (previousNo->nextNoLeft == NULL)
        {
            previousNo->nextNoLeft = currentyNo;
            currentyNo->noPoint = point;
            currentyNo->layer = 1;
            cout << "No Address: " << currentyNo << endl;
            cout << "point x: " << currentyNo->noPoint[0] << endl;
            cout << "point y: " << currentyNo->noPoint[1] << endl;
            cout << "Point Level: " << currentyNo->layer << endl;
            cout << "Previous No: " << previousNo << endl;
            cout << "Previous Rigth No: " << previousNo->nextNoRigth << endl;
            cout << "Previous Left No: " << previousNo->nextNoLeft << endl;
            cout << "-----------------------------------------------------: " << endl;
        }
        else
        {
            insertNo(previousNo->nextNoLeft, currentyNo, point);
        }
    }

 //For layer = 1
    if (previousNo->layer == 1 && point[1] >= previousNo->noPoint[1])
    {
        if (previousNo->nextNoRigth == NULL)
        {
            previousNo->nextNoRigth = currentyNo;
            currentyNo->noPoint = point;
            currentyNo->layer = 0;
            cout << "No Address: " << currentyNo << endl;
            cout << "point x: " << currentyNo->noPoint[0] << endl;
            cout << "point y: " << currentyNo->noPoint[1] << endl;
            cout << "Point Level: " << currentyNo->layer << endl;
            cout << "Previous No: " << previousNo << endl;
            cout << "Previous Rigth No: " << previousNo->nextNoRigth << endl;
            cout << "Previous Left No: " << previousNo->nextNoLeft << endl;
            cout << "-----------------------------------------------------: " << endl;
        }
        else
        {
            insertNo(previousNo->nextNoRigth, currentyNo, point);
        }
    }

    if (previousNo->layer == 1 && point[1] < previousNo->noPoint[1])
    {
        if (previousNo->nextNoLeft == NULL)
        {
            previousNo->nextNoLeft = currentyNo;
            currentyNo->noPoint = point;
            currentyNo->layer = 0;
            cout << "No Address: " << currentyNo << endl;
            cout << "point x: " << currentyNo->noPoint[0] << endl;
            cout << "point y: " << currentyNo->noPoint[1] << endl;
            cout << "Point Level: " << currentyNo->layer << endl;
            cout << "Previous No: " << previousNo << endl;
            cout << "Previous Rigth No: " << previousNo->nextNoRigth << endl;
            cout << "Previous Left No: " << previousNo->nextNoLeft << endl;
            cout << "-----------------------------------------------------: " << endl;
        }
        else
        {
            insertNo(previousNo->nextNoLeft, currentyNo, point);
        }
    }
}
//void insertNo(No* previousNo, No* currentyNo, vector<float> point)
void insertPointAtTree(vector<float> point)
{
    static No *root = NULL;

    No* no = new No;

    if (root == NULL)
    {
        no->noPoint = point;
        no->layer = 0;
        root = no;
        cout << "ROOT ADDRESS: " << root << endl;
        cout << "point x: " << root->noPoint[0] << endl;
        cout << "point y: " << root->noPoint[1] << endl;
        cout << "Root Layer: " << root->layer << endl;
        cout << "-----------------------------------------------------: " << endl;

    }
    else
    {
        insertNo(root, no, point);
    }

}

vector<float> choosetheponintToBalanceKDtree(vector<vector<float>> cloud, int region)
{
    /*
    region = 0 -> x
    region = 1 -> y
    region = 2 -> z
    */
    float large, menor, range, median, deltaP;
    
    vector<float> bestpoint;

    //initialization
    large = cloud[0][region];
    menor = cloud[0][region];

    for (int index = 0; index < cloud.size(); index++)
    {
        if (cloud[index][region] < menor)
            menor = cloud[index][region];
        if (cloud[index][region] > large)
            large = cloud[index][region];
    }
    // << "Menor: " << menor << endl;
    //cout << "Large: " << large << endl;
    range = large - menor;
    median = menor + range / 2;

    //init
    deltaP = fabs(median - cloud[0][region]);
    //bestpoint = cloud[0][region];
    //bestpoint = { {0,5} };
    bestpoint = {{ cloud[0][0], cloud[0][1], 0 }};
    for (int index = 0; index < cloud.size(); index++)
    {
        
        if (fabs(median - cloud[index][region]) < deltaP)
        {
            //cout << "INDEX: " << float(index) << endl;
            deltaP = fabs(median - cloud[index][region]);
            //bestpoint.push_back(cloud[index]);
            bestpoint = { { cloud[index][0],cloud[index][1], float(index) } };
        }
    }
    //cout << "Point choosed x: " << bestpoint[0] << endl;
    //cout << "Point choosed y: " << bestpoint[1] << endl;
    //cout << "Point Index: " << bestpoint[2] << endl;
    //cout << "Index func: " << bestpoint[2] << endl;
    return bestpoint;
}





//void createKDtree(vector<vector<float>> points, int minNopoints)
//{
//    No* previousNoAddress;
//
//    previousNoAddress = rootCreator(points, 0);
//
//    previousNoAddress = noCreator(previousNoAddress, 0, 1);
//
//    cout << "No Value: " << previousNoAddress->NOvalue << endl;
//    for (int i = 0; i < previousNoAddress->rigth.size(); i++)
//    {
//        cout << "Rigth: " << previousNoAddress->rigth[i][0] << endl;
//    }
//
//    for (int i = 0; i < previousNoAddress->left.size(); i++)
//    {
//        cout << "Left: " << previousNoAddress->left[i][0] << endl;
//    }
//
//
//}
//
//No* noCreator(No* lastNoAddress, int side, int dim)
//{
//    vector<vector<float>> points;
//    No* ptrNo;
//    ptrNo = new No;
//
//    if ( side == 0 )
//    {
//        points = lastNoAddress->rigth;
//    }
//    else
//    {
//        points = lastNoAddress->left;
//    }
//        ptrNo->NOvalue = choosetheponintToBalanceKDtree(points, dim);
//        ptrNo->NOdimention = 0;
//
//        for (int i = 0; i < points.size(); i++)
//        {
//            if (points[i][dim] >= ptrNo->NOvalue)
//            {
//                ptrNo->rigth.push_back(points[i]);
//            }
//            else
//            {
//                ptrNo->left.push_back(points[i]);
//            }
//        }
//
//    return ptrNo;
//}
//
//No* rootCreator(vector<vector<float>> cloud, int dim)
//{
//    No* ptrRoot;
//    ptrRoot = new No;
//    ptrRoot->NOvalue = choosetheponintToBalanceKDtree(cloud,dim);
//    ptrRoot->NOdimention = 0;
//
//    for (int i = 0; i < cloud.size(); i++)
//    {
//        if (cloud[i][0] >= ptrRoot->NOvalue)
//        {
//            ptrRoot->rigth.push_back(cloud[i]);
//        }
//        else
//        {
//            ptrRoot->left.push_back(cloud[i]);
//        }
//    }
//    cout << "Size Rigth: " <<ptrRoot->rigth.size() << endl;
//    return ptrRoot;
//}
//
//float choosetheponintToBalanceKDtree(vector<vector<float>> cloud, int region)
//{
//    /*
//    region = 0 -> x
//    region = 1 -> y
//    region = 2 -> z
//    */
//    float large, menor, range, median, deltaP, bestpoint;
//
//    //initialization
//    large = cloud[0][region];
//    menor = cloud[0][region];
//
//    for (int index = 0; index < cloud.size(); index++)
//    {
//        if (cloud[index][region] < menor)
//            menor = cloud[index][region];
//        if (cloud[index][region] > large)
//            large = cloud[index][region];
//    }
//
//    range = large - menor;
//    median = menor + range / 2;
//
//    //init
//    deltaP = fabs(median - cloud[0][region]);
//    bestpoint = cloud[0][region];
//    for (int index = 0; index < cloud.size(); index++)
//    {
//        if (fabs(median - cloud[index][region]) < deltaP)
//        {
//            deltaP = fabs(median - cloud[index][region]);
//            bestpoint = cloud[index][region];
//        }
//    }
//    return bestpoint;
//}








