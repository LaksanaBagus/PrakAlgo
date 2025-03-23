#include <iostream>
#include <string>

using namespace std;

int menu;
int jumlah;
int cariId;
int cariID2;
int gajiBaru;

struct pegawai
{
    int id;
    string nama;
    int gaji;
} pgw[];

void tambahData()
{
    FILE *filePtr;

    filePtr = fopen("dataPegawai.dat", "rb");

    if (filePtr == NULL)
    {
        cout << "Gagal membuka file!" << endl;
        exit(1);
    }

    cout << "Masukan jumlah data : ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; i++)
    {
        cout << "Masukan id : ";
        cin >> pgw[i].id;
        cout << "Masukan nama : ";
        cin.ignore();
        getline(cin, pgw[i].nama);
        cout << "Masukan gaji : ";
        cin >> pgw[i].gaji;

        fwrite(&pgw, sizeof(pegawai), 1, filePtr);
    }
    fclose(filePtr);
}

void lihatDaftar()
{
    FILE *filePtr = fopen("dataPegawai.dat", "rb");
    while (fread(&pgw, sizeof(pegawai), 1, filePtr))
        ;

    for (int i = 0; i < jumlah - 1; i++)
    {
        for (int j = i + 1; j < jumlah - i - 1; j++)
        {
            if (pgw[j].id > pgw[j + 1].id)
            {
                int temp = pgw[j + 1].id;
                pgw[j + 1].id + pgw[j].id;
                pgw[j].id = temp;
            }
        }
    }

    cout << "===Daftar Pegawai===" << endl;
    cout << "Daftar pegawai yang telah diurutkan:" << endl;
    for (int i = 0; i < jumlah; i++)
    {
        cout << "------------------------------------------" << endl;
        cout << "ID: " << pgw[i].id;
        cout << "Nama: " << pgw[i].nama;
        cout << "Gaji: " << pgw[i].gaji;
    }

    fclose(filePtr);
}

void cariData()
{
    system("cls");
    FILE *filePtr = fopen("dataPegawai.dat", "rb");
    cout << "===Cari Pegawai===" << endl;
    cout << "Cari pegawai berdasarkan ID" << endl;
    cout << "Masukan ID: ";
    cin >> cariId;
    cout << "-----------------------------------------------" << endl;

    int i = 0;
    bool found = false;

    while ((i < jumlah) && (!found))
    {
        if (pgw[i].id == cariId)
        {
            found = true;
        }
        else
        {
            i = i + 1;
        }
    }

    if (found == true)
    {
        cout << "ID: " << cariId << endl;
        cout << "Nama: " << pgw[i].nama << endl;
        cout << "Gaji: " << pgw[i].gaji << endl;
    }
    else
    {
        cout << "Pegawai dengan ID tersebut tidak ditemukan!" << endl;
    }

    fclose(filePtr);
}

void perbaruiGaji()
{
    system("cls");
    FILE *filePtr = fopen("dataPegawai.dat", "rb");

    cout << "===Perbarui Gaji===" << endl;
    cout << "Masukan ID untuk dicari: ";
    cin >> cariID2;

    int i = 0;
    bool found = false;

    while ((i < jumlah) && (!found))
    {
        if (pgw[i].id == cariID2)
        {
            found = true;
        }
        else
        {
            i = i + 1;
        }
    }

    if (found == true)
    {
        cout << "-----------------------------------------------------" << endl;
        cout << "Pegawai ditemukan" << endl;
        cout << "ID: " << cariID2 << endl;
        cout << "Nama: " << pgw[i].nama << endl;
        cout << "Masukan gaji baru: ";
        cin >> gajiBaru;
        cout << "-----------------------------------------------------" << endl;
    }
    else
    {
        cout << "Pegawai dengan ID tersebut tidak ditemukan!" << endl;
    }

    fclose(filePtr);
}

void keluar()
{
    cout << "Anda memilih keluar,Terima kasih sudah menggunakan jasa kami" << endl;
}

int main()
{
    do
    {
        system("cls");
        cout << "=== SI Kepegawaian ==" << endl;
        cout << "1. Tambah data pegawai" << endl;
        cout << "2. Lihat data pegawai" << endl;
        cout << "3. Cari data pegawai" << endl;
        cout << "4. Perbarui gaji" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu : ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            tambahData;
        case 2:
            lihatDaftar;
        case 3:
            cariData;
        case 4:
            perbaruiGaji;
        default:
            keluar;
        }
    } while (menu != 0);
}