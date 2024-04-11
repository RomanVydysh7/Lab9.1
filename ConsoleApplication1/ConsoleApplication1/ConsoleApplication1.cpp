#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Specialty { KN, IT, ME, FI, TN };

struct Student {
	string prizv;
	int kurs;
	Specialty specialty;
	union {
		int Math;
		int Fizik;
		int Informat;
		int Program;
		int Num_met;
		int Pedagogik;
	};
};

void Create(Student* p, const int n);
void Print(Student* p, const int n);
void Search(Student* p, const int n);
void SearchStudens(Student* p, const int n);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	cout << "Введіть кількість студентів: ";
	cin >> n;

	Student* p = new Student[n];

	Create(p, n);
	Print(p, n);

	cout << "Учні які вчаться без 3: " << endl;
	Search(p, n);

	cout << "Студенти у яких з фізики 5" << endl;
	SearchStudens(p, n);

	return 0;
}

void Create(Student* p, const int n) {
	int specialty;
	for (int i = 0; i < n; i++) {
		cout << "Cтудент № " << i + 1 << ":" << endl;

		cin.get();
		cin.sync();

		cout << "Прізвище: "; getline(cin, p[i].prizv);
		cout << "Курс: "; cin >> p[i].kurs;
		cout << "Оцінка з математики: "; cin >> p[i].Math;
		cout << "Оцінка з фізики: "; cin >> p[i].Fizik;
		cout << "Спеціальність (0 - КН, 1 - ІН, 2 - МЕ, 3 - ФІ, 4 - ТТІ): ";
		cin >> specialty;
		p[i].specialty = (Specialty)specialty;

		switch (p[i].specialty)
		{
		case KN:
			cout << "Оцінка з програмування: "; cin >> p[i].Program;
			break;
		case IT:
			cout << "Оцінка з чисельних методів: "; cin >> p[i].Num_met;
			break;
		case ME:
		case FI:
		case TN:
			cout << "Оцінка з педагогіки: "; cin >> p[i].Pedagogik;
			break;
		}
		cout << endl;
	}
};

void Print(Student* p, const int n) {
	cout << "============================================================================================================"
		<< endl;
	cout << "| № | Прізвище | Курс | Математика | Фізика | Спеціальність | Програмування | Чисельні методи | Педагогіка |"
		<< endl;
	cout << "------------------------------------------------------------------------------------------------------------"
		<< endl;

	for (int i = 0; i < n; i++) {
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(9) << left << p[i].prizv
			<< "| " << setw(4) << right << p[i].kurs << " "
			<< "| " << setw(10) << left << p[i].Math << " "
			<< "| " << setw(6) << left << p[i].Fizik << " "
			<< "| " << setw(14) << left << p[i].specialty;

		switch (p[i].specialty)
		{
		case KN:
			cout << "| " << setw(13) << setprecision(2) << fixed << right
				<< p[i].Program << " |" << setw(18) << right << "|"
				<< setw(13) << right << "|" << endl;
			break;
		case IT:
			cout << "| " << setw(15) << right << "|"
				<< setw(16) << setprecision(2) << fixed << right << p[i].Num_met << " |"
				<< setw(13) << right << "|" << endl;
			break;
		case ME:
		case FI:
		case TN:
			cout << "| " << setw(15) << right << "|"
				<< setw(18) << right << "|"
				<< setw(11) << setprecision(2) << fixed << right << p[i].Num_met << " |" << endl;
			break;
		}
	}
	cout << "============================================================================================================"
		<< endl;
	cout << endl;
};

void Search(Student* p, const int n) {
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (p[i].Fizik > 3 && p[i].Informat > 3 && p[i].Math > 3 && p[i].Num_met > 3 && p[i].Pedagogik > 3) {
			cout << setw(3) << right << i + 1
				<< ". " << p[i].prizv << endl;
		}
	}
};

void SearchStudens(Student* p, const int n) {
	for (int i = 0; i < n; i++) {
		if (p[i].Fizik == 5) {
			cout << setw(3) << right << i + 1
				<< ". " << p[i].prizv << endl;
		}
	}
}