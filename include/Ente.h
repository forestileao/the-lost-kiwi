//
// Created by forestileao on 12/08/2021.
//

#ifndef ENTE_H
#define ENTE_H


#include <Managers/GraphicManager.h>
class Ente
{
protected:
    Managers::GraphicManager* pGraphicManager;
public:
    Ente(Managers::GraphicManager* pGraphic);
    virtual ~Ente();

};


#endif //ENTE_H
