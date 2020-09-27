#include"KDtree.hpp"

No* ROOT;
//dimension = 0 -> 2D and dimension = 1 -> 3D
bool dimension;

void createKDtree(vector<vector<float>> points, bool dim)
{
    vector<float> balancedPoint;
    if(dim)
     dimension = 1;
    else
     dimension = 0;
    int i;
    i = 0;
    do{
        balancedPoint = choosetheponintToBalanceKDtree(points);
        insertPointAtTree(balancedPoint, 0);
        if(dimension)
            points.erase(points.begin() + balancedPoint[3]);
        else
            points.erase(points.begin() + balancedPoint[2]);
        i++;
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
                cout << "-------------------- New No -------------------------:" << endl;
                cout << "No Address: " << currentyNo << endl;
                cout << "point x: " << currentyNo->noPoint[0] << endl;
                cout << "point y: " << currentyNo->noPoint[1] << endl;
                if (dimension)
                cout << "point z: " << currentyNo->noPoint[2] << endl;
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
            cout << "-------------------- New No -------------------------:" << endl;
            cout << "No Address: " << currentyNo << endl;
            cout << "point x: " << currentyNo->noPoint[0] << endl;
            cout << "point y: " << currentyNo->noPoint[1] << endl;
            if (dimension)
            cout << "point z: " << currentyNo->noPoint[2] << endl;
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
            if(dimension)
                currentyNo->layer = 2;
            else
                currentyNo->layer = 0;
            cout << "-------------------- New No -------------------------:" << endl;
            cout << "No Address: " << currentyNo << endl;
            cout << "point x: " << currentyNo->noPoint[0] << endl;
            cout << "point y: " << currentyNo->noPoint[1] << endl;
            if(dimension)
                cout << "point z: " << currentyNo->noPoint[2] << endl;
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
            if (dimension)
                currentyNo->layer = 2;
            else
                currentyNo->layer = 0;
            cout << "-------------------- New No -------------------------:" << endl;
            cout << "No Address: " << currentyNo << endl;
            cout << "point x: " << currentyNo->noPoint[0] << endl;
            cout << "point y: " << currentyNo->noPoint[1] << endl;
            if (dimension)
                cout << "point z: " << currentyNo->noPoint[2] << endl;
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
//For layer = 2
    if (dimension)
    {
        if (previousNo->layer == 2 && point[2] >= previousNo->noPoint[2])
        {
            if (previousNo->nextNoRigth == NULL)
            {
                previousNo->nextNoRigth = currentyNo;
                currentyNo->noPoint = point;
               currentyNo->layer = 0;
                cout << "-------------------- New No -------------------------:" << endl;
                cout << "No Address: " << currentyNo << endl;
                cout << "point x: " << currentyNo->noPoint[0] << endl;
                cout << "point y: " << currentyNo->noPoint[1] << endl;
                cout << "point z: " << currentyNo->noPoint[2] << endl;
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

        if (previousNo->layer == 2 && point[2] < previousNo->noPoint[2])
        {
            if (previousNo->nextNoLeft == NULL)
            {
                previousNo->nextNoLeft = currentyNo;
                currentyNo->noPoint = point;
                currentyNo->layer = 0;
                cout << "-------------------- New No -------------------------:" << endl;
                cout << "No Address: " << currentyNo << endl;
                cout << "point x: " << currentyNo->noPoint[0] << endl;
                cout << "point y: " << currentyNo->noPoint[1] << endl;
                cout << "point z: " << currentyNo->noPoint[2] << endl;
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

}

void deleteNos(void)
{
    insertPointAtTree({ 0,0,0 }, 1);
}

void insertPointAtTree(vector<float> point, bool deleteNo)
{
    static No *root = NULL;
    No* no = new No;
    if(deleteNo == 0)
    {
        if (root == NULL)
        {
            no->noPoint = point;
            no->layer = 0;
            root = no;
            ROOT = root;
            cout << "----------------------- ROOT --------------------------: " << endl;
            cout << "ROOT ADDRESS: " << root << endl;
            cout << "point x: " << root->noPoint[0] << endl;
            cout << "point y: " << root->noPoint[1] << endl;
             if( dimension )
             cout << "point z: " << root->noPoint[2] << endl;
            cout << "Root Layer: " << root->layer << endl;
            cout << "-----------------------------------------------------: " << endl;

        }
        else
        {
            insertNo(root, no, point);
        }
    }
    if (deleteNo == 1)
        delete no;

}

vector<float> choosetheponintToBalanceKDtree(vector<vector<float>> cloud)
{
    float large, menor, range, median, deltaP;
    int region = 0;
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
    if(dimension)
        bestpoint = { { cloud[0][0], cloud[0][1],cloud[0][2], 0 } };
    else
        bestpoint = {{ cloud[0][0], cloud[0][1], 0 }};
    for (int index = 0; index < cloud.size(); index++)
    {
        
        if (fabs(median - cloud[index][region]) < deltaP)
        {
            deltaP = fabs(median - cloud[index][region]);
            if(dimension)
                bestpoint = { { cloud[index][0],cloud[index][1], cloud[index][2],float(index) } };
            else
                bestpoint = { { cloud[index][0],cloud[index][1], float(index) } };
        }
    }
    return bestpoint;
}


vector<vector<float>> searchNearestNeighbors(vector<float> target, float tolerance)
{
    vector<vector<float>> nearestNeighbors;
    goThrougthTheTree(ROOT, target, tolerance, nearestNeighbors);
    return nearestNeighbors;
}

void goThrougthTheTree(No* no, vector<float> target, float tolerance, vector<vector<float>>& NearestNeighbor)
{
    vector<float> addNN;
    float distance;

    if (no != NULL)
    {
        if (dimension)
        {
            if ((no->noPoint[0] >= (target[0] - tolerance) && no->noPoint[0] <= (target[0] + tolerance)) &&
                (no->noPoint[1] >= (target[1] - tolerance) && no->noPoint[1] <= (target[1] + tolerance)) &&
                (no->noPoint[2] >= (target[2] - tolerance) && no->noPoint[2] <= (target[2] + tolerance)))
            {
                distance = sqrt((no->noPoint[0] - target[0]) * (no->noPoint[0] - target[0]) +
                                (no->noPoint[1] - target[1]) * (no->noPoint[1] - target[1]) +
                                (no->noPoint[2] - target[2]) * (no->noPoint[2] - target[2]));

                if (distance <= tolerance)
                {
                    addNN.push_back(no->noPoint[0]);
                    addNN.push_back(no->noPoint[1]);
                    addNN.push_back(no->noPoint[2]);
                    NearestNeighbor.push_back(addNN);
                }

            }
        }

        else
        { 
            if ((no->noPoint[0] >= (target[0] - tolerance) && no->noPoint[0] <= (target[0] + tolerance)) &&
                no->noPoint[1] >= (target[1] - tolerance) && no->noPoint[1] <= (target[1] + tolerance))
            {
                distance = sqrt((no->noPoint[0] - target[0]) * (no->noPoint[0] - target[0]) +
                                (no->noPoint[1] - target[1]) * (no->noPoint[1] - target[1]));
                if (distance <= tolerance)
                {
                    addNN.push_back(no->noPoint[0]);
                    addNN.push_back(no->noPoint[1]);
                    NearestNeighbor.push_back(addNN);
                }

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

        if (no->layer == 2)
        {
            if ((target[2] + tolerance) > (no->noPoint[2]))
                goThrougthTheTree(no->nextNoRigth, target, tolerance, NearestNeighbor);

            if ((target[2] - tolerance) <= (no->noPoint[2]))
                goThrougthTheTree(no->nextNoLeft, target, tolerance, NearestNeighbor);
        }
    }
}

void deleteClusters(void)
{
    vector<bool> proc;
    int min;
    vector<vector<float>>* back = clusteringTree({ 0,0,0 }, { { 0,0,0 } }, proc, 0.0, min, 1);
}

vector<vector<float>>* clusteringTree(vector<float> point, vector<vector<float>> points, vector<bool>& processed, float distanceTol, int& minpoints, bool deleteClusters)
{
    vector<vector<float>> nearest;
    vector<vector<float>> nearestOfnearest;
    vector<vector<float>>* cluster = new vector<vector<float>>;

    if (deleteClusters == 0)
    {
        nearestOfnearest.clear();
        nearest = searchNearestNeighbors(point, distanceTol);
        nearestOfnearest.insert(nearestOfnearest.end(), nearest.begin(), nearest.end());

        for (int i = 0; i < nearestOfnearest.size(); i++)
        {
            for (int j = 0; j < points.size(); j++)
            {
                if (nearestOfnearest[i][0] == points[j][0] && nearestOfnearest[i][1] == points[j][1] &&
                    nearestOfnearest[i][2] == points[j][2] && processed[j] == false)
                    processed[j] = true;
            }
        }

        cout << "Points in clustering: " << points.size() << endl;
        cout << "NearestOfnearest size before: " << nearestOfnearest.size() << endl;

        vector<vector<float>>::iterator itnext = nearestOfnearest.begin() + 1;
        vector<vector<float>>::iterator itend = nearestOfnearest.end();
        int indexnextPoint = 0;

        do
        {
            vector<vector<float>> newPoits;
            vector<vector<float>> NN = searchNearestNeighbors(*itnext, distanceTol);

            for (int id = 0; id < NN.size(); id++)
            {
                bool pointPresent = false;
                for (int i = 0; i < nearestOfnearest.size(); i++)
                {
                    if (nearestOfnearest[i][0] == NN[id][0] && nearestOfnearest[i][1] == NN[id][1] &&
                        nearestOfnearest[i][2] == NN[id][2])
                    {
                        pointPresent = true;
                        break;
                    }
                }
                if (pointPresent == false)
                {
                    for (int j = 0; j < points.size(); j++)
                    {
                        if (NN[id][0] == points[j][0] && NN[id][1] == points[j][1] &&
                            NN[id][2] == points[j][2] && processed[j] == false)
                        {
                            processed[j] = true;
                            newPoits.push_back(NN[id]);
                        }
                    }
                }
            }

            nearestOfnearest.reserve(newPoits.size());
            nearestOfnearest.insert(nearestOfnearest.end(), newPoits.begin(), newPoits.end());
            newPoits.clear();
            itend = nearestOfnearest.end();
            itnext = nearestOfnearest.begin();
            ++indexnextPoint;
            itnext += indexnextPoint;

        } while (itnext != itend);
        cout << "nearestOfnearest size after: " << nearestOfnearest.size() << endl;

        for (int i = 0; i < nearestOfnearest.size(); i++)
        {
            cluster->push_back(nearestOfnearest[i]);
        }

        if (cluster->size() >= minpoints)
            return cluster;
        else
            return NULL;
    }

    if (deleteClusters == 1)
    {
        delete cluster;
        return NULL;
    }

}


vector<vector<vector<float>>*> clustersTree(vector<vector<float>> points, float distanceTol, int minpoints)
{
    vector<vector<vector<float>>*> ptrClusters;
    vector<vector<float>>* ptrCluster;
    vector<bool> processed(points.size(), false);
    ptrClusters.clear();
    int i = 0;
    while (i < points.size())
    {
        if (processed[i])
        {
            i++;
            continue;
        }
        ptrCluster = clusteringTree(points[i], points, processed, distanceTol, minpoints,0);
        if(ptrCluster != NULL)
          ptrClusters.push_back(ptrCluster);
          i++;
    }
    return ptrClusters;
}
