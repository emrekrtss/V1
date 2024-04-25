#include <stdio.h>
#include <math.h>

int main() {
    FILE *dosya;
    char satir[5000];
    double x1, y1, z1, x2, y2, z2, sonuc;
    int i = 1;
    dosya = fopen("veri.src", "r"); // Veriyi veri.txt dosyasindan oku   //.src

    if (dosya == NULL) {
        printf("Dosya acilamadi.\n");
        return 1;
    }

    // Dosyayi satir satir oku
    while (fgets(satir, sizeof(satir), dosya)) {
        // X1, Y1 ve Z1 değerlerini al
        sscanf(satir, "CIRC {X %lf, Y %lf, Z %lf, A %*lf, B %*lf, C %*lf}, {X %lf, Y %lf, Z %lf, A %*lf, B %*lf, C %*lf}", &x1, &y1, &z1, &x2, &y2, &z2);
         
        // Değerleri ekrana yazdir
        sonuc = sqrt(pow(x1 - x2, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
        if (sonuc < 8)
        {
            printf("%d. Satir Degeri 8'den Kucuk Degeri==>%lf\n", i,sonuc);
        }
           
        i++;
        
    }

    fclose(dosya); // Dosyayi kapat
    return (0);
}