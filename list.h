#ifndef LIST_H
#define LIST_H
typedef struct
{
int value;
}Data;

typedef struct node
 {
 Data data;
 struct node * next;
 struct node * prev;
 }Node;

typedef struct
 {
 Node * head;
 Node * tail;
 }List;

typedef struct
 {
List *list;
 }Stack;
 
 typedef struct
 {
List *list;
 }Queue;

List * createList();
void insertData(List * , int , Data );
void removeData(List * , int );
Data * readData(List * , int );
int isEmpty(List *);
void deleteList(List * );
int searchForward(List *, Data);
int searchBackward(List *, Data);
void push(Stack *, Data);
Data pop(Stack *);
void enqueue(Queue *, Data);
Data dequeue(Queue *);
Data * readTailData(List * list);
void removeTailData(List *list);

#endif
