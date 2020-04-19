// Reference: https://codeforces.com/blog/entry/11080

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef
tree<
  int,
  null_type,
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;

int main() {
	
  ordered_set X;
  X.insert(1);        // X.erase(value); it works too
  X.insert(2);
  X.insert(4);
  X.insert(8);
  X.insert(16);
   
   // X = {1, 2, 4, 8, 16}
   // find_by_order = what is the element in the position i? 
  cout<<*X.find_by_order(1)<<endl; // 2         X[1] = 2;
  cout<<*X.find_by_order(2)<<endl; // 4         X[2] = 4;
  cout<<*X.find_by_order(4)<<endl; // 16        X[4] = 16;
  cout<<(end(X)==X.find_by_order(6))<<endl; // true
  
  // order_of_key = how many elements are LESS than the value?
  cout<<X.order_of_key(-5)<<endl;  // 0         
  cout<<X.order_of_key(1)<<endl;   // 0
  cout<<X.order_of_key(3)<<endl;   // 2
  cout<<X.order_of_key(4)<<endl;   // 2
  cout<<X.order_of_key(400)<<endl; // 5


	return 0;	
}
