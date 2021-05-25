using UnityEngine;
using System.Collections;

public class player : MonoBehaviour {
    public static SpriteRenderer renderer_P;
    Vector2 pos;
    int UD_flag = 0;
    public static uint ChangeC_flag = 3;
    public static Vector2 player_pos;
    // Use this for initialization
    
    void Start () {
        pos = GetComponent<Vector2>();
        
        renderer_P.material.SetColor("_Color", Color.white);
        

    }

    // Update is called once per frame
    void Update() {
        renderer_P = GetComponent<SpriteRenderer>();
        pos = transform.position;
        player_pos = this.transform.position;
        speedcontrol(enemy_R.count, enemy_G.count, enemy_B.count);
        
        if (Input.GetKeyDown(KeyCode.RightArrow)) {
            ChangeC_flag += 1;
            ChangeColor(ChangeC_flag);
        }
        if (Input.GetKeyDown(KeyCode.LeftArrow))
        {
            ChangeC_flag -= 1;
            ChangeColor(ChangeC_flag);
        }
        if (Input.GetKeyDown(KeyCode.UpArrow))
        {
            if (UD_flag >= 1)
            {
                UD_flag = 1;
            }
            UD_flag--;
            UpDownControl(UD_flag);
        }
        if (Input.GetKeyDown(KeyCode.DownArrow))
        {
            if (UD_flag <= -1)
            {
                UD_flag = -1;
            }
            UD_flag++;
            UpDownControl(UD_flag);
        }
        /*if (Input.GetKey(KeyCode.Space))
        {
            renderer_P.material.SetColor("_Color", Color.white);
        }*/
        SFXmanager.instance.soundEffect(gameroot.OnOff);

    }
    void OnTriggerEnter2D(Collider2D col_color)
    {
        /*
        if (col_color.gameObject.tag.Equals("color_B") )
        {
            renderer_P.material.SetColor("_Color", Color.blue);
        }
        if (col_color.gameObject.tag.Equals("color_R"))
        {
            renderer_P.material.SetColor("_Color", Color.red);
        }
        if (col_color.gameObject.tag.Equals("color_G"))
        {
            renderer_P.material.SetColor("_Color", Color.green);
        }
        //아이템 체크
        */
        if (col_color.gameObject.tag.Equals("Enemy_R"))
        {
            if (enemy_R.renderer_ER.material.GetColor("_Color") != renderer_P.material.GetColor("_Color")) {
                
                gameroot.PdeadFlag = true; 
            }
        }

        if (col_color.gameObject.tag.Equals("Enemy_G"))
        {
            if (enemy_G.renderer_EG.material.GetColor("_Color") != renderer_P.material.GetColor("_Color"))
            {
                
                gameroot.PdeadFlag = true;
            }
        }

        if (col_color.gameObject.tag.Equals("Enemy_B"))
        {
            if (enemy_B.renderer_EB.material.GetColor("_Color") != renderer_P.material.GetColor("_Color"))
            {
                
                gameroot.PdeadFlag = true;
            }
        }
        //적체크
    }
    void UpDownControl(int flag) {
        
        
        switch (flag) {

            case -1:
                transform.position = new Vector2(pos.x, 2.0f);//x는 원래위치, y는 1.0f로
                break;
            case 0:
                transform.position = new Vector2(pos.x, 0.0f);
                break;
            case 1:
                transform.position = new Vector2(pos.x, -2.0f);
                break;
            default:
                break;
        }
    }
    void ChangeColor(uint flag)
    {
        uint a = flag % 3;
        switch (a)
        {
            case 0:
                renderer_P.material.SetColor("_Color", Color.red);
                break;
            case 1:
                renderer_P.material.SetColor("_Color", Color.green);
                break;
            case 2:
                renderer_P.material.SetColor("_Color", Color.blue);
                break;
        }
    }
    void speedcontrol(uint r, uint g, uint b) {
        Vector2 speed = new Vector2(1.0f *( r + g + b )*2.0f* Time.deltaTime, 0.0f);
        transform.Translate(new Vector2(5.0f * Time.deltaTime, 0.0f)+speed);
    }
}