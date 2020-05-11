#include <genesis.h>


int main()
{


    int counter = 1;
    const u32 tileA[8]=
    {
            0x00111100,
            0x01144110,
            0x11244211,
            0x11244211,
            0x11222211,
            0x11222211,
            0x01122110,
            0x00111100
    };
    const u32 tileB[8]=
    {
            0x00CCCC00,
            0x01144110,
            0x11244211,
            0x11244211,
            0x11222211,
            0x11222211,
            0x011EE110,
            0x001EE100
    };

    const u32 dinosaur[8] = {
            0xCCC22CCC,
            0xCCC22CCC,
            0xCCCCCCCC,
            0xCCCCCCCC,
            0xCCCCCCCC,
            0xCCCCCCCC,
            0xCC22CC22,
            0xCC22CC22
    };


//we load our unique tile data at position 1 on VRAM

    VDP_loadTileData( (const u32 *)tileA, 1, 1, CPU);
    VDP_loadTileData( (const u32 *)tileB, 2, 1, CPU);
    VDP_loadTileData( (const u32 *)dinosaur, 3, 1, CPU);


    VDP_setTileMapXY(PLAN_A, TILE_ATTR_FULL(PAL1, 1, 0, 0, 1), counter, counter + 5);
    VDP_setTileMapXY(PLAN_B, TILE_ATTR_FULL(PAL2, 0, 0, 0, 1), counter, counter + 5);
    VDP_setTileMapXY(PLAN_B, 2, counter+2, counter + 3);
    VDP_setTileMapXY(PLAN_A, TILE_ATTR_FULL(PAL1, 1, 0, 0, 2), counter, counter + 5);

    VDP_setTileMapXY(PLAN_B, TILE_ATTR_FULL(PAL0, 1, 0, 0, 3), counter, counter + 5); // 3 - dinosaur


	VDP_fillTileMapRect(PLAN_B, TILE_ATTR_FULL(PAL3, 0, 0, 0, 2), 12, 12, 8, 8);
	VDP_fillTileMapRect(PLAN_B, TILE_ATTR_FULL(PAL2, 0, 0, 0, 1), 20, 12, 8, 8);


    VDP_setBackgroundColor(12); // Grey background

    while(1)
    {
        counter+=1;
        // VDP_setHorizontalScroll(PLAN_B, -1 * counter);
        VDP_setVerticalScroll(PLAN_A, counter);
        VDP_waitVSync();
    }
    return 0;
    }
