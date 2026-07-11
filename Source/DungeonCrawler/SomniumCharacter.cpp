#include "SomniumCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "DrawDebugHelpers.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/LocalPlayer.h"
#include "Engine/World.h"
#include "OrganGun.h"

ASomniumCharacter::ASomniumCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCamera->SetupAttachment(GetMesh(), FName("head"));
	FirstPersonCamera->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
	FirstPersonCamera->bUsePawnControlRotation = true; 
}

void ASomniumCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			if (DefaultMappingContext)
			{
				Subsystem->AddMappingContext(DefaultMappingContext, 0);
			}
			
			if (MouseLookMappingContext)
			{
				Subsystem->AddMappingContext(MouseLookMappingContext, 1);
			}
		}
	}
	if (OrganGunClass)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = GetInstigator();

		EquippedGun = GetWorld()->SpawnActor<AOrganGun>(OrganGunClass, FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
        
		if (EquippedGun && FirstPersonCamera)
		{
			EquippedGun->AttachToComponent(FirstPersonCamera, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
			EquippedGun->SetActorRelativeLocation(FVector(40.0f, 20.0f, -10.0f)); 
		}
	}
}
void ASomniumCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASomniumCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 2. Łączenie Input Action z naszymi funkcjami w C++
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASomniumCharacter::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ASomniumCharacter::Look);
		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Started, this, &ASomniumCharacter::Shoot);
	}
}

void ASomniumCharacter::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void ASomniumCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ASomniumCharacter::Shoot(const FInputActionValue& Value)
{
	if (EquippedGun && FirstPersonCamera)
	{
		FVector Start = FirstPersonCamera->GetComponentLocation();
		FVector ForwardVector = FirstPersonCamera->GetForwardVector();
        
		EquippedGun->Fire(Start, ForwardVector);
	}
}
