// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "Player_VS_AI.h"

//////////////////////////////////////////////////////////Creation and Destruction
APlayer_VS_AI::APlayer_VS_AI()
{
	int_Score = 0;
	int_CreepsLeft = 0;
	int_TowsLeft = 0;
	int_RoundsTot = 0;
	int_CurrRound = 1;
	int_Materials = 1000;
	int_Prog = 0;
}
APlayer_VS_AI::~APlayer_VS_AI()
{

}


///////////////////////////////////////////////////////Update Every frame
void APlayer_VS_AI::onTick()
{
	/*
	We might need two sets of controller data, silly notion as we definitely do but we will need
	a defense side and a attack side, the player and AI obviously need both and we need to be able to switch them
	and load the various towers and creeps associated, meaning that players and AI will need to be able to store some
	manner of tower and creep data, then this would handle who is what.
	*/

	if (int_CurrRound <= int_RoundsTot)
	{
		//Setup Phase
		//Timer associated, 
		//purchases of units and 
		//dealing of resources
		if (int_Prog == 0)
		{
			setup();
			if (CountdownTime <1)
				AdvanceTimer();

		}

		//Action phase First player
		else if (int_Prog == 1)
		{
			//Will need to track creeps left alive, 
			//fetch from attacker data

			if (int_CreepsLeft == 0)
			{
				int_Prog = 2;
				//reload with switched sides
			}
			//Action phase Second Player/AI
			//repeat fetch data of attacker
			else if (int_Prog == 2)
			{
				if (int_CreepsLeft == 0)
				{
					int_CurrRound++;
					endRnd();
					//Bring up final results and advance to next round if needed
				}
			}
		}
		if (int_CurrRound > int_RoundsTot)
			EndMatch();
		//update HUD displays
		//UpdateDisplay();

	}
}

///////////////////////////////////////////////////Set up phase intitiation
//establish setup time and resources alloted
void APlayer_VS_AI::setup()
{
	set_Materials(1000);
	CountdownTime = 10;
	//set_Mana(x);
}

/////////////////////////////////////////////////////End Round 
void APlayer_VS_AI::endRnd()
{
	if (int_CurrRound > int_RoundsTot)
		EndMatch();
	else
	{
		int_Prog = 0;
		setup();
	}
}

void APlayer_VS_AI::endGame()
{
	//In total Honesty not sure what type of code should go here.
}

////////////////////////////////Display update if I even need to which I don't think I do
/*
void GameMode::UpdateDisplay()
{
//will need the functions for displaying
}
*/

///////////////////////////////////////////////////////////Timer
void APlayer_VS_AI::AdvanceTimer()
{
	--CountdownTime;
	if (CountdownTime < 1)
	{
		GetWorldTimerManager().ClearTimer(CDTHandle);
		CountdownDone();
	}
}

void APlayer_VS_AI::CountdownDone()
{
	int_Prog = 1;
}



///////////////////////////////////////////////////////fetch functions
int APlayer_VS_AI::get_Score()
{
	return int_Score;
}
int APlayer_VS_AI::get_CreepsLeft()
{
	return int_CreepsLeft;
}
int APlayer_VS_AI::get_TowsLeft()
{
	return int_TowsLeft;
}
int APlayer_VS_AI::get_RoundsTot()
{
	return int_RoundsTot;
}
int APlayer_VS_AI::get_CurrRound()
{
	return int_CurrRound;
}
int APlayer_VS_AI::get_Materials()
{
	return int_Materials;
}

int APlayer_VS_AI::get_Prog()
{
	return int_Prog;
}

//////////////////////////////////////////////////Set value functions
void APlayer_VS_AI::set_Score(int value)
{
	int_Score = value;
}
void APlayer_VS_AI::set_CreepsLeft(int value)
{
	int_CreepsLeft = value;
}
void APlayer_VS_AI::set_TowsLeft(int value)
{
	int_TowsLeft = value;
}
void APlayer_VS_AI::set_RoundsTot(int value)
{
	int_RoundsTot = value;
}
void APlayer_VS_AI::set_CurrRound(int value)
{
	int_CurrRound = value;
}
void APlayer_VS_AI::set_Materials(int value)
{
	int_Materials = value;
}

void APlayer_VS_AI::set_Prog(int value)
{
	int_Prog = value;
}


