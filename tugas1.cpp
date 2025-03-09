#include <iostream>
#include <string>

using namespace std;

struct film
{
    string judul[5];
    string kode[5];
    int harga[5];
} film;

void quick_sort(int filmHarga[], int awal, int akhir)
{

    int low = awal, high = akhir;

    int pivot = filmHarga[(awal + akhir) / 2];

    do
    {

        while (filmHarga[low] < pivot)

            low++;

        while (filmHarga[high] > pivot)

            high--;

        if (low <= high)
        {

            swap(filmHarga[low], filmHarga[high]);

            low++;

            high--;
        }

    } while (low <= high);

    if (awal < high)

        quick_sort(filmHarga, awal, high);

    if (low < akhir)

        quick_sort(filmHarga, low, akhir);
}

int main()
{
    system("cls");

    film.judul[0] = "Avengers";
    film.kode[0] = "F001";
    film.harga[0] = 8500;

    film.judul[1] = "Titanic";
    film.kode[1] = "F002";
    film.harga[1] = 9000;

    film.judul[2] = "Inception";
    film.kode[2] = "F003";
    film.harga[2] = 8800;

    film.judul[3] = "Interstellar";
    film.kode[3] = "F004";
    film.harga[3] = 9200;

    film.judul[4] = "Joker";
    film.kode[4] = "F005";
    film.harga[4] = 8700;

    int menu;
    string kodeFilm;
    int hargaFilm;
    cout << "========= Bioskop Double B =========" << endl;
    cout << "1. Tampilkan film" << endl;
    cout << "2. Cari berdasarkan kode" << endl;
    cout << "3. Cari berdasarkan harga" << endl;
    cout << "4. Sort harga film (asc)" << endl;
    cout << "5. Sort harga film (desc)" << endl;
    cout << "6. Exit" << endl;
    cout << "pilih menu : ";
    cin >> menu;

    switch (menu)
    {
    case 1:
        system("cls");
        cout << "==================================" << endl;
        cout << "Judul         Kode      Harga" << endl;
        cout << "==================================" << endl;
        cout << "Avengers      F001      8500" << endl;
        cout << "Titanic       F002      9000" << endl;
        cout << "Inception     F003      8800" << endl;
        cout << "Interstellar  F001      9200" << endl;
        cout << "Joker         F001      8700" << endl;
        cout << "==================================" << endl;
        system("pause");
        return main();
        break;
    case 2:
        system("cls");
        cout << "Masukan Kode : ";
        cin.ignore();
        getline(cin, kodeFilm);
        int i;
        bool found;
        i = 0;
        found = false;
        while ((i < 10) && (!found))
        {
            if (film.kode[i] == kodeFilm)
                found = true;
            else
                i = i + 1;
        }

        if (found)
            cout << "Judul: " << film.judul[i] << ", Kode: " << film.kode[i] << ", Harga: " << film.harga[i] << endl;
        else
            cout << "Kode " << kodeFilm << " tidak ditemukan" << endl;
        system("pause");
        return main();
        break;

    case 3:
    {
        system("cls");
        int n = sizeof(film.harga) / sizeof(*film.harga);
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (film.harga[i] > film.harga[j])
                {
                    // int temp = film.harga[j + 1];

                    // film.harga[j + 1] = film.harga[j];

                    // film.harga[j] = temp;
                    swap(film.harga[i], film.harga[j]);
                }
            }
        }

        cout << "Masukan Harga : ";
        cin >> hargaFilm;

        int awal = 0, tengah, akhir = 4;
        bool found = false;
        int indexHasil;

        while ((!found) && awal <= akhir)
        {
            tengah = (awal + akhir) / 2;
            if (film.harga[tengah] == hargaFilm)
            {
                found = true;
            }
            else
            {
                if (hargaFilm > film.harga[tengah])
                {
                    awal = tengah + 1;
                }
                else if (hargaFilm < film.harga[tengah])
                {
                    akhir = tengah - 1;
                }
            }
        }

        if (found)
            cout << "Judul: " << film.judul[tengah] << ", Kode: " << film.kode[tengah] << ", Harga: " << film.harga[tengah] << endl;
        else
            cout << "Harga " << hargaFilm << " tidak ditemukan" << endl;
        system("pause");
        return main();
        break;
    }
    case 4:
    {
        system("cls");
        quick_sort(film.harga, 0, 5 - 1);
        cout << endl;

        cout << "==================================" << endl;
        cout << "Judul         Kode      Harga" << endl;
        cout << "==================================" << endl;
        cout << film.judul[0] << "      " << film.kode[0] << "      " << film.harga[0] << endl;
        cout << film.judul[1] << "       " << film.kode[1] << "      " << film.harga[1] << endl;
        cout << film.judul[2] << "     " << film.kode[2] << "      " << film.harga[2] << endl;
        cout << film.judul[3] << "  " << film.kode[3] << "      " << film.harga[3] << endl;
        cout << film.judul[4] << "         " << film.kode[4] << "      " << film.harga[4] << endl;
        cout << "==================================" << endl;
        system("pause");
        return main();
        break;
    }
    case 5:
    {
        int n = sizeof(film.harga) / sizeof(*film.harga);
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (film.harga[i] < film.harga[j])
                {
                    swap(film.harga[i], film.harga[j]);
                }
            }
        }
        cout << "==================================" << endl;
        cout << "Judul         Kode      Harga" << endl;
        cout << "==================================" << endl;
        cout << film.judul[0] << "      " << film.kode[0] << "      " << film.harga[0] << endl;
        cout << film.judul[1] << "       " << film.kode[1] << "      " << film.harga[1] << endl;
        cout << film.judul[2] << "     " << film.kode[2] << "      " << film.harga[2] << endl;
        cout << film.judul[3] << "  " << film.kode[3] << "      " << film.harga[3] << endl;
        cout << film.judul[4] << "         " << film.kode[4] << "      " << film.harga[4] << endl;
        cout << "==================================" << endl;
    }
    }
}
