// Copyright Epic Games, Inc. All Rights Reserved.

#include "platformer3d_cppCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SphereComponent.h"
#include "Engine/Engine.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"

//////////////////////////////////////////////////////////////////////////
// Aplatformer3d_cppCharacter

Aplatformer3d_cppCharacter::Aplatformer3d_cppCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 800.f;
	GetCharacterMovement()->AirControl = 0.f;
	GetCharacterMovement()->MaxFlySpeed = 200.0f;
	GetCharacterMovement()->SetWalkableFloorAngle(30.f);
	GetCharacterMovement()->CrouchedHalfHeight = 30.f;


	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)


	//adding my own components

	//adding sphere tracer
	SphereTracer = CreateDefaultSubobject<USphereComponent>(TEXT("SphereTracer"));
	SphereTracer->SetupAttachment(RootComponent);
	SphereTracer->SetSphereRadius(100.f);
	SphereTracer->SetRelativeLocation(FVector(0.f, 0.f, 10.f));
	SphereTracer->SetCollisionProfileName("SphereTracer");
	SphereTracer->bHiddenInGame = false; //temporary, just for development purposes

	SphereTracer->OnComponentBeginOverlap.AddDynamic(this, &Aplatformer3d_cppCharacter::OnSphereTracerOverlapBegin);
	SphereTracer->OnComponentEndOverlap.AddDynamic(this, &Aplatformer3d_cppCharacter::OnSphereTracerOverlapEnd);

	
}

//////////////////////////////////////////////////////////////////////////
// Input

void Aplatformer3d_cppCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &Aplatformer3d_cppCharacter::Crouch);

	PlayerInputComponent->BindAxis("MoveForward", this, &Aplatformer3d_cppCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &Aplatformer3d_cppCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &Aplatformer3d_cppCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &Aplatformer3d_cppCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &Aplatformer3d_cppCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &Aplatformer3d_cppCharacter::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &Aplatformer3d_cppCharacter::OnResetVR);
}



//adding my own beginplay
void Aplatformer3d_cppCharacter::BeginPlay()
{
	Super::BeginPlay();

	Player = Cast<Aplatformer3d_cppCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)); // get reference to Player to make my life easier
}

void Aplatformer3d_cppCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//perform traces for platforming if CanTrace is true, meaning the character is near platformable objects
	if (CanTrace == true)
	{
		Aplatformer3d_cppCharacter::LedgeHeightTracer();
		Aplatformer3d_cppCharacter::WallTracer();
		
	}


}



void Aplatformer3d_cppCharacter::OnResetVR()
{
	// If platformer3d_cpp is added to a project via 'Add Feature' in the Unreal Editor the dependency on HeadMountedDisplay in platformer3d_cpp.Build.cs is not automatically propagated
	// and a linker error will result.
	// You will need to either:
	//		Add "HeadMountedDisplay" to [YourProject].Build.cs PublicDependencyModuleNames in order to build successfully (appropriate if supporting VR).
	// or:
	//		Comment or delete the call to ResetOrientationAndPosition below (appropriate if not supporting VR)
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void Aplatformer3d_cppCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

void Aplatformer3d_cppCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

void Aplatformer3d_cppCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void Aplatformer3d_cppCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void Aplatformer3d_cppCharacter::MoveForward(float Value)
{
	if (IsHanging == false)
	{
		if ((Controller != nullptr) && (Value != 0.0f))
		{
			// find out which way is forward
			const FRotator Rotation = Controller->GetControlRotation();
			const FRotator YawRotation(0, Rotation.Yaw, 0);

			// get forward vector
			const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
			AddMovementInput(Direction, Value);
		}
	}
	else if (IsHanging == true)
	{
		Aplatformer3d_cppCharacter::LedgeMovementForward(Value);
	}
	
}

void Aplatformer3d_cppCharacter::MoveRight(float Value)
{
	if (IsHanging == false)
	{
		if ((Controller != nullptr) && (Value != 0.0f))
		{
			// find out which way is right
			const FRotator Rotation = Controller->GetControlRotation();
			const FRotator YawRotation(0, Rotation.Yaw, 0);

			// get right vector 
			const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
			// add movement in that direction
			AddMovementInput(Direction, Value);
		}
		else if (true)
		{

		}
	}
	
}

void Aplatformer3d_cppCharacter::Crouch()
{
	if (IsHanging == false)
	{
		//crouch functin here
	}
	else if (IsHanging == true)
	{
		Aplatformer3d_cppCharacter::ReleaseLedge();

	}
}

void Aplatformer3d_cppCharacter::ForceStopMovementCompletely()
{
	GetCharacterMovement()->StopMovementImmediately();
}






/*SPHERE TRACER TO CHECK IF WE PERFORM THE OTHER TRACES AND STUFF*/

void Aplatformer3d_cppCharacter::OnSphereTracerOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	CanTrace = true;
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Cyan, "SphereTracer enter");
}

void Aplatformer3d_cppCharacter::OnSphereTracerOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	CanTrace = false;
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Cyan, "SphereTracer exit");
}




