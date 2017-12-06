//by MuhammadPawn
//RandomizeFloat by Londlem
#if !defined ANTIMAPPLUS_INC_
	#define ANTIMAPPLUS_INC_

    #define RandomizeFloat(%0) \
        ((!random(2) ? (-1) : (1)) * (random(%0) + (random(1001) * 0.001)))
    new antimapplusobject;
	stock hak_CreateObject(modelid, Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ, Float:DrawDistance = 0.0)
	{
		antimapplusobject = CreateObject(modelid, X+RandomizeFloat(10), Y+RandomizeFloat(10), Z+RandomizeFloat(10), rX+RandomizeFloat(10), rY+RandomizeFloat(10), rZ+RandomizeFloat(10), DrawDistance = 0.0);
		DestroyObject(antimapplusobject);
	    return CreateObject(modelid, Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ, Float:DrawDistance = 0.0);
	}
    #if !defined _streamer_included

	#if defined _ALS_CreateObject
	    #undef CreateObject
	#else
	    #define _ALS_CreateObject
	#endif
	#define CreateObject hak_CreateObject 

	#else 

    stock hak_CreateDynamicObject(modelid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = STREAMER_OBJECT_SD, Float:drawdistance = STREAMER_OBJECT_DD, STREAMER_TAG_AREA areaid = STREAMER_TAG_AREA -1, priority = 0)
	{
		antimapplusobject = CreateDynamicObject(modelid, x+RandomizeFloat(10), y+RandomizeFloat(10), z+RandomizeFloat(10), rx+RandomizeFloat(10), ry+RandomizeFloat(10), rz+RandomizeFloat(10), worldid, interiorid, playerid, streamdistance, drawdistance,areaid, priority);
		DestroyDynamicObject(antimapplusobject);
	    return CreateDynamicObject(modelid, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = STREAMER_OBJECT_SD, Float:drawdistance = STREAMER_OBJECT_DD, STREAMER_TAG_AREA areaid = STREAMER_TAG_AREA -1, priority = 0);
	}
	
	#if defined _ALS_CreateDynamicObject
	    #undef CreateDynamicObject
	#else
	    #define _ALS_CreateDynamicObject
	#endif
	#define CreateDynamicObject hak_CreateDynamicObject
    
    #endif

#endif