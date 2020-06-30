#include"KDtree.hpp"

No* ROOT;


void createKDtree(vector<vector<float>> points)
{
    vector<float> balancedPoint;
    int dim;

    dim = 0;
    do{
        balancedPoint = choosetheponintToBalanceKDtree(points,0);
        insertPointAtTree(balancedPoint);
        points.erase(points.begin() + balancedPoint[2]);
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

void insertPointAtTree(vector<float> point)
{
    static No *root = NULL;

    No* no = new No;

    if (root == NULL)
    {
        no->noPoint = point;
        no->layer = 0;
        root = no;
        ROOT = root;
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
    range = large - menor;
    median = menor + range / 2;

    //init
    deltaP = fabs(median - cloud[0][region]);
    bestpoint = {{ cloud[0][0], cloud[0][1], 0 }};
    for (int index = 0; index < cloud.size(); index++)
    {
        
        if (fabs(median - cloud[index][region]) < deltaP)
        {
            deltaP = fabs(median - cloud[index][region]);
            bestpoint = { { cloud[index][0],cloud[index][1], float(index) } };
        }
    }
    return bestpoint;
}


vector<vector<float>> searchNearestNeighbors(vector<float> target, int tolerance)
{
    vector<vector<float>> nearestNeighbors;
    cout << "Return root address in search: " << ROOT << endl;
    goThrougthTheTree(ROOT, target, tolerance, nearestNeighbors);
    return nearestNeighbors;
}

void goThrougthTheTree(No* no, vector<float> target, int tolerance, vector<vector<float>>& NearestNeighbor)
{
    vector<float> addNN;

    if (no != NULL)
    {
        cout << "Search X: " << no->noPoint[0] << endl;
        if ((no->noPoint[0] >= (target[0] - tolerance) && no->noPoint[0] <= (target[0] + tolerance)) &&
            no->noPoint[1] >= (target[1] - tolerance) && no->noPoint[1] <= (target[1] + tolerance))
        {
            float distance = sqrt((no->noPoint[0] - target[0]) * (no->noPoint[0] - target[0]) +
                (no->noPoint[1] - target[1]) * (no->noPoint[1] - target[1]));
            std::cout << "Distance: " << distance << std::endl;
            if (distance <= tolerance)
            {
                addNN.push_back(no->noPoint[0]);
                addNN.push_back(no->noPoint[1]);
                NearestNeighbor.push_back(addNN);
            }

        }

        if (no->layer == 0)
        {
           if(( target[0] + tolerance) > (no->noPoint[0] ))
             goThrougthTheTree(no->nextNoRigth, target, tolerance, NearestNeighbor);
        
           if(( target[0] - tolerance) <= (no->noPoint[0] ))
             goThrougthTheTree(no->nextNoLeft, target, tolerance, NearestNeighbor);
        }

        if (no->layer == 1)
        {
           if ((target[1] + tolerance) > (no->noPoint[1]))
             goThrougthTheTree(no->nextNoRigth, target, tolerance, NearestNeighbor);
        
           if ((target[1] - tolerance) <= (no->noPoint[1]))
             goThrougthTheTree(no->nextNoLeft, target, tolerance, NearestNeighbor);
        }
    }
}