/*LEDGE HEIGHT TRACING FUNCTIONS*/

void Aplatformer3d_cppCharacter::LedgeHeightTracer()
{
	if (WallRunJumpOff == false)
	{
		Aplatformer3d_cppCharacter::LedgeCheckFloorBelowTrace();
		if (IsWallRunning == true && WallRunSideType == 1)
		{
			Aplatformer3d_cppCharacter::LedgeTraceAboveWallRunning();
		}
		else
		{
			Aplatformer3d_cppCharacter::CheckLedgeTraceResult();
			Aplatformer3d_cppCharacter::LedgeTraceFront();
		}
		

	}
	
}

void Aplatformer3d_cppCharacter::LedgeTraceFront()
{
	GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::Cyan, "Trace front");

	float ForwardDistance = 70.f;
	float TraceEndHeight = -175.f;
	float TraceStartHeight = 125.f;
	float TraceRadius = 10.f;
	const FVector PlayerPos = Player->GetActorLocation();
	const FVector TraceForwardDistance = Player->GetActorForwardVector() * ForwardDistance;
	const FVector TraceStartOffset = FVector(0.f, 0.f, TraceStartHeight);
	const FVector TraceDistance = FVector(0.f, 0.f, TraceEndHeight);
	const FVector Start = PlayerPos + TraceForwardDistance + TraceStartOffset;
	const FVector End = Start + TraceDistance;

	TArray<AActor*> ActorsToIgnore;

	ActorsToIgnore.Add(Player);

	//TArray<FHitResult> HitArray;

	FHitResult HitResult;

	HitFront = UKismetSystemLibrary::SphereTraceSingle(GetWorld(), Start, End, TraceRadius, UEngineTypes::ConvertToTraceType(ECC_GameTraceChannel2), false, ActorsToIgnore, EDrawDebugTrace::ForDuration, HitResult, true, FLinearColor::Yellow, FLinearColor::Blue, 0.1f); //ECC_GameTraceChannel2 = LedgeTracer in DefaultEngine.ini
	
	if (HitFront == true && HitResult.ImpactNormal.Z > 0.9f )
	{
		//just printing variables to check it's working
		LedgeHeight = HitResult.ImpactPoint;
		const float LedgeHeightX = LedgeHeight.X;
		const float LedgeHeightY = LedgeHeight.Y;
		const float LedgeHeightZ = LedgeHeight.Z;
		LedgeDistanceCheck = HitResult.Distance;
		HitWall = HitResult.GetActor();	

		const FVector ImpactPoint = HitResult.ImpactPoint;
		const float ImpactX = ImpactPoint.X;
		const float ImpactY = ImpactPoint.Y;
		const float ImpactZ = ImpactPoint.Z;
		const float Distance = HitResult.Distance;
		GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::Cyan, FString::Printf(TEXT("Hit wall: %s | LedgeDistanceCheck: %f | LedgeHeight: %f %f %f"), *HitWall->GetName(), LedgeDistanceCheck, LedgeHeightX, LedgeHeightY, LedgeHeightZ));
		//GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::Cyan, FString::Printf(TEXT("Hit wall: %s | LedgeDistanceCheck: %f | LedgeHeight: %f %f %f"), *HitResult.Actor->GetName(), LedgeDistanceCheck, LedgeHeightX, LedgeHeightY, LedgeHeightZ));


	}
}

void Aplatformer3d_cppCharacter::LedgeCheckFloorBelowTrace()
{
}

void Aplatformer3d_cppCharacter::LedgeTraceAboveWallRunning()
{
}


void Aplatformer3d_cppCharacter::CheckLedgeTraceResult()
{
	if (HitFront == true || HitLeft == true || HitRight == true)
	{
		if (IsWallRunning == false) // FALTAN LOS CHECKS DE SI ES RAILING PERO ESOS LOS AGREGO DESPUES!!!!!!!!!!!!!!!!!!!!!!!!
			if (IsHanging == true)
			{
				Aplatformer3d_cppCharacter::HangFromLedge();
			}
			else if (IsHanging == false)
			{
				Aplatformer3d_cppCharacter::MoveToLedge();
			}
	}
}



void Aplatformer3d_cppCharacter::WallTracer()
{
	float ForwardDistance = 75.f;
	const FVector PlayerPos = Player->GetActorLocation();
	const FVector TraceForwardDistance = Player->GetActorForwardVector() * ForwardDistance;
	const FVector Start = PlayerPos;
	const FVector End = PlayerPos + TraceForwardDistance;

	float TraceRadius = 10.f;
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(Player);

	FHitResult HitResult;

	WallTrace = UKismetSystemLibrary::SphereTraceSingle(GetWorld(), Start, End, TraceRadius, UEngineTypes::ConvertToTraceType(ECC_GameTraceChannel2), false, ActorsToIgnore, EDrawDebugTrace::ForDuration, HitResult, true, FLinearColor::Red, FLinearColor::Green, 0.1f); //ECC_GameTraceChannel2 = LedgeTracer in DefaultEngine.ini

	if (WallTrace == true)
	{
		FrontWallTraceDistance = HitResult.Distance;
		WallTraceImpact = HitResult.ImpactPoint;
		WallNormal = HitResult.ImpactNormal;

	}

}


