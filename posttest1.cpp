#include <iostream>
using namespace std;

struct ternak {
    int id_ternak;
    string jenis_ternak;
    string berat_ternak;
    string jenis_kelamin_ternak;
    int umur_ternak; // Mengubah tipe data umur_ternak menjadi int (jumlah bulan)
};

void create(ternak *trnk, int &jumlah) {
    cout << "masukkan id : "; cin >> trnk->id_ternak;
    cin.ignore(); // Membersihkan newline dalam buffer masukan
    cout << "masukkan jenis ternak : "; getline(cin, trnk->jenis_ternak);
    cout << "masukkan berat ternak : "; getline(cin, trnk->berat_ternak);
    cout << "masukkan jenis kelamin ternak : "; getline(cin, trnk->jenis_kelamin_ternak);
    cout << "masukkan umur ternak (bulan) : "; cin >> trnk->umur_ternak;
    jumlah += 1;
}

void display(ternak *trnk, int &jumlah) {
    for (int i = 0; i < jumlah; i++) {
        cout << "id ternak : " << trnk[i].id_ternak << endl;
        cout << "jenis ternak : " << trnk[i].jenis_ternak << endl;
        cout << "berat ternak : " << trnk[i].berat_ternak << endl;
        cout << "jenis kelamin ternak : " << trnk[i].jenis_kelamin_ternak << endl;
        int umur_tahun = trnk[i].umur_ternak / 12; // Menghitung tahun
        int umur_bulan = trnk[i].umur_ternak % 12; // Menghitung bulan
        cout << "umur ternak : " << umur_tahun << " tahun " << umur_bulan << " bulan" << endl;
        cout << "=================================" << endl;
    }
}

void deleteEntry(ternak *trnk, int &jumlah, int idToDelete) {
    if (jumlah <= 0) {
        cout << "Data ternak kosong." << endl;
        return;
    }

    int indexToDelete = -1;
    for (int i = 0; i < jumlah; i++) {
        if (trnk[i].id_ternak == idToDelete) {
            indexToDelete = i;
            break;
        }
    }

    if (indexToDelete != -1) {
        for (int j = indexToDelete; j < jumlah - 1; j++) {
            trnk[j] = trnk[j + 1];
        }
        jumlah--;
        cout << "Data ternak dengan ID " << idToDelete << " berhasil dihapus." << endl;
    } else {
        cout << "Data ternak dengan ID " << idToDelete << " tidak ditemukan." << endl;
    }
}

void updateEntry(ternak *trnk, int &jumlah, int idToUpdate) {
    if (jumlah <= 0) {
        cout << "Data ternak kosong." << endl;
        return;
    }

    for (int i = 0; i < jumlah; i++) {
        if (trnk[i].id_ternak == idToUpdate) {
            cout << "Masukkan jenis ternak yang baru: "; fflush(stdin);
            getline(cin, trnk[i].jenis_ternak);
            cout << "Masukkan berat ternak yang baru: "; 
            getline(cin, trnk[i].berat_ternak);
            cout << "Masukkan jenis kelamin ternak yang baru: "; 
            getline(cin, trnk[i].jenis_kelamin_ternak);
            cout << "Masukkan umur ternak (bulan) yang baru: "; 
            cin >> trnk[i].umur_ternak;
            cout << "Data ternak dengan ID " << idToUpdate << " berhasil diperbarui." << endl;
            return;
        }
    }
    cout << "Data ternak dengan ID " << idToUpdate << " tidak ditemukan." << endl;
}

int main() {
    ternak trnk[20];
    int jumlah = 0;
    int pilih;
    while (true) {
        cout << "\n";
        cout << "======== menu =========" << endl;
        cout << "1. tambah " << endl;
        cout << "2. lihat " << endl;
        cout << "3. update " << endl;
        cout << "4. hapus " << endl;
        cout << "5. exit " << endl;
        cout << "=======================" << endl;
        cout << "pilih : "; cin >> pilih;
        if (pilih == 1) {
            create(&trnk[jumlah], jumlah);
        }
        else if (pilih == 2) {
            display(trnk, jumlah);
        }
        else if (pilih == 3) {
            int idToUpdate;
            cout << "Masukkan ID ternak yang ingin diperbarui: ";
            cin >> idToUpdate;
            updateEntry(trnk, jumlah, idToUpdate);
        }
        else if (pilih == 4) {
            int idToDelete;
            cout << "Masukkan ID ternak yang ingin dihapus: ";
            cin >> idToDelete;
            deleteEntry(trnk, jumlah, idToDelete);
        }
        else if (pilih == 5) {
            cout << "=== Anda telah keluar dari Program ===" << endl;
            break; // Keluar dari program jika5 memilih "exit"
        }
    }
    return 0;
}
