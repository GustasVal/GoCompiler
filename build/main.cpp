#include <string>
#include <iostream>
#include "Builtins.cpp"
#pragma GCC diagnostic ignored "-Wunused-value"

Int loop(Int x) {
Int y = x;
Int tmp_1 = Int(5);
Bool tmp_2 = tmp_1.GT(y);
if ("true" == tmp_2.val) {
Int tmp_3 = Int(1);
Int tmp_4 = y.PLUS(tmp_3);
y = tmp_4;
Nothing tmp_5 = y.PRINT();tmp_5;
Int tmp_6 = loop(y);tmp_6;
} else {
return y;
}

Int tmp_7 = Int(0);
return tmp_7;
}

int main() {
Int tmp_8 = Int(1);
Int tmp_9 = loop(tmp_8);Nothing tmp_10 = tmp_9.PRINT();tmp_10;
return 0;
}