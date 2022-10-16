.MODEL SMALL
.STACK 100H
.DATA

msg1 DB 'For Add type:''+''$'    ;store message1
msg2 DB 10,13,'For Sub type:''-''$' ;store message2
msg3 DB 10,13,'For Mul type:''*''$'  ;store message3
msg4 DB 10,13,'For Div type:''/''$'  ;store message4
msg5 DB 10,13,'For Greater Number:''>''$'  ;store message5
msg6 DB 10,13,'For Smaller Number:''<''$'  ;store message6
msg7 DB 10,13,'Choose Any One:$'  ;store message7
msg8 DB 10,13,10,13,'Enter 1st Number:$'    ;store message8
msg9 DB 10,13,'Enter 2nd Number:$'  ;store message9
msg10 DB 10,13,10,13,'The Result is:$'   ;store message10
msg11 DB 10,13,10,13,'Number 1 is greater than Number 2$'   ;store message11
msg12 DB 10,13,10,13,'Number 2 is greater than Number 1$'   ;store message12
msg13 DB 10,13,10,13,'Number 1 is lesser than Number 2$'   ;store message13
msg14 DB 10,13,10,13,'Number 2 is lesser than Number 1$'   ;store message14
MSG DB 10,13,'Exiting Program$'   ;store exit msg
MSG15 DB 10,13,10,13,'The Greater Number is$'   ;store exit msg
MSG16 DB 10,13,10,13,'The Smaller Number is$'   ;store exit msg
                      

