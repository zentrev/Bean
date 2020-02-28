// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BeanPot.generated.h"

UCLASS()
class BEAN_API ABeanPot : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABeanPot();

public:
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* PotMesh;
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* PlantMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BeanPot")
		float WateredGrowRate = 5.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BeanPot")
		float DryGrowRate = 15.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BeanPot")
		float WaterTimerReset = 5.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BeanPot")
		int BeanPods = 0;
	UFUNCTION()
		void WaterBeanPot();
	UFUNCTION()
		void HarvestBeans();
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	bool NeedsWatering = false;
	float CurrentWaterTimer = 5.0f;
	float CurrentGrowRate = 5.0f;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
