#include <iostream>
#include <string>
#include <limits> 

#include "bank_customer.h"
#include "buyer.h"


using namespace std;


void handleUserDashboard();
void processRegistration();

void handleUserDashboard() {
    int dashboardChoice;
    bool hasSellerAccount = false;

    do {
        cout << "\n--- Dasbor Pengguna ---\n";
        cout << "1. Lihat Detail Akun\n";
        cout << "2. Tingkatkan ke Akun Penjual\n";
        cout << "3. Logout\n";
        cout << "Pilihan Anda: ";
        cin >> dashboardChoice;

        switch (dashboardChoice) {
            case 1:
                cout << "\n>> Menampilkan detail akun...\n";
                break;

            case 2:
                if (!hasSellerAccount) {
                    cout << "\n>> Proses Peningkatan Akun ke Penjual...\n";
                    string shopName, shopAddress;
                    cout << "Masukkan Nama Toko Anda: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    getline(cin, shopName);
                    cout << "Masukkan Alamat Toko: ";
                    getline(cin, shopAddress);
                    cout << "Selamat! Toko '" << shopName << "' berhasil dibuat.\n";
                    hasSellerAccount = true; 
                } else {
                    cout << "\n>> Anda sudah terdaftar sebagai penjual.\n";
                }
                break;

            case 3:
                cout << "\n>> Anda telah logout. Kembali ke menu utama...\n";
                break;

            default:
                cout << "\n>> Pilihan tidak valid, silakan coba lagi.\n";
        }
    } while (dashboardChoice != 3);
}


void processRegistration() {
    cout << "\n--- Pendaftaran Akun Baru ---\n";
    string fullName, homeAddress, phoneNumber;
    
    cout << "Masukkan Nama Lengkap: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, fullName);

    cout << "Masukkan Alamat Rumah: ";
    getline(cin, homeAddress);

    cout << "Masukkan Nomor Telepon: ";
    getline(cin, phoneNumber);

    cout << "\n>> Akun untuk " << fullName << " berhasil dibuat!\n";

    char createShopChoice;
    cout << "Apakah Anda ingin membuka toko sekarang? (y/n): ";
    cin >> createShopChoice;

    if (createShopChoice == 'y' || createShopChoice == 'Y') {
        handleUserDashboard(); 
    }
}

int main() {
    int menuSelection;
    enum MainMenuOption { LOGIN = 1, REGISTER, EXIT };

    while (true) { 
        cout << "\n--- Selamat Datang di Toko Online ---\n";
        cout << "1. Login\n";
        cout << "2. Registrasi\n";
        cout << "3. Keluar\n";
        cout << "Silakan pilih opsi: ";
        cin >> menuSelection;

        if (cin.fail()) {
            cout << "Input tidak valid. Harap masukkan angka.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (menuSelection) {
            case LOGIN: {
                cout << "\n--- Halaman Login ---\n";
                string username, password;
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;

              
                if (username == "user" && password == "password") {
                    cout << "\n>> Login berhasil!\n";
                    handleUserDashboard();
                } else {
                    cout << "\n>> Username atau password salah.\n";
                }
                break;
            }

            case REGISTER:
                processRegistration();
                cout << "\n>> Registrasi selesai. Silakan login untuk melanjutkan.\n";
                break;

            case EXIT:
                cout << "\n>> Terima kasih telah berkunjung. Sampai jumpa!\n";
                return 0; 

            default:
                cout << "\n>> Opsi tidak dikenal.\n";
                break;
        }
    }

    return 0;
}
