// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BeanFarm.generated.h"

UCLASS()
class BEAN_API ABeanFarm : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABeanFarm();

public:
	UPROPERTY(VisibleAnywhere) 
		UStaticMeshComponent* VisualMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BeanFarm")
		float GrowRate = 5.0f;
	UFUNCTION()
		void HarvestBeans();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
