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
	GetCharacterMovement()->MaxWalkSpeed = RunSpeed;


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
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &Aplatformer3d_cppCharacter::Jump);
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


/*OVERRIDE JUMP FUNCTION AND ADD OTHER ACTIONS TRIGGERED BY JUMP BUTTON BASED ON CHAR STATE*/
void Aplatformer3d_cppCharacter::Jump()
{
	if (IsHanging == true)
	{
		if (CanJumpOffWall == true && CanClimbUpLedge == false)
		{
			Aplatformer3d_cppCharacter::LedgeJumpOffWall();
		}
		else
		{
			if (CanClimbUpLedge == true && CanJumpOffWall == false)
			{
				Aplatformer3d_cppCharacter::LedgeJumpUp();
			}
			else
			{
				if (CanSideJump == true)
				{
					Aplatformer3d_cppCharacter::LedgeJumpSide();
				}
			}
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Cyan, "my jump override function");
		bPressedJump = true;
		JumpKeyHoldTime = 0.0f;
	}	
}

void Aplatformer3d_cppCharacter::LedgeJumpOffWall()
{
	//set platforming flags
	IsLedgeJumpOffWall = true;
	CanTrace = false;
	IsHanging = false;
	//make vector for launch character
	FVector LaunchVelocity = ((WallNormal * (RunSpeed * 1.5f)) + FVector(0.f, 0.f, RunSpeed * 1.5f));

	GetCharacterMovement()->GravityScale = 0.f;
	GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	LaunchCharacter(LaunchVelocity, false, false);
	GetCharacterMovement()->GravityScale = 1.f;
	GetWorld()->GetTimerManager().SetTimer(LedgeJumpOffWallTimerHandle, this, &Aplatformer3d_cppCharacter::LedgeJumpOffWallResetFlags, 0.5f, false); //delay resetting the flags so character doesn't re-snap to ledge
}

void Aplatformer3d_cppCharacter::LedgeJumpOffWallResetFlags()
{
	CanGrabLedge = true;
	CanTrace = true;
	IsLedgeJumpOffWall = false;
}

void Aplatformer3d_cppCharacter::DoClimdUpLedge()
{
	if (IsHanging == true)
	{
		CanMove = false;
		IsHanging = false;

		//first trace
		float ForwardDistanceA = 50.f;
		float ForwardDistanceB = 150.f;
		float TraceEndHeight = -175.f;
		float TraceStartHeight = 125.f;
		float TraceRadius = 10.f;
		const FVector PlayerPos = Player->GetActorLocation();
		const FVector TraceForwardDistanceA = Player->GetActorForwardVector() * ForwardDistanceA;
		const FVector TraceForwardDistanceB = Player->GetActorForwardVector() * ForwardDistanceB;
		const FVector TraceStartOffset = FVector(0.f, 0.f, TraceStartHeight);
		const FVector TraceDistance = FVector(0.f, 0.f, TraceEndHeight);
		const FVector StartA = PlayerPos + TraceForwardDistanceA + TraceStartOffset;
		const FVector StartB = PlayerPos + TraceForwardDistanceB + TraceStartOffset;
		const FVector EndA = StartA + TraceDistance;
		const FVector EndB = StartB + TraceDistance;

		TArray<AActor*> ActorsToIgnore;

		ActorsToIgnore.Add(Player);

		//TArray<FHitResult> HitArray;

		FHitResult HitResultA;
		FHitResult HitResultB;

		bool HitA;
		bool HitB;

		HitA = UKismetSystemLibrary::SphereTraceSingle(GetWorld(), StartA, EndA, TraceRadius, UEngineTypes::ConvertToTraceType(ECC_GameTraceChannel2), false, ActorsToIgnore, EDrawDebugTrace::ForDuration, HitResultA, true, FLinearColor::Yellow, FLinearColor::Blue, 0.1f); //ECC_GameTraceChannel2 = LedgeTracer in DefaultEngine.ini
		HitB = UKismetSystemLibrary::SphereTraceSingle(GetWorld(), StartB, EndB, TraceRadius, UEngineTypes::ConvertToTraceType(ECC_GameTraceChannel2), false, ActorsToIgnore, EDrawDebugTrace::ForDuration, HitResultB, true, FLinearColor::Yellow, FLinearColor::Blue, 0.1f); //ECC_GameTraceChannel2 = LedgeTracer in DefaultEngine.ini
		
		//climbing up is handled via animation montages, implementing root motion, in Blueprints
		if (abs(HitResultA.Distance - HitResultB.Distance) < 1.f)
		{
			BpClimbUpLedge(); //used for normal climb up ledge
		}
		else
		{
			BpClimbOverRailing(); //used for railing climb up, say you are hanging on one side of the railing and climb to the other side, to the floor (also used for narrow ledges to jump to the other side, like vertical boards)
		}
	}
}

