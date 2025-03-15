#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Hasta bilgisi yapisi
struct Hasta {
    char isim[50];
    char tcKimlikNo[12];
    int yas;
    char cinsiyet[10];
    char tani[100];
    int oncelik;  
    char servis[50]; 
};

// Ilac bilgisi yapisi
struct Ilac {
    char isim[50];
    int miktar;
    int adet;
};

// Recete numarasi ureten fonksiyon
int receteNoUret() {
    return rand() % 10000;
}

// Hastaya uygun servisi belirleyen fonksiyon
void servisAta(struct Hasta *h) {
    if (strcmp(h->tani, "kalp krizi") == 0 || strcmp(h->tani, "carpinti") == 0) {
        strcpy(h->servis, "Kardiyoloji");
    } else if (strcmp(h->tani, "beyin kanamasi") == 0 || strcmp(h->tani, "bas agrisi") == 0) {
        strcpy(h->servis, "Nöroloji");
    } else if (strcmp(h->tani, "hamilelik") == 0 || strcmp(h->tani, "dogum") == 0) {
        strcpy(h->servis, "Kadin Dogum");
    } else if (strcmp(h->tani, "deri hastaligi") == 0 || strcmp(h->tani, "kasinti") == 0) {
        strcpy(h->servis, "Cildiye");
    } else if (strcmp(h->tani, "bobrek tasi") == 0 || strcmp(h->tani, "idrar yolu enfeksiyonu") == 0) {
        strcpy(h->servis, "Üroloji");
    } else {
        strcpy(h->servis, "Dahiliye"); 
    }
}

// HL7 formatinda hasta kaydi yazdiran fonksiyon
void hastaKaydiniHL7Yaz(struct Hasta h) {
    printf("HL7 Hasta Kaydi: PID|1|%s|%d|%s|%s|Servis:%s\n", h.isim, h.yas, h.cinsiyet, h.tani, h.servis);
}

// Ilac bilgilerini yazdiran fonksiyon
void ilacBilgisiYaz(struct Ilac i) {
    printf("Ilac: %s | Miktar: %d mg | Adet: %d\n", i.isim, i.miktar, i.adet);
}

// Acil servis islem siralamasi yapan fonksiyon
void acilServisSiralama(struct Hasta hastalar[], int boyut) {
    for (int i = 0; i < boyut - 1; i++) {
        for (int j = i + 1; j < boyut; j++) {
            if (hastalar[i].oncelik > hastalar[j].oncelik) {
                struct Hasta temp = hastalar[i];
                hastalar[i] = hastalar[j];
                hastalar[j] = temp;
            }
        }
    }
}

// Hasta servise sevk edilir
void hastaServiseSevk(struct Hasta h) {
    printf("\nHasta: %s, %s servisine sevk edildi.\n", h.isim, h.servis);
}

// Hasta taburcu edilir
void taburcuIslemi(struct Hasta h) {
    printf("\nHasta Taburcu Edildi: %s\n", h.isim);
    printf("Taburcu Edildigi Servis: %s\n", h.servis);
}

// Acil servis islemi gerceklestiren fonksiyon
void acilServisIslemi(struct Hasta h) {
    printf("\nIslem Baslatildi: %s\n", h.isim);
    printf("Oncelik: %d | Recete Numarasi: %d\n", h.oncelik, receteNoUret());
}

int main() {
    srand(time(NULL)); // Rastgelelik icin sadece 1 kez calisir

    int hastaSayisi;
    
    printf("Kac hasta kaydi gireceksiniz? ");
    scanf("%d", &hastaSayisi);
    
    struct Hasta hastalar[hastaSayisi];
    struct Ilac ilaclar[hastaSayisi];
    
    for (int i = 0; i < hastaSayisi; i++) {
        printf("\nHasta %d Bilgileri:\n", i + 1);
        
        printf("Isim: ");
        scanf(" %[^\n]", hastalar[i].isim);
        
        printf("TC Kimlik No:");
        scanf("%11s", hastalar[i].tcKimlikNo);
        
        printf("Yas: ");
        scanf("%d", &hastalar[i].yas);
        
        printf("Cinsiyet: ");
        scanf(" %[^\n]", hastalar[i].cinsiyet);
        
        printf("Tani: ");
        scanf(" %[^\n]", hastalar[i].tani);
        
        printf("Oncelik (1: yuksek, 2: orta, 3: dusuk): ");
        scanf("%d", &hastalar[i].oncelik);
        
        servisAta(&hastalar[i]); // Servis belirleme islemi
        
        printf("Ilac Ismi: ");
        scanf(" %[^\n]", ilaclar[i].isim);
        
        printf("Ilac Miktari (mg): ");
        scanf("%d", &ilaclar[i].miktar);
        
        printf("Ilac Adedi: ");
        scanf("%d", &ilaclar[i].adet);
    }
    
    acilServisSiralama(hastalar, hastaSayisi);
    
    printf("\nAcil Servis Islem Sirasi:\n");
    for (int i = 0; i < hastaSayisi; i++) {
        acilServisIslemi(hastalar[i]);
        hastaKaydiniHL7Yaz(hastalar[i]);
        ilacBilgisiYaz(ilaclar[i]);
        hastaServiseSevk(hastalar[i]);
    }
    
    printf("\nTaburcu Islemleri:\n");
    for (int i = 0; i < hastaSayisi; i++) {
        taburcuIslemi(hastalar[i]);
    }
    
    return 0;
}

