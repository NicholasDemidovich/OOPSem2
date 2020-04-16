#pragma once
#include "Firm.h"
#include "stdio.h"
#include <iostream>
#include <vector>
using namespace std;

ostream& operator<<(ostream& out, Firm firm)
{
	return out << "\nИдентификационный номер фирмы:  " << firm.getIdFirm()
		<< "\nНазвание фирмы:  " << firm.getNameOfFirm()
		<< "\nТип фирмы:  " << firm.getTypeOfFirm()
		<< "\nСчет фирмы:  " << firm.getMoneyFirm() << endl;
}

ostream& operator<<(ostream& out, Service service)
{
	return out << "\nИдентификационный номер услуги:  " << service.getIdService()
		<< "\nНазвание услуги:  " << service.getServicetName()
		<< "\nСтоимость услуги:  " << service.getServiceCost() << endl;
}

ostream& operator<<(ostream& out, Product product)
{
	return out << "\nИдентификационный номер товара:  " << product.getIdProduct()
		<< "\nНазвание товара:  " << product.getProductName()
		<< "\nСтоимость товара:  " << product.getProductCost() << endl;
}

Firm addFirm(int* counter)
{
	Firm firm;

	int idFirm = *counter;
	char* nameOfFirm = new char[40];
	char* typeOfFirm = new char[30];
	float moneyFirm;

	cout << "\nВведите название фирмы:  ";
	cin >> nameOfFirm;
	cout << "\nВведите тип фирмы:  ";
	cin >> typeOfFirm;
	cout << "\nВведите счет фирмы:  ";
	cin >> moneyFirm;

	firm.setIdFirm(idFirm);
	firm.setNameOfFirm(nameOfFirm);
	firm.setTypeOfFirm(typeOfFirm);
	firm.setMoneyFirm(moneyFirm);

	(*counter)++;
	return firm;
}

void addService(vector<Firm>* tmp)
{
	Firm firm;
	Service service;

	int idFirm;
	int idService;
	char* serviceName = new char[30];
	float serviceCost;
	cout << "\n\tСписок фирм: ";
	for (int i = 0; i < (*tmp).size(); i++)
	{
		cout << "\n\t***Информация о фирме***";
		cout << (*tmp)[i];
	}
	cout << "\nВведите идентификационный номер подходящей фирмы:  ";
	cin >> idFirm;
	if (idFirm > (*tmp).size()) { cout << "\nДанной фирмы в списке нет!!!"; return; }
	cout << "\nВведите идентфикационный номер услуги:  ";
	cin >> idService;
	cout << "\nВведите название услуги:  ";
	cin >> serviceName;
	cout << "\nВведите стоимость услуги:  ";
	cin >> serviceCost;
	firm = (*tmp)[idFirm];

	service.setIdService(idService);
	service.setServiceName(serviceName);
	service.setServiceCost(serviceCost);

	firm.addService(service);

	(*tmp)[idFirm] = firm;
}

void addProduct(vector<Firm>* tmp)
{
	Firm firm;
	Product product;

	int idFirm;
	int idProduct;
	char* productName = new char[30];
	float productCost;
	cout << "\n\tСписок фирм: ";
	for (int i = 0; i < (*tmp).size(); i++)
	{
		cout << "\n\t***Информация о фирме***";
		cout << (*tmp)[i];
	}
	cout << "\nВведите идентификационный номер подходящей фирмы:  ";
	cin >> idFirm;
	if (idFirm > (*tmp).size()) { cout << "\nДанной фирмы в списке нет!!!"; return; }
	cout << "\nВведите идентфикационный номер товара:  ";
	cin >> idProduct;
	cout << "\nВведите название товара:  ";
	cin >> productName;
	cout << "\nВведите стоимость товара:  ";
	cin >> productCost;
	firm = (*tmp)[idFirm];

	product.setIdProduct(idProduct);
	product.setProductName(productName);
	product.setProductCost(productCost);

	firm.addProduct(product);

	(*tmp)[idFirm] = firm;
}

void showFirm(vector<Firm> firm)
{
	if (firm.size() == 0)
	{
		cout << "\nВ списке нет ни одной фирмы!" << endl;
		return;
	}
	cout << "\n\t***Информация о фирме***";
	for (int i = 0; i < firm.size(); i++)
	{
		cout << firm[i];
	}
}

void showService(vector<Firm> firm)
{
	Service tmp;
	int id;
	if (firm.size() == 0)
	{
		cout << "\nВ списке нет ни одной фирмы!" << endl;
		return;
	}
	cout << "\nВведите идентификационный номер фирмы:  ";
	cin >> id;
	if (firm[id].getCountService() == 0)
	{
		cout << "В списке нет ни одной услуги!";
		return;
	}
	if (id > (firm).size()) { cout << "\nДанной фирмы в списке нет!!!"; return; }
	for (int i = 0; i < firm[id].getCountService(); i++)
	{
		tmp = firm[id].getService(i);
		cout << tmp;
	}
}

