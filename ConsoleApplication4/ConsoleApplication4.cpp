//1
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функція для перевірки чи є число простим
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Функція для генерації чисел Фібоначчі до певного числа
vector<int> fibonacci(int limit) {
    vector<int> fib = { 0, 1 };
    while (fib.back() < limit) {
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    }
    return fib;
}

int main() {
    srand(time(0));

    vector<int> primes;
    vector<int> fibonacciNumbers;
    vector<int> randomNumbers;

    // Генерація 100 випадкових чисел
    for (int i = 0; i < 100; i++) {
        randomNumbers.push_back(rand() % 1000 + 1);
    }

    // Генерація чисел Фібоначчі до 1000
    vector<int> fib = fibonacci(1000);

    // Фільтруємо прості числа та числа Фібоначчі
    for (int num : randomNumbers) {
        if (isPrime(num)) {
            primes.push_back(num);
        }
        if (find(fib.begin(), fib.end(), num) != fib.end()) {
            fibonacciNumbers.push_back(num);
        }
    }

    // Записуємо в файли
    ofstream primeFile("primes.txt");
    ofstream fibFile("fibonacci.txt");

    for (int prime : primes) {
        primeFile << prime << endl;
    }
    for (int fibNum : fibonacciNumbers) {
        fibFile << fibNum << endl;
    }

    // Виведення статистики
    cout << "Статистика:" << endl;
    cout << "Прості числа: " << primes.size() << endl;
    cout << "Числа Фібоначчі: " << fibonacciNumbers.size() << endl;

    return 0;
}
//2
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void replaceWordInFile(const string& filePath, const string& oldWord, const string& newWord) {
    ifstream file(filePath);
    stringstream buffer;
    buffer << file.rdbuf();
    string content = buffer.str();

    size_t pos = 0;
    while ((pos = content.find(oldWord, pos)) != string::npos) {
        content.replace(pos, oldWord.length(), newWord);
        pos += newWord.length();
    }

    ofstream outFile(filePath);
    outFile << content;
}

int main() {
    string filePath, oldWord, newWord;

    cout << "Введіть шлях до файлу: ";
    getline(cin, filePath);

    cout << "Введіть слово для пошуку: ";
    getline(cin, oldWord);

    cout << "Введіть слово для заміни: ";
    getline(cin, newWord);

    // Виконання заміни
    replaceWordInFile(filePath, oldWord, newWord);

    cout << "Заміна завершена!" << endl;

    return 0;
}
//3
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void moderateFile(const string& inputFile, const string& wordsFile) {
    ifstream inFile(inputFile);
    ifstream wordsIn(wordsFile);

    vector<string> wordsToModerate;
    string word;

    while (getline(wordsIn, word)) {
        wordsToModerate.push_back(word);
    }

    string content, line;
    while (getline(inFile, line)) {
        content += line + "\n";
    }

    // Заміна слів на "*"
    for (const string& badWord : wordsToModerate) {
        size_t pos = 0;
        while ((pos = content.find(badWord, pos)) != string::npos) {
            content.replace(pos, badWord.length(), string(badWord.length(), '*'));
            pos += badWord.length();
        }
    }

    // Запис результату в новий файл
    ofstream outFile("moderated_file.txt");
    outFile << content;

    cout << "Модерація завершена!" << endl;
}

int main() {
    string inputFile, wordsFile;

    cout << "Введіть шлях до файлу з текстом: ";
    getline(cin, inputFile);

    cout << "Введіть шлях до файлу зі словами для модерації: ";
    getline(cin, wordsFile);

    moderateFile(inputFile, wordsFile);

    return 0;
}
//4
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void reverseFileContent(const string& filePath) {
    ifstream file(filePath);
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

    // Перевертаємо вміст
    reverse(content.begin(), content.end());

    // Записуємо перевернутий вміст в новий файл
    ofstream outFile("reversed_file.txt");
    outFile << content;

    cout << "Перевернуте вміст збережено в 'reversed_file.txt'." << endl;
}

int main() {
    string filePath;
    cout << "Введіть шлях до файлу: ";
    getline(cin, filePath);

    reverseFileContent(filePath);

    return 0;
}
//5
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ifstream inputFile("numbers.txt");

    int number;
    int positiveCount = 0, negativeCount = 0, twoDigitCount = 0, fiveDigitCount = 0;

    vector<int> positiveNumbers, negativeNumbers, twoDigitNumbers, fiveDigitNumbers;

    while (inputFile >> number) {
        if (number > 0) {
            positiveCount++;
            positiveNumbers.push_back(number);
        }
        else if (number < 0) {
            negativeCount++;
            negativeNumbers.push_back(number);
        }

        if (abs(number) >= 10 && abs(number) < 100) {
            twoDigitCount++;
            twoDigitNumbers.push_back(number);
        }

        if (abs(number) >= 10000 && abs(number) < 100000) {
            fiveDigitCount++;
            fiveDigitNumbers.push_back(number);
        }
    }

    // Записуємо результати в окремі файли
    ofstream posFile("positive_numbers.txt");
    for (int num : positiveNumbers) {
        posFile << num << endl;
    }

    ofstream negFile("negative_numbers.txt");
    for (int num : negativeNumbers) {
        negFile << num << endl;
    }

    ofstream twoDigitFile("two_digit_numbers.txt");
    for (int num : twoDigitNumbers) {
        twoDigitFile << num << endl;
    }

    ofstream fiveDigitFile("five_digit_numbers.txt");
    for (int num : fiveDigitNumbers) {
        fiveDigitFile << num << endl;
    }

    // Виведення статистики
    cout << "Статистика:" << endl;
    cout << "Кількість додатних чисел: " << positiveCount << endl;
    cout << "Кількість від'ємних чисел: " << negativeCount << endl;
    cout << "Кількість двозначних чисел: " << twoDigitCount << endl;
    cout << "Кількість п'ятизначних чисел: " << fiveDigitCount << endl;

    return 0;
}
