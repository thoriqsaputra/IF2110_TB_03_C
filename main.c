#include "ADT/tempRun.h"
#include "Lib/commands.h"
#include <stdio.h>
#include <stdlib.h>
// #include "Lib/ganti_profil/gantiprofil.h"
#include "inisialisasi/pengguna/pengguna.h"
#include "inisialisasi/draf/draf.h"
#include "fitur/drafKicauan/drafKicauan.h"

// main ini masi sementara
// yang baru bisa
// - Profil
// - Pengguna
// - Draf Kicauan

// command run sementara
// gcc -o main main.c inisialisasi/draf/draf.c inisialisasi/pengguna/pengguna.c fitur/drafKicauan/drafKicauan.c

int main()
{
    printf(".______    __    __  .______      .______    __  .______      \n");
    printf("|   _  \\  |  |  |  | |   _  \\     |   _  \\  |  | |   _  \\     \n");
    printf("|  |_)  | |  |  |  | |  |_)  |    |  |_)  | |  | |  |_)  |    \n");
    printf("|   _  <  |  |  |  | |      /     |   _  <  |  | |      /     \n");
    printf("|  |_)  | |  `--'  | |  |\\  \\----.|  |_)  | |  | |  |\\  \\----.\n");
    printf("|______/   \\______/  | _| `._____||______/  |__| | _| `._____| \n");

    printf("\nSelamat datang di BurBir.\n\n");

    printf("Aplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan metode (pengambilan data berupa) Focused Group Discussion kedua di zamannya.\n\n");

    // printf("Silahkan masukan folder konfigurasi untuk dimuat: ");

    // STARTWORDINPUT();

    // Word folder = currentWord;

    boolean isLogged = false; // sementara true

    // Inisialiasi (sementara)
    ListUserStatik LU;
    CreateEmptyPengguna(&LU);
    loadPenggunaConfig("configs/config-1/pengguna.config", &LU);

    ListDinDraf LD;
    loadDrafConfig("configs/config-1/draf.config", &LD);

    currentUser CU;
    CreateEmptyCurrentUser(&CU);

    DrafKicauan DK;
    CreateDrafKicauan(&DK);

    // Nanti pake ini
    // muat(Word folder, ListUserStatik * LU, ListDinBalasan * LB, ListDinDraf * LD, ListDinKicauan * LK)

    printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n\n");

    boolean runProgram = true;
    while (runProgram)
    {
        printf("\n");
        printf(">> ");

        STARTWORD(); // gapake STARTWORDINPUT() aja?
        // command.tabword = currentWord.tabword  & command.length = currentWord.length
        printf("\n");
        Word command = currentWord;
        Word lu = {"lu", 2};

        while ((!isLogged))
        {
            if (isWordEqual(command, masukCmd))
            {
                Masuk(&LU, &CU, &isLogged);
                CreateDrafKicauan(&DK);
                loadDrafKicauan(LD, &DK, CU); // Load draf dari raw data sesuai dengan current user
            }
            else if (isWordEqual(command, daftarCmd))
            {
                Daftar(&LU);
            }
            else if (isWordEqual(command, tutupProgramCmd))
            {
                isLogged = true; // biar keluar loop
                command = currentWord;
                break;
            }
            else if (isWordEqual(command, lu))
            {
                for (int i = 0; i < LU.capacity; i++)
                {
                    tulisDataPengguna(&LU.buffer[i]);
                }
            }
            else
            {
                printf("Anda Belum Login, silahkan MASUK terlebih dahulu!\n");
            }
            printf("\n");
            printf(">> ");
            STARTWORD();
            command = currentWord;
            printf("\n");
        }

        // Udah login
        if (isWordEqual(command, tutupProgramCmd))
        {
            fclose(pita);
            runProgram = false;
            printf("Anda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.\n");
        }
        else if (isWordEqual(command, kicauCmd))
        {
            ADVWORD();
            Word kicau = currentWord;
            printf("kamu masuk kicau\n");

            for (int i = 0; i < kicau.Length; i++)
            {
                printf("%c", kicau.TabWord[i]);
            }
            printf("\n");
        }
        else if (isWordEqual(command, gantiProfilCmd))
        {
            gantiProfil(&LU, &CU);
        }
        // Buat Debugging
        else if (isWordEqual(command, currentU))
        {
            tulisDataPengguna(&LU.buffer[idUser(CU)]);
        }
        else if (isWordEqual(command, lihatProfilCmd))
        {
            STARTWORDINPUT();
            Word findusername = currentWord;
            lihatUser(&LU, findusername);
        }
        else if (isWordEqual(command, keluarCmd))
        {
            Keluar(&LU, &CU, &isLogged);
        }
        else if (isWordEqual(command, aturJenisAkunCmd))
        {
            aturJenisAkun(&LU, &CU);
        }
        else if (isWordEqual(command, ubahFotoProfilCmd))
        {
            ubahFotoProfil(&LU, &CU);
        }
        else if (isWordEqual(command, buatDrafCmd))
        {
            buatDraf(&DK, CU, &LD);
        }
        else if (isWordEqual(command, lihatDrafCmd))
        {
            lihatDraf(&DK, &LD, CU);
        }
        else
        {
            printf("Tidak ada command itu\n\n");
        }
    }
    return 0;
}
