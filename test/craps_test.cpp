#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"

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

TEST_CASE("Assert Die Rolls Return - Question 4 - 1/2 (ComeOutPhase)")
{
	Die dice5;
	Die dice6;
	Shooter shooter;

	ComeOutPhase comeOutPhase;

	for (int i = 0; i < 10; ++i)
	{

		Roll *comeOutRoll = shooter.throw_die(dice5, dice6);
		RollOutcome comeOutOutcome = comeOutPhase.get_outcome(comeOutRoll);

		REQUIRE((comeOutOutcome == RollOutcome::point || comeOutOutcome == RollOutcome::natural || comeOutOutcome == RollOutcome::craps));
	}
}

TEST_CASE("Assert Die Rolls Return - Question 4 - 2/2 (PointPhase)")
{
	Die dice5;
	Die dice6;
	Shooter shooter;

	PointPhase pointPhase(5); // Assuming point is set to 5

	for (int i = 0; i < 10; ++i)
	{

		Roll *pointRoll = shooter.throw_die(dice5, dice6);
		RollOutcome pointOutcome = pointPhase.get_outcome(pointRoll);

		REQUIRE((pointOutcome == RollOutcome::point || pointOutcome == RollOutcome::seven_out || pointOutcome == RollOutcome::nopoint));
	}
}