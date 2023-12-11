#include <iostream>
#include <string>
#include <memory>
#include <ctime>

#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "phase.h"
#include "come_out_phase.h"
#include "point_phase.h"

using std::cout;
using std::endl;

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	// make srand(time(0));
	Die die1;
	Die die2;
	Shooter shooter;

	// //////////////////////////////////////////////////////////////////////////////////////////
	// Question 5 for come_out_phase
	std::cout << "<<<<<<<<<<<<<<<<<<< Question 5 for come_out_phase " << std::endl;
	ComeOutPhase come_out_phase;
	Roll *roll = shooter.throw_die(die1, die2);
	// Create an int point variable set to roll rolled_value
	int point = roll->roll_value();
	// RollOutcome comeOutOutcome = come_out_phase.get_outcome(roll);

	// Display the rolled value with the text "Start of point phase"
	std::cout << "Rolled Value: " << roll->roll_value() << " Start of point phase." << std::endl;
	std::cout << "Roll until " << point << " or 7 is rolled" << std::endl;

	while ((come_out_phase.get_outcome(roll) == RollOutcome::natural || come_out_phase.get_outcome(roll) == RollOutcome::craps))
	{

		// Display the rolled value

		// std::cout << "Roll again" << std::endl;
		std::cout << "Rolled Value: " << roll->roll_value() << " Roll again" << std::endl;

		// Set roll equal to the return value of the shooter throw_die function
		// delete roll; // Clean up the previous roll
		roll = shooter.throw_die(die1, die2);
	}

	// Continue rolling until the rolled value is equal to the initial point or 7
	while (roll->roll_value() != point && roll->roll_value() != 7)
	{
		// Display the rolled value
		std::cout << "Rolled Value: " << roll->roll_value() << std::endl;
		// std::cout << "Roll until " << point << " or 7 is rolled" << std::endl;

		// Set roll equal to the return value of the shooter throw_die function
		// delete roll; // Clean up the previous roll
		roll = shooter.throw_die(die1, die2);
	}

	std::cout << "Rolled Value: " << roll->roll_value() << " End of point phase." << std::endl;

	std::cout << shooter << std::endl;
	// Clean up the last roll outside the loop
	//delete roll;

	// //////////////////////////////////////////////////////////////////////////////////////////
	// Question 5 for point_phase
	std::cout << "\n";
	std::cout << "<<<<<<<<<<<<<<<<<<< Question 5 for point_phase " << std::endl;
	PointPhase point_phase(5); // Assuming point is set to 5
	Roll *roll2 = shooter.throw_die(die1, die2);

	// Display the rolled value with the text "Start of point phase"
	std::cout << "Rolled Value: " << roll2->roll_value() << " Start of point phase." << std::endl;

	while ((point_phase.get_outcome(roll2) == RollOutcome::point || point_phase.get_outcome(roll2) == RollOutcome::nopoint))
	{

		// std::cout << "Roll again" << std::endl;
		std::cout << "Rolled Value: " << roll2->roll_value() << " Roll again" << std::endl;

		// Set roll equal to the return value of the shooter throw_die function
		// delete roll; // Clean up the previous roll
		roll2 = shooter.throw_die(die1, die2);
	}

	std::cout << "Rolled Value: " << roll2->roll_value() << " End of point phase." << std::endl;

	std::cout << shooter << std::endl;
	// Clean up the last roll outside the loop
	//delete roll2;

	return 0;
}
