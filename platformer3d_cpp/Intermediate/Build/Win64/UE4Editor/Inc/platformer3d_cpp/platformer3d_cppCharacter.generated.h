// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef PLATFORMER3D_CPP_platformer3d_cppCharacter_generated_h
#error "platformer3d_cppCharacter.generated.h already included, missing '#pragma once' in platformer3d_cppCharacter.h"
#endif
#define PLATFORMER3D_CPP_platformer3d_cppCharacter_generated_h

#define platformer3d_cpp_Source_platformer3d_cpp_platformer3d_cppCharacter_h_12_SPARSE_DATA
#define platformer3d_cpp_Source_platformer3d_cpp_platformer3d_cppCharacter_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnSphereTracerOverlapEnd); \
	DECLARE_FUNCTION(execOnSphereTracerOverlapBegin); \
	DECLARE_FUNCTION(execForceStopMovementImmediately);


#define platformer3d_cpp_Source_platformer3d_cpp_platformer3d_cppCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnSphereTracerOverlapEnd); \
	DECLARE_FUNCTION(execOnSphereTracerOverlapBegin); \
	DECLARE_FUNCTION(execForceStopMovementImmediately);


#define platformer3d_cpp_Source_platformer3d_cpp_platformer3d_cppCharacter_h_12_EVENT_PARMS \
	struct platformer3d_cppCharacter_eventBpLedgeLateralMovement_Parms \
	{ \
		float bpvalue; \
	};


#define platformer3d_cpp_Source_platformer3d_cpp_platformer3d_cppCharacter_h_12_CALLBACK_WRAPPERS
#define platformer3d_cpp_Source_platformer3d_cpp_platformer3d_cppCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAplatformer3d_cppCharacter(); \
	friend struct Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics; \
public: \
	DECLARE_CLASS(Aplatformer3d_cppCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/platformer3d_cpp"), NO_API) \
	DECLARE_SERIALIZER(Aplatformer3d_cppCharacter)


#define platformer3d_cpp_Source_platformer3d_cpp_platformer3d_cppCharacter_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAplatformer3d_cppCharacter(); \
	friend struct Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics; \
public: \
	DECLARE_CLASS(Aplatformer3d_cppCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/platformer3d_cpp"), NO_API) \
	DECLARE_SERIALIZER(Aplatformer3d_cppCharacter)


#define platformer3d_cpp_Source_platformer3d_cpp_platformer3d_cppCharacter_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API Aplatformer3d_cppCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(Aplatformer3d_cppCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, Aplatformer3d_cppCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(Aplatformer3d_cppCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API Aplatformer3d_cppCharacter(Aplatformer3d_cppCharacter&&); \
	NO_API Aplatformer3d_cppCharacter(const Aplatformer3d_cppCharacter&); \
public:


#define platformer3d_cpp_Source_platformer3d_cpp_platformer3d_cppCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API Aplatformer3d_cppCharacter(Aplatformer3d_cppCharacter&&); \
	NO_API Aplatformer3d_cppCharacter(const Aplatformer3d_cppCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, Aplatformer3d_cppCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(Aplatformer3d_cppCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(Aplatformer3d_cppCharacter)


#define platformer3d_cpp_Source_platformer3d_cpp_platformer3d_cppCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(Aplatformer3d_cppCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(Aplatformer3d_cppCharacter, FollowCamera); } \
	FORCEINLINE static uint32 __PPO__CanMove() { return STRUCT_OFFSET(Aplatformer3d_cppCharacter, CanMove); } \
	FORCEINLINE static uint32 __PPO__CanClimbUpLedge() { return STRUCT_OFFSET(Aplatformer3d_cppCharacter, CanClimbUpLedge); } \
	FORCEINLINE static uint32 __PPO__CanGrabLedge() { return STRUCT_OFFSET(Aplatformer3d_cppCharacter, CanGrabLedge); } \
	FORCEINLINE static uint32 __PPO__IsHanging() { return STRUCT_OFFSET(Aplatformer3d_cppCharacter, IsHanging); } \
	FORCEINLINE static uint32 __PPO__LedgeTargetRelativeLocation() { return STRUCT_OFFSET(Aplatformer3d_cppCharacter, LedgeTargetRelativeLocation); } \
	FORCEINLINE static uint32 __PPO__LedgeTargetRelativeRotation() { return STRUCT_OFFSET(Aplatformer3d_cppCharacter, LedgeTargetRelativeRotation); }


#define platformer3d_cpp_Source_platformer3d_cpp_platformer3d_cppCharacter_h_9_PROLOG \
	platformer3d_cpp_Source_platformer3d_cpp_platformer3d_cppCharacter_h_12_EVENT_PARMS


#define platformer3d_cpp_Source_platformer3d_cpp_platformer3d_cppCharacter_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	platformer3d_cpp_Source_platformer3d_cpp_platformer3d_cppCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	platformer3d_cpp_Source_platformer3d_cpp_platformer3d_cppCharacter_h_12_SPARSE_DATA \
	platformer3d_cpp_Source_platformer3d_cpp_platformer3d_cppCharacter_h_12_RPC_WRAPPERS \
	platformer3d_cpp_Source_platformer3d_cpp_platformer3d_cppCharacter_h_12_CALLBACK_WRAPPERS \
	platformer3d_cpp_Source_platformer3d_cpp_platformer3d_cppCharacter_h_12_INCLASS \
	platformer3d_cpp_Source_platformer3d_cpp_platformer3d_cppCharacter_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define platformer3d_cpp_Source_platformer3d_cpp_platformer3d_cppCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	platformer3d_cpp_Source_platformer3d_cpp_platformer3d_cppCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	platformer3d_cpp_Source_platformer3d_cpp_platformer3d_cppCharacter_h_12_SPARSE_DATA \
	platformer3d_cpp_Source_platformer3d_cpp_platformer3d_cppCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	platformer3d_cpp_Source_platformer3d_cpp_platformer3d_cppCharacter_h_12_CALLBACK_WRAPPERS \
	platformer3d_cpp_Source_platformer3d_cpp_platformer3d_cppCharacter_h_12_INCLASS_NO_PURE_DECLS \
	platformer3d_cpp_Source_platformer3d_cpp_platformer3d_cppCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PLATFORMER3D_CPP_API UClass* StaticClass<class Aplatformer3d_cppCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID platformer3d_cpp_Source_platformer3d_cpp_platformer3d_cppCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
