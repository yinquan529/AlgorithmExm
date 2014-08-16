#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define false 0;
#define true 1;

void swap(char* a, char* b){
    char t = *a;
    *a = *b;
    *b = t;
}

void Reverse(char *a, char *b){
    while (a < b)
        swap(a++,b--);
}

int Next_permutation(char a[]){
    char *pEnd = a + strlen(a);
    if( a == pEnd)
        return false;

    char *p, *q, *pFind;
    pEnd--;
    p = pEnd;

    while( p != a){
        q = p;
        --p;
        if (*p < *q) {
            pFind = pEnd;
            while(*pFind <= *p)
                --pFind;
            swap(pFind,p);
            Reverse(q, pEnd);
            return true;
        }
    }

    Reverse(q,pEnd);
    return false;
}

int QsortCmp(const void *pa, const void *pb){
    return *(char*)pa - *(char*)pb;
}


int main(){
    char szTextStr[] = "abcd";
    printf("%s\n",szTextStr);
    qsort(szTextStr, strlen(szTextStr),sizeof(szTextStr[0]),QsortCmp);
    int i =1;
    do{
        printf("%3d \t %s \n", i++, szTextStr);
    }while(Next_permutation(szTextStr));

    return 0;
}
