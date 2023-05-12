// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSPlayer.h"

#include "P_PlayerInvetory.h"
#include "Camera/CameraComponent.h"
#include "Camera/CameraShakeSourceComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFPSPlayer::AFPSPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;


	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);
	Camera->SetRelativeLocation(FVector3d(0.f, 0.f, GetDefaultHalfHeight()));

	Invetory = CreateDefaultSubobject<UP_PlayerInvetory>(TEXT("Invetory"));
	
	
}

// Called when the game starts or when spawned
void AFPSPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFPSPlayer::AddForward(float axis)
{
	MovementTarget += Camera->GetForwardVector() * axis * MovementSpeed;
}

void AFPSPlayer::AddRight(float axis)
{
	MovementTarget += Camera->GetRightVector() * axis * MovementSpeed;
}

void AFPSPlayer::AddPitch(float axis)
{
	FRotator CameraRotation = Camera->GetRelativeRotation();
	CameraRotation.Pitch += axis * LookSpeed;
	CameraRotation.Pitch = FMath::Clamp(CameraRotation.Pitch, -89.0f, 89.0f);
	Camera->SetRelativeRotation(CameraRotation);
}

void AFPSPlayer::AddYaw(float axis)
{
	FRotator CameraRotation = Camera->GetRelativeRotation();
	CameraRotation.Yaw += axis * LookSpeed;
	Camera->SetRelativeRotation(CameraRotation);
}

void AFPSPlayer::AddJump()
{
	bPressedJump = true;
}

// Called every frame
void AFPSPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovementTarget.Z = 0.0f;
	MovementTarget += FVector3d(0.0f, 0.f, 9.8f * DeltaTime);
	AddMovementInput(MovementTarget);
	MovementTarget = FVector3d(0.0f);
	

}

// Called to bind functionality to input
void AFPSPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Forward", this, &AFPSPlayer::AddForward);
	PlayerInputComponent->BindAxis("Right", this, &AFPSPlayer::AddRight);


	PlayerInputComponent->BindAxis("CameraPitch", this, &AFPSPlayer::AddPitch);
	PlayerInputComponent->BindAxis("CameraYaw", this, &AFPSPlayer::AddYaw);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFPSPlayer::AddJump);
}

