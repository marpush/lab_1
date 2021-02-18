#include <iostream>
#include <cmath>  
using namespace std;
//ускорение свободного падени€
#define acceleration_of_gravity 9,806
//расчет полного времени полЄта камн€
double calculating_the_flight_of_a_stone(const double cliff_height, const double stone_speed, const double angle_of_incidence);
//проверка правильного ввода времени в границах и на то, введено ли число 
double scan_time_in_range(const double left_border, const double right_border);
//вывод, если камень упал на дно обрыва 
void outpute_if_the_stone_fell_to_the_bottom_of_the_cliff();
//вывод положени€ камн€
void output_information_about_the_position_of_the_stone(const double height_from_the_bottom_of_the_cliff, const double distance_to_the_edge_of_the_cliff);

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "ƒанна€ программа определ€ет положение камн€: высоту от дна обрыва и "
		 << "раcсто€ние до кра€ обрыва при его бросании с обрыва в конкретный момент времени\n";
	//высота обрыва
	const double cliff_height = 50;
	//начальна€ скорость, с которой брошен камень
	const double stone_speed = 10;
	//угол к горизонту, под которым брошен камень
	const double angle_of_incidence = 30;
	//полное врем€ полЄта камн€
	const double flight_time = calculating_the_flight_of_a_stone(cliff_height, stone_speed, angle_of_incidence);
	const double left_border = 0;
	double entered_time = scan_time_in_range(left_border, flight_time);
	
	//высота от дна обрыва 
	const double height_from_the_bottom_of_the_cliff = stone_speed * entered_time * cos(angle_of_incidence);

	//рассто€ние до кра€ обрыва
	const double distance_to_the_edge_of_the_cliff = cliff_height + 
		         (stone_speed * entered_time * sin(angle_of_incidence)) - ((acceleration_of_gravity * entered_time * entered_time) / 2);
	
	(distance_to_the_edge_of_the_cliff == 0) ? outpute_if_the_stone_fell_to_the_bottom_of_the_cliff() : output_information_about_the_position_of_the_stone(height_from_the_bottom_of_the_cliff, distance_to_the_edge_of_the_cliff);
	
	return 0;
}

double calculating_the_flight_of_a_stone(const double cliff_height, const double stone_speed, const double angle_of_incidence)
{
	const double flight_time = ((stone_speed * sin(angle_of_incidence)) / acceleration_of_gravity)
		* (1 + sqrt(1 + ((2 * acceleration_of_gravity * cliff_height) / (stone_speed * stone_speed * sin(angle_of_incidence) * sin(angle_of_incidence)))));
	return flight_time;
}

double scan_time_in_range(const double left_border, const double right_border)
{
	while (true) {
		cout << "¬ведите врем€ дл€ определени€ положени€ камн€, не большее " << right_border << ": ";
		double time = 0;
		cin >> time;

		if (cin.fail()) {
			cout << "¬ведено не число.\n";
			cin.clear();
			std::cin.ignore(32767, '\n');
		}
		else {
			if ((time >= left_border) && (time <= right_border)) {
				return time;
			}
			else {
				if (time <= left_border) {
					cout << "¬веденное число меньше " << left_border << "\n";
					cin.clear();
				}

				if (time >= right_border) {
					cout << "¬веденное число больше " << right_border << "\n";
					cin.clear();
				}
			}
		}

	}
}

void outpute_if_the_stone_fell_to_the_bottom_of_the_cliff()
{
	cout << " амень упал на дно обрыва\n";
}

void output_information_about_the_position_of_the_stone(const double height_from_the_bottom_of_the_cliff, const double distance_to_the_edge_of_the_cliff)
{
	cout << "¬ысота от дна обрыва: " << height_from_the_bottom_of_the_cliff << " –ассто€ние до кра€ обрыва: " << distance_to_the_edge_of_the_cliff;
}