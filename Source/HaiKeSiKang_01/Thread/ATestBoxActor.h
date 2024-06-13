#pragma once

#include "CoreMinimal.h"
#include <GameFramework/Actor.h>
#include "ATestBoxActor.generated.h"

UCLASS()
class HAIKESIKANG_01_API AATestBoxActor : public AActor
{
	GENERATED_BODY()

public:
	AATestBoxActor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Setting)
	UStaticMeshComponent StaticMeshComponent;
};
