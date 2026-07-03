#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char isim[40];
    int yas;
    int boy;
    int dogumTarihi[3];
} kisi;

void bilgileriAl (kisi *kisiler, int kisiSayisi){
    
    printf ("kisi bilgilerini giriniz:\n");
    for (int i=0; i<kisiSayisi; i++){
        printf ("%d. kisinin ismi: ", i+1);
        scanf ("%39s", kisiler[i].isim);
        printf ("%d. kisinin yasi: ", i+1);
        scanf ("%d", &kisiler[i].yas);
        printf ("%d. kisinin boyu: ", i+1);
        scanf ("%d", &kisiler[i].boy);
        printf ("%d. kisinin dogum tarihi (gun ay yil): ", i+1);
        scanf ("%d %d %d", &kisiler[i].dogumTarihi[0], &kisiler[i].dogumTarihi[1], &kisiler[i].dogumTarihi[2]); 
     }
}

void bilgileriGuncelle (kisi *kisiler, int kisiSayisi){
    char arananIsim[40];
    int bulundu = 0;
printf ("kisi bilgilerini guncellemek istediginiz kisinin ismini giriniz: ");
scanf ("%39s", arananIsim);

for (int i=0; i<kisiSayisi; i++){

    if (strcmp(kisiler[i].isim, arananIsim) == 0){
     bulundu = 1;
    int secim;
 printf ("\n%s adli kisi bulundu. hangi bilgilerini guncellemek istiyorsunuz?\n", arananIsim);
 printf ("1. isim\n2. yas\n3. boy\n4. dogum tarihi\nSeciminizi giriniz: ");
 scanf ("%d", &secim);

 switch (secim){
    case 1:
        printf ("yeni ismi giriniz: ");
        scanf ("%39s", kisiler[i].isim);
        break;
    case 2:
        printf ("yeni yasi giriniz: ");
        scanf ("%d", &kisiler[i].yas);
        break;
    case 3:
        printf ("yeni boyu giriniz: ");
        scanf ("%d", &kisiler[i].boy);
        break;
    case 4:
        printf ("yeni dogum tarihini giriniz (gun ay yil): ");
        scanf ("%d %d %d", &kisiler[i].dogumTarihi[0], &kisiler[i].dogumTarihi[1], &kisiler[i].dogumTarihi[2]);
        break;
    default:
        printf ("gecersiz secim!\n");
        break;
 }
 break;
}

}
if (!bulundu){
    printf ("%s adli kisi bulunamadi.\n", arananIsim);
}
int devam;
printf("baska kisi bilgilerini guncellemek istiyor musunuz? (1: Evet, 0: Hayir): ");
scanf("%d", &devam);
if (devam == 1) {
    bilgileriGuncelle(kisiler, kisiSayisi);
} else {
    printf("Guncelleme islemi tamamlandi.\n\n");
}
}


void bilgileriYazdir (kisi *kisiler, int kisiSayisi){
    printf ("kisi bilgileri:\n");
    for (int i=0; i<kisiSayisi; i++){
        printf ("%d. kisinin ismi: %s\n", i+1, kisiler[i].isim);
        printf ("%d. kisinin yasi: %d\n", i+1, kisiler[i].yas);
        printf ("%d. kisinin boyu: %d\n", i+1, kisiler[i].boy);
        printf ("%d. kisinin dogum tarihi: %d.%d.%d\n", i+1, kisiler[i].dogumTarihi[0], kisiler[i].dogumTarihi[1], kisiler[i].dogumTarihi[2]);
        printf("********************\n");
 }
}

void dosyayaYazdir (kisi *kisiler, int kisiSayisi){
    FILE *dosya = fopen("kisiler.txt", "w");
    if (dosya == NULL) {
        printf("Dosya acilamadi!\n");
        return;
    }
    
    for (int i=0; i<kisiSayisi; i++){
        fprintf(dosya, "%s %d %d %d.%d.%d\n", kisiler[i].isim, kisiler[i].yas, kisiler[i].boy, kisiler[i].dogumTarihi[0], kisiler[i].dogumTarihi[1], kisiler[i].dogumTarihi[2]);    
    }
    fclose(dosya);
}

int main (){

int kisiSayisi;
printf (" kac kisi bilgisi gireceksiniz: ");
scanf ("%d", &kisiSayisi);

kisi *kisiler = (kisi *) malloc (kisiSayisi * sizeof(kisi));

if (kisiler == NULL) {
        printf("Bellek yetersiz!");
        return 1;
}

bilgileriAl(kisiler, kisiSayisi);
bilgileriGuncelle(kisiler, kisiSayisi);
bilgileriYazdir(kisiler, kisiSayisi);
dosyayaYazdir(kisiler, kisiSayisi);
free(kisiler);
return 0;
}
