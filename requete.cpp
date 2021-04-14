#include "requete.h"

int Requete::getVille() const
{
    return ville;
}

void Requete::setVille(int value)
{
    ville = value;
}

int Requete::getCanal_bancaire() const
{
    return canal_bancaire;
}

void Requete::setCanal_bancaire(int value)
{
    canal_bancaire = value;
}

int Requete::getCanal_assurance() const
{
    return canal_assurance;
}

void Requete::setCanal_assurance(int value)
{
    canal_assurance = value;
}

int Requete::getCanal_boursier() const
{
    return canal_boursier;
}

void Requete::setCanal_boursier(int value)
{
    canal_boursier = value;
}

int Requete::getId_produit() const
{
    return id_produit;
}

void Requete::setId_produit(int value)
{
    id_produit = value;
}

int Requete::getTotal_ventes() const
{
    return total_ventes;
}

void Requete::setTotal_ventes(int value)
{
    total_ventes = value;
}

Requete::Requete(int a, int b, int c, int d, int e, int f)
{
    ville=a;
    canal_bancaire=b;
    canal_assurance=c;
    canal_boursier=d;
    id_produit=e;
    total_ventes=f;
}
