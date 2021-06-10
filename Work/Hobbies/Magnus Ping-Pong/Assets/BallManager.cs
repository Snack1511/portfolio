using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BallManager : MonoBehaviour
{

    // Start is called before the first frame update
    BallScript Ball;
    public BallManager(BallScript _Ball)
    {
        Ball = _Ball;
    }
    public void ResetBallMgr(bool winner)
    {
        Ball.ResetBall(winner);
    }
}
