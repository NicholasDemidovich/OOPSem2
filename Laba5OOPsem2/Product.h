#pragma once

class Product
{
	int idProduct;
	char* productName = new char[30];
	float productCost;

public:

	void setIdProduct(int idProduct) { this->idProduct = idProduct; }
	void setProductName(char* productName) { this->productName = productName; }
	void setProductCost(float productCost) { this->productCost = productCost; }

	int getIdProduct() { return idProduct; }
	char* getProductName() { return productName; }
	float getProductCost() { return productCost; }

	Product(int idProduct, char* productName, float productCost)
	{
		this->idProduct = idProduct;
		this->productName = productName;
		this->productCost = productCost;
	}
	Product() {}
	~Product() {}
};

