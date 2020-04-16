#pragma once
#include "Service.h"
#include "Product.h"
#include <list>

class Firm : public Service, public Product
{
	int idFirm;
	char* nameOfFirm = new char[40];
	char* typeOfFirm = new char[30];
	float moneyFirm;

	Service* service = new Service[50];
	Product* product = new Product[50];

	int countService = 0;
	int countProduct = 0;

public:

	void setIdFirm(int idFirm) { this->idFirm = idFirm; }
	void setNameOfFirm(char* nameOfFirm) { this->nameOfFirm = nameOfFirm; }
	void setTypeOfFirm(char* typeOfFirm) { this->typeOfFirm = typeOfFirm; }
	void setMoneyFirm(float moneyFirm) { this->moneyFirm = moneyFirm; }

	int getIdFirm() { return idFirm; }
	char* getNameOfFirm() { return nameOfFirm; }
	char* getTypeOfFirm() { return typeOfFirm; }
	float getMoneyFirm() { return moneyFirm; }

	Firm(int idFirm, char* nameOfFirm, char* typeOfFirm, float moneyFirm,
		int idService, char* serviceName, float serviceCost,
		int idProduct, char* productName, float productCost) :Service(idService, serviceName, serviceCost), Product(idProduct, productName, productCost)
	{
		this->idFirm = idFirm;
		this->nameOfFirm = nameOfFirm;
		this->typeOfFirm = typeOfFirm;
		this->moneyFirm = moneyFirm;
	}

	void addService(Service serv) { service[countService] = serv; countService++; }
	void addProduct(Product prod) { product[countProduct] = prod; countProduct++; }

	int getCountService() { return countService; }
	int getCountProduct() { return countProduct; }

	Service getService(int id) { return service[id]; }
	Product getProduct(int id) { return product[id]; }

	Firm() {}
	~Firm() {}
};

