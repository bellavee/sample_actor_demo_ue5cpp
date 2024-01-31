// Fill out your copyright notice in the Description page of Project Settings.


#include "Target.h"

#include "Bullet.h"
#include "SampleGameMode.h"

// Sets default values
ATarget::ATarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("Static Mesh");
	SetRootComponent(StaticMesh);

	MovementRange = 200.0f;
}

// Called when the game starts or when spawned
void ATarget::BeginPlay()
{
	Super::BeginPlay();
	OnActorHit.AddDynamic(this, &ATarget::OnHit);

	MoveDirection = FMath::VRand();
}

void ATarget::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("Target hit"));
	if (ABullet* bullet = Cast<ABullet>(OtherActor))
	{
		UE_LOG(LogTemp, Warning, TEXT("Bullet detected"));
		if (ASampleGameMode* mode = Cast<ASampleGameMode>(GetWorld()->GetAuthGameMode()))
		{
			UE_LOG(LogTemp, Warning, TEXT("SampleGameMode detected"));
			mode->IncreasePoints();
			Destroy();
		}
	}
}

// Called every frame
void ATarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector movement = MoveDirection * MovementRange * FMath::Sin(GetWorld()->GetTimeSeconds()) * DeltaTime;

	AddActorWorldOffset(movement, true);
}

