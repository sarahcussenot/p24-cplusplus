# include <iostream>

int add (int a, int b){
    int t = a + b;
    return t;
}


void swap(int* pa, int* pb){
    int t = *pa;
    *pa = *pb;
    *pb = t;
}

int main(){
    int a {5};
    int b {10};
    int* pa = &a;
    int*  pb = &b;
    swap(pa, pb);
    std::cout<<"a = "<<a<<", b = "<<b<<std::endl;
    return 0;
}