// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PoolActor.h"
#include "ActorPoolProjectile.generated.h"

UCLASS(config=Game)
class AActorPoolProjectile : public APoolActor
{
	GENERATED_BODY()

	virtual void OnActivated() override;

	UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
	class USphereComponent* CollisionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	class UProjectileMovementComponent* ProjectileMovement;

public:
	AActorPoolProjectile();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	FORCEINLINE class USphereComponent* GetCollisionComp() const { return CollisionComp; }
	FORCEINLINE class UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }
};

