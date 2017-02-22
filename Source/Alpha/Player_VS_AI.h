// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "Player_VS_AI.generated.h"

/**
 * 
 */
UCLASS()
class ALPHA_API APlayer_VS_AI : public AGameMode
{
	GENERATED_BODY()
private:
	//variables
	UPROPERTY(EditAnywhere)
		int int_Score;
	UPROPERTY(EditAnywhere)
		int int_CreepsLeft;
	UPROPERTY(EditAnywhere)
		int int_TowsLeft;
	UPROPERTY(EditAnywhere)
		int int_RoundsTot;
	UPROPERTY(EditAnywhere)
		int int_CurrRound;
	UPROPERTY(EditAnywhere)
		int int_Materials;
	UPROPERTY(EditAnywhere)
		int int_Prog;
	UPROPERTY(EditAnywhere)
		int CountdownTime;

public:
	//Destruction and Creation
	APlayer_VS_AI();
	~APlayer_VS_AI();

	//fetch functions
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
		int get_Score();
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
		int get_CreepsLeft();
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
		int get_TowsLeft();
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
		int get_RoundsTot();
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
		int get_CurrRound();
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
		int get_Materials();

	UFUNCTION(BlueprintCallable, Category = JustDoIt)
		int get_Prog();

	//Set value functions
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
		void set_Score(int value);
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
		void set_CreepsLeft(int value);
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
		void set_TowsLeft(int value);
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
		void set_RoundsTot(int value);
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
		void set_CurrRound(int value);
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
		void set_Materials(int value);

	UFUNCTION(BlueprintCallable, Category = JustDoIt)
		void set_Prog(int value);

	//Update every tick
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
		void onTick();

	//virtual void Tick(float dx) override;

	//Setup phase 
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
		void setup();

	//End Round
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
		void endRnd();

	//End Game
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
		void endGame();

	//timer
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
		void AdvanceTimer();

	UFUNCTION(BlueprintCallable, Category = JustDoIt)
		void CountdownDone();

	FTimerHandle CDTHandle;
};
