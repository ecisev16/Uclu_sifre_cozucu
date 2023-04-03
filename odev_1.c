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
    int yer, yer2, yer3;
    int ikinci, ucuncu;

    node* createNode();
    void insertEnd(node**, int, int);
    void insertEnd2(node **, node **, node **, int , int);
    void printLists(node**);
    int ortakSayiYerlestirme(node **, int , int);
    int ortakSayiveYeri(node **, node **, node **);
    int hangiYoneKacTur(int, int, int);

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

    yer = ortakSayiYerlestirme(&head, ortak, M);
    yer2 = ortakSayiYerlestirme(&head2, ortak, M);
    yer3 = ortakSayiYerlestirme(&head3, ortak, M);

    printLists(&head);
    printf("\n\n");
    printLists(&head2);
    printf("\n\n");
    printLists(&head3);

    printf("\nyer=%d\tyer2=%d\tyer3=%d", yer, yer2, yer3);
    ortakSayiveYeri(&head, &head2, &head3);
    ikinci = hangiYoneKacTur(yer, yer2, M);
    ucuncu = hangiYoneKacTur(yer, yer3, M);



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

        if((*head3 == NULL) && (value == ortak)){
            flag = 1;
        }
        
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

int ortakSayiYerlestirme(node **head, int ortak, int M){
    int yer = rand() % M;
    int i;
    node *newNode = createNode();
    node *curr = *head;
    node *prev = NULL;

    printf("    %d", yer);

    if(yer==0){
        newNode->value = ortak;
        newNode->next = curr;
        *head = newNode;
    }else{

        for(i=0;i<yer;i++){
            prev = curr;
            curr = curr->next;
        }
        newNode->value = ortak;
        prev->next = newNode;
        newNode->next = curr;
    }

    return yer;
}

int ortakSayiveYeri(node **head, node **head2, node **head3){
    node *tmp = *head;
    node *tmp2 = *head2;
    node *tmp3 = *head3;
    int i=0, i2=0, i3=0;
    int flag = 0;

    while((tmp!=NULL)&&(flag==0)){
        i++;
        i2 = 0;
        tmp2 = *head2;
        while((tmp2!=NULL)&&(flag==0)){
            i2++;
            i3 = 0;
            tmp3 = *head3;
            if(tmp->value == tmp2->value){
                while((tmp3!=NULL)&&(flag==0)){
                    i3++;
                    if(tmp->value == tmp3->value){
                        flag = 1;
                        printf("\nOrtak deger = %d", tmp->value);
                    }
                    tmp3 = tmp3->next;
                }
            }
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }

    printf("\ni=%d\ti2=%d\ti3=%d\n", i, i2, i3);
}

int hangiYoneKacTur(int yer, int yer2, int M){
    int sayi, sayi2, sayi3, sayi4, mesafe, mesafe2, x;
    
    printf("\nSayinin onundeki eksi deger ters yönde çevrilmesi gerektigini belirtir.\n");

    sayi = yer - yer2;
    printf("\nmesafe1=%d", sayi);
    if(sayi<=0){
        x = yer + M;
        sayi2 = x - yer2;
        printf("\nmesafe2=%d", sayi2);
    }else if(sayi>0){
        x = yer2 + M;
        sayi2 = yer - x;
        printf("\nmesafe2=%d", sayi2);
    }
    
    if(abs(sayi) <= abs(sayi2)){

        printf("\nmesafe    =   %d", sayi);
        return sayi;
    }else if(abs(sayi2) < abs(sayi)){
        printf("\nmesafe    =   %d", sayi2);
        return sayi2;
    }

}


