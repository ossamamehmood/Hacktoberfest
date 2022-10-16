#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue
{
    char nama[80];
    char alamat[80];
    char email[80];
    int NIM, id;
    struct queue *next;
} queue;

int insert(queue **front, queue **rear, char nama[80], char alamat[80], char email[80], int NIM)
{
    queue *temp;
    temp = (queue *)malloc(sizeof(queue));
    strcpy(temp->nama, nama);
    strcpy(temp->alamat, alamat);
    strcpy(temp->email, email);
    temp->NIM = NIM;
    temp->id = 1;
    temp->next = NULL;
    if (*front == NULL)
    {
        *front = temp;
    }
    else
    {
        temp->id = (*rear)->id + 1;
        (*rear)->next = temp;
        *rear = temp;
    }
    *rear = temp;
    return 0;
}

int delete (queue **front, queue **rear, char nama[80], char alamat[80], char email[80], int NIM)
{
    // jika queue kosong
    if (*front == NULL)
    {
        printf("Queue is empty\n");
        return 0;
    }
    else if (*front != NULL && (*front)->next == NULL)
    {
        free(*front);
        *front = NULL;
        *rear = NULL;
        printf("Data berhasil dihapus, data kosong.\n");
        return 0;
    }

    int selected_id, i;
    printf("hapus berdasarkan id: ");
    scanf("%d", &selected_id);

    // cursor bakal maju terus sampai id yang diinputkan sama dengan id yang ada di queue
    // precursor adalah pointer sebelum cursor, dan cursor adalah pointer yang sedang ditunjukkan
    queue *cursor, *precursor;
    for (cursor = *front; cursor != NULL; cursor = cursor->next)
    {
        // jika id yang diinputkan sama dengan id yang ada di queue
        // berhenti
        if (cursor->id == selected_id)
        {
            break;
        }

        // jika beda, maka precursor bakal menunjuk ke simpul sekarang
        precursor = cursor;
    }

    if (cursor == *rear)
    {
        // ubah *rear jadi sebelum terakhir
        *rear = precursor;
        precursor->next = NULL;
    }
    else if (cursor == *front)
    {
        // ubah front jadi data selanjutnya
        *front = cursor->next;
    }
    else
    {
        // sambung data sebelum dan sesudahnya
        // precursor -> cursor -> cursor.next
        // a         -> b      -> c
        // jika b di delete harus sambung a dan c
        precursor->next = cursor->next;
    }

    printf("Data dari id %d berhasil dihapus\n", cursor->id);
    free(cursor);
    cursor = NULL;
    return 1;
}

int display(queue *front)
{
    char value[80] = {};
    queue *temp;
    int i;
    temp = front;
    if (temp == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("(%d) - ", temp->id);
            printf("%s_", temp->nama);
            printf("%d_", temp->NIM);
            printf("%s_", temp->alamat);
            printf("%s", temp->email);
            temp = temp->next;
            printf("\n");
        }
    }
    return 0;
}

int modify(queue **front, queue **rear, char nama[80], char alamat[80], char email[80], int NIM)
{
    queue *temp;
    int select;
    temp = *front;
    if (temp == NULL)
    {
        printf("Queue Kosong\n");
    }
    else
    {
        printf("Select the data you want to modify by id: ");
        scanf("%d", &select);
        while (temp != NULL)
        {
            if (temp->id == select)
            {
                printf("masukkan nama: ", temp->nama);
                scanf("%s", temp->nama);
                printf("masukkan NIM: ");
                scanf("%d", &temp->NIM);
                printf("masukkan alamat: ");
                scanf("%s", temp->alamat);
                printf("masukkan email: ");
                scanf("%s", temp->email);
                printf("\nNama berhasil diubah ke %s\n", temp->nama);
                printf("NIM berhasil diubah ke %d\n", temp->NIM);
                printf("Alamat berhasil diubah ke %s\n", temp->alamat);
                printf("Email berhasil diubah ke %s\n", temp->email);
                return 1;
            }
            temp = temp->next;
        }
    }
    return 0;
}

int main()
{
    queue *front = NULL;
    queue *rear = NULL;
    char nama[80], alamat[80], email[80];
    int NIM, id;
    int choice;

    //  data dummy
    // for (int i = 0 ; i < 5 ; i++) {
    //     char a[80], b[80], c[80];
    //     sprintf(a, "nama%d", i);
    //     sprintf(b, "alamat%d", i);
    //     sprintf(c, "email%d", i);
    //     insert(&front, &rear, a, b, c, i);
    // }
    do
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Modify data by id\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n!program ga bisa detect spasi, jangan dimasukkin \n");
            printf("Masukkan Nama: ");
            scanf("%s", nama);
            printf("Masukkan NIM: ");
            scanf("%d", &NIM);
            printf("Masukkan Alamat: ");
            scanf("%s", alamat);
            printf("Masukkan Email: ");
            scanf("%s", email);
            insert(&front, &rear, nama, alamat, email, NIM);
            break;
        case 2:
            delete (&front, &rear, nama, alamat, email, NIM);
            break;
        case 3:
            display(front);
            break;
        case 4:
            modify(&front, &rear, nama, alamat, email, NIM);
            break;
        case 5:
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 5);
    return 0;
}

// muhammad erlangga 21107004