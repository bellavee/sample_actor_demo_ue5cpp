// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bullet.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "SamplePawn.generated.h"

UCLASS()
class SAMPLEACTORDEMO_API ASamplePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASamplePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly);
	UFloatingPawnMovement* Movement;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly);
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere)
	TAssetSubclassOf<ABullet> BulletClass;

	UPROPERTY(EditAnywhere)
	float BulletSpawnOffset;
	
	// Input bindings
	void MoveForward(float scale);
	void MoveRight(float scale);
	void Turn(float scale);
	void LookUp(float scale);
	void Shoot();
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
