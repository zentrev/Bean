// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Beanstalk.generated.h"

UCLASS()
class BEAN_API ABeanstalk : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABeanstalk();

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* VisualMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Placeable")
		float WaveRate = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Placeable")
		float WaveAmplitude = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Placeable")
		float RotationSpeed = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Placeable")
		float Health = 100.0f;

	UFUNCTION()
		void OnPlace(FVector location);
private:
	FVector StartLocation;
	int StalkType = 0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
