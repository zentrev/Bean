// Fill out your copyright notice in the Description page of Project Settings.


#include "BeanPod.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include <Bean\BeanCharacter.h>

// Sets default values
ABeanPod::ABeanPod()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);
	VisualMesh->BodyInstance.SetResponseToAllChannels(ECR_Overlap);
	VisualMesh->OnComponentBeginOverlap.AddDynamic(this, &ABeanPod::OnOverlapBegin);
}

// Called when the game starts or when spawned
void ABeanPod::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABeanPod::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this && OtherComp) {
		if (OtherActor && OtherActor != this && OtherComp) {
			ABeanCharacter* Character = Cast<ABeanCharacter>(OtherActor);
			if (Character) {
				//Character->PickUp(5.0f);
				Destroy();
			}
		}
	}
}

// Called every frame
void ABeanPod::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

