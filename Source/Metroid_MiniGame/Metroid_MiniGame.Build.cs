// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Metroid_MiniGame : ModuleRules
{
	public Metroid_MiniGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput","GameplayTasks" });
	}
}
