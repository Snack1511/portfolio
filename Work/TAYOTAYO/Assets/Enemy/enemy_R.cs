using UnityEngine;
using System.Collections;

public class enemy_R : MonoBehaviour {
    public static new SpriteRenderer renderer_ER;
    public static uint count = 0;
    
    // Use this for initialization
    void Start()
    {
        renderer_ER = GetComponent<SpriteRenderer>();
        renderer_ER.material.SetColor("_Color", Color.red);
    }

    // Update is called once per frame
    void Update()
    {
        transform.Translate(new Vector2(-2.0f * Time.deltaTime, 0.0f));
        if (player.player_pos.x - 5.0f > this.transform.position.x) {
            Destroy(this.gameObject);
        }
    }
    void OnTriggerEnter2D(Collider2D col_color)
    {
        if (col_color.gameObject.tag.Equals("Player"))
        {
            if (player.renderer_P.material.GetColor("_Color") == renderer_ER.material.GetColor("_Color"))
            {
                gameroot.score += 5 - count;
                if (count < 4){
                    count++;
                }
                else if (count >= 4){
                    count = 4;
                }
                
                Destroy(this.gameObject);
                gameroot.flag = Random.Range(1, 4);
                gameroot.EdeadFlag = true;
                gameroot.OnOff = 1;
                gameroot.PR++;
                if (enemy_G.count > 0)
                {
                    enemy_G.count--;
                }
                else if (enemy_G.count <= 0)
                {
                    enemy_G.count = 0;
                }
                if (enemy_B.count > 0)
                {
                    enemy_B.count--;
                }
                else if (enemy_B.count <= 0)
                {
                    enemy_B.count = 0;
                }

            }
        }
    }
}
