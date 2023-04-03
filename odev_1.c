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
    void insertEnd2(node **, node **, node **, int , int);
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

    while(N < n){
        printf("\nLutfen N degerini %d degerin esit ya da buyuk olacak sekilde giriniz: ", n+1);
        scanf("%d", &N);
    }

    ortak = rand() % N + 1;
    printf("\n%d  %d  %d", M, N, ortak);

    for(i=0;i<M-1;i++){
        printf("\nBir");
        insertEnd(&head, N, ortak);    
    }

    for(i=0;i<M-1;i++){
        printf("\nBir");
        insertEnd(&head2, N, ortak);    
    }

    for(i=0;i<M-1;i++){
        printf("\nBir");
        insertEnd2(&head, &head2, &head3, N, ortak);
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

void insertEnd2(node **head, node **head2, node **head3, int N, int ortak){
    int flag = 1;
    int value;
    node *tmp;
    node *tmp2;
    node *tmp3;
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

    while(flag == 1){
        //prev = NULL;
        tmp = *head;
        //tmp2 = *head2;
        tmp3 = *head3;
        flag = 0;
        while((tmp3!=NULL)&&(flag==0)){
            if((tmp3->value == value) || (ortak == value)){
                
                value = rand() % N + 1;
                printf("icicic rand sayi = %d", value);
                flag = 1;
            }
            
            //prev = tmp;
            printf("\nvalue of tmp = %d", tmp->value);
            tmp3 = tmp3->next;
            //printf("\nvalue of tmp2 = %d", tmp->value);
        }
        printf("        flag1=%d", flag);
        while((tmp!=NULL)&&(flag==0)){
            if(tmp->value==value){
                tmp2 = *head2;
                while((tmp2!=NULL)&&(flag==0)){
                    if(tmp2->value == value){
                        value = rand() % N + 1;
                        printf("icicic rand sayi = %d", value);
                        flag = 1;
                    }
                    tmp2 = tmp2->next;
                }
            }
            tmp = tmp->next;
        }
        printf("        flag2=%d", flag);
        
    }

    if(*head3 == NULL){
        newNode->value = value;
        newNode->next = NULL;
        printf("\n          %d");
        *head3 = newNode;
        
    }else{
    node *curr = *head3;
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

