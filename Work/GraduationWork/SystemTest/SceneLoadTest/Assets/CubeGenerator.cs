using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CubeGenerator : MonoBehaviour
{
    public GameObject cube;
    
    // Start is called before the first frame update
    void Start()
    {
        
        for(int i = 0; i < 5; i++)
        {
            var pos = new Vector3(Random.Range(-3, 3), 0, Random.Range(-3, 3));
            Instantiate(cube, pos, Quaternion.identity);
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
