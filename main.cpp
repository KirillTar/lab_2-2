#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;

bool ender(char ch) {
	char enders[3] = { '.','?','!' };
	for (char c : enders) {
		if (c == ch) return true;
	}
	return false;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream in("data.txt");

	if (!in.is_open()) {
		cout << "Не удалось открыть файл.";
		return 0;
	}

	int cnt = 0;
	char word;

	while ((word = in.get()) && word != EOF) {

		if (ender(word)) {
			cnt++;
		}
	}

	in.clear();
	in.seekg(0);

	string *sentences = new string[cnt];

	for (int i = 0; i < cnt; i++) {

		while (!ender(word)) {
			word = in.get();
			sentences[i] += word;
		}
		word = in.get();
	}

	for (int k = cnt - 1; k >= 0; k--) {
		cout << sentences[k];
	}

	in.close();

	return 0;
}