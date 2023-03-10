// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "platformer3d_cpp/platformer3d_cppCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeplatformer3d_cppCharacter() {}
// Cross Module References
	PLATFORMER3D_CPP_API UClass* Z_Construct_UClass_Aplatformer3d_cppCharacter_NoRegister();
	PLATFORMER3D_CPP_API UClass* Z_Construct_UClass_Aplatformer3d_cppCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_platformer3d_cpp();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
// End Cross Module References
	DEFINE_FUNCTION(Aplatformer3d_cppCharacter::execOnSphereTracerOverlapEnd)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp);
		P_GET_OBJECT(AActor,Z_Param_OtherActor);
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
		P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnSphereTracerOverlapEnd(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(Aplatformer3d_cppCharacter::execOnSphereTracerOverlapBegin)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp);
		P_GET_OBJECT(AActor,Z_Param_OtherActor);
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
		P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
		P_GET_UBOOL(Z_Param_bFromSweep);
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnSphereTracerOverlapBegin(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(Aplatformer3d_cppCharacter::execForceStopMovementImmediately)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ForceStopMovementImmediately();
		P_NATIVE_END;
	}
	static FName NAME_Aplatformer3d_cppCharacter_BpClimbOverRailing = FName(TEXT("BpClimbOverRailing"));
	void Aplatformer3d_cppCharacter::BpClimbOverRailing()
	{
		ProcessEvent(FindFunctionChecked(NAME_Aplatformer3d_cppCharacter_BpClimbOverRailing),NULL);
	}
	static FName NAME_Aplatformer3d_cppCharacter_BpClimbUpLedge = FName(TEXT("BpClimbUpLedge"));
	void Aplatformer3d_cppCharacter::BpClimbUpLedge()
	{
		ProcessEvent(FindFunctionChecked(NAME_Aplatformer3d_cppCharacter_BpClimbUpLedge),NULL);
	}
	static FName NAME_Aplatformer3d_cppCharacter_BpHangFromLedge = FName(TEXT("BpHangFromLedge"));
	void Aplatformer3d_cppCharacter::BpHangFromLedge()
	{
		ProcessEvent(FindFunctionChecked(NAME_Aplatformer3d_cppCharacter_BpHangFromLedge),NULL);
	}
	static FName NAME_Aplatformer3d_cppCharacter_BpLedgeLateralMovement = FName(TEXT("BpLedgeLateralMovement"));
	void Aplatformer3d_cppCharacter::BpLedgeLateralMovement(float bpvalue)
	{
		platformer3d_cppCharacter_eventBpLedgeLateralMovement_Parms Parms;
		Parms.bpvalue=bpvalue;
		ProcessEvent(FindFunctionChecked(NAME_Aplatformer3d_cppCharacter_BpLedgeLateralMovement),&Parms);
	}
	static FName NAME_Aplatformer3d_cppCharacter_BpMoveToLedge = FName(TEXT("BpMoveToLedge"));
	void Aplatformer3d_cppCharacter::BpMoveToLedge()
	{
		ProcessEvent(FindFunctionChecked(NAME_Aplatformer3d_cppCharacter_BpMoveToLedge),NULL);
	}
	void Aplatformer3d_cppCharacter::StaticRegisterNativesAplatformer3d_cppCharacter()
	{
		UClass* Class = Aplatformer3d_cppCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ForceStopMovementImmediately", &Aplatformer3d_cppCharacter::execForceStopMovementImmediately },
			{ "OnSphereTracerOverlapBegin", &Aplatformer3d_cppCharacter::execOnSphereTracerOverlapBegin },
			{ "OnSphereTracerOverlapEnd", &Aplatformer3d_cppCharacter::execOnSphereTracerOverlapEnd },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpClimbOverRailing_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpClimbOverRailing_Statics::Function_MetaDataParams[] = {
		{ "Category", "Platforming" },
		{ "ModuleRelativePath", "platformer3d_cppCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpClimbOverRailing_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_Aplatformer3d_cppCharacter, nullptr, "BpClimbOverRailing", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpClimbOverRailing_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpClimbOverRailing_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpClimbOverRailing()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpClimbOverRailing_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpClimbUpLedge_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpClimbUpLedge_Statics::Function_MetaDataParams[] = {
		{ "Category", "Platforming" },
		{ "ModuleRelativePath", "platformer3d_cppCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpClimbUpLedge_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_Aplatformer3d_cppCharacter, nullptr, "BpClimbUpLedge", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpClimbUpLedge_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpClimbUpLedge_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpClimbUpLedge()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpClimbUpLedge_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpHangFromLedge_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpHangFromLedge_Statics::Function_MetaDataParams[] = {
		{ "Category", "Platforming" },
		{ "Comment", "//Align character to ledge during ledge transversal\n" },
		{ "ModuleRelativePath", "platformer3d_cppCharacter.h" },
		{ "ToolTip", "Align character to ledge during ledge transversal" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpHangFromLedge_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_Aplatformer3d_cppCharacter, nullptr, "BpHangFromLedge", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpHangFromLedge_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpHangFromLedge_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpHangFromLedge()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpHangFromLedge_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpLedgeLateralMovement_Statics
	{
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_bpvalue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpLedgeLateralMovement_Statics::NewProp_bpvalue = { "bpvalue", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(platformer3d_cppCharacter_eventBpLedgeLateralMovement_Parms, bpvalue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpLedgeLateralMovement_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpLedgeLateralMovement_Statics::NewProp_bpvalue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpLedgeLateralMovement_Statics::Function_MetaDataParams[] = {
		{ "Category", "Platforming" },
		{ "Comment", "//Perform ledge lateral movement Anim Montages (does root motion)\n" },
		{ "ModuleRelativePath", "platformer3d_cppCharacter.h" },
		{ "ToolTip", "Perform ledge lateral movement Anim Montages (does root motion)" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpLedgeLateralMovement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_Aplatformer3d_cppCharacter, nullptr, "BpLedgeLateralMovement", nullptr, nullptr, sizeof(platformer3d_cppCharacter_eventBpLedgeLateralMovement_Parms), Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpLedgeLateralMovement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpLedgeLateralMovement_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpLedgeLateralMovement_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpLedgeLateralMovement_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpLedgeLateralMovement()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpLedgeLateralMovement_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpMoveToLedge_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpMoveToLedge_Statics::Function_MetaDataParams[] = {
		{ "Category", "Platforming" },
		{ "Comment", "/*BLUEPRINT IMPLEMENTABLE FUNCTIONS*///Move character to ledge after ledge detection\n" },
		{ "ModuleRelativePath", "platformer3d_cppCharacter.h" },
		{ "ToolTip", "BLUEPRINT IMPLEMENTABLE FUNCTIONS//Move character to ledge after ledge detection" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpMoveToLedge_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_Aplatformer3d_cppCharacter, nullptr, "BpMoveToLedge", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpMoveToLedge_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpMoveToLedge_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpMoveToLedge()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpMoveToLedge_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_Aplatformer3d_cppCharacter_ForceStopMovementImmediately_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_Aplatformer3d_cppCharacter_ForceStopMovementImmediately_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/** Called to stop movement completely *///para que sea llamada desde FName\n" },
		{ "ModuleRelativePath", "platformer3d_cppCharacter.h" },
		{ "ToolTip", "Called to stop movement completely //para que sea llamada desde FName" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_Aplatformer3d_cppCharacter_ForceStopMovementImmediately_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_Aplatformer3d_cppCharacter, nullptr, "ForceStopMovementImmediately", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_Aplatformer3d_cppCharacter_ForceStopMovementImmediately_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_Aplatformer3d_cppCharacter_ForceStopMovementImmediately_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_Aplatformer3d_cppCharacter_ForceStopMovementImmediately()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_Aplatformer3d_cppCharacter_ForceStopMovementImmediately_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics
	{
		struct platformer3d_cppCharacter_eventOnSphereTracerOverlapBegin_Parms
		{
			UPrimitiveComponent* OverlappedComp;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			int32 OtherBodyIndex;
			bool bFromSweep;
			FHitResult SweepResult;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OverlappedComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OverlappedComp;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
		static void NewProp_bFromSweep_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SweepResult;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::NewProp_OverlappedComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::NewProp_OverlappedComp = { "OverlappedComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(platformer3d_cppCharacter_eventOnSphereTracerOverlapBegin_Parms, OverlappedComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::NewProp_OverlappedComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::NewProp_OverlappedComp_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(platformer3d_cppCharacter_eventOnSphereTracerOverlapBegin_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(platformer3d_cppCharacter_eventOnSphereTracerOverlapBegin_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::NewProp_OtherComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::NewProp_OtherComp_MetaData)) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(platformer3d_cppCharacter_eventOnSphereTracerOverlapBegin_Parms, OtherBodyIndex), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::NewProp_bFromSweep_SetBit(void* Obj)
	{
		((platformer3d_cppCharacter_eventOnSphereTracerOverlapBegin_Parms*)Obj)->bFromSweep = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(platformer3d_cppCharacter_eventOnSphereTracerOverlapBegin_Parms), &Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(platformer3d_cppCharacter_eventOnSphereTracerOverlapBegin_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::NewProp_SweepResult_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::NewProp_SweepResult_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::NewProp_OverlappedComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::NewProp_OtherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::NewProp_OtherComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::NewProp_OtherBodyIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::NewProp_bFromSweep,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::NewProp_SweepResult,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*SPHERE TRACER TO CHECK IF WE PERFORM THE OTHER TRACES AND STUFF*///spheretracer functions\x09\n" },
		{ "ModuleRelativePath", "platformer3d_cppCharacter.h" },
		{ "ToolTip", "SPHERE TRACER TO CHECK IF WE PERFORM THE OTHER TRACES AND STUFF//spheretracer functions" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_Aplatformer3d_cppCharacter, nullptr, "OnSphereTracerOverlapBegin", nullptr, nullptr, sizeof(platformer3d_cppCharacter_eventOnSphereTracerOverlapBegin_Parms), Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapEnd_Statics
	{
		struct platformer3d_cppCharacter_eventOnSphereTracerOverlapEnd_Parms
		{
			UPrimitiveComponent* OverlappedComp;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			int32 OtherBodyIndex;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OverlappedComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OverlappedComp;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapEnd_Statics::NewProp_OverlappedComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapEnd_Statics::NewProp_OverlappedComp = { "OverlappedComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(platformer3d_cppCharacter_eventOnSphereTracerOverlapEnd_Parms, OverlappedComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapEnd_Statics::NewProp_OverlappedComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapEnd_Statics::NewProp_OverlappedComp_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapEnd_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(platformer3d_cppCharacter_eventOnSphereTracerOverlapEnd_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapEnd_Statics::NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapEnd_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(platformer3d_cppCharacter_eventOnSphereTracerOverlapEnd_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapEnd_Statics::NewProp_OtherComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapEnd_Statics::NewProp_OtherComp_MetaData)) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapEnd_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(platformer3d_cppCharacter_eventOnSphereTracerOverlapEnd_Parms, OtherBodyIndex), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapEnd_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapEnd_Statics::NewProp_OverlappedComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapEnd_Statics::NewProp_OtherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapEnd_Statics::NewProp_OtherComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapEnd_Statics::NewProp_OtherBodyIndex,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapEnd_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "platformer3d_cppCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapEnd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_Aplatformer3d_cppCharacter, nullptr, "OnSphereTracerOverlapEnd", nullptr, nullptr, sizeof(platformer3d_cppCharacter_eventOnSphereTracerOverlapEnd_Parms), Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapEnd_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapEnd_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapEnd_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapEnd_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapEnd()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapEnd_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_Aplatformer3d_cppCharacter_NoRegister()
	{
		return Aplatformer3d_cppCharacter::StaticClass();
	}
	struct Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseTurnRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BaseTurnRate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseLookUpRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BaseLookUpRate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SphereTracer_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SphereTracer;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CanMove_MetaData[];
#endif
		static void NewProp_CanMove_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_CanMove;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CanClimbUpLedge_MetaData[];
#endif
		static void NewProp_CanClimbUpLedge_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_CanClimbUpLedge;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CanGrabLedge_MetaData[];
#endif
		static void NewProp_CanGrabLedge_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_CanGrabLedge;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsHanging_MetaData[];
#endif
		static void NewProp_IsHanging_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsHanging;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LedgeTargetRelativeLocation_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_LedgeTargetRelativeLocation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LedgeTargetRelativeRotation_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_LedgeTargetRelativeRotation;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_platformer3d_cpp,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpClimbOverRailing, "BpClimbOverRailing" }, // 3940895656
		{ &Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpClimbUpLedge, "BpClimbUpLedge" }, // 4069514943
		{ &Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpHangFromLedge, "BpHangFromLedge" }, // 3532231663
		{ &Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpLedgeLateralMovement, "BpLedgeLateralMovement" }, // 279443968
		{ &Z_Construct_UFunction_Aplatformer3d_cppCharacter_BpMoveToLedge, "BpMoveToLedge" }, // 4175395582
		{ &Z_Construct_UFunction_Aplatformer3d_cppCharacter_ForceStopMovementImmediately, "ForceStopMovementImmediately" }, // 3001227378
		{ &Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapBegin, "OnSphereTracerOverlapBegin" }, // 1328378053
		{ &Z_Construct_UFunction_Aplatformer3d_cppCharacter_OnSphereTracerOverlapEnd, "OnSphereTracerOverlapEnd" }, // 2915238670
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "platformer3d_cppCharacter.h" },
		{ "ModuleRelativePath", "platformer3d_cppCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Camera boom positioning the camera behind the character */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "platformer3d_cppCharacter.h" },
		{ "ToolTip", "Camera boom positioning the camera behind the character" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Aplatformer3d_cppCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_CameraBoom_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_CameraBoom_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_FollowCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Follow camera */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "platformer3d_cppCharacter.h" },
		{ "ToolTip", "Follow camera" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Aplatformer3d_cppCharacter, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_FollowCamera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_FollowCamera_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_BaseTurnRate_MetaData[] = {
		{ "Category", "Camera" },
		{ "Comment", "/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */" },
		{ "ModuleRelativePath", "platformer3d_cppCharacter.h" },
		{ "ToolTip", "Base turn rate, in deg/sec. Other scaling may affect final turn rate." },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_BaseTurnRate = { "BaseTurnRate", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Aplatformer3d_cppCharacter, BaseTurnRate), METADATA_PARAMS(Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_BaseTurnRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_BaseTurnRate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_BaseLookUpRate_MetaData[] = {
		{ "Category", "Camera" },
		{ "Comment", "/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */" },
		{ "ModuleRelativePath", "platformer3d_cppCharacter.h" },
		{ "ToolTip", "Base look up/down rate, in deg/sec. Other scaling may affect final rate." },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_BaseLookUpRate = { "BaseLookUpRate", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Aplatformer3d_cppCharacter, BaseLookUpRate), METADATA_PARAMS(Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_BaseLookUpRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_BaseLookUpRate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_SphereTracer_MetaData[] = {
		{ "Category", "Components" },
		{ "Comment", "//add sphere tracer\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "platformer3d_cppCharacter.h" },
		{ "ToolTip", "add sphere tracer" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_SphereTracer = { "SphereTracer", nullptr, (EPropertyFlags)0x001000000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Aplatformer3d_cppCharacter, SphereTracer), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_SphereTracer_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_SphereTracer_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_CanMove_MetaData[] = {
		{ "Category", "CharVariables" },
		{ "Comment", "/*BLUEPRINT IMPLEMENTABLE VARIABLES*/" },
		{ "ModuleRelativePath", "platformer3d_cppCharacter.h" },
		{ "ToolTip", "BLUEPRINT IMPLEMENTABLE VARIABLES" },
	};
#endif
	void Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_CanMove_SetBit(void* Obj)
	{
		((Aplatformer3d_cppCharacter*)Obj)->CanMove = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_CanMove = { "CanMove", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(Aplatformer3d_cppCharacter), &Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_CanMove_SetBit, METADATA_PARAMS(Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_CanMove_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_CanMove_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_CanClimbUpLedge_MetaData[] = {
		{ "Category", "CharVariables" },
		{ "ModuleRelativePath", "platformer3d_cppCharacter.h" },
	};
#endif
	void Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_CanClimbUpLedge_SetBit(void* Obj)
	{
		((Aplatformer3d_cppCharacter*)Obj)->CanClimbUpLedge = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_CanClimbUpLedge = { "CanClimbUpLedge", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(Aplatformer3d_cppCharacter), &Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_CanClimbUpLedge_SetBit, METADATA_PARAMS(Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_CanClimbUpLedge_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_CanClimbUpLedge_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_CanGrabLedge_MetaData[] = {
		{ "Category", "CharVariables" },
		{ "ModuleRelativePath", "platformer3d_cppCharacter.h" },
	};
#endif
	void Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_CanGrabLedge_SetBit(void* Obj)
	{
		((Aplatformer3d_cppCharacter*)Obj)->CanGrabLedge = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_CanGrabLedge = { "CanGrabLedge", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(Aplatformer3d_cppCharacter), &Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_CanGrabLedge_SetBit, METADATA_PARAMS(Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_CanGrabLedge_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_CanGrabLedge_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_IsHanging_MetaData[] = {
		{ "Category", "CharVariables" },
		{ "ModuleRelativePath", "platformer3d_cppCharacter.h" },
	};
#endif
	void Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_IsHanging_SetBit(void* Obj)
	{
		((Aplatformer3d_cppCharacter*)Obj)->IsHanging = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_IsHanging = { "IsHanging", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(Aplatformer3d_cppCharacter), &Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_IsHanging_SetBit, METADATA_PARAMS(Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_IsHanging_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_IsHanging_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_LedgeTargetRelativeLocation_MetaData[] = {
		{ "Category", "CharVariables" },
		{ "ModuleRelativePath", "platformer3d_cppCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_LedgeTargetRelativeLocation = { "LedgeTargetRelativeLocation", nullptr, (EPropertyFlags)0x0020080000020015, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Aplatformer3d_cppCharacter, LedgeTargetRelativeLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_LedgeTargetRelativeLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_LedgeTargetRelativeLocation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_LedgeTargetRelativeRotation_MetaData[] = {
		{ "Category", "CharVariables" },
		{ "ModuleRelativePath", "platformer3d_cppCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_LedgeTargetRelativeRotation = { "LedgeTargetRelativeRotation", nullptr, (EPropertyFlags)0x0020080000020015, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Aplatformer3d_cppCharacter, LedgeTargetRelativeRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_LedgeTargetRelativeRotation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_LedgeTargetRelativeRotation_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_CameraBoom,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_FollowCamera,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_BaseTurnRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_BaseLookUpRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_SphereTracer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_CanMove,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_CanClimbUpLedge,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_CanGrabLedge,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_IsHanging,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_LedgeTargetRelativeLocation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::NewProp_LedgeTargetRelativeRotation,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<Aplatformer3d_cppCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::ClassParams = {
		&Aplatformer3d_cppCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_Aplatformer3d_cppCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_Aplatformer3d_cppCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(Aplatformer3d_cppCharacter, 2324131641);
	template<> PLATFORMER3D_CPP_API UClass* StaticClass<Aplatformer3d_cppCharacter>()
	{
		return Aplatformer3d_cppCharacter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_Aplatformer3d_cppCharacter(Z_Construct_UClass_Aplatformer3d_cppCharacter, &Aplatformer3d_cppCharacter::StaticClass, TEXT("/Script/platformer3d_cpp"), TEXT("Aplatformer3d_cppCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(Aplatformer3d_cppCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
