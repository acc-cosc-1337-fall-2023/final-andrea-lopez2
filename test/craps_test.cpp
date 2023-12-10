#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify assertion retuns values from 1 to 6-- Question 1")
{
	Die dice;

	for (int i = 1; i <= 10; i++)
	{
		dice.roll();
		REQUIRE (dice.rolled_value() >= 1);
		REQUIRE (dice.rolled_value() <= 6);

	}
	
	
}


