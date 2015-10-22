#ifndef PION_H
#define PION_H

#define VIDE -1
#define ROI 0
#define SOLDATS 1
#define MOSCOVITES 2

class Pion
{
    public:
        Pion(int typePion):type(typePion){};
        virtual ~Pion();
        void afficher() const;
    protected:
    private:
        int type;
};

#endif // PION_H
