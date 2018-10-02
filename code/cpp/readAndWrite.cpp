#include <iostream>
using namespace std;

struct element
{
	int data;
	int priority;
	struct element *next;
};

bool empty (element *first){	if (first == NULL) return true;
	return false;
}

void make_null(element** first)
{
	element* position = *first; //start of list
	while (position != NULL) {
		*first = position->next; //next
		delete position;	//delete current one
		position=*first;
	}
    *first=NULL;
}

void insert(element** first, int number, string ime){ 
     element* position = *first;
     element* novi=new element;
     novi->data=ime;
     novi->priority=number;
     if(position==NULL){  //if list is empty
           novi->next=position;
           *first=novi;
     }
     else {
          while (position->next!=NULL && number>priority_s(position)){
               position=position->next;
          }
          novi->next=position->next;
          position->next=novi;
          
     }
}

void delete_min (element **first){ // delete number from list
	if (empty(*first)) return;
	element *position = *first;
	*first = position->next;
	delete position;
	return;
}

int main(){
    int number;
    float anotherNumber;
    string name;
    cout<<"Number: "<<endl;
    cin>>number;
    cout<<"Another number: "<<endl;
    cin>>anotherNumber;
    cout<<"Name: "<<endl;
    cin>>name;
    return 0;
}
