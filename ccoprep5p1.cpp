/*#include <iostream>
#include <deque>

using namespace std;

int n, m;

int max(int a, int b) { return a > b ? a : b; };

int main() {
	int cases;
	cin >> cases;
	for (int t = 0; t < cases; t++) {
		int ans = 0;
		cin >> n >> m;
		//iterate through each row and calculate the larest rectangle in histogram each time
		int histogram[1001] = { 0 };
		for (int i = 0; i < n; i++) {
			//add new weights
			for (int j = 0; j < m; j++) {
				char c;
        cin >> c;
        if(c == 'R')histogram[j] = 0;
        else histogram[j]++;
			}
			deque <pair <int, int>> st;
			//first is the value, second is the index
			for (int j = 1; j <= m; j++) {
				int cur = histogram[j], curIndex = j;
				while (st.size() > 0 && st.back().first > cur) {
					int backIndex = st.back().second;
					st.pop_back();
					ans = max(ans, (backIndex - st.front().second + 1) * st.front().first);
				}
				st.push_back(make_pair(cur, curIndex));
			}
		}
		cout << ans << endl;
	}
}*/

// C++ program to find maximum rectangular area in 
// linear time 
#include<iostream> 
#include<stack> 
using namespace std; 
  
// The main function to find the maximum rectangular  
// area under given histogram with n bars 
int getMaxArea(int hist[], int n) 
{ 
    // Create an empty stack. The stack holds indexes  
    // of hist[] array. The bars stored in stack are  
    // always in increasing order of their heights. 
    stack<int> s; 
  
    int max_area = 0; // Initalize max area 
    int tp;  // To store top of stack 
    int area_with_top; // To store area with top bar 
                       // as the smallest bar 
  
    // Run through all bars of given histogram 
    int i = 0; 
    while (i < n) 
    { 
        // If this bar is higher than the bar on top  
        // stack, push it to stack 
        if (s.empty() || hist[s.top()] <= hist[i]) 
            s.push(i++); 
  
        // If this bar is lower than top of stack,  
        // then calculate area of rectangle with stack  
        // top as the smallest (or minimum height) bar.  
        // 'i' is 'right index' for the top and element  
        // before top in stack is 'left index' 
        else
        { 
            tp = s.top();  // store the top index 
            s.pop();  // pop the top 
  
            // Calculate the area with hist[tp] stack  
            // as smallest bar 
            area_with_top = hist[tp] * (s.empty() ? i :  
                                   i - s.top() - 1); 
  
            // update max area, if needed 
            if (max_area < area_with_top) 
                max_area = area_with_top; 
        } 
    } 
  
    // Now pop the remaining bars from stack and calculate 
    // area with every popped bar as the smallest bar 
    while (s.empty() == false) 
    { 
        tp = s.top(); 
        s.pop(); 
        area_with_top = hist[tp] * (s.empty() ? i :  
                                i - s.top() - 1); 
  
        if (max_area < area_with_top) 
            max_area = area_with_top; 
    } 
  
    return max_area; 
} 

int n, m;
  
// Driver program to test above function 
int main() 
{ 
    //cout << "Maximum area is " << getMaxArea(hist, n); 
    int numTimes = 0;
    cin >> numTimes;
    for(int o = 0; o < numTimes; o++){
      int ans = -1;
      cin >> n >> m;
      deque <int> stack;
      int hist[1001] = {0};
      for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
          char c;
          cin >> c;
          if(c == 'R')hist[j] = 0;
          else hist[j]++;
        }
        ans = max(ans, getMaxArea(hist, m));
      }
      cout << 3 * ans << endl;
    }
    return 0; 
}