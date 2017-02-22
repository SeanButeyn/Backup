// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "Projectile.h"


// Sets default values
AProjectile::AProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Location = FVector(0.0f, 0.0f, 0.0f);
	TarLoc = FVector(0.0f, 0.0f, 0.0f);
	Direction = FVector(0.0f, 0.0f, 0.0f);
	int_speed = 10;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AProjectile::Tick( float DeltaTime )
{
	
	Super::Tick( DeltaTime );
	Location = GetActorLocation();
	Location.X += int_speed * Direction.X;
	Location.Y += int_speed * Direction.Y;
	Location.Z += int_speed * Direction.Z;
	SetActorLocation(Location);
}

void AProjectile::NotTick()
{
	Normal();
	Location = GetActorLocation();
	Location.X += int_speed * Direction.X;
	Location.Y += int_speed * Direction.Y;
	Location.Z += int_speed * Direction.Z;
	SetActorLocation(Location);
}

// Normalize
void AProjectile::Normal()
{
	double magnitude;
	magnitude = sqrt(((TarLoc.X - Location.X)*(TarLoc.X - Location.X) + (TarLoc.Y - Location.Y)*(TarLoc.Y - Location.Y) + (TarLoc.Z - Location.Z)*(TarLoc.Z - Location.Z)));
	//magnitude = sqrt((TarLoc.X*TarLoc.X + TarLoc.Y*TarLoc.Y + TarLoc.Z*TarLoc.Z));
	Direction.X = (TarLoc.X - Location.X) / magnitude;
	Direction.Y = (TarLoc.Y - Location.Y) / magnitude;
	Direction.Z = (TarLoc.Z - Location.Z) / magnitude;
}

//Gets and Sets
void AProjectile::set_Location(FVector a)
{
	Location = a;
}
void AProjectile::set_TarLoc(FVector a)
{
	TarLoc = a;
}
void AProjectile::set_Direction(FVector a)
{
	Direction = a;
}
void AProjectile::set_speed(int a)
{
	int_speed = a;
}

void AProjectile::setAttack(int a)
{
	int_Attack = a;
}
int AProjectile::getAttack()
{
	return int_Attack;
}