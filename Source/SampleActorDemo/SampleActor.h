// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SampleActor.generated.h"

UCLASS()
class SAMPLEACTORDEMO_API ASampleActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASampleActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, Category="Components")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Test")
	int CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
	int MaxHealth;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
