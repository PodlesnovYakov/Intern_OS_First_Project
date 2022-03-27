#include "Car.h"
#include "Plane.h"
#include "Boat.h"
#include "Spaceship.h"
#include <iostream>
#include <windows.h>
#include <vector>
#include <memory>
#include <iomanip>
#include <algorithm>
#include <fstream>

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
		std::cout << "������ ����������:" << (*iter)->model << std::endl;
		if ((*iter)->type_transport == "������") {
			Car* temp = (Car*)(*iter);
			std::cout << "����� ���������:" << temp->engine_size << std::endl;
			std::cout << "���������� ��������� ���:" << temp->horsepower << std::endl;
		}
		else if ((*iter)->type_transport == "������") {
			Plane* temp = (Plane*)(*iter);
			std::cout << "������ �����:" << temp->wingspan << std::endl;
			std::cout << "����������������:" << temp->load_capacity << std::endl;
		}
		else if ((*iter)->type_transport == "�����") {
			Boat* temp = (Boat*)(*iter);
			std::cout << "������� ���������� �����:" << temp->screw_inmmersion_depth << std::endl;
		}
		else if ((*iter)->type_transport == "����������� �������") {
			Spaceship* temp = (Spaceship*)(*iter);
			std::cout << "��� �������:" << temp->fuel_type<< std::endl;
		}
		std::cout << std::endl;
	}
}
void print_data_base_infile(std::vector<Transport*> table) {
	std::fstream inOut;
	inOut.open("file.txt", std::ios::out);
	inOut << "					������� �������" << std::endl;
	int i = 1;
	for (auto iter = table.begin(); iter != table.end(); iter++, i++) {
		inOut << "����� ������:" << i << std::endl;
		inOut << "���������� ������������� ����������:" << (*iter)->unique_identificator << std::endl;
		inOut << "��� ����������:" << (*iter)->type_transport << std::endl;
		inOut << "��� ����������:" << (*iter)->weight << std::endl;
		inOut << "��� ������� ����������:" << (*iter)->year_manufacture << std::endl;
		inOut << "����� ����������:" << (*iter)->brand << std::endl;
		inOut << "������ ����������:" << (*iter)->model << std::endl;
		if ((*iter)->type_transport == "������") {
			Car* temp = (Car*)(*iter);
			inOut << "����� ���������:" << temp->engine_size << std::endl;
			inOut << "���������� ��������� ���:" << temp->horsepower << std::endl;
		}
		else if ((*iter)->type_transport == "������") {
			Plane* temp = (Plane*)(*iter);
			inOut << "������ �����:" << temp->wingspan << std::endl;
			inOut << "����������������:" << temp->load_capacity << std::endl;
		}
		else if ((*iter)->type_transport == "�����") {
			Boat* temp = (Boat*)(*iter);
			inOut << "������� ���������� �����:" << temp->screw_inmmersion_depth << std::endl;
		}
		else if ((*iter)->type_transport == "����������� �������") {
			Spaceship* temp = (Spaceship*)(*iter);
			inOut << "��� �������:" << temp->fuel_type << std::endl;
		}
		inOut << std::endl;
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
void print_transport(Transport* a) {
	std::cout << "���������� ������������� ����������:" << (*a).unique_identificator << std::endl;
	std::cout << "��� ����������:" << (*a).type_transport << std::endl;
	std::cout << "��� ����������:" << (*a).weight << std::endl;
	std::cout << "��� ������� ����������:" << (*a).year_manufacture << std::endl;
	std::cout << "����� ����������:" << (*a).brand << std::endl;
	std::cout << "������ ����������:" << (*a).model << std::endl << std::endl;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
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
				std::cout << "������� ��������������� ����������:";
				std::cin >> (*a).load_capacity;
				std::cout << "������� ������ ����� ����������:";
				std::cin >> (*a).wingspan;
				data_base.push_back(a);
				break;
			}
			case 3:
			{
				Boat* a = new Boat();
				(*a).type_transport = "�����";
				fill_blank(a);
				std::cout << "������� ������� ���������� ����� ����������:";
				std::cin >> (*a).screw_inmmersion_depth;
				data_base.push_back(a);
				break;
			}
			case 4: 
			{
				Spaceship* a = new Spaceship();
				(*a).type_transport = "����������� �������";
				fill_blank(a);
				std::cout << "������� ��� ������� ����������:";
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
			std::vector<Transport*>::iterator it;
			for (auto iter = data_base.begin(); iter != data_base.end(); iter++) {
				if ((*iter)->unique_identificator == unique_id) it = iter;
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
				std::cin >> (*it)->unique_identificator;
				break;
			case 2:
				std::cout << "������� ����� ��� ����������:";
				std::cin >> (*it)->weight;
				break;
			case 3:
				std::cout << "������� ����� ��� �������:";
				std::cin >> (*it)->year_manufacture;
				break;
			case 4:
				std::cout << "������� ����� ����� ����������:";
				std::cin >> (*it)->brand;
				break;
			case 5:
				std::cout << "������� ����� ������ ����������:";
				std::cin >> (*it)->model;
				break;
			case 6:
			{
				if ((*it)->type_transport == "������") {
					Car* temp = (Car*)(*it);
					int res;
					std::cout << "������� 1 - ���� ������ �������� ����� ���������, 0 - ���� ������ �������� ���������� ��������� ���." << std::endl;
					std::cin >> res;
					if (res) {
						std::cout << "������� ����� ����� ��������� ����������:";
						std::cin>>temp->engine_size;
					}
					else {
						std::cout << "������� ����� ���������� ��������� ��� ����������:";
						std::cin>>temp->horsepower;
					}
				}
				else if ((*it)->type_transport == "������") {
					Plane* temp = (Plane*)(*it);
					int res;
					std::cout << "������� 1 - ���� ������ �������� ������ �����, 0 - ���� ������ �������� ����������������." << std::endl;
					std::cin >> res;
					if (res) {
						std::cout << "������� ����� ������ ����� ����������:";
						std::cin>>temp->wingspan;
					}
					else {
						std::cout << "������� ����� ���������������� ����������:";
						std::cin>>temp->load_capacity;
					}
				}
				else if ((*it)->type_transport == "�����") {
					Boat* temp = (Boat*)(*it);
					std::cout << "������� ����� ������� ���������� �����:";
					std::cin>>temp->screw_inmmersion_depth;
				}
				else if ((*it)->type_transport == "����������� �������") {
					Spaceship* temp = (Spaceship*)(*it);
					std::cout << "������� ����� ��� �������:";
					std::cin>>temp->fuel_type;
				}
			}
			}
			break;
		}
			
		case 3:
		{
			print_data_base(data_base);
			int unique_id;
			std::cout << "������� ���������� ������������� ����������, ������� �������� ������ ������� �� �������:";
			std::cin >> unique_id;
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
				<< "������� 5, ���� ������ ������� ���������� �� ������ ����������." << std::endl
				<< "������� 6, ���� ������ ������� ���������� �� ���� ����������." << std::endl;
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
				sort(data_base.begin(), data_base.end(), comp_type);
				break;
			}
			print_data_base(data_base);
			break;
		}
		case 5:
			std::cout << "������� 1, ���� ������ ������� ����� �� ����������� ��������������." << std::endl
				<< "������� 2, ���� ������ ������� ����� �� ���� ����������." << std::endl
				<< "������� 3, ���� ������ ������� ����� �� ���� �������." << std::endl
				<< "������� 4, ���� ������ ������� ����� �� ����� ����������." << std::endl
				<< "������� 5, ���� ������ ������� ����� �� ������ ����������." << std::endl
				<< "������� 6, ���� ������ ������� ����� �� ���� ����������." << std::endl;
			int choice_change;
			std::cin >> choice_change;
			switch (choice_change) {
			case 1:
			{
				int search_unique_id;
				int temp = 1;
				std::cout << "������� ���������� ������������� (��������) ����������:";
				std::cin >> search_unique_id;
				for (auto iter = data_base.begin(); iter != data_base.end(); iter++, temp++) {
					if ((*iter)->unique_identificator == search_unique_id) {
						std::cout << "����� ������:" << temp << std::endl;
						print_transport(*iter);
					}
				}
				break;
			}
			case 2:
			{
				int temp = 1;
				int search_weight;
				std::cout << "������� ��� ����������:";
				std::cin >> search_weight;
				for (auto iter = data_base.begin(); iter != data_base.end(); iter++, temp++) {
					if ((*iter)->weight == search_weight) {
						std::cout << "����� ������:" << temp << std::endl;
						print_transport(*iter);
					}
				}
				break;
			}
			case 3:
			{
				int search_year;
				int temp = 1;
				std::cout << "������� ��� ������� ����������:";
				std::cin >> search_year;
				for (auto iter = data_base.begin(); iter != data_base.end(); iter++, temp++) {
					if ((*iter)->year_manufacture == search_year) {
						std::cout << "����� ������:" << temp << std::endl;
						print_transport(*iter);
					}
				}
				break;
			}
			case 4: 
			{
				int temp = 1;
				std::string search_brand;
				std::cout << "������� ����� ����������:";
				std::cin >> search_brand;
				for (auto iter = data_base.begin(); iter != data_base.end(); iter++, temp++) {
					if ((*iter)->brand == search_brand) {
						std::cout << "����� ������:" << temp << std::endl;
						print_transport(*iter);
					}
				}
				break;
			}	
			case 5: 
			{
				int temp = 1;
				std::string search_model;
				std::cout << "������� ������ ����������:";
				std::cin >> search_model;
				for (auto iter = data_base.begin(); iter != data_base.end(); iter++, temp++) {
					if ((*iter)->model == search_model) {
						std::cout << "����� ������:" << temp << std::endl;
						print_transport(*iter);
					}
				}
				break;
			}
			case 6: 
			{
				int temp = 1;
				std::string search_type_transport;
				std::cout << "������� ��� ����������:";
				std::cin >> search_type_transport;
				for (auto iter = data_base.begin(); iter != data_base.end(); iter++, temp++) {
					if ((*iter)->type_transport == search_type_transport) {
						std::cout << "����� ������:" << temp << std::endl;
						print_transport(*iter);
					}
				}
				break;
			}
			}
			break;
		case 6:
		{
			print_data_base_infile(data_base);
			break;
		}
		case 7:
			break;
		}
		std::cout << "������� 1 - ���� ������ ��������� �����-�� ���������� �������� � ��������, 0 - ���� ������ ��������� ���������."<<std::endl;
		std::cin >> k;
	}
}

