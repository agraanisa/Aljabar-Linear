#include <iostream>
#include <iomanip>

using namespace std;

// isyana
void InputMatriks(float matriks[][10], int baris, int kolom) {
    cout << "Masukkan elemen-elemen Matriks:\n";
    int i = 0;
    while (i < baris) {
        int j = 0;
        while (j < kolom) {
            cout << "Matriks[" << i << "][" << j << "] = ";
            cin >> matriks[i][j];
            j++;
        }
        i++;
    }
}

// isyana
void TampilkanMatriks(float matriks[][10], int baris, int kolom) {
    int i = 0;
    while (i < baris) {
        int j = 0;
        while (j < kolom) {
            cout << setw(3) << matriks[i][j] << " "; 
            j++;
        }
        cout << endl;
        i++;
    }
}

// agra
void InisiasiMatriks() {
    int baris, kolom;
    cout << "Masukkan jumlah baris untuk Matriks: ";
    cin >> baris;
    cout << "Masukkan jumlah kolom untuk Matriks: ";
    cin >> kolom;

    float matriks[10][10];
    InputMatriks(matriks, baris, kolom);

    cout << "Matriks yang diinisiasi:\n";
    TampilkanMatriks(matriks, baris, kolom);
}

// isyana
void PenjumlahanMatriks() {
    int baris1, kolom1, baris2, kolom2;
    cout << "Masukkan jumlah baris untuk Matriks 1: ";
    cin >> baris1;
    cout << "Masukkan jumlah kolom untuk Matriks 1: ";
    cin >> kolom1;
    
    cout << "Masukkan jumlah baris untuk Matriks 2: ";
    cin >> baris2;
    cout << "Masukkan jumlah kolom untuk Matriks 2: ";
    cin >> kolom2;
    
    if (baris1 != baris2 || kolom1 != kolom2) {
        cout << "Matriks tidak bisa dijumlahkan karena ordo berbeda." << endl;
        return;
    }
    
    float matriks1[10][10], matriks2[10][10], hasil[10][10];
    cout << "Matriks 1:\n";
    InputMatriks(matriks1, baris1, kolom1);
    cout << "Matriks 2:\n";
    InputMatriks(matriks2, baris2, kolom2);
    
    int i = 0;
    while (i < baris1) {
        int j = 0;
        while (j < kolom1) {
            hasil[i][j] = matriks1[i][j] + matriks2[i][j];
            j++;
        }
        i++;
    }
    
    cout << "Hasil Penjumlahan Matriks:\n";
    TampilkanMatriks(hasil, baris1, kolom1);
}

// agra
void PenguranganMatriks() {
    int baris1, kolom1, baris2, kolom2;
    cout << "Masukkan jumlah baris untuk Matriks 1: ";
    cin >> baris1;
    cout << "Masukkan jumlah kolom untuk Matriks 1: ";
    cin >> kolom1;
    
    cout << "Masukkan jumlah baris untuk Matriks 2: ";
    cin >> baris2;
    cout << "Masukkan jumlah kolom untuk Matriks 2: ";
    cin >> kolom2;
    
    if (baris1 != baris2 || kolom1 != kolom2) {
        cout << "Matriks tidak bisa dikurangkan karena ordo berbeda." << endl;
        return;
    }
    
    float matriks1[10][10], matriks2[10][10], hasil[10][10];
    cout << "Matriks 1:\n";
    InputMatriks(matriks1, baris1, kolom1);
    cout << "Matriks 2:\n";
    InputMatriks(matriks2, baris2, kolom2);
    
    int i = 0;
    while (i < baris1) {
        int j = 0;
        while (j < kolom1) {
            hasil[i][j] = matriks1[i][j] - matriks2[i][j];
            j++;
        }
        i++;
    }
    
    cout << "Hasil Pengurangan Matriks:\n";
    TampilkanMatriks(hasil, baris1, kolom1);
}

