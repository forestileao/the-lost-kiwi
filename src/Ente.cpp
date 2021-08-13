//
// Created by forestileao on 12/08/2021.
//

#include "Ente.h"
Ente::Ente(Managers::GraphicManager *pGraphic):
    pGraphicManager(pGraphic)
{

}

Ente::~Ente()
{
    pGraphicManager = nullptr;
}
