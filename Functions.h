#pragma once
#include "stdafx.h"
#include "peremenie.h"

using namespace std;

void Brosok1() {
	std::cout << "���-�� �������: ";
	std::cin >> kol_vo_kubov;
	std::cout << "�����������: ";
	std::cin >> modificator;
	cout << "�������� ������: " << endl;



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
		cout << " = " << pulaDMG <<" " << "���� ���������(���� �� ������ ��������): " << ZonaVremenno << endl << endl;
		sumdice += pulaDMG;
		pulaDMG = 0;

	}



	damage = sumdice;
	cout << endl << "����: " << damage << endl;
	kubik = 0;
	kol_vo_kubov = 0;
}

void BrosokNavik() {
	cout<<endl << "������� �������� ������: ";
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
	cout << endl << "����� �������: " << sumdice << endl;
	if (sumdice > protiv) {
		cout <<endl<< "������!" << endl << "���-�� �������: " << uspehi << endl;
	}
	else if (sumdice <= protiv) {
		cout <<endl<< "�����!" << endl << "���-�� �������: " << uspehi << endl;
	}
}

void CritCheck() {
	if (sumdice <= 4) {
		critsuccess = true;
		critfail = false;
		cout<<endl << "����: �����" << endl;
	}
	else if (sumdice >= 17) {
		critfail = true;
		critsuccess = false;
		cout << "����: ������" << endl;
	}
	else {
		critsuccess = false;
		critfail = false;
	}
}

void Vibor_deystviya() {
	cout << "�������� ��������:" << endl << "N)������ ������ D)������ ����� " << endl << "��� �����: ";
	cin >> input;
	cout << endl << endl;
	if (input == 'N') {
		kol_vo_kubov = 3;
		BrosokNavik();
		CritCheck();
	}
	 else if (input == 'D') {
		cout << "������� ���-�� ����: ";
		cin >> puliAMOUNT;
		cout << endl<<endl;
		Brosok1();
	}
	 else if(input == 'E'){
		 cout << endl << endl << endl << "--------------------------------------------------------------------------------" << endl << endl;
		 cout << "�� �������� " << PlayerName << "!";
		 Sleep(1000);
		 exit(0);
	 }
}