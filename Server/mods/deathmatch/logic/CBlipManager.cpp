/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        mods/deathmatch/logic/CBlipManager.cpp
 *  PURPOSE:     Blip entity manager class
 *
 *  Multi Theft Auto is available from http://www.multitheftauto.com/
 *
 *****************************************************************************/

#include "StdInc.h"

CBlipManager::CBlipManager(void)
{
}

CBlip* CBlipManager::Create(CElement* pParent)
{
    CBlip* const pBlip = new CBlip(pParent, this);

    if (pBlip->GetID() == INVALID_ELEMENT_ID)
    {
        delete pBlip;
        return nullptr;
    }

    return pBlip;
}

CBlip* CBlipManager::CreateFromXML(CElement* pParent, CXMLNode& Node, CEvents* pEvents)
{
    CBlip* const pBlip = new CBlip(pParent, this);

    if (pBlip->GetID() == INVALID_ELEMENT_ID || !pBlip->LoadFromCustomData(pEvents, Node))
    {
        delete pBlip;
        return nullptr;
    }

    return pBlip;
}

void CBlipManager::DeleteAll(void)
{
    // Delete all our blips
    DeletePointersAndClearList(m_List);
}

bool CBlipManager::Exists(CBlip* pBlip)
{
    return ListContains(m_List, pBlip);
}
