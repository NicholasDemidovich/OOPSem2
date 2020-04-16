#pragma once
#include "stdio.h"
#include <iostream>
#include "Firm.h"
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void addInFileFirm(Firm firm)
{
	ofstream out;
	out.open("Firm.txt", ios::out | ios::app);
	if (!out)
	{
		cerr << "\nОшибка открытия файла!!!";
		return;
	}
	out << firm.getIdFirm() << "  " << firm.getNameOfFirm()
		<< "  " << firm.getMoneyFirm() << "  " << firm.getTypeOfFirm() << "\n";
	out.close();
}

void addInFileAlllFirm(vector<Firm> firm)
{
	ofstream out;
	out.open("Firm.txt", ios::out);
	if (!out)
	{
		cerr << "\nОшибка открытия файла!!!";
		return;
	}
	for (int i = 0; i < firm.size(); i++)
	{
		out << (firm)[i].getIdFirm() << "  " << (firm)[i].getNameOfFirm()
			<< "  " << (firm)[i].getMoneyFirm() << "  " << (firm)[i].getTypeOfFirm() << "\n";
	}
	out.close();
}

