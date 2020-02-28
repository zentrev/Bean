// Fill out your copyright notice in the Description page of Project Settings.


#include "BeanPot.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include <Bean\BeanCharacter.h>

// Sets default values
ABeanPot::ABeanPot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PotMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PotMesh"));
	PotMesh->SetupAttachment(RootComponent);
	PotMesh->BodyInstance.SetResponseToAllChannels(ECR_Overlap);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> VisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder"));
	if (VisualAsset.Succeeded()) {
		PotMesh->SetStaticMesh(VisualAsset.Object);
	}

	PlantMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlantMesh"));
	PlantMesh->SetupAttachment(RootComponent);
	PlantMesh->BodyInstance.SetResponseToAllChannels(ECR_Overlap);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> VisualPotMesh(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere")); //start w healthy plant
	if (VisualPotMesh.Succeeded()) {
		PlantMesh->SetStaticMesh(VisualPotMesh.Object);
	}
	PlantMesh->OnComponentBeginOverlap.AddDynamic(this, &ABeanPot::OnOverlapBegin);

}

void ABeanPot::WaterBeanPot()
{
	if (NeedsWatering) {
		CurrentGrowRate = WateredGrowRate;
		CurrentWaterTimer = WaterTimerReset;
		NeedsWatering = false;
		static ConstructorHelpers::FObjectFinder<UStaticMesh> VisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere")); //Set back to healthy plant
		if (VisualAsset.Succeeded()) {
			PlantMesh->SetStaticMesh(VisualAsset.Object);
		}
	}
}

void ABeanPot::HarvestBeans()
{
	for (int i = 0; i < BeanPods; i++) {
		//Instantiate and throw into the air
	}
	BeanPods = 0;
}

void ABeanPot::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this && OtherComp) {
		ABeanCharacter* Character = Cast<ABeanCharacter>(OtherActor);
		if (Character) {
			//Show UI to choose between water or harvest
		}
	}
}

// Called when the game starts or when spawned
void ABeanPot::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABeanPot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentGrowRate -= DeltaTime;

	if (CurrentGrowRate <= 0.0f) {
		BeanPods++;
		CurrentGrowRate = (NeedsWatering) ? DryGrowRate : WateredGrowRate ;
	}

}

