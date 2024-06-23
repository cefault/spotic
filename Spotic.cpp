#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

#include "Art.h"

#define NEWLINE cout << endl
#define CLEAR system("CLS")

#define GREEN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10)
#define RESET SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7)


struct Audio {                                          // Audio structure
    string audio_name;
    string audio_author;
    string audio_year;
    string audio_lyrics = "";
    string audio_link;
};

vector <Audio> AudioCollection;                         // Song-list

void audio_register(Audio& Input) {                     // Register function
    CLEAR;
    GREEN; cout << "Реєстрація нового запису\n\n"; RESET;
    cout << "   Введіть назву: "; cin.ignore(); getline(cin, Input.audio_name);
    cout << "   Введіть автора: "; getline(cin, Input.audio_author);
    cout << "   Введіть рік створення: "; getline(cin, Input.audio_year);

    short _TEXT_CHOICE;
    cout << "\n   Текст пісні:\n"
            "       [1] Введення самотужки\n"
            "       [2] Завантаження через файл\n"
            "       [3] Завантажити текст пізніше\n\n"
            "   Ваш вибір: ";
    cin >> _TEXT_CHOICE;
    NEWLINE;
    if (_TEXT_CHOICE == 1) {
        string KeyboardInput;
        cout << "Введіть \"-\" для того щоб завершити\n";
        while (true) {
            getline(cin, KeyboardInput);
            if (KeyboardInput == "-") break;
            else Input.audio_lyrics += KeyboardInput + '\n';
        }
    }
    else if (_TEXT_CHOICE == 2) {
        string LyricsFileName;
        cout << "Введіть назву текстового документу: ";
        cin.ignore();
        getline(cin, LyricsFileName);

        ifstream Lyrics(LyricsFileName + ".txt");
        if (!Lyrics.is_open()) cout << "Файл не знайдено";

        string Lyric;
        while (getline(Lyrics, Lyric)) Input.audio_lyrics += Lyric + '\n';
    }
    else Input.audio_lyrics = "Пусто";

    NEWLINE;
    cout << "   Посилання: ";
    cin >> Input.audio_link;
}

bool index_reach(short audio_index) {                   // Check if index created in collection
    if (audio_index > 0 && audio_index <= AudioCollection.size()) return true;
    return false;
}

void audio_editor(short audio_index) {
    if (!index_reach(audio_index)) return;
    while (true) {
        CLEAR;
        GREEN; cout << "Редагування запису [" << audio_index << "]\n\n"; RESET;
        cout << "\tНазва: " << AudioCollection[audio_index - 1].audio_name << endl;
        cout << "\tАвтор: " << AudioCollection[audio_index - 1].audio_author << endl;
        cout << "\tРік: " << AudioCollection[audio_index - 1].audio_year << endl;
        cout << "\tТекст: ...\n"; 
        cout << "\tПосилання: " << AudioCollection[audio_index - 1].audio_name << endl << endl;
        cout << "   Яку опцію потрібно відредагувати?\n";
        cout << "       [1] Назва\n"
                "       [2] Автор\n"
                "       [3] Рік\n"
                "       [4] Текст\n"
                "       [5] Посилання\n\n"
                "       [0] Повернутися в меню\n\n"
                "   Ваш вибір: ";
        int _OPTION;
        cin >> _OPTION;

        cin.ignore();
        if (_OPTION == 1) {
            cout << "Введіть назву: ";
            getline(cin, AudioCollection[audio_index - 1].audio_name);
        }
        else if (_OPTION == 2) {
            cout << "Введіть автора: ";
            getline(cin, AudioCollection[audio_index - 1].audio_author);
        }
        else if (_OPTION == 3) {
            cout << "Введіть рік: ";
            getline(cin, AudioCollection[audio_index - 1].audio_year);
        }
        else if (_OPTION == 4) {
            AudioCollection[audio_index - 1].audio_lyrics = "";
            short _TEXT_CHOICE;
            cout << "       [1] Введення самотужки\n"
                    "       [2] Завантаження через файл\n\n"
                    "   Ваш вибір: ";
            cin >> _TEXT_CHOICE;
            NEWLINE;
            if (_TEXT_CHOICE == 1) {
                string KeyboardInput;
                cout << "Введіть \"-\" для того щоб завершити\n";
                while (true) {
                    getline(cin, KeyboardInput);
                    if (KeyboardInput == "-") break;
                    else AudioCollection[audio_index - 1].audio_lyrics += KeyboardInput + '\n';
                }
            }
            else if (_TEXT_CHOICE == 2) {
                string LyricsFileName;
                cout << "Введіть назву текстового документу: ";
                cin.ignore();
                getline(cin, LyricsFileName);

                ifstream Lyrics(LyricsFileName + ".txt");
                if (!Lyrics.is_open()) cout << "Файл не знайдено";

                string Lyric;
                while (getline(Lyrics, Lyric)) AudioCollection[audio_index - 1].audio_lyrics += Lyric + '\n';
            }
            else AudioCollection[audio_index - 1].audio_lyrics = "Пусто";
        }
        else if (_OPTION == 5) {
            cout << "Введіть посилання: ";
            getline(cin, AudioCollection[audio_index - 1].audio_link);
        }
        else break;
    }
};


