#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>

#define SIZE 10 // Maximum size of the matrix
#define EPSILON 1e-6

using namespace std;

void printMatrix(double a[SIZE][SIZE], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(8) << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printEquations(double a[SIZE][SIZE], int m, int n) {
    for (int i = 0; i < m; i++) {
        cout << "Persamaan " << i + 1 << ": ";
        bool first = true;
        for (int j = 0; j < n - 1; j++) {
            if (fabs(a[i][j]) > EPSILON) {
                if (!first && a[i][j] > 0) cout << "+ ";
                if (fabs(a[i][j] - 1) > EPSILON && fabs(a[i][j] + 1) > EPSILON) 
                    cout << a[i][j];
                if (a[i][j] == -1) cout << "-";
                cout << "x" << j + 1 << " ";
                first = false;
            }
        }
        cout << "= " << a[i][n - 1] << endl;
    }
    cout << endl;
}

// Perbaikan fungsi formatTerm untuk menangani tanda dengan benar
string formatTerm(double coeff, const string& var) {
    stringstream ss;
    if (fabs(coeff) < EPSILON) return "";
    if (coeff > 0) ss << "+";
    if (coeff < 0 && fabs(coeff + 1) < EPSILON) ss << "-";
    else if (fabs(fabs(coeff) - 1) > EPSILON) ss << coeff;
    ss << var;
    return ss.str();
}

int main() {
    double a[SIZE][SIZE], ratio;
    int i, j, k, m, n;

    cout << setprecision(4) << fixed;

    cout << "Masukkan jumlah persamaan (baris): ";
    cin >> m;
    cout << "Masukkan jumlah variabel (kolom): ";
    cin >> n;

    cout << "Masukkan Koefisien Matriks Augmented (" << m << "x" << n + 1 << " matriks): " << endl;
    for (i = 0; i < m; i++) {
        for (j = 0; j <= n; j++) {
            cout << "a[" << i + 1 << "][" << j + 1 << "]= ";
            cin >> a[i][j];
        }
    }

    cout << "Matriks awal:" << endl;
    printMatrix(a, m, n + 1);

    // Gauss-Jordan elimination
    for (i = 0; i < m && i < n; i++) {
        int pivot_row = i;
        for (k = i + 1; k < m; k++) {
            if (fabs(a[k][i]) > fabs(a[pivot_row][i])) {
                pivot_row = k;
            }
        }

        if (pivot_row != i) {
            for (j = 0; j <= n; j++) {
                swap(a[i][j], a[pivot_row][j]);
            }
            cout << "Menukar baris " << i + 1 << " dengan baris " << pivot_row + 1 << endl;
            printMatrix(a, m, n + 1);
        }

        if (fabs(a[i][i]) > EPSILON) {
            double pivot = a[i][i];
            cout << "Normalisasi baris " << i + 1 << " dengan membagi semua elemen baris ini dengan " << pivot << "." << endl;
            for (j = i; j <= n; j++) {
                a[i][j] /= pivot;
            }
            printMatrix(a, m, n + 1);
        }

        for (k = 0; k < m; k++) {
            if (k != i && fabs(a[k][i]) > EPSILON) {
                ratio = a[k][i];
                cout << "Mengurangi baris " << k + 1 << " dengan baris " << i + 1 << " dikalikan " << ratio << " untuk membuat elemen kolom ke-" << i + 1 << " menjadi nol." << endl;
                for (j = i; j <= n; j++) {
                    a[k][j] -= ratio * a[i][j];
                }
                printMatrix(a, m, n + 1);
            }
        }
    }

    cout << "Matriks setelah eliminasi Gauss-Jordan:" << endl;
    printMatrix(a, m, n + 1);

    cout << "Persamaan Linear setelah eliminasi Gauss-Jordan:" << endl;
    printEquations(a, m, n + 1);

    // Back substitution and parametric solution
    cout << "Solusi Parametrik:" << endl;
    vector<string> solution(n);
    vector<bool> is_free(n, true);
    char param = 'r'; // Mulai dari 'r' untuk variabel bebas

    // Identifikasi variabel bebas
    for (i = 0; i < m && i < n; i++) {
        if (fabs(a[i][i]) > EPSILON) {
            is_free[i] = false; // Ini bukan variabel bebas
        }
    }

    // Menugaskan variabel bebas secara eksplisit dalam urutan alfabet
    int free_var_count = 0; // Counter untuk melacak jumlah variabel bebas
    for (i = 0; i < n; i++) {
        if (is_free[i]) {
            solution[i] = string(1, param + free_var_count); // Menetapkan 'r', 's', dst. untuk variabel bebas
            free_var_count++;
        }
    }

    // Penyulihan untuk variabel dependen
    for (i = min(m, n) - 1; i >= 0; i--) {
        if (!is_free[i]) {
            stringstream ss;
            bool has_constant = fabs(a[i][n]) > EPSILON; // Hanya tambahkan konstanta jika tidak nol
            if (has_constant) ss << a[i][n]; // Mulai dengan nilai konstanta jika ada

            for (j = i + 1; j < n; j++) {
                if (fabs(a[i][j]) > EPSILON) {
                    if (is_free[j]) {
                        ss << formatTerm(-a[i][j], solution[j]); // Gunakan variabel bebas ('r', 's', dll.)
                    } else {
                        ss << formatTerm(-a[i][j], "x" + to_string(j + 1)); // Gunakan variabel dependen
                    }
                }
            }
            solution[i] = ss.str();
            if (solution[i].empty()) solution[i] = "0"; // Jika tidak ada istilah apapun
        }
    }

    // Cetak solusi
    for (i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }

    return 0;
}
