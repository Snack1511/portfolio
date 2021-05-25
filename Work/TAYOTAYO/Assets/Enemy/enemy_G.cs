using UnityEngine;
using System.Collections;

public class enemy_G : MonoBehaviour {
    public static new SpriteRenderer renderer_EG;
    public static uint count = 0;
    // Use this for initialization
    void Start()
    {
        renderer_EG = GetComponent<SpriteRenderer>();
        renderer_EG.material.SetColor("_Color", Color.green);
    }

    // Update is called once per frame
    void Update()
    {
        transform.Translate(new Vector2(-2.0f * Time.deltaTime, 0.0f));
        if (player.player_pos.x - 10.0f > this.transform.position.x)
        {
            Destroy(this.gameObject);
        }
    }
    void OnTriggerEnter2D(Collider2D col_color)
    {
        if (col_color.gameObject.tag.Equals("Player"))
        {
            if (player.renderer_P.material.GetColor("_Color") == renderer_EG.material.GetColor("_Color"))
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
                gameroot.OnOff = 2;
                gameroot.PG++;
                if (enemy_B.count > 0)
                {
                    enemy_B.count--;
                }
                else if (enemy_B.count <= 0)
                {
                    enemy_B.count = 0;
                }
                if (enemy_R.count > 0)
                {
                    enemy_R.count--;
                }
                else if (enemy_R.count <= 0)
                {
                    enemy_R.count = 0;
                }

            }
        }
    }
}
