#pragma once
#include "stdio.h"
#include <iostream>
#include <fstream>
#include "Client.h"
#include "FirmFunc.h"
#include <map>


void addClient(multimap<int, Client>* client, int* counter)
{
	using namespace std;
	Client tmp;
	ofstream out;
	char* surname = new char[30];
	float bill;
	system("cls");
	cout << "\nВведите свою фамилию  ";
	cin >> surname;
	for (int i = 0; i < (*client).size(); i++)
	{
		auto it = (*client).find(i);
		if (it != (*client).end())
		{
			if (strcmp(it->second.getSurname(), surname) == 0)
			{
				return;
			}
		}
	}
	cout << "\nВведите свой счет:  ";
	cin >> bill;


	tmp.setIdCLient(*counter);
	tmp.setSurname(surname);
	tmp.setBill(bill);

	out.open("ClientFile.txt", ios::out | ios::app);
	if (!out)
	{
		cerr << "\nОшибка открытия файла!" << endl;
		system("pause");
	}
	else
	{
		out << surname << "  " << bill << "\n";
	}
	out.close();
	(*client).emplace(*counter, tmp);
	(*counter)++;
}


void checkoutOrder(vector<Firm> firm, multimap<int, Client>* tmp)
{
	Client clientTmp;
	Service serviceTmp;
	Product productTmp;
	int id, sw, firmTmp;
	char* surname = new char[30];
	float bill;
	system("cls");
	if (firm.size() == 0)
	{
		cout << "\nВ списке нет ни одной фирмы!" << endl;
		return;
	}
	cout << "\nВведите свою фамилию:  ";
	cin >> surname;
	for (int i = 0; i < (*tmp).size(); i++)
	{
		auto it = (*tmp).find(i);
		if (it != (*tmp).end())
		{
			if (strcmp(it->second.getSurname(), surname) == 0)
			{
				id = i;
				clientTmp.setBill(it->second.getBill());
				clientTmp.setIdCLient(it->second.getIdClient());
				clientTmp.setSurname(it->second.getSurname());
				break;
			}
		}
	}
	cout << "\nОформить заказ на услугу - 1;"
		<< "\nОформить заказ на товар - 2: ";
	cin >> sw;
	switch (sw)
	{
	case 1:
		showFirm(firm);
		cout << "\nВведите идентификационный номер фирмы:  ";
		cin >> firmTmp;
		if (firm[firmTmp].getCountService() == 0)
		{
			cout << "В списке нет ни одной услуги!";
			return;
		}
		for (int i = 0; i < firm[firmTmp].getCountService(); i++)
		{
			serviceTmp = firm[firmTmp].getService(i);
			cout << serviceTmp;
		}
		cout << "Введите номер требуемой услуги:  ";
		cin >> sw;
		bill = firm[firmTmp].getService(sw).getServiceCost();
		(*tmp).erase(id);
		clientTmp.setBill(clientTmp.getBill() - bill);
		(*tmp).emplace(id, clientTmp);
		cout << "\nСпасибо за покупку!!!" << endl;
		break;
	case 2:
		showFirm(firm);
		cout << "\nВведите идентификационный номер фирмы:  ";
		cin >> firmTmp;
		if (firm[firmTmp].getCountService() == 0)
		{
			cout << "В списке нет ни одного товара!";
			return;
		}
		for (int i = 0; i < firm[firmTmp].getCountProduct(); i++)
		{
			productTmp = firm[firmTmp].getProduct(i);
			cout << productTmp;
		}
		cout << "Введите номер требуемого товара:  ";
		cin >> sw;
		bill = firm[firmTmp].getProduct(sw).getProductCost();
		(*tmp).erase(id);
		clientTmp.setBill(clientTmp.getBill() - bill);
		(*tmp).emplace(id, clientTmp);
		cout << "\nСпасибо за покупку!!!" << endl;
		break;
	default:cout << "\nВведите корректное знаечние!!!"; break;
	}

}


void showBillClient(multimap<int, Client> tmp)
{
	char* surname = new char[30];
	cout << "\n\tВведите свою фамилию:  ";
	cin >> surname;
	for (int i = 0; i < (tmp).size(); i++)
	{
		auto it = (tmp).find(i);
		if (it != (tmp).end())
		{
			if (strcmp(it->second.getSurname(), surname) == 0)
			{
				cout << "\nВаш счет составляет:  " << it->second.getBill() << endl;
				break;
			}
		}
	}
}