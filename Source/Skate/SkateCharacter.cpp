// Fill out your copyright notice in the Description page of Project Settings.

#include "Skate.h"
#include "SkateCharacter.h"


// Sets default values
ASkateCharacter::ASkateCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASkateCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASkateCharacter::Tick( float DeltaTime )
{
	FlushPersistentDebugLines(GetWorld());
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ASkateCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}


void ASkateCharacter::CapsuleTraceDown(float width, float height, AActor *ignore,  bool & Hit, FVector & ImpactNormal, FVector & ImpactPoint)
{
	ECollisionChannel CollisionChannel = ECC_WorldStatic;
	const FName TraceTag("SkateTrace");
	GetWorld()->DebugDrawTraceTag = TraceTag;

	FCollisionQueryParams TraceParams(FName(TEXT("Capsule Trace Down")), true, this);
	TraceParams.bTraceComplex = true;
	TraceParams.AddIgnoredActor(this);
	TraceParams.bTraceAsyncScene = true;
	TraceParams.bReturnPhysicalMaterial = false;

	TraceParams.AddIgnoredActor(ignore);
	//TraceParams.TraceTag = TraceTag;

	FHitResult HitOut;


	FVector Up = GetActorUpVector() * -1.0f;

	FVector Start = GetActorLocation();
	FVector End = Start + Up;

	FRotator Orientation = GetActorUpVector().Rotation() + FRotator(-90, 0, 0);



	GetWorld()->SweepSingleByChannel(

		HitOut,
		Start,
		End,
		Orientation.Quaternion(),
		CollisionChannel,
		FCollisionShape::MakeCapsule(FVector(width, width, height)),
		TraceParams


		);
	if (HitOut.bBlockingHit) {


		Hit = true;
		ImpactNormal = HitOut.ImpactNormal;
		ImpactPoint = HitOut.ImpactPoint;
	}

	
}
void ASkateCharacter::BoxTraceDown(float width, float height, AActor *ignore, bool & Hit, FVector & ImpactNormal, FVector & ImpactPoint)
{


const FName TraceTag("SkateTrace");
GetWorld()->DebugDrawTraceTag = TraceTag;

FCollisionQueryParams TraceParams(FName(TEXT("Capsule Trace Down")), true, this);
TraceParams.bTraceComplex = true;
TraceParams.AddIgnoredActor(this);
TraceParams.bTraceAsyncScene = true;
TraceParams.bReturnPhysicalMaterial = false;
TraceParams.TraceTag = TraceTag;
TraceParams.AddIgnoredActor(ignore);
FHitResult HitOut;


FVector Up = GetActorUpVector() * -1.0f;

FVector Start = GetActorLocation();
FVector End = Start + Up;

FRotator Orientation = GetActorUpVector().Rotation() + FRotator(-90, 0, 0);



GetWorld()->SweepSingleByChannel(

	HitOut,
	Start,
	End,
	Orientation.Quaternion(),
	ECC_WorldStatic,
	FCollisionShape::MakeBox(FVector(width, width, height)),
	TraceParams


	);
if (HitOut.bBlockingHit) {


	Hit = true;
	ImpactNormal = HitOut.ImpactNormal;
	ImpactPoint = HitOut.ImpactPoint;
}


}
void ASkateCharacter::SphereTraceDown(float radius, AActor *ignore, bool & Hit, FVector & ImpactNormal, FVector & ImpactPoint)
{

	ECollisionChannel CollisionChannel = ECC_WorldStatic;
	const FName TraceTag("SkateTrace");
	GetWorld()->DebugDrawTraceTag = TraceTag;

	FCollisionQueryParams TraceParams(FName(TEXT("Sphere Trace Down")), true, this);
	TraceParams.bTraceComplex = true;
	TraceParams.AddIgnoredActor(this);
	TraceParams.bTraceAsyncScene = true;
	TraceParams.bReturnPhysicalMaterial = false;
	//TraceParams.TraceTag = TraceTag;
	TraceParams.AddIgnoredActor(ignore);
	FHitResult HitOut;

	FVector Up = GetActorUpVector() * -1.0f;

	FVector Start = GetActorLocation();
	FVector End = Start + Up;

	FRotator Orientation = GetActorUpVector().Rotation() + FRotator(-90, 0, 0);



	GetWorld()->SweepSingleByChannel(

		HitOut,
		Start,
		End,
		Orientation.Quaternion(),
		CollisionChannel,
		FCollisionShape::MakeSphere(radius),
		TraceParams


		);
	if (HitOut.bBlockingHit) {


		Hit = true;
		ImpactNormal = HitOut.ImpactNormal;
		ImpactPoint = HitOut.ImpactPoint;
	}

}

void ASkateCharacter::LineTraceDown(float length, float offset, AActor *ignore, bool & Hit, FVector & ImpactNormal, FVector & ImpactPoint)

{
	const FName TraceTag("SkateTrace");
	GetWorld()->DebugDrawTraceTag = TraceTag;
	FCollisionQueryParams RV_TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true, this);
	RV_TraceParams.bTraceComplex = true;
	RV_TraceParams.bTraceAsyncScene = true;
	RV_TraceParams.bReturnPhysicalMaterial = false;
	RV_TraceParams.TraceTag = TraceTag;
	RV_TraceParams.AddIgnoredActor(ignore);
	FHitResult RV_Hit(ForceInit);

	FVector Up = GetActorUpVector() * length;
	FVector Offset = GetActorForwardVector() * offset;
	


	FVector Start = GetActorLocation() + Offset;
	FVector End = Start + Up;

	
	GetWorld()->LineTraceSingleByChannel(
		RV_Hit,        
		Start,   
		End, 
		ECC_WorldStatic,
		RV_TraceParams
		);

	if (RV_Hit.bBlockingHit) {

		Hit = true;
		ImpactNormal = RV_Hit.ImpactNormal;
		ImpactPoint = RV_Hit.ImpactPoint;

	}

}
