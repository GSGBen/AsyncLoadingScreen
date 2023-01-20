/************************************************************************************
 *																					*
 * Copyright (C) 2020 Truong Bui.													*
 * Website:	https://github.com/truong-bui/AsyncLoadingScreen						*
 * Licensed under the MIT License. See 'LICENSE' file for full license information. *
 *																					*
 ************************************************************************************/


#include "AsyncLoadingScreenLibrary.h"
#include "MoviePlayer.h"
#include "LoadingScreenSettings.h"
#include "AsyncLoadingScreen.h"

int32 UAsyncLoadingScreenLibrary::DisplayBackgroundIndex = -1;
int32 UAsyncLoadingScreenLibrary::DisplayTipTextIndex = -1;
int32 UAsyncLoadingScreenLibrary::DisplayMovieIndex = -1;

void UAsyncLoadingScreenLibrary::SetDisplayBackgroundIndex(int32 BackgroundIndex)
{
	UAsyncLoadingScreenLibrary::DisplayBackgroundIndex = BackgroundIndex;
}

void UAsyncLoadingScreenLibrary::SetDisplayTipTextIndex(int32 TipTextIndex)
{
	UAsyncLoadingScreenLibrary::DisplayTipTextIndex = TipTextIndex;
}

void UAsyncLoadingScreenLibrary::SetDisplayMovieIndex(int32 MovieIndex)
{
	UAsyncLoadingScreenLibrary::DisplayMovieIndex = MovieIndex;	
}

void UAsyncLoadingScreenLibrary::SetupLoadingScreenForSeamlessTravel()
{
	const ULoadingScreenSettings* Settings = GetDefault<ULoadingScreenSettings>();

	// copy to modify
	FALoadingScreenSettings DefaultLoadingScreenCopy = Settings->DefaultLoadingScreen;
	DefaultLoadingScreenCopy.bAllowEngineTick = true;
	DefaultLoadingScreenCopy.bWaitForManualStop = true;

	FAsyncLoadingScreenModule::Get().SetupLoadingScreen(DefaultLoadingScreenCopy);
}

void UAsyncLoadingScreenLibrary::UnsetupLoadingScreenForSeamlessTravel()
{
	const ULoadingScreenSettings* Settings = GetDefault<ULoadingScreenSettings>();
	FAsyncLoadingScreenModule::Get().SetupLoadingScreen(Settings->DefaultLoadingScreen);
}

void UAsyncLoadingScreenLibrary::StopLoadingScreen()
{
	GetMoviePlayer()->StopMovie();
}