// jihan
void PerkalianMatriks() {
    int baris1, kolom1, baris2, kolom2;
    cout << "Masukkan jumlah baris untuk Matriks 1: ";
    cin >> baris1;
    cout << "Masukkan jumlah kolom untuk Matriks 1: ";
    cin >> kolom1;
    
    cout << "Masukkan jumlah baris untuk Matriks 2: ";
    cin >> baris2;
    cout << "Masukkan jumlah kolom untuk Matriks 2: ";
    cin >> kolom2;
    
    if (kolom1 != baris2) {
        cout << "Matriks tidak bisa dikalikan karena ordo tidak sesuai." << endl;
        return;
    }
    
    float matriks1[10][10], matriks2[10][10], hasil[10][10] = {0};
    cout << "Matriks 1:\n";
    InputMatriks(matriks1, baris1, kolom1);
    cout << "Matriks 2:\n";
    InputMatriks(matriks2, baris2, kolom2);
    
    int i = 0;
    while (i < baris1) {
        int j = 0;
        while (j < kolom2) {
            int k = 0;
            while (k < kolom1) {
                hasil[i][j] += matriks1[i][k] * matriks2[k][j];
                k++;
            }
            j++;
        }
        i++;
    }
    
    cout << "Hasil Perkalian Matriks:\n";
    TampilkanMatriks(hasil, baris1, kolom2);
}

// jihan
void PerkalianSkalar() {
    int baris, kolom;
    float skalar;
    cout << "Masukkan jumlah baris untuk Matriks: ";
    cin >> baris;
    cout << "Masukkan jumlah kolom untuk Matriks: ";
    cin >> kolom;
    cout << "Masukkan nilai skalar: ";
    cin >> skalar;
    
    float matriks[10][10], hasil[10][10];
    InputMatriks(matriks, baris, kolom);
    
    int i = 0;
    while (i < baris) {
        int j = 0;
        while (j < kolom) {
            hasil[i][j] = matriks[i][j] * skalar;
            j++;
        }
        i++;
    }
    
    cout << "Hasil Perkalian Matriks dengan Skalar:\n";
    TampilkanMatriks(hasil, baris, kolom);
}

// elsa
void KombinasiLinearMatriks() {
    int n, m;
    cout << "Masukkan jumlah baris matriks: ";
    cin >> n;
    cout << "Masukkan jumlah kolom matriks: ";
    cin >> m;

    int jumlahMatriks;
    cout << "Masukkan jumlah matriks yang akan dikombinasikan: ";
    cin >> jumlahMatriks;

    float hasil[10][10] = {0};
    
    int k = 0;
    while (k < jumlahMatriks) {
        float matriks[10][10];
        cout << "Masukkan elemen-elemen Matriks " << k + 1 << ":\n";
        InputMatriks(matriks, n, m);

        float skalar;
        cout << "Masukkan skalar untuk Matriks " << k + 1 << ": ";
        cin >> skalar;

        int i = 0;
        while (i < n) {
            int j = 0;
            while (j < m) {
                hasil[i][j] += skalar * matriks[i][j];
                j++;
            }
            i++;
        }
        k++;
    }

    cout << "Hasil Kombinasi Linear Matriks:\n";
    TampilkanMatriks(hasil, n, m);
}

// elsa
void TransposeMatriks() {
    int baris, kolom;
    cout << "Masukkan jumlah baris untuk Matriks: ";
    cin >> baris;
    cout << "Masukkan jumlah kolom untuk Matriks: ";
    cin >> kolom;
    
    float matriks[10][10], transpose[10][10];
    InputMatriks(matriks, baris, kolom);
    
    int i = 0;
    while (i < baris) {
        int j = 0;
        while (j < kolom) {
            transpose[j][i] = matriks[i][j];
            j++;
        }
        i++;
    }
    
    cout << "Transpose Matriks:\n";
    TampilkanMatriks(transpose, kolom, baris);
}

// agra
void TraceMatriks() {
    int ukuran;
    float trace = 0;
    cout << "Masukkan ukuran Matriks (harus persegi): ";
    cin >> ukuran;
    
    float matriks[10][10];
    InputMatriks(matriks, ukuran, ukuran);
    
    int i = 0;
    while (i < ukuran) {
        trace += matriks[i][i];
        i++;
    }
    
    cout << "Trace Matriks: " << trace << endl;
}

