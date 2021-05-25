using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;
public class AttButton : MonoBehaviour, IDragHandler, IPointerUpHandler, IPointerDownHandler
{
    private Image Attbutton;
    private Animator anim;
    bool attflag = false;
    // Use this for initialization
    void Start () {
        Attbutton = GetComponent<Image>();
        anim = GameObject.Find("slime").GetComponent<Animator>();
    }
    public virtual void OnDrag(PointerEventData ped)
    {



    }
    public virtual void OnPointerDown(PointerEventData ped)
    {
        if (!Slime.attackedflag)
        {
            if (!attflag)
            {
                Vector2 Pos;
                if (RectTransformUtility.ScreenPointToLocalPointInRectangle(Attbutton.rectTransform,
                                                                             ped.position,
                                                                             ped.pressEventCamera,
                                                                             out Pos))
                {
                    anim.SetBool("IsAtt", true);
                    SoundMgr.instance.AttEffectSound();
                    Slime.moveflag = false;
                    attflag = true;
                    Debug.Log(attflag);

                }
            }
        }

    }
    public virtual void OnPointerUp(PointerEventData ped)
    {
        anim.SetBool("IsAtt", false);
        anim.SetInteger("IsDirection", 1);
        Slime.moveflag = true;
        attflag = false;
    }
    // Update is called once per frame
    void Update () {
		
	}
}
