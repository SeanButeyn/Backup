// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "Tower.h"
#include "Creep.h"


// Sets default values
ATower::ATower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	World = GetWorld();
}

// Called when the game starts or when spawned
void ATower::BeginPlay()
{
	Super::BeginPlay();
	
	
}

/////////////////////////////////////////////////////////////// Called every frame
void ATower::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	//Update target queue
	for (int i = 0; i < 10; i++)
	{
		if (targets[i].exists == false)
		{
			for (int j = i; j < 10; j++)
			{
				if (targets[j].exists == true)
				{
					targets[i].target = targets[j].target;
					targets[j].exists = false;
				}
			}
		}
		else if (i == 9 && targets[i].exists == true)
			b_QueFull = true;
	}
	if (!targets[0].exists)
		b_QueEmpt = true;
	else
		b_QueEmpt = false;
}
void ATower::NotTick()
{
	if (int_health <= 0)
		kill();
	//Update target queue
	for (int i = 0; i < 10; i++)
	{
		if (targets[i].exists == false)
		{
			for (int j = i; j < 10; j++)
			{
				if (targets[j].exists == true)
				{
					targets[i].target = targets[j].target;
					targets[j].exists = false;
				}
			}
		}
		else if (i == 9 && targets[i].exists == true)
			b_QueFull = true;
	}
	if (!targets[0].exists)
		b_QueEmpt = true;
	else
		b_QueEmpt = false;
}



////////////////////////////////////Interactive Functions

FVector ATower::fetch_Target()
{
	FVector temLoc = FVector(0.0f,0.0f,0.0f);
	if (targets[0].exists)
	{
		int speed;
		FVector temp;
		temp = targets[0].target->getDirection();
		
		speed = targets[0].target->getSpeed();
		temLoc = targets[0].target->GetActorLocation();
		temLoc.X += temp.X * speed;
		temLoc.Y += temp.Y * speed;
		temLoc.Z += temp.Z * speed;
	}
	return temLoc;
}
void ATower::attack()
{
	b_CanAttack = false;

}
void ATower::timer()
{
	b_CanAttack = true;

}
void ATower::add_Queue(ACreep *creep)
{
	for (int i = 0; i < 10; i++)
	{
		if (!targets[i].exists)
		{
			targets[i].exists = true;
			targets[i].target = creep;
		}
	}
}
void ATower::rem_Queue(ACreep *creep)
{
	for (int i = 0; i < 10; i++)
	{
		if (targets[i].target == creep)
		{
			targets[i].exists = false;
		}
	}
}
void ATower::kill()
{
	b_alive = false;
}

/////////////////////////////////Get/Set Nonsense

void ATower::set_health(int a)
{
	int_health = a;
}
void ATower::set_attack(int a)
{
	int_attack = a;
}
void ATower::set_speed(int a)
{
	int_speed = a;
}
void ATower::set_armor(int a)
{
	int_armor = a;
}
void ATower::set_level(int a)
{
	int_level = a;
}
void ATower::set_levCost(int a)
{
	int_levCost = a;
}
void ATower::set_range(int a)
{
	int_range = a;
}

void ATower::set_CanAttack(bool a)
{
	b_CanAttack = a;
}
void ATower::set_QueFull(bool a)
{
	b_QueFull = a;
}

void ATower::set_Location(FVector a)
{
	Location = a;
}

bool ATower::get_QueEmpt()
{
	return b_QueEmpt;
}

bool ATower::get_canAttack()
{
	return b_CanAttack;
}

int ATower::get_speed()
{
	return int_speed;
}
int ATower::get_attack()
{
	return int_attack;
}