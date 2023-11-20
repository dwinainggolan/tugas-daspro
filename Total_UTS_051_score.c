#include <stdio.h>

int main() {
    char nim[4];
    float uts, totalUTS = 0;
    int count = 0;

    FILE *file = fopen("nilai_uts.txt", "r");

    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return 1;
    }

    printf("Masukkan NIM (3 digits): ");
    scanf("%s", nim);

    while (fscanf(file, "%*[^|]|%*[^|]|%*[^|]|%f%*c", &uts) == 1) {
        totalUTS += uts;
        count++;
    }

    fclose(file);

    if (count == 0) {
        printf("Data tidak ditemukan atau format file salah.\n");
    } else {
        float averageUTS = totalUTS / count;
        printf("Rata-rata Nilai UTS untuk NIM %s: %.2f\n", nim, averageUTS);
    }

    return 0;
}
