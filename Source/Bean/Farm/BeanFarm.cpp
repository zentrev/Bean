// Fill out your copyright notice in the Description page of Project Settings.


#include "BeanFarm.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ABeanFarm::ABeanFarm()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);
	VisualMesh->BodyInstance.SetResponseToAllChannels(ECR_Overlap);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> VisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid"));
	if (VisualAsset.Succeeded()) {
		VisualMesh->SetStaticMesh(VisualAsset.Object);
	}
}

void ABeanFarm::HarvestBeans()
{
	//Create beans and toss them in the air
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

