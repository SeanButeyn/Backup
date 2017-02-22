// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "Creep.h"
#include "Tower.h"


// Sets default values
ACreep::ACreep()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Direction
	Direction = FVector(1.0f, 0.0f, 0.0f);
	
}

// Called when the game starts or when spawned
void ACreep::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void ACreep::NotTick()
{
	if (int_health <= 0)
		kill();
	//Direction and Movement
	Location = GetActorLocation();
	Location.X += int_speed*Direction.X;
	Location.Y += int_speed*Direction.Y;

	SetActorLocation(Location);
}

void ACreep::Tick( float DeltaTime )
{
	if (int_health <= 0)
		kill();
	Super::Tick( DeltaTime );
	//Direction and Movement
	Location = GetActorLocation();
	Location.X += int_speed*Direction.X;
	Location.Y += int_speed*Direction.Y;
	
	SetActorLocation(Location);

}


void ACreep::attack(ATower* tower)
{
	tower->GetActorLocation();
}

void ACreep::timer()
{

}
void ACreep::kill()
{
	b_Alive = false;
}

//////////////////////////Get
int ACreep::getSpeed()
{
	return int_speed;
}
FVector ACreep::getLocation()
{
	return Location;
}
bool ACreep::getAlive()
{
	return b_Alive;
}
FVector ACreep::getDirection()
{
	return Direction;
}

////////////////////////Set
void ACreep::setHealth(int a)
{
	int_health -= a;
}

void ACreep::setDirection(FVector a)
{
	Direction = a;
}

void ACreep::setSpeed(int a)
{
	int_speed = a;
}