#include <string>
#include <iostream>
#include "Builtins.cpp"
#pragma GCC diagnostic ignored "-Wunused-value"

Int add(Int b,Int a) {
Int tmp_1 = a.PLUS(b);
return tmp_1;
}

String hello(String name) {
String tmp_2 = String("hello");
String tmp_3 = String(" ");
String tmp_4 = tmp_2.PLUS(tmp_3);
String tmp_5 = tmp_4.PLUS(name);
return tmp_5;
}

int main() {
Int tmp_6 = Int(2);
Int tmp_7 = Int(1);
Int tmp_8 = add(tmp_6,tmp_7);Int num = tmp_8;
String tmp_9 = String("Jeff");
String tmp_10 = hello(tmp_9);String phrase = tmp_10;
Nothing tmp_11 = phrase.PRINT();tmp_11;
Nothing tmp_12 = num.PRINT();tmp_12;
return 0;
}