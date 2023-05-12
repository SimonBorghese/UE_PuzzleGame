// Copyright Epic Games, Inc. All Rights Reserved.


#include "SCPGameGameModeBase.h"

#include "FPSPlayer.h"

ASCPGameGameModeBase::ASCPGameGameModeBase()
{
	auto Player = CreateDefaultSubobject<AFPSPlayer>(TEXT("Player"));
	DefaultPawnClass = Player->GetClass();
}
