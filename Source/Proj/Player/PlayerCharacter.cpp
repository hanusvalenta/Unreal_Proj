// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/PawnMovementComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(GetCapsuleComponent());
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// NOTE: Not update, better performance
	PlayerInputComponent->BindKey(EKeys::SpaceBar, EInputEvent::IE_Pressed, this, &APlayerCharacter::Jump);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	
	PlayerInputComponent->BindAxis("MouseRight", this, &APlayerCharacter::RotateCameraAroundCharacter);
	PlayerInputComponent->BindAxis("MouseUp", this, &APlayerCharacter::RotateCameraUpDown);
}

void APlayerCharacter::MoveRight(float Axis)
{
	GetMovementComponent()->AddInputVector(Camera->GetComponentRotation().RotateVector(FVector::RightVector * Axis * GetWorld()->GetDeltaSeconds() * MovementSpeed));
}

void APlayerCharacter::MoveForward(float Axis)
{
	GetMovementComponent()->AddInputVector(Camera->GetComponentRotation().RotateVector(FVector::ForwardVector * Axis * GetWorld()->GetDeltaSeconds() * MovementSpeed));
}

void APlayerCharacter::RotateCameraUpDown(float Axis)
{
	FRotator rot = Camera->GetComponentRotation() + FRotator(Axis * GetWorld()->GetDeltaSeconds() * CameraSensitivity.Y, 0, 0);
	rot.Pitch = FMath::Clamp(rot.Pitch, PitchLimits.X, PitchLimits.Y);
	
	Camera->SetWorldRotation(rot);
}

void APlayerCharacter::RotateCameraAroundCharacter(float Axis)
{
	Camera->SetWorldRotation(Camera->GetComponentRotation() + FRotator(0, Axis * GetWorld()->GetDeltaSeconds() * CameraSensitivity.X, 0));
}

