#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

priority_queue <int> maxHeap;
priority_queue <int, vector<int>, greater<int>> minHeap;
double mid;

int main() 
{
    int n, x, y;
    cin >> n;
    if(n >= 2)
    {
        //first 2 elements
        cin >> x >> y;
        n -= 2;
        mid = (x + y)*1.0/2;
        printf("%.1lf\n", double(x));
        printf("%.1lf\n", mid);
        if(x > y)
        {
            minHeap.push(x);
            maxHeap.push(y);
        }
        else 
            if(x <= y)
            {
                minHeap.push(y);
                maxHeap.push(x);
            }
        //orther elements
        for(int i = 0;i < n;i++)
        {
            cin >> x;
            // greater than mid -> maxHeap
            // smaller or equal than mid -> maxHeap
            if(x > mid)
                minHeap.push(x);
            else
                maxHeap.push(x);
            //case diffirent of 2 heaps are greater than 1
            int diff = minHeap.size() - maxHeap.size();
            if(diff == 2 || diff == -2)
            {
                if (maxHeap.size() > minHeap.size())
                {
                    y = maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(y);
                }
                else
                {
                    y = minHeap.top();
                    minHeap.pop();
                    maxHeap.push(y);
                }
            }
            if(minHeap.size() == maxHeap.size())
                mid = (minHeap.top() + maxHeap.top())*1.0/2;
            else
                if(minHeap.size() > maxHeap.size())
                    mid = minHeap.top();
                else
                    mid = maxHeap.top();
            printf("%.1lf\n", mid);
        }
    }
    else 
        {
            cin >> x;
            printf("%.1lf\n", double(x));
        }
   return 0;
}
