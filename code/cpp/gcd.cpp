#include<iostream>
using namespace std;

int gcd(int a,int b){
if(b==0)
return a;
else
return(b,a%b);
}

int main(){
cout<<"input two numbers";
int a,b;
cin>>a>>b;
int g=gcd(a,b);
cout<<"The gcd of a and b is"<<g;
}