void showProduct(vector<Firm> firm)
{
	Product tmp;
	int id;
	if (firm.size() == 0)
	{
		cout << "\nВ списке нет ни одной фирмы!" << endl;
		return;
	}
	cout << "\nВведите идентификационный номер фирмы:  ";
	cin >> id;
	if (firm[id].getCountProduct() == 0)
	{
		cout << "В списке нет ни одного товара!";
		return;
	}
	if (id > (firm).size()) { cout << "\nДанной фирмы в списке нет!!!"; return; }
	for (int i = 0; i < firm[id].getCountProduct(); i++)
	{
		tmp = firm[id].getProduct(i);
		cout << tmp;
	}
}


void deleteFirm(vector<Firm>* tmp)
{
	int idFirm;
	bool flag = false;
	if ((*tmp).size() == 0)
	{
		cout << "\nВ списке нет ни одной фирмы!" << endl;
		return;
	}
	cout << "\n\tСписок фирм: ";
	for (int i = 0; i < (*tmp).size(); i++)
	{
		cout << "\n\t***Информация о фирме***";
		cout << (*tmp)[i];
	}
	cout << "\nВведите идентификационный номер удаляемой фирмы:  ";
	cin >> idFirm;
	for (int i = 0; i < (*tmp).size(); i++)
	{
		if (idFirm == (*tmp)[i].getIdFirm())
		{
			flag = true;
			for (int j = i; j < (*tmp).size() - 1; j++)
			{
				(*tmp)[j] = (*tmp)[j + 1];
			}
			(*tmp).resize((*tmp).size() - 1);
		}
	}
	if (flag == true) { cout << "\nФирма с идентификационным номером:  " << idFirm << " удалена!" << endl; }
	else { cout << "\nФирмы с идентификационным номером:  " << idFirm << " в списке нет!" << endl; }
}

void editFirm(vector<Firm>* tmp)
{
	Firm firmTmp;
	int idFirm;
	char* nameOfFirm = new char[40];
	char* typeOfFirm = new char[30];
	float moneyFirm;
	bool flag = false;
	if ((*tmp).size() == 0)
	{
		cout << "\nВ списке нет ни одной фирмы!" << endl;
		return;
	}
	cout << "\n\tСписок фирм: ";
	for (int i = 0; i < (*tmp).size(); i++)
	{
		cout << "\n\t***Информация о фирме***";
		cout << (*tmp)[i];
	}
	cout << "\nВведите идентификационный номер редактируемой фирмы:  ";
	cin >> idFirm;
	for (int i = 0; i < (*tmp).size(); i++)
	{
		if (idFirm == (*tmp)[i].getIdFirm())
		{
			flag = true;
			cout << "\nВведите новое название фирмы:  ";
			cin >> nameOfFirm;
			cout << "\nВведите новый тип фирмы:  ";
			cin >> typeOfFirm;
			cout << "\nВведите новый счет фирмы:  ";
			cin >> moneyFirm;

			(*tmp)[idFirm].setNameOfFirm(nameOfFirm);
			(*tmp)[idFirm].setTypeOfFirm(typeOfFirm);
			(*tmp)[idFirm].setMoneyFirm(moneyFirm);
		}
	}
	if (flag == true) { cout << "\nФирма с идентификационным номером:  " << idFirm << " изменена!" << endl; }
	else { cout << "\nФирмы с идентификационным номером:  " << idFirm << " в списке нет!" << endl; }
}


void findFirm(vector<Firm> tmp)
{
	int idFirm;
	bool flag = false;
	if (tmp.size() == 0)
	{
		cout << "\nВ списке нет ни одной фирмы!" << endl;
		return;
	}
	cout << "\nВведите идентификационный номер искомой фирмы:  ";
	cin >> idFirm;
	for (int i = 0; i < (tmp).size(); i++)
	{
		if (idFirm == (tmp)[i].getIdFirm())
		{
			flag = true;
			cout << (tmp)[idFirm];
		}
	}
	if (flag == true) { cout << "\nФирма с идентификационным номером:  " << idFirm << " найдена!" << endl; }
	else { cout << "\nФирмы с идентификационным номером:  " << idFirm << " в списке нет!" << endl; }
}

void sortFirm(vector<Firm>* tmp)
{
	if ((*tmp).size() == 0)
	{
		cout << "\nВ списке нет ни одной фирмы!" << endl;
		return;
	}
	Firm firmTmp;
	for (int i = 0; i < (*tmp).size(); i++)
	{
		for (int j = i + 1; j < (*tmp).size(); j++)
		{
			if ((*tmp)[i].getMoneyFirm() > (*tmp)[j].getMoneyFirm())
			{
				firmTmp = (*tmp)[i];
				(*tmp)[i] = (*tmp)[j];
				(*tmp)[j] = firmTmp;
			}
		}
	}
}