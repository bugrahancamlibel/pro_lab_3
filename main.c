#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node node;
struct node {
    int x;
    char *word;
    struct node* next;
};

/*void bastir(node* r) {
    while (r!= NULL) {
        printf("%d \n", r->x);
        r = r->next;
    }
}*/


/*void sona_ekle(node* r,int a) {
    while(r->next!=NULL){
        r = r->next;
    }
    r->next = (node*)malloc(sizeof (struct node));
    r->next->x = a;
    r->next->next = NULL;
}*/

void bastir(node* r) {
    while (r!= NULL) {
        printf("%s \n", r->word);
        r = r->next;
    }
}

void sona_ekle(node* r,char *kelime,int a) {
    while(r->next!=NULL){
        r = r->next;
    }
    r->next = (node*)malloc(sizeof (struct node));
    r->next->word = malloc(strlen(kelime)+1);
    strcpy(r->next->word,kelime);
    r->next->x = a;
    //printf("%s ",r->next->word);
    r->next->next = NULL;

}


int main() {

    FILE *dosya;
    dosya = fopen("C:\\Users\\BUGRA\\CLionProjects\\pro_lab_3\\metin.txt","r");
//    printf("%c",fgetc(dosya));


    node* root;
    int i = 0;
    char kelime[100];
    root = (node*)malloc(sizeof(node));
    root->x = 10;
    root->word = malloc(strlen(" ")+1);
    strcpy(root->word," ");
    root->next = (node*)malloc(sizeof(node));
    root ->next = NULL;
    node* iter = root;
    /*for (int j = 0; j <4; j++) {
        sona_ekle(root,j);
    }*/
    //bastir(root);

    if(dosya==NULL){
        printf("Dosya bulunamadi...");
    }
    else {
        while (!feof(dosya)) {
            fscanf(dosya,"%s",&kelime);
            /*for (arama algoritması kelimenin aynısından var mı node ların içine bakıyore)
                node ların içinde yoksa bütün metni arayan arama algoritması çalışanzi
                kaç tane olduğunu bulsun sallıyorum int sayisi = 4;
                aga şuan farkettim bi de en fazla tekrar eden kelimenin kaç kez tekrar ettiğini de tutmamız lazım
                şöyle diyelim int en_fazla=6; ->> if(sayisi>=en_fazla) basa_ekle();
                sonra da if(sayisi==1) sona_ekle

             */
            sona_ekle(root,&kelime,6);
        }
    }
    bastir(root);
    return 0;
}