// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "Basic_Tower.h"


ABasic_Tower::ABasic_Tower()
{
	set_health(100);
	set_attack(20);
	set_speed(30);
	set_armor(40);
	set_level(1);
	set_levCost(1000);
	set_range(50);

	set_CanAttack(true);

	set_Location(GetActorLocation());
}

