#ifndef ARRAY_LIST
#define ARRAY_LIST

#define LIST_INIT_SIZE 80
#define LIST_INCREMENT 10

typedef enum StoreType{
    INT_TYPE
} storetype;

typedef enum State {
    StateOK,
    StateBad,
    StateError,
    StateNone
} state;

typedef struct ArrayList{
   int length;
   int size;
   storetype type;
   void* data;
} spList;

typedef int (*Compare)(void* data1, void* data2, storetype type); 

state initList(spList* L, storetype type);
int locateElem(spList* L, void* data, Compare compare);
state insertElem(spList* L, int pos, void* data);
state deleteElem(spList* L, int pos, void* data);
void getList();



#endif //ARRAY_LIST
