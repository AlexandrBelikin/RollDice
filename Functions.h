#pragma once
#include "stdafx.h"
#include "peremenie.h"

using namespace std;

void Brosok1() {
	std::cout << "Кол-во кубиков: ";
	std::cin >> kol_vo_kubov;
	std::cout << "Модификатор: ";
	std::cin >> modificator;
	cout << "Выпавшие кубики: " << endl;



	for (int k = 0; k < puliAMOUNT; k++) {
		
		cout << "( ";

		for (int i = 0; i < kol_vo_kubov; i++) {
			kubik = 1 + rand() % 6;
			Dice[i] = kubik;
			cout << "|" << Dice[i] << "|" << " ";
			pulaDMG += kubik;
		}


		ZonaVremenno = 3 + rand() % 15;
		cout << ") ";
		cout << "[" << modificator << "]" ;
		pulaDMG += modificator;
		cout << " = " << pulaDMG <<" " << "зона попадания(пока не сделал структур): " << ZonaVremenno << endl << endl;
		sumdice += pulaDMG;
		pulaDMG = 0;

	}



	damage = sumdice;
	cout << endl << "Урон: " << damage << endl;
	kubik = 0;
	kol_vo_kubov = 0;
}

void BrosokNavik() {
	cout<<endl << "Введите значение навыка: ";
	cin >> protiv;
	cout << endl << endl;
	for (int i = 0; i < kol_vo_kubov; i++) {
		kubik = 1 + rand() % 6;
		Dice[i] = kubik;
		cout << Dice[i] << " ";
		sumdice += kubik;
		kubik = 0;
	}
	uspehi = protiv - sumdice;
	cout << endl << "Сумма кубиков: " << sumdice << endl;
	if (sumdice > protiv) {
		cout <<endl<< "Провал!" << endl << "Кол-во успехов: " << uspehi << endl;
	}
	else if (sumdice <= protiv) {
		cout <<endl<< "Успех!" << endl << "Кол-во успехов: " << uspehi << endl;
	}
}

void CritCheck() {
	if (sumdice <= 4) {
		critsuccess = true;
		critfail = false;
		cout<<endl << "Крит: успех" << endl;
	}
	else if (sumdice >= 17) {
		critfail = true;
		critsuccess = false;
		cout << "Крит: провал" << endl;
	}
	else {
		critsuccess = false;
		critfail = false;
	}
}

void Vibor_deystviya() {
	cout << "Выберите действие:" << endl << "N)Бросок навыка D)Бросок урона " << endl << "Ваш выбор: ";
	cin >> input;
	cout << endl << endl;
	if (input == 'N') {
		kol_vo_kubov = 3;
		BrosokNavik();
		CritCheck();
	}
	 else if (input == 'D') {
		cout << "Введите кол-во пуль: ";
		cin >> puliAMOUNT;
		cout << endl<<endl;
		Brosok1();
	}
	 else if(input == 'E'){
		 cout << endl << endl << endl << "--------------------------------------------------------------------------------" << endl << endl;
		 cout << "До свидания " << PlayerName << "!";
		 Sleep(1000);
		 exit(0);
	 }
}
