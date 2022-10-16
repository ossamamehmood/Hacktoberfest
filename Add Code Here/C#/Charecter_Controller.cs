using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovement : MonoBehaviour
{
    public float turnSpeed;
    Animator m_Animator;
    Rigidbody m_Rigidbody;
    Vector3 m_Movement;
    Quaternion m_Rotation = Quaternion.identity;

    
    // Start is called before the first frame update
    void Start()
    {
        m_Animator = GetComponent<Animator> ();
        m_Rigidbody = GetComponent<Rigidbody> ();
    }

    // Update is called once per frame
    void Update()
    {
        float horizontal = Input.GetAxis ("Horizontal");
        float vertical = Input.GetAxis ("Vertical");

         m_Movement.Set(horizontal, 0f, vertical);
         m_Movement.Normalize ();
        
         bool hasHorizontalInput = !Mathf.Approximately (horizontal, 0f);
         bool hasVerticalInput = !Mathf.Approximately (vertical, 0f);
        
         bool isWalking = hasHorizontalInput || hasVerticalInput;

          m_Animator.SetBool ("IsWalking", isWalking);

          Vector3 desiredForward = Vector3.RotateTowards (transform.forward, m_Movement, turnSpeed * Time.deltaTime, 0f);
          m_Rotation = Quaternion.LookRotation (desiredForward);
    }
    
     void OnAnimatorMove() {

         m_Rigidbody.MovePosition (m_Rigidbody.position + m_Movement * m_Animator.deltaPosition.magnitude);
         m_Rigidbody.MoveRotation (m_Rotation); 
}
