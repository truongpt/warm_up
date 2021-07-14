#include <iostream>
#include <variant>
#include <string>

using namespace std;

int main(void)
{
  std::variant<int, float> v, w;       // (1)
  v = 12;                    
  int i = std::get<int>(v);
  w = std::get<int>(v);                // (2)
  w = std::get<0>(v);                  // (2)
  w = v;                               // (2)

  cout << std::get<float>(v) << endl;

  //  std::get<double>(v);   // error: no double in [int, float] (3)
  //  std::get<3>(v);        // error: valid index values are 0 and 1 (4)
 
  try{
    std::get<float>(w);                // (5)   
  }
  catch (std::bad_variant_access&) {}
 
  std::variant<std::string> v2("abc"); // (6)
  v2 = "def";  

}
