#include<iostream>
#include<cstring>

]

using namespace std;

int min(int a,int b) {
   return ((a < b) ? a : b);
}



int editDistance(char str1[],int size1,char str2[],int size2) {

   int cost[size1][size2];
   int i,j;
   for (i=0;i<size1;i++) {
      for(j=0;j<size2;j++) {
         if (i == 0) {

            cost[i][j] = j*INSERT_COST;
         } else if (j == 0) {
            cost[i][j] = i*DELETE_COST;
         } else {
            cost[i][j] = -1;
         }
      }
   }
   for(i=1;i<size1;i++) {
      for(j=1;j<size2;j++) {
         int x = cost[i-1][j] + DELETE_COST;
         int y = cost[i][j-1] + INSERT_COST;
   
         int z = cost[i-1][j-1] + (str1[i-1] != str2[j-1])*REPLACE_COST;
         cost[i][j] = min(x, min(y,z));
      }
   }

   return cost[size1-1][size2-1];
}

int main() {
   char str1[] = "sunflower";
   char str2[] = "sunlight";
   int size1 = strlen(str1);
   int size2 = strlen(str2);
   int min_cost = editDistance(str1,size1+1,str2,size2+1);
   cout<<"\nMinimum edits required to convert "<<str1<<
                                       " to "<<str2<<" is "<<min_cost;
   cout<<endl;
   return 0;
}

