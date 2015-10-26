#ifndef PION_H
#define PION_H

#define VIDE -1
#define ROI 0
#define SOLDATS 1
#define MOSCOVITES 2

#define VERT 3
#define JAUNE 4

class Pion
{
    public:
        Pion(int typePion):type(typePion){};
        virtual ~Pion();
        void afficher() const;
        void modifPion(int i) { type = i; };
        bool estVide() const { return type == VIDE; };
        int getType() const { return type; };
    protected:
    private:
        int type;
};

#endif // PION_H
