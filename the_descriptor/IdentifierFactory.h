#pragma once

#include "CompKeyHolder.h"
#include "Identifier.h"
#include "CommunicationIdentifier.h"
#include "NumericalMeasureIdentifier.h"

template<unsigned KindValue, unsigned InstanceValue, int Group>
struct IdFact : CompKeyHolder<KindValue, InstanceValue>
{
    template<typename Id>
    struct ComId
    {
        static_assert(Group == Id::Group, "ID Keytype does not belong to this group.");

        static Core::CommunicationIdentifier get(typename Id::ComElemKeyType key)
        {
            return Core::CommunicationIdentifier(
                CompKeyHolder::getKey(),
                Group,
                key);
        }
    };

    template<typename Id>
    struct NumMeasId
    {
        static_assert(Group == Id::Group, "ID Keytype does not belong to this group.");

        static Core::NumericalMeasureIdentifier get(typename Id::NumMeasElemKeyType key)
        {
            return Core::NumericalMeasureIdentifier(
                CompKeyHolder::getKey(),
                Group,
                key);
        }
    };
};

template<typename Component, int Group>
struct Descriptor : IdFact<Component::Kind, Component::Instance, Group>
{};