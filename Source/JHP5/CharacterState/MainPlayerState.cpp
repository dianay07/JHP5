#include "MainPlayerState.h"

#include "AbilitySystem/PPAbilitySystemComponent.h"
#include "AbilitySystem/PPAttributeSet.h"


AMainPlayerState::AMainPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UPPAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<UPPAttributeSet>("AttributeSet");

	/* ������ Ŭ���̾�Ʈ ������Ʈ�� �õ��ϴ� ��
	 �÷��̾� ���¿� ������ ����� ������Ʈ, ����ȭ �õ� */
	NetUpdateFrequency = 100.0f;
}

UAbilitySystemComponent* AMainPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
