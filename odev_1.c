#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node{
    int value;
    struct node *next;
}node;

int main(){
    int N=0, M;
    int ortak;
    int n;
    int i;
 

    node* createNode();
    void insertEnd(node**, int, int);
    void printLists(node**);

    node *head = NULL;
    node *head2 = NULL;
    node *head3 = NULL;
    
    node *tmp;
    srand(time(NULL));

    printf("Lutfen M degerini giriniz: ");
    scanf("%d", &M);

    n = ((M-1)*3) / 2;
    if((((M-1)*3) % 2) == 1){
        n++;
    }

    while(N <= n){
        printf("\nLutfen N degerini %d degerinden buyuk olacak sekilde giriniz: ", n);
        scanf("%d", &N);
    }

    ortak = rand() % N + 1;
    printf("\n%d  %d  %d", M, N, ortak);

    for(i=0;i<M;i++){
        printf("\nBir");
        insertEnd(&head, N, ortak);    
    }

    for(i=0;i<M;i++){
        printf("\nBir");
        insertEnd(&head2, N, ortak);    
    }

    for(i=0;i<M;i++){
        printf("\nBir");
        insertEnd(&head3, N, ortak);    
    }

    printLists(&head);
    printf("\n\n");
    printLists(&head2);
    printf("\n\n");
    printLists(&head3);


    return 0;
}

void printLists(node **head){
    node *tmp = *head;
    while(tmp != NULL){
        printf("\n%d", tmp->value);
        tmp = tmp->next;
        
    }
}

node* createNode(){
    printf("\niki");
    node *ptr;
    ptr = (node*)malloc(sizeof(node));
    if(ptr == NULL){
        printf("Allocation error\n");
        exit(-16);
    }
    //ptr->next = NULL;
    return ptr;
}

void insertEnd(node **head, int N, int ortak){
    int flag = 1;
    int value;
    node *tmp;
    node *prev;
    node *newNode = createNode();
    printf("%d", newNode);

    printf("\nuc");
    value = rand() % N + 1;
    printf("    rand sayi: %d", value);
    while(value == ortak){
        value = rand() % N + 1;
        printf("    iç rand sayi: %d", value);
    }

    if(*head == NULL){
        newNode->value = value;
        newNode->next = NULL;
        printf("\n          %d");
        *head = newNode;
        
    }else{
    

    while(flag == 1){
        //prev = NULL;
        tmp = *head;
        flag = 0;
        while((tmp!=NULL)&&(flag==0)){
            if((tmp->value == value) || (ortak == value)){
                
                value = rand() % N + 1;
                printf("icicic rand sayi = %d", value);
                flag = 1;
            }
            //prev = tmp;
            printf("\nvalue of tmp = %d", tmp->value);
            tmp = tmp->next;
            //printf("\nvalue of tmp2 = %d", tmp->value);
        }
        printf("        flag=%d", flag);
        
    }

    node *curr = *head;
    while(curr->next!=NULL){
        curr = curr->next;
    }
    newNode->value = value;
    newNode->next = NULL;
    curr->next = newNode;

    
    printf("\nvalue of tmp2 = %d", curr->next->value);
    
    }
    

    
    return;
}


