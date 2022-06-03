#include <iostream>
#include <Windows.h>
#include <string.h>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;//к-сть студентів
	float sm, sf, sp;//сума оцінок з усіх предметів
	cout << "Введіть кількість студентів\t";
	cin >> n;

	struct stud {
		char fam[25];
		int mat, fiz, prg;
		float sb;
	}

	ved[15];
	sm = 0;
	sf = 0;
	sp = 0;

	int i = 0;
	for (i = 0; i <= n - 1; i++) {
		cout << "*******Введіть інформацію про " << (i + 1) << " студента\n"; {
			cout << "Введіть прізвище\n";
			cin >> ved[i].fam;
			cout << "Оцінка з математики\t";
			cin >> ved[i].mat;
			cout << endl;
			cout << "Оцінка з фізики\t";
			cin >> ved[i].fiz;
			cout << endl;
			cout << "Оцінка з програмування\t";
			cin >> ved[i].prg;
			cout << endl;

			//обчислення среднього бала студента за сесію
			ved[i].sb = (float(ved[i].mat + ved[i].fiz + ved[i].prg)) / 3;
			//сумування оцінок в групі по предметам
			sm += ved[i].mat;
			sf += ved[i].fiz;
			sp += ved[i].prg;
		}
	}
	//виведення відомості успішності
	cout << "Відомість успішності\n";
	cout << "Прізвище\t" << "Математика\t" << "Фізика\t" << "Програмування\t" << "Ср. бал\n";

	for (i = 0; i <= n - 1; i++) {
			cout << ved[i].fam << "\t\t";
			cout << ved[i].mat << "\t\t";
			cout << ved[i].fiz << "\t\t";
			cout << ved[i].prg << "\t";
			cout << ved[i].sb;
			cout << endl;
	}
	//виведення результатів обчислень
	cout << "\n*********Результат сесії\n";
	cout.precision(3);
	for (i = 0; i <= n - 1; i++)
		cout << i + 1 << " " << ved[i].fam << "\t" << "математика = " << ved[i].mat << "\t" << "фізика = " << ved[i].fiz << "програмування = " << ved[i].prg;
	cout << endl;
	cout << "Середній бал групи з математики = " << sm / n << "\n";
	cout << "Середній бал групи з фізики = " << sf / n << "\n";
	cout << "Середній бал групи з програмування = " << sp / n << "\n";
	cout << endl;
	cout << "Відмінники з програмування: \n ";
	for (i = 0; i <= n - 1; i++)
		if (ved[i].prg == 5)
			cout << ved[i].fam << "\n";

	return 0;
}