using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;
/*
ScreenPointToLocalPointInRectangle
magnitude
*/
public class JoyStick : MonoBehaviour, IDragHandler, IPointerUpHandler, IPointerDownHandler {

	private Image bgstick;
	private Image joystick;
	private Vector3 inputVector;

    private Animator anim;
	// Use this for initialization
	void Start () {
		bgstick = GetComponent<Image> ();
		joystick = transform.GetChild (0).GetComponent<Image> ();
        anim = GameObject.Find("slime").GetComponent<Animator>();
	}
	
	// Update is called once per frame
	void Update () {
		
	}
	public virtual void OnDrag(PointerEventData ped)
	{
        Vector2 Pos;
		if (RectTransformUtility.ScreenPointToLocalPointInRectangle (bgstick.rectTransform, 
																	 ped.position, 
																	 ped.pressEventCamera, 
																	 out Pos)) 
		{
			Pos.x = (Pos.x / bgstick.rectTransform.sizeDelta.x);
			Pos.y = (Pos.y / bgstick.rectTransform.sizeDelta.y);



			inputVector = new Vector3 (Pos.x , Pos.y , 0 );
			inputVector = (inputVector.sqrMagnitude > 1.0f) ? inputVector.normalized : inputVector;


            
			joystick.rectTransform.anchoredPosition = 
				new Vector3 (inputVector.x * (bgstick.rectTransform.sizeDelta.x / 3), 
							 inputVector.y * (bgstick.rectTransform.sizeDelta.y / 3));

            if (inputVector.x >= 0)
            {
                anim.SetInteger("IsDirection", 1);
            }
            else if (inputVector.x < 0)
            {
                anim.SetInteger("IsDirection", -1);
            }
           
        }
        

    }
	public virtual void OnPointerDown(PointerEventData ped)
	{
		OnDrag (ped);
        anim.SetBool("IsMove", true);
        SoundMgr.instance.walksound();
        
    }
	public virtual void OnPointerUp(PointerEventData ped)
	{
		inputVector = Vector3.zero;
		joystick.rectTransform.anchoredPosition = Vector3.zero;
        anim.SetBool("IsMove", false);
        anim.SetInteger("IsDirection", 1);
    }

	public float Horizontal()
	{
		if (inputVector.x != 0) {
			return inputVector.x;
		} else
			return Input.GetAxis ("Horizontal");
        
	}
	public float Vertical()
	{
		if (inputVector.y != 0) {
			return inputVector.y;
		} else
			return Input.GetAxis ("Vertical");
	}

    public Animator Anim
    {
        get { return anim; }
        set { anim = value; }
    }
}
