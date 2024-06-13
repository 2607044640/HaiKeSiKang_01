


#include "ATestBoxActor.h"


AATestBoxActor::AATestBoxActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AATestBoxActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AATestBoxActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

