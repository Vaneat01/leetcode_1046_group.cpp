#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {  //Store the weights of the stones in a vector

        priority_queue<int> maxHeap;    //Priority queue acts as a max heap

        for (int s : stones) {  //Push all the stones into maxHeap
            maxHeap.push(s);
        }

        while (maxHeap.size() > 0) {    //While there is at least one stone

            int largest = maxHeap.top();    //Find the largest stone
            maxHeap.pop();                  //Take out the largest stone

            if (maxHeap.empty()) {      //If there was only one stone
                return largest;         //Return the only stone that was there
            }

            int secondLargest = maxHeap.top();      //Otherwise find the next largest stone
            maxHeap.pop();                          //Take out the stone

            int difference = largest - secondLargest;   //Find the difference between the weights of the stones
            if (difference > 0) {                      //If there is a difference between the weights
                maxHeap.push(difference);               //Push the new stone with the weight=difference into maxHeap
            }
        }
        return 0;   //If there are no stones left
    }
};

//Time Complexity: O(n log n)
//Space Complexity: O(n)
