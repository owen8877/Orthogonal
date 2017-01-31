#ifndef MAP_H
#define MAP_H

#include <string>

class Player;
class Renderer;

struct blocktype{
    int passable;
    int spritenum;
};

class Map{
public:
    const static struct blocktype blockTypes[];

    int size;
    int bsize;
    int * blocks;
    int version;

    Map(int _size);
    ~Map();

    void clear();
    int get(int x, int y, int z, int w);
    void set(int block, int x, int y, int z, int w);
    void load(const std::string & filename);
    void save(const std::string & filename);

    void fill(int block, int x1, int x2, int y1, int y2, int z1, int z2, int w1, int w2);

    void render(Player * player, Renderer * ren);
};

#endif
