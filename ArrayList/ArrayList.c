#include <stdlib.h>
#include <stdio.h>

#include "ArrayList.h"


int arrayCompare(void* data1, void* data2, storetype type){

    switch(type){
        case INT_TYPE:
           if ((*((int*)data1)) ==  (*((int*)data2))){
               return 0;
           }else if ((*((int*)data1)) > (*((int*)data2))){
               return 1;
           }else{
               return -1;
           }
        break;
        defaut:
        break;
    }
}


void main(){
    state result = StateNone;
    spList arrayList;

    result = initList(&arrayList, INT_TYPE);
    printf("The size of ArrayList is %d\n", arrayList.size);

    int data = 5;
    result = insertElem(&arrayList,1,&data);
    
    data = 6;
    result = insertElem(&arrayList,2,&data);

    printf("The eleme 1 is %d\n", *((int*)(arrayList.data)));
    printf("The eleme 2 is %d\n", *((int*)(arrayList.data)+1));

    int pos = locateElem(&arrayList,&data,arrayCompare);
    printf("The pos is %d\n",pos);


}


state initList(spList* L, storetype type){
    
    switch (type){
        case INT_TYPE:
            L->data = malloc(LIST_INIT_SIZE*sizeof(int));
        break;
        defaut:
        break;
    }

    if(!L->data){
        return StateBad; 
    }

    L->length = 0;
    L->size = LIST_INIT_SIZE;
    L->type = type;
    return StateOK;
}

int locateElem(spList*L, void* data, Compare compare){
    int i = 1;
    void* p = L->data;
    
    size_t typesize = 0;
    switch(L->type){
        case INT_TYPE:
            typesize = sizeof(int);
        break;
        default:
        break;
    }

    while( i <= L->length && (*compare)(p, data, L->type)){
        ++i;
        p += typesize;
    }

    if(i <= L->length){
        return i;
    }else{
        return -1;
    }
}

state insertElem(spList* L, int pos, void * data){
    size_t typesize = 0;
    switch(L->type){
        case INT_TYPE:
            typesize = sizeof(int);
        break;
        default:
        break;
    }


    if( pos < 1 || pos > L->length+1){
        return StateError;
    }

    if(L->length >= L->size){
        void * newbase = realloc(L->data,L->size + LIST_INCREMENT*typesize); 
        if (!newbase){
            return StateError;
        }

        L->data = newbase;
        L->size += LIST_INCREMENT;

    }

    void* q = L->data + (pos-1)*typesize;
    void* p = L->data + (L->length-1)*typesize;

    for(; p >= q; p -= typesize){
        switch(L->type){
            case INT_TYPE:
                *((int*)p +1) = *((int*)p);
            break;
            default:
            break;
        }
    }

    switch(L->type){
        case INT_TYPE:
            *((int*)q) = *((int*)data);
        break;
        default:
        break;
    }
    
    ++L->length;
    return StateOK;
}

