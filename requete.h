#ifndef REQUETE_H
#define REQUETE_H


class Requete
{
    int ville;
    int canal_bancaire;
    int canal_assurance;
    int canal_boursier;
    int id_produit;
    int total_ventes;

public:
    Requete(int a, int b, int c, int d, int e, int f);
    int getVille() const;
    void setVille(int value);
    int getCanal_bancaire() const;
    void setCanal_bancaire(int value);
    int getCanal_assurance() const;
    void setCanal_assurance(int value);
    int getCanal_boursier() const;
    void setCanal_boursier(int value);
    int getId_produit() const;
    void setId_produit(int value);
    int getTotal_ventes() const;
    void setTotal_ventes(int value);
};

#endif // REQUETE_H