void Aplatformer3d_cppCharacter::HangFromLedge()
{
	if (LedgeFloorBelow == false)
	{
		if (CanMove == true)
		{
			//setup MoveComponentTo variables
			FVector ModWallNormal = WallNormal * FVector(42.f, 42.f, 0.f);
			float LedgeHeightVerticalOffset = 45.f; //lower values move the character up when hanging
			float TargetRelativeLocationX = ModWallNormal.X + WallTraceImpact.X;
			float TargetRelativeLocationY = ModWallNormal.Y + WallTraceImpact.Y;
			float TargetRelativeLocationZ = LedgeHeight.Z + LedgeHeightVerticalOffset;
			FVector TargetRelativeLocation = FVector(TargetRelativeLocationX, TargetRelativeLocationY, TargetRelativeLocationZ);

			FVector InvertedNormal = WallNormal * FVector(-1.f, -1.f, 0.f);
			FVector UpVector = GetCapsuleComponent()->GetUpVector();
			FRotator TargetRelativeRotation = UKismetMathLibrary::MakeRotFromXZ(InvertedNormal, UpVector);
			//FHitResult* OutSweepHitResult;
			//ETeleportType Teleport;
			GetCapsuleComponent()->SetRelativeRotation(TargetRelativeRotation, false/*, OutSweepHitResult, Teleport*/);

			float OverTime = 0.1f;
			TEnumAsByte< EMoveComponentAction::Type > MoveAction;
			FLatentActionInfo LatentInfo;

			UKismetSystemLibrary::MoveComponentTo(GetCapsuleComponent(), TargetRelativeLocation, TargetRelativeRotation, false, false, OverTime, true, MoveAction, LatentInfo);
		}
	}
}


void Aplatformer3d_cppCharacter::MoveToLedge() // todavia faltan los montones de checks, pero eso despues porque quiero probar funcionalidad
{
	if ( (GetCharacterMovement()->MovementMode == MOVE_Falling || (GetCharacterMovement()->MovementMode == MOVE_Flying && (IsJumpingRailLedge == true || IsCrouchingDownLedge == true)) )  &&   CanGrabLedge == true  &&  CanClimbUpObject == false )
	{
		//setup MoveComponentTo variables
		FVector ModWallNormal = WallNormal * FVector(42.f, 42.f, 0.f);
		float LedgeHeightVerticalOffset = 45.f; //lower values move character up when hanging
		float TargetRelativeLocationX = ModWallNormal.X + WallTraceImpact.X;
		float TargetRelativeLocationY = ModWallNormal.Y + WallTraceImpact.Y;
		float TargetRelativeLocationZ = LedgeHeight.Z + LedgeHeightVerticalOffset;
		FVector TargetRelativeLocation = FVector(TargetRelativeLocationX, TargetRelativeLocationY, TargetRelativeLocationZ);

		FVector InvertedNormal = WallNormal * FVector(-1.f, -1.f, 0.f);
		FVector UpVector = GetCapsuleComponent()->GetUpVector();
		FRotator TargetRelativeRotation = UKismetMathLibrary::MakeRotFromXZ(InvertedNormal, UpVector);

		float OverTime = 0.1f;
		//TEnumAsByte< EMoveComponentAction::Move > MoveAction;
		FLatentActionInfo LatentInfo;



		GetCharacterMovement()->SetMovementMode(MOVE_Flying);
		CanGrabLedge = false;
		IsCrouchingDownLedge = false;
		IsJumpingRailLedge;
		IsHanging = true;
		ForceStopMovementCompletely();
		UKismetSystemLibrary::MoveComponentTo(GetCapsuleComponent(), TargetRelativeLocation, TargetRelativeRotation, false, false, OverTime, true, EMoveComponentAction::Move, LatentInfo);
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan, FString::Printf(TEXT("LedgeHeight: %f | TargetRelLocation: %f"), LedgeHeight.Z, TargetRelativeLocationZ));
		
		//GetWorld()->GetTimerManager().SetTimer(MoveToLedgeTimerHandle, this, &Aplatformer3d_cppCharacter::ForceStopMovementCompletely, 0.1f, false);

	}
	
}


void Aplatformer3d_cppCharacter::LedgeMovementForward(float Value)
{
}

void Aplatformer3d_cppCharacter::LedgeMovementRight(float Value)
{
}

void Aplatformer3d_cppCharacter::ReleaseLedge()
{
	GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	IsHanging = false;
	GetWorld()->GetTimerManager().SetTimer(ReleaseLedgeTimerHandle, this, &Aplatformer3d_cppCharacter::SetCanGrabLedge, 0.5f, false);
}

void Aplatformer3d_cppCharacter::SetCanGrabLedge()
{
	CanGrabLedge = true;
}



