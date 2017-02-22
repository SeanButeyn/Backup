// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Creep.generated.h"
class ATower;

UCLASS()
class ALPHA_API ACreep : public AActor
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere)
	int int_health;
	UPROPERTY(EditAnywhere)
	int int_attack;
	UPROPERTY(EditAnywhere)
	int int_speed;
	UPROPERTY(EditAnywhere)
	int int_armor;
	UPROPERTY(EditAnywhere)
	int int_level;
	UPROPERTY(EditAnywhere)
	int int_levCost;
	UPROPERTY(EditAnywhere)
	int int_range;

	UPROPERTY(EditAnywhere)
	bool b_Alive;

	UPROPERTY(EditAnywhere)
	FVector Location;
	UPROPERTY(EditAnywhere)
	FVector Direction;

public:	
	// Sets default values for this actor's properties
	ACreep();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
		void NotTick();
	virtual void Tick( float DeltaSeconds ) override;

	//Interactive functions
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	void attack(ATower* tower);
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	void timer();
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	void kill();

	//Get
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	int getSpeed();
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	FVector getLocation();
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	bool getAlive();
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	FVector getDirection();

	//Set
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	void setHealth(int a);
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	void setDirection(FVector a);
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	void setSpeed(int a);
};