void Aplatformer3d_cppCharacter::DoClimbUpShimmy()
{
	//not implemented in this version
}

void Aplatformer3d_cppCharacter::DoJumpUpLedge()
{
	CanTrace = false;
	WallJumpUp = true;
	IsHanging = false;
	GetCharacterMovement()->GravityScale = 0.f;
	GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	GetWorld()->GetTimerManager().SetTimer(DelayActionTimerHandle, this, &Aplatformer3d_cppCharacter::JumpUpLedgeDelay1, 0.5f, false);
}

void Aplatformer3d_cppCharacter::JumpUpLedgeDelay1()
{
	float LaunchVelocityZ = GetCharacterMovement()->JumpZVelocity;
	FVector LaunchVelocity = FVector(0.f, 0.f, LaunchVelocityZ);
	LaunchCharacter(LaunchVelocity, false, false);
	GetCharacterMovement()->GravityScale = 1.f;
	GetWorld()->GetTimerManager().SetTimer(DelayActionTimerHandle, this, &Aplatformer3d_cppCharacter::JumpUpLedgeDelay2, 0.5f, false);
}

void Aplatformer3d_cppCharacter::JumpUpLedgeDelay2()
{
	CanGrabLedge = true;
	WallJumpUp = false;
	CanTrace = true;
}

void Aplatformer3d_cppCharacter::LedgeJumpUp()
{
	switch (LedgeJumpUpType)
	{
	case 1 :
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Cyan, "case 1");
		Aplatformer3d_cppCharacter::DoClimdUpLedge();
		break;
	case 2 :
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Cyan, "case 2");
		Aplatformer3d_cppCharacter::DoClimbUpShimmy();
		break;
	case 3:
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Cyan, "case 3");
		Aplatformer3d_cppCharacter::DoJumpUpLedge();
		break;
	}
}




