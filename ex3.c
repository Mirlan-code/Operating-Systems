#include <stdio.h>
#include <stdlib.h>

struct node{
        int data;
        struct node *next;
};
void print_list(struct node *list) {
        struct node *cur = list;
        while (cur->next != NULL) {
                cur = cur->next;
                printf("%d ", cur->data);
        }
        printf("\n");
}
void insert(struct node *list, int x){
        struct node *cur = list;
        while(cur->next != NULL){
                cur = cur->next;
        }
        cur->next = malloc(sizeof(struct node));
        cur->next->data = x;
        cur->next->next = NULL;
}
void _delete(struct node *list, int x){
        struct node *cur = list;
        struct node *prev;
        while(cur->next!=NULL){
                prev = cur;
                cur = cur->next;
                if(cur->data == x){
                        prev->next = cur->next;
                        break;
                }
        }
}

int main(){
        int n;
        scanf("%d", &n);
        struct node *list = NULL;
        list = malloc(sizeof(struct node));
        for(int i = 0; i < n; i++){
                // 0 - print list
                // 1 - insert node
                // 2 - delete node
                int type;
                scanf("%d", &type);
                if(type == 0){
                        print_list(list);
                }
                else if(type == 1){
                        int x;
                        scanf("%d", &x);
                        insert(list, x);
                }
                else{
                        int x;
                        scanf("%d", &x);
                        _delete(list, x);
                }
        }
        return 0;
}