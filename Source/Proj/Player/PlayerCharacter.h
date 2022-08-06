// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class UCameraComponent;

UCLASS()
class PROJ_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	// Sets default values for this character's properties
	APlayerCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	// Moves either to the left or right, depending on the axis
	void MoveRight(float Axis);
	
	// Moves either to the forward or backward, depending on the axis
	void MoveForward(float Axis);

	// Rotates camera along the Yaw axis depending on the passed axis
	void RotateCameraUpDown(float Axis);
	
	// Rotates camera along the Pitch axis depending on the passed axis
	void RotateCameraAroundCharacter(float Axis);

protected: // Movement variables
	
	UPROPERTY(EditDefaultsOnly, Category="Movement")
	float MovementSpeed = 100;

protected: // Camera variables

	UPROPERTY(EditDefaultsOnly, Category="Camera")
	FVector2D PitchLimits = FVector2D(-40, 40);
	
	UPROPERTY(EditDefaultsOnly, Category="Camera")
	FVector2D CameraSensitivity = FVector2D(100,50);
	
protected: // Components

	UPROPERTY(EditDefaultsOnly)
	UCameraComponent* Camera;
};
