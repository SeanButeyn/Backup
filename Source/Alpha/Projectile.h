// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class ALPHA_API AProjectile : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	FVector Location;
	UPROPERTY(EditAnywhere)
	FVector TarLoc;
	UPROPERTY(EditAnywhere)
	FVector Direction;

	UPROPERTY(EditAnywhere)
	int int_speed;
	UPROPERTY(EditAnywhere)
	int int_Attack;
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	void NotTick();

	virtual void Tick( float DeltaSeconds ) override;

	// Normalize direction
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	void Normal();

	// Gets and Sets
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	void set_Location(FVector a);
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	void set_TarLoc(FVector a);
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	void set_Direction(FVector a);
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	void set_speed(int a);

	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	void setAttack(int a);
	UFUNCTION(BlueprintCallable, Category = JustDoIt)
	int getAttack();

};
