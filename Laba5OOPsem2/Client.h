#pragma once
class Client
{
	int idClient;
	char* surname = new char[30];
	float bill;

public:

	void setIdCLient(int idClient) { this->idClient = idClient; }
	void setSurname(char* surname) { this->surname = surname; }
	void setBill(float bill) { this->bill = bill; }

	int getIdClient() { return idClient; }
	char* getSurname() { return surname; }
	float getBill() { return bill; }

	Client(int idClient, char* surname, float bill)
	{
		this->idClient = idClient;
		this->surname = surname;
		this->bill = bill;
	}
	Client() {}
	~Client() {}
};

