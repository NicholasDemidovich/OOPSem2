#include "stdio.h"
#include <iostream>
#include "Firm.h"
#include "Client.h"
#include "FirmFunc.h"
#include "FileFunc.h"
#include "ClientFunc.h"
#include "Verification.h"
#include <vector> 
#include <map>



void main()
{
    using namespace std;
    setlocale(LC_ALL, "Russian");
    vector<Firm>* firm = new vector<Firm>;
    multimap<int, Client>* client = new multimap<int, Client>;
    int counterIdFirm = 0, counterIdClient = 0;
    int sw;
    while (true)
    {
    mainMenu:
        system("cls");
        cout << "0 - Выход;"
            << "\n1 - Администратор; "
            << "\n2 - Клиент: ";
        cin >> sw;
        if (sw == 0)return;
        if (sw == 1)
        {
            if (verificationAdmin())
            {
                while (true)
                {
                    system("cls");
                    cout << "0 - Переход на верхний уровень;"
                        << "\n1 - Добавить фирму;"
                        << "\n2 - Отобразить список фирм;"
                        << "\n3 - Добавить услугу;"
                        << "\n4 - Отобразить список услуг;"
                        << "\n5 - Добавить продукт;"
                        << "\n6 - Отобразть список товаров;"
                        << "\n7 - Удалть фирму;"
                        << "\n8 - Редактировать фирму;"
                        << "\n9 - Найти фирму;"
                        << "\n10 -Сортировка фирм: ";
                    cin >> sw;
                    switch (sw)
                    {
                    case 0:goto mainMenu;
                    case 1:
                        system("cls");
                        (*firm).push_back(addFirm(&counterIdFirm));
                        addInFileFirm((*firm)[counterIdFirm - 1]);
                        system("pause");
                        break;
                    case 2:
                        system("cls");
                        showFirm(*firm);
                        system("pause");
                        break;
                    case 3:
                        system("cls");
                        addService(firm);
                        system("pause");
                        break;
                    case 4:
                        system("cls");
                        showService(*firm);
                        system("pause");
                        break;
                    case 5:
                        system("cls");
                        addProduct(firm);
                        system("pause");
                        break;
                    case 6:
                        system("cls");
                        showProduct(*firm);
                        system("pause");
                        break;
                    case 7:
                        system("cls");
                        deleteFirm(firm);
                        addInFileAlllFirm(*firm);
                        system("pause");
                        break;
                    case 8:
                        system("cls");
                        editFirm(firm);
                        addInFileAlllFirm(*firm);
                        system("pause");
                        break;
                    case 9:
                        system("cls");
                        findFirm(*firm);
                        system("pause");
                        break;
                    case 10:
                        system("cls");
                        sortFirm(firm);
                        addInFileAlllFirm(*firm);
                        system("pause");
                        break;
                    default:cout << "Error!"; break;
                    }
                }
            }
            else { goto mainMenu; }
        }
        if (sw == 2)
        {
            addClient(client, &counterIdClient);
            while (true)
            {
                system("cls");
                cout << "0 - Переход на верхний уровень;"
                    << "\n1 - Отобразить список фирм;"
                    << "\n2 - Отобразить список услуг;"
                    << "\n3 - Отобразть список товаров;"
                    << "\n4 - Найти фирму;"
                    << "\n5 - Оформить заказ;"
                    << "\n6 - Вывести остаток средств: ";
                cin >> sw;
                switch (sw)
                {
                case 0:goto mainMenu;
                case 1:
                    system("cls");
                    showFirm(*firm);
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    showService(*firm);
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    showProduct(*firm);
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    findFirm(*firm);
                    system("pause");
                    break;
                case 5:
                    system("cls");
                    checkoutOrder(*firm, client);
                    system("pause");
                    break;
                case 6:
                    system("cls");
                    showBillClient(*client);
                    system("pause");
                    break;
                default:cout << "Error!"; break;
                }
            }
        }
    }



}