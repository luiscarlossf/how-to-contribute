// Just a simple Tower of Hanoi code using recursion

#include <iostream>
using namespace std;

void TOH(int n,char x,char y,char z){
    if(n==1)
        cout<<"Move top disk from "<<x<<" to "<<z<<std::endl;
    else{
        TOH(n-1,x,z,y);
        TOH(1,x,y,z);
        TOH(n-1,y,x,z);
    }
    
}

int main() {
    int num;
    char x,y,z;
    cout << "Hello, How many disks you want to make your tower with?\n";
    cin>>num;
    cout<<"Name your towers respetively\n";
    cin>>x>>y>>z;
    TOH(num,x,y,z);
    return 0;
}
