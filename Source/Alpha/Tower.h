// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Tower.generated.h"
class ACreep;

UCLASS()
class ALPHA_API ATower : public AActor
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
	bool b_alive;
	UPROPERTY(EditAnywhere)
	bool b_CanAttack;
	UPROPERTY(EditAnywhere)
	bool b_QueFull;
	UPROPERTY(EditAnywhere)
	bool b_QueEmpt;

	UPROPERTY(EditAnywhere)
	FVector Location;

	struct Queue
	{
		ACreep *target;
		bool exists;
		int id;
	};
	Queue targets[10];
	
	FTimerHandle CountDownTimerHandle;

	UWorld * World;
public:	
	
	// Sets default values for this actor's properties
	ATower();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	void NotTick();
	
	//Interactive functions
	UFUNCTION(BlueprintCallable, Category=JustDoIt)
	FVector fetch_Target();
	UFUNCTION(BlueprintCallable, Category=JustDoIt)
	void attack();
	UFUNCTION(BlueprintCallable, Category=JustDoIt)
	void timer();
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	void add_Queue(ACreep *creep);
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	void rem_Queue(ACreep *creep);
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	void kill();

	//Get/Set
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	void set_health(int a);
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	void set_attack(int a);
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	void set_speed(int a);
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	void set_armor(int a);
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	void set_level(int a);
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	void set_levCost(int a);
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	void set_range(int a);
		
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	void set_CanAttack(bool a);
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	void set_QueFull(bool a);

	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	void set_Location(FVector a);


	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	bool get_QueEmpt();
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	bool get_canAttack();
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	int get_speed();
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	int get_attack();
};
