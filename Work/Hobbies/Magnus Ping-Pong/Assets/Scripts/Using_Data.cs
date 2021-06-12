using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace BallValuse
{
    public struct GiveData
    {
        Vector2 Pos, Dir;
        float Spd;

        public GiveData(Vector2 pos, Vector2 dir, float spd)
        {
            Pos = pos;
            Dir = dir;
            Spd = spd;
        }

        public void DataUpdate(Vector2 pos, Vector2 dir, float spd)
        {
            Pos = pos;
            Dir = dir;
            Spd = spd;
        }
        
        public Vector2 POS { get { return Pos; } private set { Pos = value; } }
        public Vector2 DIR { get { return Dir; } private set { Dir = value; } }
        public float SPD { get { return Spd; } private set { Spd = value; } }
    }

}
namespace Custom
{
    public enum ROOMTAG
    {
        Menu,
        Play,
        Ending,
    };
    public enum SFXTAG
    {
        BUTTONCLICK,
        BALLCOLLISION,
        COUNTDONW,
        STARTROUND,
        GOAL,
    }


}

