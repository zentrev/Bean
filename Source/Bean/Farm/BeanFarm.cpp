// Fill out your copyright notice in the Description page of Project Settings.


#include "BeanFarm.h"

// Sets default values
ABeanFarm::ABeanFarm()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ABeanFarm::AddPot()
{
	PotSpawnLocation += PotSpawnOffset;
//	ABeanPot* SpawnedActor1 = (ABeanPot*)GetWorld()->SpawnActor(ABeanPot::StaticClass(), &PotSpawnLocation, NULL);

}

// Called when the game starts or when spawned
void ABeanFarm::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABeanFarm::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