void Aplatformer3d_cppCharacter::LedgeJumpSide()
{
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
	}
	else if (IsHanging == true)
	{
		Aplatformer3d_cppCharacter::LedgeMovementRight(Value);
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

void Aplatformer3d_cppCharacter::ForceStopMovementImmediately()
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


/*WALL TRACING FUNCTIONS*/

void Aplatformer3d_cppCharacter::WallTracer()
{
	Aplatformer3d_cppCharacter::WallLeftTracer();
	Aplatformer3d_cppCharacter::WallRightTracer();
	Aplatformer3d_cppCharacter::TraceAboveHead();
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

void Aplatformer3d_cppCharacter::TraceAboveHead()
{
	if (IsHanging == true)
	{
		const FVector PlayerPos = Player->GetActorLocation();
		const FVector Start = PlayerPos + Player->GetActorUpVector() * 100;// +(0.f, 0.f, 100.f);	
		const FVector ForwardVector = Player->GetActorForwardVector();
		float ModifiedForwardVectorX = ForwardVector.X * 150.f;
		float ModifiedForwardVectorY = ForwardVector.Y * 150.f;
		float ModifiedForwardVectorZ = ForwardVector.Z;
		const FVector ModifiedForwardVector = FVector(ModifiedForwardVectorX, ModifiedForwardVectorY, ModifiedForwardVectorZ);
		const FVector End = Start + ModifiedForwardVector;

		float TraceRadius = 10.f;
		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypesArray; // object types to trace
		ObjectTypesArray.Add(UEngineTypes::ConvertToObjectType(ECC_WorldStatic));
		TArray<AActor*> ActorsToIgnore;
		ActorsToIgnore.Add(Player);
		FHitResult HitResult;

		WallTrace = UKismetSystemLibrary::SphereTraceSingleForObjects(GetWorld(), Start, End, TraceRadius, ObjectTypesArray, false, ActorsToIgnore, EDrawDebugTrace::ForDuration, HitResult, true, FLinearColor::Yellow, FLinearColor::Blue, 0.1f);

		if (WallTrace == true)
		{
			if (HitResult.Distance < 42.f)
			{
				LedgeJumpUpType = 3; //there is a wall, can jump up to next ledge
			}
			else
			{
				LedgeJumpUpType = 2; //there is a gap, can go to shimmy (not implemented in this controller)
			}
		}
		else
		{
			LedgeJumpUpType = 1; //there is no wall, can climb up
		}
	}	
}

void Aplatformer3d_cppCharacter::WallLeftTracer()
{
	const FVector PlayerPos = Player->GetActorLocation();
	const FVector Start = PlayerPos;
	const FVector LeftDistance = Player->GetActorRightVector() * -75.f;
	const FVector End = Start + LeftDistance;

	float TraceRadius = 20.f;
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(Player);

	FHitResult HitResult;

	WallTrace = UKismetSystemLibrary::SphereTraceSingle(GetWorld(), Start, End, TraceRadius, UEngineTypes::ConvertToTraceType(ECC_GameTraceChannel2), false, ActorsToIgnore, EDrawDebugTrace::ForDuration, HitResult, true, FLinearColor::White, FLinearColor::Blue, 0.1f); //ECC_GameTraceChannel2 = LedgeTracer in DefaultEngine.ini

	if (WallTrace == true)
	{
		LeftWallTraceDistance = HitResult.Distance;
		WallTraceSideImpact = HitResult.ImpactPoint;
		WallSideNormal = HitResult.ImpactNormal;
		TraceHitLeftWall = true;
		TraceHitRightWall = false;
	}
	else if (WallTrace == false)
	{
		if (IsWallRunning == true && WallRunSideType == 2)
		{
			Aplatformer3d_cppCharacter::StopWallRun();
		}
	}
}

void Aplatformer3d_cppCharacter::WallRightTracer()
{
	const FVector PlayerPos = Player->GetActorLocation();
	const FVector Start = PlayerPos;
	const FVector RightDistance = Player->GetActorRightVector() * 75.f;
	const FVector End = Start + RightDistance;

	float TraceRadius = 20.f;
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(Player);

	FHitResult HitResult;

	WallTrace = UKismetSystemLibrary::SphereTraceSingle(GetWorld(), Start, End, TraceRadius, UEngineTypes::ConvertToTraceType(ECC_GameTraceChannel2), false, ActorsToIgnore, EDrawDebugTrace::ForDuration, HitResult, true, FLinearColor::White, FLinearColor::Blue, 0.1f); //ECC_GameTraceChannel2 = LedgeTracer in DefaultEngine.ini

	if (WallTrace == true)
	{
		RightWallTraceDistance = HitResult.Distance;
		WallTraceSideImpact = HitResult.ImpactPoint;
		WallSideNormal = HitResult.ImpactNormal;		
		TraceHitRightWall = true;
		TraceHitLeftWall = false;
	}
	else if (WallTrace == false)
	{
		if (IsWallRunning == true && WallRunSideType == 3)
		{
			Aplatformer3d_cppCharacter::StopWallRun();
		}
	}
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
			if (IsHanging == true || IsWallRunning == true)
			{

			}
			else if (IsHanging == false && IsWallRunning == false)
			{
				if (CanMove == true)
				{
					Aplatformer3d_cppCharacter::LedgeTraceLeft();
					Aplatformer3d_cppCharacter::LedgeTraceRight();
				}
			}
				
			
		}
		

	}
	
}

void Aplatformer3d_cppCharacter::LedgeTraceFront()
{
	//GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::Cyan, "Trace front");

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
		//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Cyan, FString::Printf(TEXT("Hit wall: %s | LedgeDistanceCheck: %f | LedgeHeight: %f %f %f"), *HitWall->GetName(), LedgeDistanceCheck, LedgeHeightX, LedgeHeightY, LedgeHeightZ));
		//GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::Cyan, FString::Printf(TEXT("Hit wall: %s | LedgeDistanceCheck: %f | LedgeHeight: %f %f %f"), *HitResult.Actor->GetName(), LedgeDistanceCheck, LedgeHeightX, LedgeHeightY, LedgeHeightZ));


	}
}

