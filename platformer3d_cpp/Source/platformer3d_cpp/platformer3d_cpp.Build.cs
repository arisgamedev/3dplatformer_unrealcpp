// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class platformer3d_cpp : ModuleRules
{
	public platformer3d_cpp(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
