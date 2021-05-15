using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Custom;

public class TextureRenderer : MonoBehaviour
{
    Material Mat_Liquid;
    Material FootMat;
    Material HandMat;
    Color[] Colors = new Color[3];
    
    private void Start()
    {
        
    }
    
    public void InitTexture(int n, string str)
    {
        Mat_Liquid = new Material(Resources.Load<Material>("Materials/Liquid_Mat"));
        FootMat = new Material(Resources.Load<Material>("Materials/PlayerMat_Colored"));
        HandMat = new Material(Resources.Load<Material>("Materials/PlayerMat_Colored"));
        Colors = ColorFunction.SetColor(n);
        Mat_Liquid.SetColor("_Tint", Colors[2]);
        FootMat.SetColor("_Color", Colors[1]);
        HandMat.SetColor("_Color", Colors[0]);
        for (int i = 0; i <  transform.GetChild(n).GetChild(0).childCount; i++)
        {
            transform.GetChild(n).GetChild(0).GetChild(i).GetChild(0).GetChild(0).GetChild(2).GetComponent<MeshRenderer>().material = Mat_Liquid;
            transform.GetChild(n).GetChild(0).GetChild(i).GetChild(1).GetChild(0).GetChild(0).GetComponent<MeshRenderer>().material = HandMat;
            transform.GetChild(n).GetChild(0).GetChild(i).GetChild(2).GetChild(0).GetChild(0).GetComponent<MeshRenderer>().material = FootMat;
            transform.GetChild(n).GetChild(0).GetChild(i).GetChild(3).GetChild(0).GetChild(0).GetComponent<MeshRenderer>().material = HandMat;
            transform.GetChild(n).GetChild(0).GetChild(i).GetChild(4).GetChild(0).GetChild(0).GetComponent<MeshRenderer>().material = FootMat;
            transform.GetChild(n).GetChild(0).GetChild(i).gameObject.SetActive(false);
        }
        transform.GetChild(n).GetChild(0).GetChild(GetStringToInt.GetModel(str)).gameObject.SetActive(true);

    }
    public void SetTextureObj(int n, int numPrev, string Nextname)
    {
        if (numPrev != -1)
        {
            transform.GetChild(n).GetChild(0).GetChild(numPrev).gameObject.SetActive(false);
        }
        if (GetStringToInt.GetModel(Nextname) == -1) return;
        transform.GetChild(n).GetChild(0).GetChild(GetStringToInt.GetModel(Nextname)).gameObject.SetActive(true);
    }
    
}
