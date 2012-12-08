/********************************************************************
  Copyright Draegerwerk AG & Co. KGaA
  Generated by Rhapsody 7.5.1 
  Component:     Core 
  Configuration: ClearCase
  Model Element: Core::CommunicationIdentifier
  File Path:     ../../Core/Interface/Base/CommunicationIdentifier.h
*********************************************************************/

#ifndef Core_Interface_Base_CommunicationIdentifier_H
#define Core_Interface_Base_CommunicationIdentifier_H

//## class CommunicationIdentifier
#include "TypedIdentifier.h"
namespace Core {
    //## package Core::Interface::Base
    
    //## class CommunicationIdentifier
    // Type safe Identifier for communication stuff (e.g. message Identifiers).
    typedef TypedIdentifier<Identifier::CommunicationType> CommunicationIdentifier;
    
    //## package Core::Interface::Base
    
    //## class CommunicationIdentifier
}

#endif
