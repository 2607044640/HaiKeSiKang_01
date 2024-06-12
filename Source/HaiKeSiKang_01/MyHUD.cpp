// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "Kismet/KismetMathLibrary.h"
void AMyHUD::ReadJsonFunc(FString JsonStr)
{

	//JsonStr 仓库数据
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(JsonStr);
	TArray<TSharedPtr<FJsonValue>> JsonValues;
	if (FJsonSerializer::Deserialize(JsonReader, JsonValues))
	{
		for (int i = 0; i < JsonValues.Num(); ++i)
		{
			if (JsonValues[i]->AsObject()->GetStringField("loadContainerCode") == TEXT(""))
			{
				/*FString TempLocationCodeStr = JsonValues[i]->AsObject()->GetStringField(TEXT("locationCode"));
				if (JsonMapLocationCodesMap.Contains(TempLocationCodeStr))
				{
					JsonMapLocationCodesMap[TempLocationCodeStr].JsonActorInfo->Destroy();
					JsonMapLocationCodesMap.Remove(TempLocationCodeStr);
				}*/
			}
			else
			{
				FVector TempLocation;
				TempLocation.X = JsonValues[i]->AsObject()->GetNumberField(TEXT("positionX")) * (-1);
				TempLocation.Y = JsonValues[i]->AsObject()->GetNumberField(TEXT("positionY"));
				TempLocation.Z = JsonValues[i]->AsObject()->GetNumberField(TEXT("positionZ"));
				//mm->cm
				TempLocation /= 10;
				TempLocation.X = UKismetMathLibrary::Round(TempLocation.X);
				TempLocation.Y = UKismetMathLibrary::Round(TempLocation.Y);
				TempLocation.Z = UKismetMathLibrary::Round(TempLocation.Z);

				FString TempLocationCodeStr = JsonValues[i]->AsObject()->GetStringField(TEXT("locationCode"));




				auto SpawnedActor = GetWorld()->SpawnActor<AActor>(
					ThisActor, TempLocation,
					FRotator::ZeroRotator);

				FName tag = FName(*JsonValues[i]->AsObject()->GetStringField("loadContainerCode"));
				//TCHAR_TO_UTF8(JsonValues[i]->AsObject()->GetStringField("loadContainerCode"));
				SpawnedActor->Tags.Add(tag);
				
				JsonMapLocationCodesMap.Add(TempLocationCodeStr, SpawnedActor);

			}
		}
	}
}

void AMyHUD::OutputData(FString& ContainerCode, AActor*& Actor)
{
	
}
