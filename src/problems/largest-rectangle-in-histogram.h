//
//  largest-rectangle-in-histogram.h
//
//  Created by jeswang 27/06/2014.
//

/*
Description:

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/

class Solution {
public:
    void run() {
        vector<int> a = {4,2,0,3,2,5};
        cout<<largestRectangleArea(a);
    }
    int largestRectangleArea(vector<int> &height) {
        int m = 0;
        unsigned long len = height.size();
        stack<int> s;
        for(int i=0; i<len; i++) {
            if(s.size()==0 || height[i] > height[s.top()]) {
                s.push(i);
            }
            else {
                while(s.size()!=0 && height[i] <= height[s.top()]) {
                    int j = s.top();s.pop();
                    int h = height[j];
                    int w = i - (s.size()!=0?s.top()+1:0);
                    m = max(m, w*h);
                }
                
                s.push(i);
            }
        }
        
        while(s.size()!=0) {
            int j = s.top();s.pop();
            int h = height[j];
            int w = int((s.size()==0)?len:len - s.top() - 1);
            m = max(m, w*h);
        }
        
        int b = -1;
        int count = 0;
        for(int i=0; i<len; i++) {
            if(b==-1){
                b = height[i];
                count = 1;
            }
            else {
                if(height[i] == b) {
                    count++;
                    m = max(m, count*b);
                }
                else {
                    b = height[i];
                    count = 1;
                }
            }
        }
        
        return m;
    }
};