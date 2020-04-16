#pragma once

class Service
{
	int idService;
	char* serviceName = new char[30];
	float serviceCost;

public:

	void setIdService(int idService) { this->idService = idService; }
	void setServiceName(char* serviceName) { this->serviceName = serviceName; }
	void setServiceCost(float serviceCost) { this->serviceCost = serviceCost; }

	int getIdService() { return idService; }
	char* getServicetName() { return serviceName; }
	float getServiceCost() { return serviceCost; }

	Service(int idService, char* serviceName, float serviceCost)
	{
		this->idService = idService;
		this->serviceName = serviceName;
		this->serviceCost = serviceCost;
	}
	Service() {}
	~Service() {}
};
