# KD-Tree Algorithm
>In computer science, a k-d tree (short for k-dimensional tree) is a space-partitioning data 
>structure for organizing points in a k-dimensional space. k-d trees are a useful data structure 
>for several applications, such as searches involving a multidimensional search key 
>(e.g. range searches and nearest neighbor searches). k-d trees are a special case of binary space partitioning trees.


![Test Image 1](https://github.com/Isacarthuso/KDtree/blob/master/readmeimg/3dtree.png)


**Functions**
- **createKDtree(points, dimension)**
It is main fuction that create the KD-Tree where need to give the arguments in follow way:
  - dimension = 0 -> 2D and dimension = 1 -> 3D.
  - points; The set of poits that will create the tree.

- **vector<float> choosetheponintToBalanceKDtree(vector<vector<float>> cloud);**
 
 Balance the tree it is so important to speed up search in the Tree, the algorithm can have best success in a balanced tree than a unbalenced tree. The function implmeted  createKDtree(points, dimension) function cosider the balance algorithm as example bellow:
 
Gaven the poits:

![Test Image 2](https://github.com/Isacarthuso/KDtree/blob/master/readmeimg/KDTreeBalValue.PNG)

The result balanced:

![Test Image 3](https://github.com/Isacarthuso/KDtree/blob/master/readmeimg/KDTreeBalC.PNG)

The KD-Tree balanced:

![Test Image 4](https://github.com/Isacarthuso/KDtree/blob/master/readmeimg/KDTreeBal-removebg-preview.png)


- **vector<vector<float>> searchNearestNeighbors(vector<float> target, float tolerance);**
The searchNearestNeighbors fuction return all points that are in tolerance distance from target point using the KNN algorithm.

# Clustering Points
>A clustering function is used when is necessary to divide an unorganized point cloud  into sets of smaller parts.

![Test Image 5](https://github.com/Isacarthuso/KDtree/blob/master/readmeimg/Cluster.PNG)
- **vector<vector<vector<float>>> clustersTree(vector<vector<float>> points, float distanceTol, int minpoints);**
 The Function return a set of cluster.
   - points; The set of points to be organized as clusters.
   - distanceTol; The tolerance distance among the poits.
   - minpoints; The minimal poits necessarie in a set to be consider a cluster.
 
 The pseudocode used was:
 ![Test Image 5](https://github.com/Isacarthuso/KDtree/blob/master/readmeimg/UCluterPS.PNG)
