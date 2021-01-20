#include"Data.h"
int dataArray[2]={0,0};
char moveArray[4]={'S','0','0','0'};

bool checkValid(char in){//a function to validate input TCP data
char validData[]={'F','B','L','R','S','1','2','3','4','5','6','7','8','9'};
for (int i =0; i<sizeof(validData); i++){
   if(in==validData[i]){
    return true;
    }
  }
 return false;
}