NUM1 DB ?
NUM2 DB ?
RESULT DB ?
.CODE
MAIN PROC
    MOV AX,@DATA   ; initialize the data segment
    MOV DS,AX
    
    LEA DX,msg1   ; display message1
    MOV AH,9
    INT 21H
    
    LEA DX,msg2  ; display message2
    MOV AH,9
    INT 21H
    
    LEA DX,msg3 ; display message3
    MOV AH,9
    INT 21H
    
    LEA DX,msg4  ;  display message4
    MOV AH,9
    INT 21H 
    
    LEA DX,msg5  ;  display message4
    MOV AH,9
    INT 21H 

    LEA DX,msg6  ;  display message4
    MOV AH,9
    INT 21H 
    
    
    LEA DX,msg7     ; display message5
    MOV AH,9
    INT 21H
    
    MOV AH,1  ; get number1
    INT 21H 
    MOV BH,AL ; store number1 in BH
    SUB BH,48 ; convert number1 to integer
    

    ; compare the given input type for performing the operation and jump to the appropriate function
    ;43 ,45 ,42 ,47 are the ASCII values for +,-,*,/ respectively

    ;convert BH to ASCII value
    
    ADD BH, '0' ; convert BH to ASCII value
    CMP BH,43  ; if number1 is + then jump to ADD function
    JE ADDITION
    
    CMP BH,45   ; if number1 is - then jump to SUB function
    JE SUBTRACT
     
    CMP BH,42  ; if number1 is *  then jump to MUL function
    JE MULTIPLY
    
    ; if number1 is non of the above then jump to MORE function
    JMP MORE

    
    
    
   
   ADDITION:
 
    LEA DX,msg8  ;Print ENTER 1ST NUMBER
    MOV AH,9
    INT 21H 
    
    MOV AH,1  ; read number1
    INT 21H
    MOV BL,AL ; store number1 in BL
    
    LEA DX,msg9    ;print ENTER 2ND NUMBER
    MOV AH,9  
    INT 21H   
    
    MOV AH,1    ;read number2
    INT 21H
    MOV CL,AL ; store number2 in CL

    ADD AL,BL
    MOV AH,0
    AAA
    
    MOV BX,AX 
    ADD BH,48
    ADD BL,48 
    
    LEA DX,msg10 ;display result
    MOV AH,9   
    INT 21H
    
    MOV AH,2  ; exit the program
    MOV DL,BH ; store the result in DL
    INT 21H
    
    MOV AH,2    ; exit the program
    MOV DL,BL
    INT 21H
    
    JMP EXIT_P    ;exit from program
    
   SUBTRACT:
 
    LEA DX,msg8  ;Print ENTER 1ST NUMBER
    MOV AH,9
    INT 21H 
    
    MOV AH,1  ; read number1
    INT 21H
    MOV BL,AL ; store number1 in BL
    
    LEA DX,msg9    ;print ENTER 2ND NUMBER
    MOV AH,9  
    INT 21H   
    
    MOV AH,1    ;read number2
    INT 21H
    MOV CL,AL ; store number2 in CL
    
    SUB BL,CL ;subtract number2 from number1
    ADD BL,48
    
    LEA DX,msg10 ;display result
    MOV AH,9
    INT 21H
    
    
    MOV AH,2    ;display result
    MOV DL,BL 
    INT 21H
    
    
    JMP EXIT_P    ;exit from program
    
   MULTIPLY:
 
    LEA DX,msg8 ;Print ENTER 1ST NUMBER
    MOV AH,9
    INT 21H
    
    MOV AH,1      ;read number1
    INT 21H   
    SUB AL,30H
    MOV NUM1,AL
    
    LEA DX,msg9     ;print ENTER 2ND NUMBER
    MOV AH,9
    INT 21H 
    
    MOV AH,1    ;read number2
    INT 21H
    SUB AL,30H
    MOV NUM2,AL
    
    MUL NUM1      ;multiply number1 and number2
    MOV RESULT,AL ;store result in RESULT
    AAM  
    
    ADD AH,30H  ;convert result to ascii
    ADD AL,30H    ;convert result to ascii
    
    MOV BX,AX       ;store result in BX
    
    LEA DX,msg10 ;display result
    MOV AH,9    
    INT 21H   
    
    MOV AH,2    ;display result
    MOV DL,BH     
    INT 21H   
    
    MOV AH,2  ;display result
    MOV DL,BL
    INT 21H
    
    JMP EXIT_P  ;exit program
  
  MORE:
   CMP BH, 47 ; if number1 is / then jump to DIV function
    JE DIVIDE

    CMP BH,62  ; if number1 is > then jump to DIV function
    JE GREATER

    JMP MORE_OP
  
  DIVIDE:
    LEA DX,msg8 ;PRINT ENTER 1ST NUMBER 
    MOV AH,9
    INT 21H
    
    MOV AH,1  ;read number1
    INT 21H
    SUB AL,30H
    MOV NUM1,AL
    
    LEA DX,msg9   ;print ENTER 2ND NUMBER
    MOV AH,9
    INT 21H 
    
    MOV AH,1  ;read number2
    INT 21H
    SUB AL,30H  ;convert number2 to ascii
    MOV NUM2,AL ;store number2 in NUM2
    
    MOV CL,NUM1 ;store number1 in CL
    MOV CH,00
    MOV AX,CX  
    
    DIV NUM2   ;divide number1 and number2
    MOV RESULT,AL ;store result in RESULT
    MOV AH, 00
    AAD  
    
    ADD AH,30H  ;convert result to ascii
    ADD AL,30H
    
    MOV BX,AX   ;store result in BX
    
    LEA DX,msg10 ;display result
    MOV AH,9
    INT 21H 
    
    MOV AH,2  ;display result
    MOV DL,BH 
    INT 21H
    
    MOV AH,2  ;display result
    MOV DL,BL 
    INT 21H
    
    JMP EXIT_P  ;exit program

    GREATER:
      LEA DX,msg8 ;PRINT ENTER 1ST NUMBER 
      MOV AH,9  ;display message1
      INT 21H
      
      MOV AH,1  ;read number1
      INT 21H 
      SUB AL,30H  ;convert number1 to ascii
      MOV NUM1,AL ;store number1 in NUM1
      
      LEA DX,msg9   ;print ENTER 2ND NUMBER
      MOV AH,9
      INT 21H 
      
      MOV AH,1  ;read number2
      INT 21H
      SUB AL,30H  ;convert number2 to ascii
      MOV NUM2,AL ;store number2 in NUM2
      
      MOV CL,NUM1 ;store number1 in CL
      MOV CH,00
      MOV AX,CX
      
      CMP AL,CL   ;compare number1 and number2
      ;check if number1 is greater than number2
      JAE GREATER_1 ;if number1 is greater than number2 then jump to GREATER_P
      JB GREATER_2   ;if number1 is less than number2 then jump to LESSER_P

      JMP EXIT_P  ;exit program

    GREATER_1:
      
      LEA DX,msg11 ;display result
      MOV AH,9
      INT 21H

      JMP EXIT_P  ;exit program
      
    MORE_OP:
    CMP BH,60  ; if number1 is < then jump to DIV function
    JE LESSER

    GREATER_2:
      LEA DX,msg12 ;display result
      MOV AH,9
      INT 21H

      JMP EXIT_P  ;exit program

    LESSER:
      ;FUNCTION TO COMPARE NUMBER1 AND NUMBER2

      LEA DX,msg8 ;PRINT ENTER 1ST NUMBER 
      MOV AH,9
      INT 21H
      
      
      MOV AH,1  ;read number1
      INT 21H 
      SUB AL,30H  ;convert number1 to ascii
      MOV NUM1,AL ;store number1 in NUM1
      
      
      LEA DX,msg9   ;print ENTER 2ND NUMBER
      MOV AH,9  ;read number2
      INT 21H   
      
      MOV AH,1  ;read number2
      INT 21H
      SUB AL,30H  ;convert number2 to ascii
      MOV NUM2,AL ;store number2 in NUM2
      

      CMP AL,NUM2   ;compare number1 and number2
      ;check if number1 is greater than number2
      JAE LESSER_2 ;if number1 is greater than number2 then jump to GREATER_P
      JB LESSER_1   ;if number1 is less than number2 then jump to LESSER_P

      JMP EXIT_P  ;exit program

    LESSER_1:
      
      LEA DX,msg13 ;display result
      MOV AH,9
      INT 21H

      JMP EXIT_P  ;exit program

    LESSER_2:
      LEA DX,msg14 ;display result
      MOV AH,9
      INT 21H

      JMP EXIT_P  ;exit program
        
    EXIT_P:
        LEA DX,MSG
        MOV AH,9
        INT 21H  
  
    EXIT:
    
    MOV AH,4CH  ;clear screen
    INT 21H   
    MAIN ENDP
END MAIN