void Aplatformer3d_cppCharacter::LedgeTraceLeft()
{
	//GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::Cyan, "Trace left");

	float ForwardDistance = 30.f;
	float TraceEndHeight = -175.f;
	float TraceStartHeight = 125.f;
	float TraceLeftOffset = -50.f;
	float TraceRadius = 10.f;
	const FVector PlayerPos = Player->GetActorLocation();
	const FVector TraceForwardDistance = Player->GetActorForwardVector() * ForwardDistance;
	const FVector TraceLeftDistance = Player->GetActorRightVector() * TraceLeftOffset;
	const FVector TraceStartOffset = FVector(0.f, 0.f, TraceStartHeight);
	const FVector TraceDistance = FVector(0.f, 0.f, TraceEndHeight);
	const FVector Start = PlayerPos + TraceForwardDistance + TraceStartOffset + TraceLeftDistance;
	const FVector End = Start + TraceDistance;

	TArray<AActor*> ActorsToIgnore;

	ActorsToIgnore.Add(Player);

	//TArray<FHitResult> HitArray;

	FHitResult HitResult;

	HitLeft = UKismetSystemLibrary::SphereTraceSingle(GetWorld(), Start, End, TraceRadius, UEngineTypes::ConvertToTraceType(ECC_GameTraceChannel2), false, ActorsToIgnore, EDrawDebugTrace::ForDuration, HitResult, true, FLinearColor::Yellow, FLinearColor::Blue, 0.1f); //ECC_GameTraceChannel2 = LedgeTracer in DefaultEngine.ini

	if (HitLeft == true && HitResult.ImpactNormal.Z > 0.9f)
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
		//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Cyan, FString::Printf(TEXT("Hit wall: %s | LedgeDistanceCheck: %f | LedgeHeight: %f %f %f"), *HitWall->GetName(), LedgeDistanceCheck, LedgeHeightX, LedgeHeightY, LedgeHeightZ));
		//GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::Cyan, FString::Printf(TEXT("Hit wall: %s | LedgeDistanceCheck: %f | LedgeHeight: %f %f %f"), *HitResult.Actor->GetName(), LedgeDistanceCheck, LedgeHeightX, LedgeHeightY, LedgeHeightZ));


	}
}

void Aplatformer3d_cppCharacter::LedgeTraceRight()
{
	//GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::Cyan, "Trace right");

	float ForwardDistance = 30.f;
	float TraceEndHeight = -175.f;
	float TraceStartHeight = 125.f;
	float TraceRightOffset = 50.f;
	float TraceRadius = 10.f;
	const FVector PlayerPos = Player->GetActorLocation();
	const FVector TraceForwardDistance = Player->GetActorForwardVector() * ForwardDistance;
	const FVector TraceRightDistance = Player->GetActorRightVector() * TraceRightOffset;
	const FVector TraceStartOffset = FVector(0.f, 0.f, TraceStartHeight);
	const FVector TraceDistance = FVector(0.f, 0.f, TraceEndHeight);
	const FVector Start = PlayerPos + TraceForwardDistance + TraceStartOffset + TraceRightDistance;
	const FVector End = Start + TraceDistance;

	TArray<AActor*> ActorsToIgnore;

	ActorsToIgnore.Add(Player);

	//TArray<FHitResult> HitArray;

	FHitResult HitResult;

	HitRight = UKismetSystemLibrary::SphereTraceSingle(GetWorld(), Start, End, TraceRadius, UEngineTypes::ConvertToTraceType(ECC_GameTraceChannel2), false, ActorsToIgnore, EDrawDebugTrace::ForDuration, HitResult, true, FLinearColor::Yellow, FLinearColor::Blue, 0.1f); //ECC_GameTraceChannel2 = LedgeTracer in DefaultEngine.ini

	if (HitRight == true && HitResult.ImpactNormal.Z > 0.9f)
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
		//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Cyan, FString::Printf(TEXT("Hit wall: %s | LedgeDistanceCheck: %f | LedgeHeight: %f %f %f"), *HitWall->GetName(), LedgeDistanceCheck, LedgeHeightX, LedgeHeightY, LedgeHeightZ));
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
	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, FString::Printf(TEXT("Check Ledge Trace Result")));
	if (HitFront == true || HitLeft == true || HitRight == true)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, FString::Printf(TEXT("LedgeHeight: %f %f %f"), LedgeHeight.X, LedgeHeight.Y, LedgeHeight.Z));
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


