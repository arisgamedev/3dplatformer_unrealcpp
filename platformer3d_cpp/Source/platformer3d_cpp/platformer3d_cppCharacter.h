// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "platformer3d_cppCharacter.generated.h"

UCLASS(config=Game)
class Aplatformer3d_cppCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	
public:
	Aplatformer3d_cppCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;


	//add sphere tracer
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Components)
		class USphereComponent* SphereTracer;

protected:

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** Called for crouching button */
	void Crouch();

	/** Called to stop movement completely */
	UFUNCTION() //para que sea llamada desde FName
	void ForceStopMovementImmediately();

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	//add my own beginplay
	virtual void BeginPlay() override;

	//add my own tick
	virtual void Tick(float Deltatime) override;

	Aplatformer3d_cppCharacter* Player;


	/*LOCOMOTION VARIABLES*/
	float RunSpeed = 600.f;


	/*BLUEPRINT IMPLEMENTABLE VARIABLES*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharVariables)
	bool CanMove = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharVariables)
	bool CanClimbUpLedge = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharVariables)
	bool CanGrabLedge = true;

	

	/*LEDGE HEIGHT TRACING FUNCTIONS AND VARIABLES*/
	//variables used to place character in correct position and orientation
	//ledge traces checks
	bool HitFront = false;
	bool HitLeft = false;
	bool HitRight = false;
	bool WallTrace = false;

	//ledge traces results
	float LedgeDistanceCheck;
	FVector LedgeHeight;
	AActor* HitWall;	
	FVector CurrentLocation;
	FRotator CurrentRotation;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = CharVariables)
	FVector LedgeTargetRelativeLocation;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = CharVariables)
	FRotator LedgeTargetRelativeRotation;


	//ledge platforming vars
	bool IsHanging = false;	
	bool IsCrouchingDownLedge = false;
	bool IsJumpingRailLedge = false;
	bool CanClimbUpObject = false;
	bool LedgeFloorBelow = false;
	int LedgeJumpUpType = 0;
	bool CanJumpOffWall = false;
	bool CornerShouldJump = false;
	float TmpMoveRightValue;
	bool CanSideJump = false;
	bool IsLedgeJumpOffWall = false;
	bool WallJumpUp = false;

	//WallTracer results
	float FrontWallTraceDistance;
	FVector WallTraceImpact;
	FVector WallNormal;


	//WallLeftTracer and WalRightTracer results
	//common
	FVector WallTraceSideImpact;
	FVector WallSideNormal;
	//left
	bool TraceHitLeftWall;
	float LeftWallTraceDistance;
	//right
	bool TraceHitRightWall;
	float RightWallTraceDistance;


	/*WALL RUNNING FUNCTIONS AND VARIABLES*/
	bool CheckWallRunHitWallStop = false;
	bool IsWallRunning = false;
	int WallRunSideType = 0;
	bool WallRunJumpOff = false;




	/*SWINGING BAR FUNCTIONS AND VARIABLES*/


	bool IsBarHanging = false;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	
	/**
	 * Make the character jump on the next update.
	 * If you want your character to jump according to the time that the jump key is held,
	 * then you can set JumpMaxHoldTime to some non-zero value. Make sure in this case to
	 * call StopJumping() when you want the jump's z-velocity to stop being applied (such
	 * as on a button up event), otherwise the character will carry on receiving the
	 * velocity until JumpKeyHoldTime reaches JumpMaxHoldTime.
	 */
	//UFUNCTION(BlueprintCallable, Category = Character)
	virtual void Jump() override;


	/*SPHERE TRACER TO CHECK IF WE PERFORM THE OTHER TRACES AND STUFF*/
	//spheretracer functions	
	UFUNCTION()
	void OnSphereTracerOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	void OnSphereTracerOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	bool CanTrace = false;

	/*WALL TRACING FUNCTIONS AND VARIABLES*/
	//trace from character to get wall normal
	void WallTracer();
	void TraceAboveHead();

	//trace to the sides
	void WallLeftTracer();
	void WallRightTracer();


	/*LEDGE HEIGHT TRACING FUNCTIONS AND VARIABLES*/
	//ledge height tracing
	void LedgeHeightTracer();

	//tracing on front
	void LedgeTraceFront();

	//tracing on left
	void LedgeTraceLeft();

	//tracing on right
	void LedgeTraceRight();

	//check if there is floor below so you don't hang on short ledges
	void LedgeCheckFloorBelowTrace();

	//trace for ledge while wallrunning upwards
	void LedgeTraceAboveWallRunning();

	//check ledge traces result to see if you should grab a ledge
	void CheckLedgeTraceResult();

	//move character to ledge after successful trace
	void MoveToLedge();
	void MoveComponentToLedge();

	//hang from ledge to move around
	void HangFromLedge();

	//move along ledge
	void LedgeMovementForward(float Value);
	void LedgeMovementRight(float Value);
	void LedgeMovementRightCacheValue(float Value);

	//jump actions when on ledge
	void LedgeJumpOffWall();
	void LedgeJumpUp();
	void LedgeJumpSide();
	void LedgeJumpOffWallResetFlags();
	void DoClimdUpLedge(); //climb up a ledge, LedgeJumpUpType = 1
	void DoClimbUpShimmy(); //climb up to a narrow shimmy thing -not implemented here-, LedgeJumpUpType = 2
	void DoJumpUpLedge(); //jump up from ledge to reach a ledge above, LedgeJumpUpType = 3
	void JumpUpLedgeDelay1();
	void JumpUpLedgeDelay2();

	//release ledge
	void ReleaseLedge();
	void SetCanGrabLedge();
	

	/*WALL RUNNING FUNCTIONS AND VARIABLES*/
	//stop wall run
	void StopWallRun();

	//TIMERS - it should be safe to use a single timer, but that will be done in a future version
	FTimerHandle MoveToLedgeTimerHandle;
	FTimerHandle ReleaseLedgeTimerHandle;
	FTimerHandle LedgeJumpOffWallTimerHandle;
	FTimerHandle DelayActionTimerHandle;
	

	/*BLUEPRINT IMPLEMENTABLE FUNCTIONS*/
	//Move character to ledge after ledge detection
	UFUNCTION(BlueprintImplementableEvent, Category = Platforming)
		void BpMoveToLedge();
	//Align character to ledge during ledge transversal
	UFUNCTION(BlueprintImplementableEvent, Category = Platforming)
		void BpHangFromLedge();
	//Perform ledge lateral movement Anim Montages (does root motion)
	UFUNCTION(BlueprintImplementableEvent, Category = Platforming)
		void BpLedgeLateralMovement(float bpvalue);
	UFUNCTION(BlueprintImplementableEvent, Category = Platforming)
		void BpClimbUpLedge();
	UFUNCTION(BlueprintImplementableEvent, Category = Platforming)
		void BpClimbOverRailing();


	


};

