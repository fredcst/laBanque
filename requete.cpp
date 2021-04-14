#include "requete.h"

int Requete::getVille() const
{
    return ville;
}

void Requete::setVille(int value)
{
    ville = value;
}

int Requete::getCanal() const
{
    return canal;
}

void Requete::setCanal(int value)
{
    canal = value;
}

int Requete::getFamille() const
{
    return famille;
}

void Requete::setFamille(int value)
{
    famille = value;
}


int Requete::getProduit() const
{
    return produit;
}

void Requete::setProduit(int value)
{
    produit = value;
}

int Requete::getTotal_ventes() const
{
    return total_ventes;
}

void Requete::setTotal_ventes(int value)
{
    total_ventes = value;
}

Requete::Requete(int a, int b, int c, int d, int e)
{
    ville=a;
    canal=b;
    famille=c;
    produit=d;
    total_ventes=e;
}
