// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ProjHUD.generated.h"

/**
 * 
 */
UCLASS()
class PROJ_API AProjHUD : public AHUD
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent)
	void OnWeaponSelected(uint8 WeaponIndex);

	virtual void DrawHUD() override;

	void AddDebugString(FString DebugString);

private:

	TArray<FString> DebugTestQueue;
	
};
