// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

UCLASS()
class TPS_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Fire();


	virtual float TakeDamage(float DamageAmount,struct FDamageEvent const& DamageEvent,	class AController* EventInstigator,	AActor* DamageCauser) override;

	UFUNCTION(BlueprintPure)
		bool IsDead() const;

	UFUNCTION(BlueprintPure)
		float GetHealthPercent() const;

private:


	void MoveForwardBackward(float axisvalue);

	void MoveLeftRight(float axisvalue);

	void LookUpDown(float axisvalue);

	void LookRightLeft(float axisvalue);

	

	void Teleport();


	float Range;

	float ImpulseAmount;

/*	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class AGun> GunClassReference;

	UPROPERTY()
		class AGun* Gun;*/

	UPROPERTY(EditAnywhere)

		UParticleSystem* MuzzleFlash;

	UPROPERTY(EditAnywhere)

		UParticleSystem* ImpactEffect;

	UPROPERTY(EditAnywhere)

		UParticleSystem* TeleportEffect;

	UPROPERTY(EditAnywhere)

		USoundWave* MuzzleSound;


	UPROPERTY(EditAnywhere)
		float DamageApplied;

	UPROPERTY(EditDefaultsOnly)
		float MaxHealth;

	UPROPERTY(VisibleAnywhere)
		float Health;





};