// isyana
void MatriksNol() {
    int baris, kolom;
    cout << "Masukkan jumlah baris untuk Matriks Nol: ";
    cin >> baris;
    cout << "Masukkan jumlah kolom untuk Matriks Nol: ";
    cin >> kolom;
    
    float matriks[10][10] = {0};
    
    int i = 0;
    while (i < baris) {
        int j = 0;
        while (j < kolom) {
            cout << setw(3) << matriks[i][j] << " ";
            j++;
        }
        cout << endl;
        i++;
    }
}

// agra
void MatriksIdentitas() {
    int ukuran;
    cout << "Masukkan ukuran Matriks Identitas: ";
    cin >> ukuran;
    
    float identitas[10][10] = {0};
    
    int i = 0;
    while (i < ukuran) {
        identitas[i][i] = 1;
        i++;
    }
    
    cout << "Matriks Identitas:\n";
    
    i = 0;
    while (i < ukuran) {
        int j = 0;
        while (j < ukuran) {
            cout << setw(3) << identitas[i][j] << " ";
            j++;
        }
        cout << endl;
        i++;
    }
}

// jihan
void Invers() {
    int n;
    cout << "Masukkan ukuran matriks persegi: ";
    cin >> n;

    float matriks[10][10], invers[10][10];

    InputMatriks(matriks, n, n);

    int i = 0;
    while (i < n) {
        int j = 0;
        while (j < n) {
            invers[i][j] = (i == j) ? 1 : 0;
            j++;
        }
        i++;
    }

    i = 0;
    while (i < n) {
        if (matriks[i][i] == 0) {
            cout << "Matriks tidak memiliki invers karena terdapat elemen diagonal yang nol." << endl;
            return;
        }

        float diagonal = matriks[i][i];
        int j = 0;
        while (j < n) {
            matriks[i][j] /= diagonal;
            invers[i][j] /= diagonal;
            j++;
        }

        int k = 0;
        while (k < n) {
            if (k != i) {
                float rasio = matriks[k][i];
                j = 0;
                while (j < n) {
                    matriks[k][j] -= rasio * matriks[i][j];
                    invers[k][j] -= rasio * invers[i][j];
                    j++;
                }
            }
            k++;
        }
        i++;
    }

    cout << "Matriks Invers:\n";
    TampilkanMatriks(invers, n, n);
}

// elsa
void Menu() {
    int pilihan;
    do {
        cout << "=============================\n";
        cout << "       Operasi Matriks       \n";
        cout << "=============================\n";
        cout << "\nMenu:\n";
        cout << "1. Fungsi Inisiasi Matriks\n";
        cout << "2. Penjumlahan Matriks\n";
        cout << "3. Pengurangan Matriks\n";
        cout << "4. Perkalian Matriks\n";
        cout << "5. Perkalian Matriks dengan Scalar\n";
        cout << "6. Kombinasi Linear Matriks\n";
        cout << "7. Transpose Matriks\n";
        cout << "8. Trace Matriks\n";
        cout << "9. Inisiasi Matriks Nol\n";
        cout << "10. Inisiasi Matriks Identitas\n";
        cout << "11. Invers Matriks (Balikin)\n";
        cout << "0. Keluar\n";
        cout << "Pilih operasi (0-11): ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1: InisiasiMatriks(); break;
            case 2: PenjumlahanMatriks(); break;
            case 3: PenguranganMatriks(); break;
            case 4: PerkalianMatriks(); break;
            case 5: PerkalianSkalar(); break;
            case 6: KombinasiLinearMatriks(); break;
            case 7: TransposeMatriks(); break;
            case 8: TraceMatriks(); break;
            case 9: MatriksNol(); break;
            case 10: MatriksIdentitas(); break;
            case 11: Invers(); break;
            case 0: cout << "Keluar dari program.\n"; break;
            default: cout << "Pilihan tidak valid, coba lagi.\n";
        }
    } while (pilihan != 0);
}

int main() {
    Menu();
    return 0;
}
