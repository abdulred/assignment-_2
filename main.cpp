
#include<iostream>
#include"stack.cpp"
#include<string>

using namespace std;

int main(){
  display();
 //string exp = "a+b*(c^d-e)^(f+g*h)-i";
  calc<string> d;
  
d.topostfix("a+b*(c^d-e)^(f+g*h)-i");
    return 0;
}

