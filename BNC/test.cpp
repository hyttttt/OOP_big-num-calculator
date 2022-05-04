#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <map>
#include "Integer.cpp"

using namespace std;
 
int main(){
    Integer a = "123456789123456789123456798", b = "456787921", c;
    c = a / b;
    cout << c << " " << a << " " << b;
}