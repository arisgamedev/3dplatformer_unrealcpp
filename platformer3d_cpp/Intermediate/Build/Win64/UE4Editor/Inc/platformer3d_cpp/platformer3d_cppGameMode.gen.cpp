// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "platformer3d_cpp/platformer3d_cppGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeplatformer3d_cppGameMode() {}
// Cross Module References
	PLATFORMER3D_CPP_API UClass* Z_Construct_UClass_Aplatformer3d_cppGameMode_NoRegister();
	PLATFORMER3D_CPP_API UClass* Z_Construct_UClass_Aplatformer3d_cppGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_platformer3d_cpp();
// End Cross Module References
	void Aplatformer3d_cppGameMode::StaticRegisterNativesAplatformer3d_cppGameMode()
	{
	}
	UClass* Z_Construct_UClass_Aplatformer3d_cppGameMode_NoRegister()
	{
		return Aplatformer3d_cppGameMode::StaticClass();
	}
	struct Z_Construct_UClass_Aplatformer3d_cppGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_Aplatformer3d_cppGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_platformer3d_cpp,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Aplatformer3d_cppGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "platformer3d_cppGameMode.h" },
		{ "ModuleRelativePath", "platformer3d_cppGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_Aplatformer3d_cppGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<Aplatformer3d_cppGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_Aplatformer3d_cppGameMode_Statics::ClassParams = {
		&Aplatformer3d_cppGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_Aplatformer3d_cppGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_Aplatformer3d_cppGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_Aplatformer3d_cppGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_Aplatformer3d_cppGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(Aplatformer3d_cppGameMode, 346858314);
	template<> PLATFORMER3D_CPP_API UClass* StaticClass<Aplatformer3d_cppGameMode>()
	{
		return Aplatformer3d_cppGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_Aplatformer3d_cppGameMode(Z_Construct_UClass_Aplatformer3d_cppGameMode, &Aplatformer3d_cppGameMode::StaticClass, TEXT("/Script/platformer3d_cpp"), TEXT("Aplatformer3d_cppGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(Aplatformer3d_cppGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
