#include <stdio.h>

//clang compiler behavior 
int main(){
    int i = 0;
    printf("Output : %d, %d, %d ", i, i++, i++);
    //Output : 0, 0, 1
    return 0;
}