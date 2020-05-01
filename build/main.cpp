#include <string>
#include <iostream>
#include "Builtins.cpp"

int main() {
Int tmp_1 = Int(5);
Int tmp_2 = Int(5);
Int tmp_3 = tmp_1.PLUS(tmp_2);
Int x = tmp_3;
Nothing tmp_4 = x.PRINT();tmp_4;
return 0;
}