/**

973. K Closest Points to Origin

We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

 

Example 1:

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)
 

Note:

1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000

*/

/**
 solution:
 1. put k elements in priority queue
 2. compare laregest element in pq with the k+1th one, if it's greater than k+1th , 
 replace it with k+1th
 */



class Solution {
public:
    struct LessVec{
        bool operator()(vector<int> &lhs, vector<int> &rhs){
            int x1 = lhs[0];
            int y1 = lhs[1];
            int x2 = rhs[0];
            int y2 = rhs[1];
            if(x1 * x1 + y1 * y1 < x2 * x2 + y2 * y2){
                return true;
            }

            return false;
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>,vector<vector<int>>,LessVec> pq;
        for(auto point : points){
            if(pq.size() < K){
                // cout << "push"<<point[0] << endl;
                pq.push(point);
            }
            else{
                // cout << "more than k" << point[0] << endl;
                auto largest = pq.top();
                // cout << "large: " << largest[0] << endl;
                if(LessVec()(point,largest)){
                    pq.pop();
                    pq.push(point);
                }
            }
        }
        
        vector<vector<int>> result;
        while(!pq.empty()){
            result.push_back(pq.top());
            pq.pop();
        }
        
        return result;
    }
};