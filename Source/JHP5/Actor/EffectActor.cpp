// Fill out your copyright notice in the Description page of Project Settings.


#include "EffectActor.h"

#include <AbilitySystemBlueprintLibrary.h>
#include <AbilitySystemComponent.h>

AEffectActor::AEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}


void AEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void AEffectActor::ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target);
	if (TargetASC == nullptr) return;

	// 1. ABS ����� �����
	// 2. ������ ABS�� EffectContext �����
	// 3. �ҽ� ��ü �߰� �Լ� ȣ��
	// 4. 

	check(GameplayEffectClass);
	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	// �������� �������� GC�� �Ȱɸ�
	EffectContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, 1.f, EffectContextHandle);
	TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
}
