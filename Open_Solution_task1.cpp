#include "Car.h"
#include "Plane.h"
#include "Boat.h"
#include "Spaceship.h"
#include <iostream>
#include <locale.h>
#include <vector>
#include <memory>
#include <iomanip>
#include <algorithm>
void fill_blank(Transport* transport) {
	std::cout << "������� ���������� ������������� (��������) ����������:";
	std::cin >> (*transport).unique_identificator;
	std::cout << "������� ��� ����������:";
	std::cin >> (*transport).weight;
	std::cout << "������� ��� �������:";
	std::cin >> (*transport).year_manufacture;
	std::cout << "������� ����� ����������:";
	std::cin >> (*transport).brand;
	std::cout << "������� ������ ����������:";
	std::cin >> (*transport).model;
}
void print_data_base(std::vector<Transport*> table) {
	std::cout << "					������� �������" << std::endl;
	int i = 1;
	for (auto iter = table.begin(); iter != table.end(); iter++, i++) {
		std::cout << "����� ������:" << i << std::endl;
		std::cout << "���������� ������������� ����������:" << (*iter)->unique_identificator << std::endl;
		std::cout << "��� ����������:" << (*iter)->type_transport << std::endl;
		std::cout << "��� ����������:" << (*iter)->weight << std::endl;
		std::cout << "��� ������� ����������:" << (*iter)->year_manufacture << std::endl;
		std::cout << "����� ����������:" << (*iter)->brand << std::endl;
		std::cout << "������ ����������:" << (*iter)->model << std::endl << std::endl;
	}
}
bool comp_id(Transport *a, Transport* b) {
	return (*a).unique_identificator < (*b).unique_identificator;
}
bool comp_type(Transport* a, Transport* b) {
	return (*a).type_transport < (*b).type_transport;
}
bool comp_weight(Transport* a, Transport* b) {
	return (*a).type_transport < (*b).type_transport;
}
bool comp_year(Transport* a, Transport* b) {
	return (*a).year_manufacture < (*b).year_manufacture;
}
bool comp_brand(Transport* a, Transport* b) {
	return (*a).brand < (*b).brand;
}
bool comp_model(Transport* a, Transport* b) {
	return (*a).model < (*b).model;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	int k = 1; // ���������� ��� ������ �����
	int choice;// ���������� ��� ������ � ���������� �������
	int type_choice; // ���������� ��� ������ ���� ����������, ������� ����� �������
	std::vector<Transport *> data_base; // ������� �������
	
	while (k) {
		std::cout << "������� 1, ���� ������ ������� ������ ������������� ��������." << std::endl
			<< "������� 2, ���� ������ ������������� ������ ������������� ��������." << std::endl
			<< "������� 3, ���� ������ ������� ������ ������������� ��������." << std::endl
			<< "������� 4, ���� ������ ���������� ���� ������ ������� � ����������� �� ���������� ����." << std::endl
			<< "������� 5, ���� ��������� ����� �� ���������� ����." << std::endl
			<< "������� 6, ���� ������ ��������� ��� ������ � ����." << std::endl
			<< "������� 7, ���� ������ ��������� ��� ������ �� �����." << std::endl;
		std::cin >> choice;
		switch (choice) {
		case 1:
		{	
			std::cout << "������� 1, ���� ������ ������� ������." << std::endl
				<< "������� 2, ���� ������ ������� �������." << std::endl
				<< "������� 3, ���� ������ ������� �����." << std::endl
				<< "������� 4, ���� ������ ������� ����������� �������." << std::endl;
			std::cin >> type_choice;
			switch (type_choice) {
			case 1:
			{
				Car *a = new Car();
				(*a).type_transport = "������";
				fill_blank(a);
				std::cout << "������� ����� ��������� ����������:";
				std::cin >> (*a).engine_size;
				std::cout << "������� ���������� ��������� ��� ����������:";
				std::cin >> (*a).horsepower;
				data_base.push_back(a);
				break;
			}
			case 2:
			{
				Plane* a = new Plane();
				(*a).type_transport = "������";
				fill_blank(a);
				std::cout << "������� ��������������� �������:";
				std::cin >> (*a).load_capacity;
				std::cout << "������� ������ ����� �������:";
				std::cin >> (*a).wingspan;
				data_base.push_back(a);
				break;
			}
			case 3:
			{
				Boat* a = new Boat();
				(*a).type_transport = "�����";
				fill_blank(a);
				std::cout << "������� ������� ���������� ����� ������:";
				std::cin >> (*a).screw_inmmersion_depth;
				data_base.push_back(a);
				break;
			}
			case 4: 
			{
				Spaceship* a = new Spaceship();
				(*a).type_transport = "����������� �������";
				fill_blank(a);
				std::cout << "������� ��� ������� ������������ �������:";
				std::cin >> (*a).fuel_type;
				data_base.push_back(a);
				break;
			}
		}
			break;
			
		}	
		case 2:
		{
			print_data_base(data_base);
			int unique_id;
			std::cout << "������� ���������� ������������� ����������, ���������� � ������� �� ������ ���������������:";
			std::cin >> unique_id;
			int temp;
			for (auto iter = data_base.begin(); iter != data_base.end(); iter++) {
				if ((*iter)->unique_identificator == unique_id) temp = iter - data_base.begin();
			}
			std::cout << "������� 1, ���� ������ �������� ���������� ������������� (��������) ����������." << std::endl
				<< "������� 2, ���� ������ �������� ��� ����������." << std::endl
				<< "������� 3, ���� ������ �������� ��� �������." << std::endl
				<< "������� 4, ���� ������ �������� ����� ����������." << std::endl
				<< "������� 5, ���� ������ �������� ������ ����������." << std::endl
				<< "������� 6, ���� ������ �������� �������������� �������� ����������." << std::endl;
			int choice_change;
			std::cin >> choice_change;
			switch (choice_change) {
			case 1:
				std::cout << "������� ����� ���������� ������������� (��������) ����������:";
				std::cin >> (*(data_base[temp])).unique_identificator;
				break;
			case 2:
				std::cout << "������� ����� ��� ����������:";
				std::cin >> (*(data_base[temp])).weight;
				break;
			case 3:
				std::cout << "������� ����� ��� �������:";
				std::cin >> (*(data_base[temp])).year_manufacture;
				break;
			case 4:
				std::cout << "������� ����� ����� ����������:";
				std::cin >> (*(data_base[temp])).brand;
				break;
			case 5:
				std::cout << "������� ����� ������ ����������:";
				std::cin >> (*(data_base[temp])).model;
				break;
			}
			break;
		}
			
		case 3:
		{
			print_data_base(data_base);
			int unique_id;
			std::cout << "������� ���������� ������������� ����������, ������� �������� ������ ������� �� �������:";
			std::cin >> unique_id;
			int temp;
			for (auto iter = data_base.begin(); iter != data_base.end(); iter++) {
				if ((*iter)->unique_identificator == unique_id) {
					data_base.erase(iter);
					break;
				}
			}
			break;
		}
		case 4:
		{
			std::cout << "������� 1, ���� ������ ������� ���������� �� ����������� ��������������." << std::endl
				<< "������� 2, ���� ������ ������� ���������� �� ���� ����������." << std::endl
				<< "������� 3, ���� ������ ������� ���������� �� ���� �������." << std::endl
				<< "������� 4, ���� ������ ������� ���������� �� ����� ����������." << std::endl
				<< "������� 5, ���� ������ ������� ���������� �� ������ ����������." << std::endl;
			int choice_change;
			std::cin >> choice_change;
			switch (choice_change) {
			case 1:
				sort(data_base.begin(), data_base.end(), comp_id);
				break;
			case 2:
				sort(data_base.begin(), data_base.end(), comp_weight);
				break;
			case 3:
				sort(data_base.begin(), data_base.end(), comp_year);
				break;
			case 4:
				sort(data_base.begin(), data_base.end(), comp_brand);
				break;
			case 5:
				sort(data_base.begin(), data_base.end(), comp_model);
				break;
			case 6:
				break;
			}
			print_data_base(data_base);
			break;
		}
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		}
		std::cout << "������� 1 - ���� ������ ��������� �����-�� ���������� �������� � ��������, 0 - ���� ������ ��������� ���������."<<std::endl;
		std::cin >> k;
	}
}

