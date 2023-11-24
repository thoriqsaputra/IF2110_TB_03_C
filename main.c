#include "ADT/tempRun.h"
#include "Lib/commands.h"
#include <stdio.h>
#include <stdlib.h>
// #include "Lib/ganti_profil/gantiprofil.h"
#include "inisialisasi/pengguna/pengguna.h"
#include "inisialisasi/draf/draf.h"
#include "inisialisasi/utas/utas.h"
#include "fitur/drafKicauan/drafKicauan.h"
#include "inisialisasi/kicauan/kicauan.h"
#include "fitur/balas/balas.h"
#include "fitur/load/loadnsave.h"

// main ini masi sementaraddd
// yang baru bisa
// - Profil
// - Pengguna
// - Draf Kicauan
// - Graf Pertemanan
// - Kicauan (on progress)
// - Utas ( on progress )

// command run sementara
// gcc -o main main.c inisialisasi/draf/draf.c inisialisasi/utas/utas.c inisialisasi/pengguna/pengguna.c inisialisasi/kicauan/kicauan.c inisialisasi/balasan/balasan.c fitur/drafKicauan/drafKicauan.c fitur/balas/balas.c fitur/teman/teman.c Lib/globalFunction.c fitur/load/loadnsave.c
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

    printf("Silahkan masukan folder konfigurasi untuk dimuat: ");

    STARTWORDINPUT();

    Word folder = currentWord;

    boolean isLogged = false;

    ListUserStatik LU;
    Graph GP;
    CreateEmptyPengguna(&LU);

    ListDinDraf LD;

    ListTree LT;

    ListDinUtas LS;

    ListDinKicauan LKD;
    ListDinKicauan LUKser;

    currentUser CU;
    CreateEmptyCurrentUser(&CU);

    DrafKicauan DK;
    CreateDrafKicauan(&DK);

    muat(folder, &LU, &LD, &LKD, &LS, &GP, &LT);

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
                loadKicauanUser(LKD, &LUKser, CU);
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
            berkicau(&LKD, &LUKser, CU);
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
            lihatUser(&LU, findusername, &GP, CU);
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
            buatDraf(&DK, CU, &LD, &LKD);
        }
        else if (isWordEqual(command, lihatDrafCmd))
        {
            lihatDraf(&DK, &LD, CU, &LKD);
        }
        else if (isWordEqual(command, kicauanCmd))
        {
            displayGraph(&GP);

            showKicauanUser(LKD, CU, &LU, GP);
        }
        else if (isWordEqual(command, ubahKicauanCmd))
        {
            STARTWORDINPUT();
            Word ID = currentWord;
            editKicauanInList(&LKD, &LUKser, wordToInt(ID), CU);
        }
        else if (isWordEqual(command, utasCmd))
        {
            STARTWORDINPUT();
            Word idkicau = currentWord;
            buatUtas(wordToInt(idkicau), &LS, LKD, CU);
        }
        else if (isWordEqual(command, cetakUtasCmd))
        {
            STARTWORDINPUT();
            Word idutas = currentWord;
            cetakUtas(LS, wordToInt(idutas), LKD, GP, CU, &LU);
        }
        else if (isWordEqual(command, sukaKicauanCmd))
        {
            STARTWORDINPUT();
            Word idkicau = currentWord;
            likeKicauanByID(&LKD, wordToInt(idkicau), &GP, CU, &LU);
        }
        else if (isWordEqual(command, balasCmd))
        {
            STARTWORDINPUT();
            // Membaca ID yang dibalas ID balasan
            Word ID = currentWord;
            int currentResult = 0;
            int idkicau = 0;
            int idbalas = 0;
            boolean isNegative = false;
            for (int i = 0; i < ID.Length; i++)
            {
                if (ID.TabWord[i] == '-')
                {
                    isNegative = true;
                }
                else if (ID.TabWord[i] == ' ')
                {
                    if (isNegative)
                    {
                        currentResult = -currentResult;
                        isNegative = false;
                    }
                    // Menyimpan ID yang dibalas
                    idkicau = currentResult;
                    currentResult = 0;
                }
                else
                {
                    currentResult = currentResult * 10 + (ID.TabWord[i] - '0');
                }
            }
            if (isNegative)
            {
                currentResult = -currentResult;
            }
            // Menyimpan ID Balasan
            idbalas = currentResult;

            BalasKicauan(LKD, idkicau, idbalas, CU, &LU, &LT, GP);
        }
        else if (isWordEqual(command, balasanCmd))
        {
            STARTWORDINPUT();
            int idkicau = wordToInt(currentWord);
            DisplayBalasan(idkicau, LT, &LU, CU, LKD, GP);
        }
        else
        {
            printf("Tidak ada command itu\n\n");
        }
    }
    return 0;
}
