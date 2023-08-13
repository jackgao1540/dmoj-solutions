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
            area_with_top = (hist[tp] + 1) * (s.empty() ? i + 1 : i - s.top()); 
            if (max_area < area_with_top) 
                max_area = area_with_top; 
        } 
    } 
    while (s.empty() == false) 
    { 
        tp = s.top(); 
        s.pop(); 
        area_with_top = (hist[tp] + 1) * (s.empty() ? i + 1 : i - s.top()); 
        if (max_area < area_with_top) 
            max_area = area_with_top; 
    } 
    return max_area; 
} 

int n, m;
  
int main() 
{ 
  int ans = 0;
  cin >> n >> m;
  bool arr[1001][1001];
  int numarr[1001][1001];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> numarr[i][j];
    }
  }
  for(int i = 0; i < n - 1; i++){
    for(int j = 0; j < m - 1; j++){
      arr[i][j] = (numarr[i][j] + numarr[i + 1][j + 1] <= numarr[i + 1][j] + numarr[i][j + 1] ? 1 : 0);
    }
  }
  deque <int> stack;
  int hist[1001] = {0};
  for(int i = 0; i < n - 1; i++){
    for(int j = 0; j < m - 1; j++){
      bool c = arr[i][j];
      if(c == 0)hist[j] = 0;
      else hist[j]++;
    }
    ans = max(ans, getMaxArea(hist, m));
  }
  cout << ans << endl;
  return 0; 
}