void audio_log(short audio_index) {
    if (!index_reach(audio_index)) return;
    CLEAR;
    GREEN; cout << "Інформація про запис [" << audio_index << "]\n\n"; RESET;
    cout << "   Назва: " << AudioCollection[audio_index - 1].audio_name << endl;
    cout << "   Автор: " << AudioCollection[audio_index - 1].audio_author << endl;
    cout << "   Рік: " << AudioCollection[audio_index - 1].audio_year << endl << endl;
    cout << "   Текст:\n\n" << AudioCollection[audio_index - 1].audio_lyrics << endl << endl;
    cout << "   Посилання: " << AudioCollection[audio_index - 1].audio_link << endl << endl;

    cout << "Натисніть \"Enter\" для того щоб повернутися в Меню\n";
    string _dump; cin.ignore(); getline(cin, _dump);
}

int main()
{   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    CLEAR; art_logo_arial(); NEWLINE; NEWLINE;          // Art & etc

    cout << "   Список пісень та аудіо: ";              // Song-list output
    if (AudioCollection.size() <= 0) cout << "Пусто";   // Is song-list empty?
    else {
        short _COUNTER = 0;
        for (Audio _Current_Audio : AudioCollection) {
            _COUNTER++;
            cout << "\n       [" << _COUNTER << "] " << 
                _Current_Audio.audio_name << " : " << 
                _Current_Audio.audio_author;
        }
    }
                                                        // Menu
    cout << "\n\n   |––––––––––––––––––––––––––––––––––––––––––––––––––––––––––|\n"; 
    cout << "   |   [1] Новий запис                                        |\n";        
    cout << "   |   [2] Редагування запису                                 |\n";
    cout << "   |   [3] Видалення запису                                   |\n";
    cout << "   |   [4] Відображення інформації                            |\n";
    cout << "   |   [5] Збереження тексту до файлу                         |\n";
    cout << "   |   [6] Відкрити аудіофайл                                 |\n";
    cout << "   |   [0] Вихід                                              |\n";
    cout << "   |––––––––––––––––––––––––––––––––––––––––––––––––––––––––––|\n";


    short User;                                           
    cout << "\n   Ваш вибір: ";
    cin >> User;

    if (User == 0) { Sleep(1000); return 0; }           // Statement
    else if (User == 1) {
        Audio Instance;
        audio_register(Instance);
        AudioCollection.push_back(Instance);
    }
    else if (User == 2) {
        short Instance_Index;
        cout << "\nВведіть індекс запису: ";
        cin >> Instance_Index;
        audio_editor(Instance_Index);
    }
    else if (User == 4) {
        short Instance_Index;
        cout << "\nВведіть індекс запису: ";
        cin >> Instance_Index;
        audio_log(Instance_Index);
    }

    main();                                             // Recall
}