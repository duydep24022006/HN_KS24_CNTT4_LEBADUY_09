#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Product
{
    int Id;
    char Name[100];
    float Price;
    int Quantity;
}Product;
typedef struct NodeSingly
{
    Product data;
    struct NodeSingly *next;
}NodeSingly;
typedef struct NodeDoubly
{
    Product data;
    struct NodeDoubly *next;
    struct NodeDoubly *prev;
}NodeDoubly;

NodeSingly* createNodeSingly(Product pr)
{
    NodeSingly *newNode = (NodeSingly *)malloc(sizeof(NodeSingly));
    newNode->data = pr;
    newNode->next = NULL;
    return newNode;
}
NodeDoubly* createNodeDoubly(Product pr)
{
    NodeDoubly *newNode = (NodeDoubly *)malloc(sizeof(NodeDoubly));
    newNode->data = pr;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void printMenu()
{
    printf("\n        MENU\n");
    printf("1. Them san pham.\n");
    printf("2. Hien thi danh sach san pham.\n");
    printf("3. Xoa san pham theo id.\n");
    printf("4. Cap nhat thong tin san pham.\n");
    printf("5. Danh dau danh sach sach pham da ban.\n");
    printf("6. Hien thi danh sach sach pham da ban.\n");
    printf("7. Sap xep san pham theo gia tang dan.\n");
    printf("8. Tim kiem san pham theo ten.\n");
    printf("9. Thoat truong trinh.\n");
    printf("Lua chon cua ban: ");

}
void inserNodeSingly(NodeSingly **head, Product pr)
{
    NodeSingly *newNode = createNodeSingly(pr);
    if(*head == NULL)
    {
        *head = newNode;
        printf("them thanh cong\n");
        return;
    }
    NodeSingly *temp = *head;
    while(temp != NULL)
    {
        if (strcmp(temp->data.Name,pr.Name)==0)
        {
            printf("ten san pham trung\n");
            free(newNode);
            return;
        }
        if (temp->next == NULL)
            break;
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = NULL;

    printf("them thanh cong\n");

}
void displayNodeSingly(NodeSingly *head)
{
    if(head == NULL)
    {
        printf("khong co san pham!\n");
        return;
    }
    NodeSingly *temp = head;
    int count = 1;
    while(temp != NULL)
    {
        printf("San pham thu: %d\n",count++);
        printf("Ma san pham: %d\n",temp->data.Id);
        printf("Ten san pham: %s\n ",temp->data.Name);
        printf("Gia san pham: %f \n",temp->data.Price);
        printf("So luong san pham: %d \n",temp->data.Quantity);
        printf("\n");
        temp = temp->next;
    }
}
void displayNodeDoubly(NodeDoubly *head)
{
    if(head == NULL)
    {
        printf("khong co san pham!\n");
        return;
    }
    NodeDoubly *temp = head;
    int count = 1;
    while(temp != NULL)
    {
        printf("San pham thu: %d\n",count++);
        printf("Ma san pham: %d\n",temp->data.Id);
        printf("Ten san pham: %s\n ",temp->data.Name);
        printf("Gia san pham: %f \n",temp->data.Price);
        printf("So luong san pham: %d \n",temp->data.Quantity);
        printf("\n");
        temp = temp->next;
    }
}
void removeAtIdNodeSingly(NodeSingly **head, int id)
{
    if(*head == NULL)
    {
        printf("khong co san pham!\n");
        return;
    }
    NodeSingly *temp = *head;
    NodeSingly *prev = NULL;
    while(temp != NULL&&temp->data.Id !=id)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)
    {
        printf("khong tim thay san pham!\n");
        return;
    }
    if (prev == NULL)
    {
        *head = temp->next;
    }else
    {
        prev->next = temp->next;
    }
    free(temp);
    printf("xoa thanh cong");
}
void editProduct(NodeSingly **head, int id)
{
    if(*head == NULL)
    {
        printf("khong co san pham!\n");
        return;
    }
    NodeSingly *temp = *head;
    while(temp != NULL&&temp->data.Id !=id)
    {
        temp = temp->next;
    }
    if(temp == NULL)
    {
        printf("khong tim thay san pham!\n");
        return;
    }

    printf("Ten san pham: ");
    scanf("%s",temp->data.Name);
    getchar();
    printf("Gia san pham: ");
    scanf("%f",&temp->data.Price);
    printf("So luong san pham: ");
    scanf("%d",&temp->data.Quantity);
    printf("xua san pham thanh cong");
}
void markNode(NodeSingly **headSingly,NodeDoubly **headDoubly, int id)
{
    if(*headSingly == NULL)
    {
        printf("khong co san pham!\n");
        return;
    }
    NodeSingly *temp = *headSingly;
    NodeSingly *prev = NULL;
    while(temp != NULL && temp->data.Id !=id)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)
    {
        printf("khong tim thay san pham!\n");
        return;
    }
    NodeDoubly *newNode = createNodeDoubly(temp->data);


    newNode->next = *headDoubly;
    newNode->prev = NULL;
    if (*headDoubly != NULL)
    {
        (*headDoubly)->prev = newNode;
    }
    *headDoubly = newNode;


    if (prev == NULL)
    {

        *headSingly = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    free(temp);
    temp = NULL;
    printf("da danh dau thanh cong\n");
}
void bubbleSort(NodeSingly *head)
{
    if(head == NULL||head->next == NULL)
    {
        return;
    }
    int swapped ;
    Product temp;
    do
    {
        swapped = 0;
        NodeSingly *ptr=head;
        while(ptr->next!=NULL)
        {
            if (ptr->next->data.Price<ptr->data.Price)
            {
                temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }

    }while(swapped);
}
void searchName(NodeSingly* head)
{
    if(head == NULL)
    {
        printf("khong co san pham!\n");
        return;
    }
    NodeSingly *temp = head;
    while(temp != NULL)
    {
        if(strcmp(temp->data.Name,head->data.Name)==0)
        {
            break;
        }
        temp = temp->next;
    }
    if(temp == NULL)
    {
        printf("khong tim thay san pham!\n");
        return;
    }
    printf("Ma san pham: %d\n",temp->data.Id);
    printf("Ten san pham: %s\n ",temp->data.Name);
    printf("Gia san pham: %f \n",temp->data.Price);
    printf("So luong san pham: %d \n",temp->data.Quantity);

}
int main()
{
    int choice,id;
    int countId=1;
    NodeSingly *headSingly = NULL;
    NodeDoubly *headDoubly = NULL;
    do
    {
        printMenu();
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                Product* pr=(Product*)malloc(sizeof(Product));
                pr->Id=countId;
                printf("Ten san pham: ");
                scanf("%s",pr->Name);
                getchar();
                printf("Gia san pham: ");
                scanf("%f",&pr->Price);
                printf("So luong san pham: ");
                scanf("%d",&pr->Quantity);
                inserNodeSingly(&headSingly,*pr);
                countId++;
                break;
            case 2:
                displayNodeSingly(headSingly);
                break;
            case 3:
                printf("Ma san pham: ");
                scanf("%d",&id);
                removeAtIdNodeSingly(&headSingly,id);
                break;
            case 4:
                printf("Ma san pham: ");
                scanf("%d",&id);
                editProduct(&headSingly,id);
                break;
            case 5:
                printf("Ma san pham: ");
                scanf("%d",&id);
                markNode(&headSingly,&headDoubly,id);
                break;
            case 6:
                displayNodeDoubly(headDoubly);
                break;
            case 7:
                bubbleSort(headSingly);
                break;
            case 8:
                char Name[100];
                printf("Ten san pham: ");
                scanf("%s",Name);
                searchName(headSingly);
                break;
            case 9:
                printf("Thoat truong trinh thanh cong\n");
                break;
            default:
                printf("Loi cu phap\n");
        }
    }
    while (choice!=9);
    return 0;
}