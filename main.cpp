#include <iostream>
#include <stdlib.h>
void Func1(){
    std::cout<<__FUNCTION__ <<std::endl;
}
void Func2(){
    std::cout<<__FUNCTION__ <<std::endl;
}
int main() {
    atexit(Func1);
    atexit(Func2);
//    exit(0);
    return 0;
}