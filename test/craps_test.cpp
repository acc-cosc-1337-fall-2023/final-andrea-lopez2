#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"

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

TEST_CASE("Assert Die Rolls Return - Question 2")
{
	Die dice;
	Die dice2;
	Roll roll(dice, dice2);
	for (int i = 1; i <= 10; i++)
	{
		roll.roll_die();
		REQUIRE(roll.roll_value() >= 2);
		REQUIRE(roll.roll_value() <= 12);
	}
}

TEST_CASE("Assert Die Rolls Return - Question 3")
{
	Die dice3;
	Die dice4;
	//Roll roll(dice3, dice4);
	Shooter shooter;

	for (int i = 0; i < 10; ++i)
	{
		
		Roll *shooterRoll = shooter.throw_die(dice3, dice4);

		REQUIRE(shooterRoll->roll_value() >= 2);
		REQUIRE(shooterRoll->roll_value() <= 12);
	}
}
