// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

USTRUCT()
struct FInfoOfJson
{
	GENERATED_BODY()
	FVector Location;
	FString parentContainerCode;
	FString locationTypeCode;
	UPROPERTY()
	AActor* JsonActorInfo;
};

/**
 * 
 */
UCLASS()
class HAIKESIKANG_01_API AMyHUD : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Setting)
	UClass* ThisActor;
	TArray<bool> bHasBaies;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Setting)
	TMap<FString, AActor*> JsonMapLocationCodesMap;
	float KeyLengthX;
	int32 GS_ThisTimeSearch = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Setting)
	float DrawScaleY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Setting)
	float DrawScaleX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Setting)
	bool bDrawAP = false;

	FString URL = TEXT("http://42.194.135.254:10098/ess-api/wms/locationQuery");

	UFUNCTION(BlueprintCallable, Category = "Utility")
	void ReadJsonFunc(FString JsonStr);

	//FVaRestCallDelegate VaRestCallDelegate;
};
