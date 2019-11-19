#include "shygame.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
typedef struct node{
    int data;
    struct node* next;
}NODE;

typedef struct{
    int node_count;
    NODE* head;
    NODE* tail;
}QUEUE;

void enqueue(QUEUE* queue,int num){
    NODE* p = new NODE;
    p->data = num;
    p->next= NULL;
    if(queue->node_count==0){
        queue->head = p;
        queue->tail = p;
    }
    else{
        queue->tail->next = p;
        queue->tail = p;
    }
    queue->node_count++;
}
void printQueue(QUEUE* queue){
    NODE* p = new NODE;
    p = queue->head;
    int count=0;
    while(count != queue->node_count){
        cout<<p->data<<"->";
        count++;
        p=p->next;
    }
    cout<<endl;
    free(p);
}

void dequeue(QUEUE* queue,int n){
    NODE* p = new NODE;
    NODE* del_p = new NODE;
    while(queue->node_count>1){
        p = queue->head;
        del_p = p;
        if(n==1){
            del_p = queue->head;
            queue->head = queue->head->next;
            free(del_p);
            queue->node_count--;
        }
        else{
            for(int i=0;i<n-2;i++){
                del_p=del_p->next;
            }
            p = del_p;
            del_p = del_p->next;
            p->next = del_p->next;
            if(del_p == queue->tail) queue->tail = p;
            free(del_p);
            queue->head = p->next;
            queue->node_count--;
        }

        /*p=del_p;
        del_p = del_p->next;
        p->next = del_p->next;
        free(del_p);
        p = p->next;
        queue->node_count--;*/
    }
}

Shygame::Shygame()
{

}

string Shygame::solve(string s){
    stringstream ss;
    ss<<s;
    int total;
    ss>>total;
    int n;
    string result="";
    while(ss>>n){
        QUEUE* queue = new QUEUE;
        queue->node_count=0;
        queue->head=NULL;
        queue->tail=NULL;
        for(int i=1;i<=total;i++){
            enqueue(queue,i);
        }
        //head and tail
        queue->tail->next = queue->head;

        //dequeue
        dequeue(queue,n);
        result.append(to_string(queue->head->data)+' ');
        //printQueue(queue);
        free(queue);
    }
    result.erase(result.length()-1);

    return result;
}
