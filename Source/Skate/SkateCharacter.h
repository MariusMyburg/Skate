// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "SkateCharacter.generated.h"

UCLASS()
class SKATE_API ASkateCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASkateCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
	UFUNCTION(BlueprintCallable, Category = "Skate")
	void CapsuleTraceDown(float width, float height, AActor *ignore, bool & Hit, FVector & ImpactNormal, FVector & ImpactPoint);

	UFUNCTION(BlueprintCallable, Category = "Skate")
	void BoxTraceDown(float width, float height, AActor *ignore, bool & Hit, FVector & ImpactNormal, FVector & ImpactPoint);

	UFUNCTION(BlueprintCallable, Category = "Skate")
	void SphereTraceDown(float radius, AActor *ignore, bool & Hit,  FVector & ImpactNormal, FVector & ImpactPoint);

	UFUNCTION(BlueprintCallable, Category = "Skate")
	void LineTraceDown(float length, float offset, AActor *ignore, bool & Hit, FVector & ImpactNormal, FVector & ImpactPoint);

};
