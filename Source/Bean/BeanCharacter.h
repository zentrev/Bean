// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Beanstalk.h"
#include "BeanCharacter.generated.h"

UCLASS(config=Game)
class ABeanCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Side view camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Reference to the Beanstalk */
	UPROPERTY(EditDefaultsOnly, Category = "Beans")
		TSubclassOf<ABeanstalk> BeanstalkClass;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Beans")
		int SmallBean = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Beans")
		int MediumBean = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Beans")
		int BigBean = 0;

	UFUNCTION(BlueprintCallable, Category = "Beans")
		void AddBean(int Size);

	UFUNCTION(BlueprintCallable, Category = "Beans")
		bool RemoveBean(int Size);
	
	UFUNCTION()
	void PlaceBean();

protected:

	/** Called for side to side input */
	void MoveRight(float Val);

	/** Handle touch inputs. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */
	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface


public:
	ABeanCharacter();

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
};
