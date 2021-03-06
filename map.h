#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include <json/json.h>
#include "declaration.h"
#include "base.h"

class Map{
public:
    typedef std::vector<BlockType::BlockType *> BlockArray;
    BlockArray blockTypes;

    int size;
    int bsize;
    std::vector<int> blocks;
    int version;
    bool updateVersion;

    double dt;
    int ticks;

    bool fixEntrance;
    vec4double initpos;
    vec4double camerapos;

    Map();
    ~Map();

    int get(int x, int y, int z, int w);
    int get(vec4int v){return get(v.x, v.y, v.z, v.w);}
    BlockType::BlockType * getBlockType(int x, int y, int z, int w){return blockTypes[get(x, y, z, w)];}
    void set(int block, int x, int y, int z, int w);
    void set(int block, vec4int v){set(block, v.x, v.y, v.z, v.w);}
    void clear();
    void fill(int block, int x1, int x2, int y1, int y2, int z1, int z2, int w1, int w2);

    Json::Value toJson();
    void fromJson(Json::Value json);
    void load(const std::string & filename);
    void save(const std::string & filename);

    void update();
    void render(Player * player, Renderer * ren);
    void addBlockType(BlockType::BlockType * blocktype);
    void initBlockTypes();
    void clearBlockTypes();
};

#endif
