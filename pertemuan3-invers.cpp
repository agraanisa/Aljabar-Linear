#include<iostream> 
#include<iomanip> 
#include<math.h>
#include<stdlib.h>

#define SIZE 10

using namespace std;

int main()
{
    float a[SIZE][SIZE*2], ratio; 
    int i,j,k,n;

    // Mengatur presisi tampilan angka desimal
    cout<< setprecision(3)<< fixed;

    // 1. Membaca ordo matriks
    cout<<"Masukkan ordo matriks: ";
    cin>>n;

    // 2. Membaca koefisien matriks
    cout<<"Masukkan koefisien-koefisien matriks: " << endl;
    for(i=0;i<n;i++) // Menggunakan indeks dari 0
    {
        for(j=0;j<n;j++)
        {
            cout<<"a["<< i+1 <<"]["<< j+1 <<"]= "; 
            cin>>a[i][j];
        }
    }

    // 3. Menambahkan Matriks Identitas ke sebelah kanan matriks masukan
    cout << "\nMenambahkan matriks identitas:\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                a[i][j+n] = 1; // Matriks identitas diisi pada kolom sebelah kanan
            }
            else
            {
                a[i][j+n] = 0; // Sisanya diisi dengan 0
            }
        }
    }

    // Menampilkan matriks augmentasi (masukan + identitas)
    cout << "\nMatriks setelah augmentasi dengan identitas:\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<2*n;j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    // 4. Melakukan Eliminasi Gauss-Jordan
    for(i=0;i<n;i++)
    {
        // Cek apakah elemen diagonal adalah 0, yang akan menyebabkan error
        if(a[i][i] == 0.0)
        {
            cout<<"Error: Elemen diagonal 0 ditemukan. Tidak bisa dilanjutkan!";
            exit(0); // Keluar dari program jika terjadi kesalahan
        }

        cout << "\nLangkah eliminasi untuk baris ke-" << i+1 << ":\n";
        for(j=0;j<n;j++)
        {
            if(i != j)
            {
                // Hitung rasio untuk mengeliminasi elemen-elemen di bawah dan di atas diagonal
                ratio = a[j][i] / a[i][i];

                // Operasi baris
                for(k=0;k<2*n;k++)
                {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }

                // Menampilkan hasil setelah setiap operasi eliminasi
                cout << "Setelah mengeliminasi baris " << j+1 << " dengan rasio " << ratio << ":\n";
                for(int p=0;p<n;p++)
                {
                    for(int q=0;q<2*n;q++)
                    {
                        cout << a[p][q] << "\t";
                    }
                    cout << endl;
                }
            }
        }
    }

    // 5. Membuat elemen diagonal utama menjadi 1
    cout << "\nNormalisasi diagonal utama ke 1:\n";
    for(i=0;i<n;i++)
    {
        for(j=n;j<2*n;j++) 
        {
            a[i][j] = a[i][j] / a[i][i];
        }

        // Menampilkan matriks setelah normalisasi tiap baris
        cout << "Setelah normalisasi baris ke-" << i+1 << ":\n";
        for(int p=0;p<n;p++)
        {
            for(int q=0;q<2*n;q++)
            {
                cout << a[p][q] << "\t";
            }
            cout << endl;
        }
    }

    // 6. Menampilkan Matriks Invers
    cout<< endl<<"Matriks Invers:"<< endl;
    for(i=0;i<n;i++)
    {
        for(j=n;j<2*n;j++)
        {
            cout<< a[i][j]<<"\t"; 
        }
        cout<< endl;
    }

    return 0;
}
