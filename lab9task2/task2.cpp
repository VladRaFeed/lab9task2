#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string.h>
#include <stdio.h>

using namespace std;

void FindAppropriationInCodeFragment(char str[]) {
    char* copy = _strdup(str);  // Створюємо копію рядка
    char* words = strtok(copy, ";");
    char* tokens[15];
    int token_count = 0; // Лічильник лексем

    while (words != NULL) {
        char* equalWord = strchr(words, '=');

        if (equalWord != NULL) {
            // Знаходимо позицію '=' в words
            int equalPos = equalWord - words;

            // Виділяємо пам'ять для identifier та копіюємо його
            char* identifier = new char[equalPos + 1];
            strncpy(identifier, words, equalPos);
            identifier[equalPos] = '\0';

            // Виводимо identifier та variableType (можна замінити на вашу логіку обробки)
            cout << "Identifier: " << identifier  << endl;
            tokens[token_count] = identifier;
            token_count++;


            /*char* pch = strtok(str, ";");
            while (pch != NULL) {
                printf("\n%s", pch);
                pch = strtok(NULL, ";");
            }*/

            // Звільняємо пам'ять, виділену для identifier та variableType
            /*delete[] identifier;*/
        }

        words = strtok(NULL, ";");
    }
    free(copy);  // Звільняємо пам'ять, виділену strdup

    puts(str);
    for (int i = 0; i < token_count; i++)
    {
        puts(tokens[i]);
    }

}

int main() {
	char str[256];

	puts("Input a row");
	gets_s(str);
	FindAppropriationInCodeFragment(str);

	return 0;
}