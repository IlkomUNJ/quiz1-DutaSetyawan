#include <iostream>
#include "bank_customer.h"
#include "buyer.h"
#include <limits> 

enum PrimaryPrompt { LOGIN, REGISTER, EXIT };
enum BuyerMenu { CHECK_STATUS, UPGRADE_TO_SELLER, BANKING, BROWSE, ORDER, PAYMENT, LOGOUT, DELETE_ACCOUNT };
enum BankingMenu { CHECK_BALANCE, DEPOSIT, WITHDRAW, BANK_EXIT };

using namespace std;

void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    BankCustomer customer1(1, "Duta Setyawan", 1000.0);
    Buyer buyer1(1, customer1.getName(), customer1);
    bool isLoggedIn = false;

    PrimaryPrompt prompt = LOGIN;
    while (prompt != EXIT) {
        cout << "Selamat Datang di Toko Online!" << endl;
        cout << "============================" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "Pilih Opsi: ";
        int choice;
        cin >> choice;
        
        
        if (cin.fail()) {
            cout << "Input tidak valid. Silakan masukkan angka." << endl;
            cin.clear();
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        prompt = static_cast<PrimaryPrompt>(choice - 1);
        switch (prompt) {
            case LOGIN: {
                cout << "\n--- Login ---" << endl;
                
                isLoggedIn = true; 
                cout << "Login berhasil! Selamat datang, " << buyer1.getName() << "." << endl;

                while (isLoggedIn) {
                    cout << "\n--- Menu Pembeli ---" << endl;
                    cout << "1. Cek Status Akun" << endl;
                    cout << "2. Upgrade Akun menjadi Penjual" << endl;
                    cout << "3. Fungsi Perbankan" << endl;
                    cout << "4. Jelajahi Toko" << endl;
                    cout << "5. Lihat Pesanan" << endl;
                    cout << "6. Pembayaran" << endl;
                    cout << "7. Logout" << endl;
                    cout << "8. Hapus Akun" << endl;
                    cout << "Pilih Opsi: ";
                    int buyerChoice;
                    cin >> buyerChoice;

                    if (cin.fail()) {
                        cout << "Input tidak valid. Silakan masukkan angka." << endl;
                        cin.clear();
                        clearInputBuffer();
                        continue;
                    }
                    clearInputBuffer();

                    BuyerMenu buyerMenu = static_cast<BuyerMenu>(buyerChoice - 1);

                    switch (buyerMenu) {
                        case UPGRADE_TO_SELLER:
                            cout << "\n--- Upgrade Akun menjadi Penjual ---" << endl;
                            cout << "Masukkan Nama Toko: ";
                            
                            break;
                        case BANKING: {
                            bool inBankingMenu = true;
                            while (inBankingMenu) {
                                cout << "\n--- Fungsi Perbankan ---" << endl;
                                cout << "1. Cek Saldo" << endl;
                                cout << "2. Deposit" << endl;
                                cout << "3. Tarik Tunai" << endl;
                                cout << "4. Kembali ke Menu Pembeli" << endl;
                                cout << "Pilih Opsi: ";
                                int bankingChoice;
                                cin >> bankingChoice;

                                if (cin.fail()) {
                                    cout << "Input tidak valid. Silakan masukkan angka." << endl;
                                    cin.clear();
                                    clearInputBuffer();
                                    continue;
                                }
                                clearInputBuffer();

                                BankingMenu bankingMenu = static_cast<BankingMenu>(bankingChoice - 1);

                                switch (bankingMenu) {
                                    case CHECK_BALANCE:
                                        cout << "Saldo Anda saat ini: $" << customer1.getBalance() << endl;
                                        break;
                                    case DEPOSIT:
                                        double depositAmount;
                                        cout << "Masukkan jumlah deposit: $";
                                        cin >> depositAmount;
                                        customer1.addBalance(depositAmount);
                                        cout << "Deposit berhasil. Saldo baru: $" << customer1.getBalance() << endl;
                                        break;
                                    case WITHDRAW:
                                        double withdrawAmount;
                                        cout << "Masukkan jumlah penarikan: $";
                                        cin >> withdrawAmount;
                                        customer1.withdrawBalance(withdrawAmount);
                                        cout << "Saldo baru: $" << customer1.getBalance() << endl;
                                        break;
                                    case BANK_EXIT:
                                        inBankingMenu = false;
                                        break;
                                    default:
                                        cout << "Opsi tidak valid." << endl;
                                        break;
                                }
                            }
                            break;
                        }
                        case LOGOUT:
                            isLoggedIn = false;
                            cout << "Anda telah logout." << endl;
                            break;
                        default:
                            cout << "Fungsi belum diimplementasikan." << endl;
                            break;
                    }
                }
                break;
            }
            case REGISTER:
                cout << "\n--- Registrasi ---" << endl;
                cout << "Masukkan Nama: " << endl;
                cout << "Masukkan Alamat: " << endl;
                cout << "Masukkan Nomor Telepon: " << endl;
                cout << "Registrasi berhasil!" << endl;
                break;
            case EXIT:
                cout << "Keluar dari program." << std::endl;
                break;
            default:
                cout << "Opsi tidak valid." << endl;
                break;
        }
        cout << endl;
    }

    return 0;
}
