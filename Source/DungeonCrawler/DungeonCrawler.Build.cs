// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DungeonCrawler : ModuleRules
{
	public DungeonCrawler(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"DungeonCrawler",
			"DungeonCrawler/Variant_Platforming",
			"DungeonCrawler/Variant_Platforming/Animation",
			"DungeonCrawler/Variant_Combat",
			"DungeonCrawler/Variant_Combat/AI",
			"DungeonCrawler/Variant_Combat/Animation",
			"DungeonCrawler/Variant_Combat/Gameplay",
			"DungeonCrawler/Variant_Combat/Interfaces",
			"DungeonCrawler/Variant_Combat/UI",
			"DungeonCrawler/Variant_SideScrolling",
			"DungeonCrawler/Variant_SideScrolling/AI",
			"DungeonCrawler/Variant_SideScrolling/Gameplay",
			"DungeonCrawler/Variant_SideScrolling/Interfaces",
			"DungeonCrawler/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
