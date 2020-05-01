#include <string>
#include <iostream>
#include "Builtins.cpp"
#pragma GCC diagnostic ignored "-Wunused-value"

Int test(Int x) {
Int tmp_1 = Int(0);
Int y = tmp_1;
Int tmp_2 = Int(5);
Bool tmp_3 = y.GT(tmp_2);
if ("true" == tmp_3.val) {
Int tmp_4 = Int(5);
y = tmp_4;
} else {
Int tmp_5 = Int(8);
y = tmp_5;
}

return y;
}

int main() {
Int tmp_6 = Int(5);
Int tmp_7 = test(tmp_6);Nothing tmp_8 = tmp_7.PRINT();tmp_8;
return 0;
}