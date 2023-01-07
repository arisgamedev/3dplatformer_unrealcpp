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
	void ForceStopMovementCompletely();

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

	Aplatformer3d_cppCharacter* Player;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	//add my own tick
	virtual void Tick(float Deltatime) override;


	/*SPHERE TRACER TO CHECK IF WE PERFORM THE OTHER TRACES AND STUFF*/
	//spheretracer functions	
	UFUNCTION()
	void OnSphereTracerOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	void OnSphereTracerOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	bool CanTrace = false;

	bool CanMove = true;

	/*LEDGE HEIGHT TRACING FUNCTIONS AND VARIABLES*/
	//ledge height tracing
	void LedgeHeightTracer();

	//tracing on front
	void LedgeTraceFront();

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

	//trace from character to get wall normal
	void WallTracer();

	//move along ledge
	void LedgeMovementForward(float Value);
	void LedgeMovementRight(float Value);

	//release ledge
	void ReleaseLedge();
	void SetCanGrabLedge();


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

	//ledge platforming vars
	bool IsHanging = false;
	bool CanGrabLedge = true;
	bool IsCrouchingDownLedge = false;
	bool IsJumpingRailLedge = false;
	bool CanClimbUpObject = false;
	bool LedgeFloorBelow = false;


	//WallTracer results
	float FrontWallTraceDistance;
	FVector WallTraceImpact;
	FVector WallNormal;

	//timers
	FTimerHandle MoveToLedgeTimerHandle;
	FTimerHandle ReleaseLedgeTimerHandle;

	//Variables visible in unreal blueprints
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = CharVariables)
	FVector MyTestVector;



	/*WALL RUNNING FUNCTIONS AND VARIABLES*/


	bool CheckWallRunHitWallStop = false;
	bool IsWallRunning = false;
	int WallRunSideType = 0;
	bool WallRunJumpOff = false;




	/*SWINGING BAR FUNCTIONS AND VARIABLES*/


	bool IsBarHanging = false;


};

