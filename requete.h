#ifndef REQUETE_H
#define REQUETE_H


class Requete
{
    int ville;
    int canal;
    int famille;
    int produit;
    int total_ventes;

public:
    Requete(int ville, int canal, int famille, int produit, int total_ventes);
    int getVille() const;
    void setVille(int value);
    int getCanal() const;
    void setCanal(int value);
    int getFamille() const;
    void setFamille(int value);
    int getProduit() const;
    void setProduit(int value);
    int getTotal_ventes() const;
    void setTotal_ventes(int value);
};

#endif // REQUETE_H
