// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "ShooterCharacter.h"







void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();

	//APawn* PlayerCharacter = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	GetWorld()->GetTimerManager().SetTimer(TimerHandle,this,&AShooterAIController::AIActivate,1.0f,true);
	

}

void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

void AShooterAIController::AIActivate()
{
	APawn* PlayerCharacter = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);


	if (this->LineOfSightTo(PlayerCharacter))
	{


		this->SetFocus(PlayerCharacter);//Default priority is gameplay
		this->MoveToActor(PlayerCharacter, 200);

		AShooterCharacter* P = Cast<AShooterCharacter>(GetPawn());

		if (P != nullptr )
		{

			if (P->IsDead())
			{
				GetWorld()->GetTimerManager().PauseTimer(TimerHandle);
				this->ClearFocus(EAIFocusPriority::Gameplay);
				this->StopMovement();
			}
			else
			{
				P->Fire();
			}
			
		}


	}

	else
	{
		this->ClearFocus(EAIFocusPriority::Gameplay);

		this->StopMovement();
	}
}