void Aplatformer3d_cppCharacter::HangFromLedge() //lateral movement is handled using Animation Montages
{
	if (LedgeFloorBelow == false)
	{
		//setup MoveComponentTo variables
		FVector ModWallNormal = WallNormal * FVector(42.f, 42.f, 0.f);
		float LedgeHeightVerticalOffset = 25.f; //lower values move character up when hanging
		float TargetRelativeLocationX = ModWallNormal.X + WallTraceImpact.X;
		float TargetRelativeLocationY = ModWallNormal.Y + WallTraceImpact.Y;
		float TargetRelativeLocationZ = LedgeHeight.Z - LedgeHeightVerticalOffset;
		LedgeTargetRelativeLocation = FVector(TargetRelativeLocationX, TargetRelativeLocationY, TargetRelativeLocationZ);

		FVector InvertedNormal = WallNormal * FVector(-1.f, -1.f, 0.f);
		FVector UpVector = GetCapsuleComponent()->GetUpVector();
		LedgeTargetRelativeRotation = UKismetMathLibrary::MakeRotFromXZ(InvertedNormal, UpVector);

		BpHangFromLedge(); //calling MoveComponentTo function from Blueprints bc doenst work in code
		
			
	}
}


void Aplatformer3d_cppCharacter::MoveToLedge() 
{
	if ( (GetCharacterMovement()->MovementMode == MOVE_Falling || (GetCharacterMovement()->MovementMode == MOVE_Flying && (IsJumpingRailLedge == true || IsCrouchingDownLedge == true)) )  &&   CanGrabLedge == true  &&  CanClimbUpObject == false )
	{		
		GetCharacterMovement()->SetMovementMode(MOVE_Flying);
						
		GetWorld()->GetTimerManager().SetTimer(MoveToLedgeTimerHandle, this, &Aplatformer3d_cppCharacter::MoveComponentToLedge, 0.1f, false);
	}
	
}

void Aplatformer3d_cppCharacter::MoveComponentToLedge()
{
	//setup MoveComponentTo variables
	FVector ModWallNormal = WallNormal * FVector(42.f, 42.f, 0.f);
	float LedgeHeightVerticalOffset = 25.f; //lower values move character up when hanging
	float TargetRelativeLocationX = ModWallNormal.X + WallTraceImpact.X;
	float TargetRelativeLocationY = ModWallNormal.Y + WallTraceImpact.Y;
	float TargetRelativeLocationZ = LedgeHeight.Z - LedgeHeightVerticalOffset;
	LedgeTargetRelativeLocation = FVector(TargetRelativeLocationX, TargetRelativeLocationY, TargetRelativeLocationZ);
	CurrentLocation = GetCapsuleComponent()->GetComponentLocation();

	GEngine->AddOnScreenDebugMessage(-1, 50.f, FColor::Yellow, FString::Printf(TEXT("TargetRelLocation: %f %f %f"), TargetRelativeLocationX, TargetRelativeLocationY, TargetRelativeLocationZ));

	FVector InvertedNormal = WallNormal * FVector(-1.f, -1.f, 0.f);
	FVector UpVector = GetCapsuleComponent()->GetUpVector();
	LedgeTargetRelativeRotation = UKismetMathLibrary::MakeRotFromXZ(InvertedNormal, UpVector);
	CurrentRotation = GetCapsuleComponent()->GetComponentRotation();

	IsHanging = true;
	CanGrabLedge = false;
	IsCrouchingDownLedge = false;
	IsJumpingRailLedge = false;
	IsBarHanging = false;
	

	BpMoveToLedge(); //calling MoveComponentTo function from Blueprints bc doenst work in code	
}


void Aplatformer3d_cppCharacter::LedgeMovementForward(float Value)
{	
	if (abs(Value) > 0.5f) // make sure player "pushes the joystick enough" to avoid false inputs
		if (Value > 0.f)
		{
			CanJumpOffWall = false;
			CanClimbUpLedge = true;
		}
		else
		{
			CanJumpOffWall = true;
			CanClimbUpLedge = false;
		}
	else
	{
		CanJumpOffWall = false;
		CanClimbUpLedge = false;
	}
}

void Aplatformer3d_cppCharacter::LedgeMovementRight(float Value)
{
	if (CornerShouldJump == true)
	{

	}
	else
	{
		if (abs(Value) > 0.5f)
		{
			BpLedgeLateralMovement(Value); //calling lateral movement from Blueprints to make it easier -- can be implemented in code in a later version
		}
		else
		{
			ForceStopMovementImmediately();
		}
	}
	Aplatformer3d_cppCharacter::LedgeMovementRightCacheValue(Value); //cache the axis value for corner tracing
}

void Aplatformer3d_cppCharacter::LedgeMovementRightCacheValue(float Value)
{
	if (abs(Value) > 0.1f)
	{
		TmpMoveRightValue = Value;
	}
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

void Aplatformer3d_cppCharacter::StopWallRun()
{
}


/*WALL RUNNING FUNCTIONS AND VARIABLES*/


