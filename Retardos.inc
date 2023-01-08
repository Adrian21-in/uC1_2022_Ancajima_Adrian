;--------------------------------
    ;@file:     Retardos.inc
    ;@brief:    Este es una libreria de retardos....
    ;@date:     08/01/2023
    ;@author:   Adrian Ancajima Yangua 
    ;Frecuencia a trabajar : 4MHz
    ;TCY = 1us
    ;----------------------------
    
    
PSECT udata_acs      ; Contiene objetos en acees ram
Variable1: DS 1      ; reserva 1Byte en access ram
Variable2: DS 1      ; reserva 1Byte en access ram
  
PSECT code


    ;; Retardo1(10us)
       ;T = (6+4k1)*TCY = (6+4(1))us = 10us
       
Delay_10us:                  ;  2TCY---CALL
    MOVLW  1                 ;  1TCY.... k1=1
    MOVWF  Variable1,0       ;  1TCY
Loop1:   
    NOP                      ;  k1*TCY
    DECFSZ Variable1,1,0     ;  (k1-1) + 3*TCY
    GOTO   Loop1             ;  (k1-1)*2TCY
    RETURN                   ;  2*TCY
    
    ;; Retardo2(25us)
       ;T = (6+4k1)*TCY =  (6+4(5))us = 26us
      
Delay_25us:                  ;  2TCY---CALL
    MOVLW  5                 ;  1TCY.... k1=5
    MOVWF  Variable1,0       ;  1TCY
Loop2:   
    NOP                      ;  k1*TCY
    DECFSZ Variable1,1,0     ;  (k1-1) + 3*TCY
    GOTO   Loop2             ;  (k1-1)*2TCY
    RETURN                   ;  2*TCY
    


    ;; Retardo3(50us)
       ;T = (6+4k1)*TCY = (6+4(11))us = 50us 
       
Delay_50us:                  ;  2TCY---CALL
    MOVLW  11                ;  1TCY.... k1=11
    MOVWF  Variable1,0       ;  1TCY
Loop3:
    NOP                      ;  k1*TCY
    DECFSZ Variable1,1,0     ;  (k1-1) + 3*TCY
    GOTO   Loop3             ;  (k1-1)*2TCY
    RETURN                   ;  2*TCY
                                  
                                  
    ;; Retardo4(100us)           
       ;T = (6+4k1)*TCY = (6+4(24))us = 102us 
      
Delay_100us:                 ;  2TCY---CALL
    MOVLW  24                ;  1TCY.... k1=24
    MOVWF  Variable1,0       ;  1TCY
Loop4:
    NOP                      ;  k1*TCY
    DECFSZ Variable1,1,0     ;  (k1-1) + 3*TCY
    GOTO   Loop4             ;  (k1-1)*2TCY
    RETURN                   ;  2*TCY

      
    ;; Retardo5(200us)
       ;T = (6+4k1)*TCY = (6+4(49))us = 202us
      
Delay_200us:                 ;  2TCY---CALL
    MOVLW  49                ;  1TCY.... k1=49
    MOVWF  Variable1,0       ;  1TCY
Loop5:
    NOP                      ;  k1*TCY
    DECFSZ Variable1,1,0     ;  (k1-1) + 3*TCY
    GOTO   Loop5             ;  (k1-1)*2TCY
    RETURN                   ;  2TCY

 
    ;; Retardo6(250us)
       ;T = (6+4k1)*TCY = (6+4(61))us = 250
      
Delay_250us:                 ; 2TCY---CALL
    MOVLW  61                ;  1TCY.... k1=61
    MOVWF  Variable1,0       ;  1TCY
Loop6:
    NOP                      ;  k1*TCY
    DECFSZ Variable1,1,0     ;  (k1-1) + 3*TCY
    GOTO   Loop6             ;  (k1-1)*2TCY
    RETURN                   ;  2TCY

    
    ;; Retardo7(500us)
       ;T = (6+4k1)*TCY = (6+4(124))us = 502us
      
Delay_500us:                 ;   2TCY---CALL
    MOVLW  124               ;   1TCY.... k1=124
    MOVWF  Variable1,0       ;   1TCY
Loop7:
    NOP                      ;   k1*TCY
    DECFSZ Variable1,1,0     ;   (k1-1) + 3*TCY
    GOTO   Loop7             ;   (k1-1)*2TCY
    RETURN                   ;   2*TCY
    
    
    ;; Retardo8(1ms)
       ;T = k2*(6+4(k1))us + k2*(1us) + 6*(1us)= k2*(6+4(249))us + k2*(1us) + 6us = 1*(1ms) + 1us + 6us = 1.007ms
      
Delay_1ms:                    ;  2TCY---Call
    MOVLW  1                  ;  1TCY.... k2=1
    MOVWF  Variable2,0        ;  1TCY
       ;T = (6+4k1)us = (6+4*(249))us = 1ms 
Loop_Ext1:  
    MOVLW  249                ;  k2*TCY.... k1=249
    MOVWF  Variable1,0        ;  k2*TCY
Loop_Int1:
    Nop                       ;  k2*k1*TCY
    DECFSZ Variable1,1,0      ;  k2*((k1-1) + 3*TCY)
    GOTO   Loop_Int1          ;  k2*((k1-1)*2TCY)
    DECFSZ Variable2,1,0      ;  (k2-1) + 3*TCY
    GOTO   Loop_Ext1          ;  (k2-1)*2TCY
    RETURN                    ;  2*TCY

  
    ;; Retardo9(5ms)
       ;T = k2*(6+4(k1))us + k2*(1us) + 6*(1us)= k2*(6+4(249))us + k2*(1us) + 6us = 5*(1ms) + 5us + 6us = 5.011ms
    
Delay_5ms:                    ;  2TCY---Call
    MOVLW  5                  ;  1TCY.... k2=5
    MOVWF  Variable2,0        ;  1TCY
       ;T = (6+4k1)us = (6+4*(249))us = 1ms 
Loop_Ext2:  
    MOVLW  249                ;  k2*TCY.... k1=249
    MOVWF  Variable1,0        ;  k2*TCY
Loop_Int2:
    Nop                       ;  k2*k1*TCY
    DECFSZ Variable1,1,0      ;  k2*((k1-1) + 3*TCY)
    GOTO   Loop_Int2          ;  k2*((k1-1)*2TCY)
    DECFSZ Variable2,1,0      ;  (k2-1) + 3*TCY
    GOTO   Loop_Ext2          ;  (k2-1)*2TCY
    RETURN                    ;  2*TCY
    
    
    ;; Retardo10(10ms)
       ;T = k2*(6+4(k1))us + k2*(1us) + 6*(1us) = k2*(6+4(249))us + k2*(1us) + 6us = 10*(1ms) + 10us + 6us = 10.016ms
 
Delay_10ms:                   ;  2TCY---Call
    MOVLW  10                 ;  1TCY.... k2=10
    MOVWF  Variable2,0        ;  1TCY
       ;T = (6+4k1)us = (6+4*(249))us = 1ms 
Loop_Ext3:  
    MOVLW  249                ;  k2*TCY.....k1=249
    MOVWF  Variable1,0        ;  k2*TCY
Loop_Int3:
    Nop                       ;  k2*k1*TCY
    DECFSZ Variable1,1,0      ;  k2*((k1-1) + 3*TCY)
    GOTO   Loop_Int3          ;  k2*((k1-1)*2TCY)
    DECFSZ Variable2,1,0      ;  (k2-1) + 3*TCY
    GOTO   Loop_Ext3          ;  (k2-1)*2TCY
    RETURN                    ;  2*TCY
    
   
    ;; Retardo11(25ms)
       ;T = k2*(6+4(k1))us + k2*(1us) + 6*(1us) = k2*(6+4(249))us + k2*(1us)+ 6us = 25*(1ms) + 25us + 6us = 25.031ms 
     
Delay_25ms:                   ;  2TCY---Call
    MOVLW  25                 ;  1TCY... k2=25
    MOVWF  Variable2,0        ;  1TCY
       ;T = (6+4k1)us = (6+4*(249))us = 1ms 
Loop_Ext4:  
    MOVLW  249                ;  k2*TCY.....k1=249
    MOVWF  Variable1,0        ;  k2*TCY
Loop_Int4:
    Nop                       ;  k2*k1*TCY
    DECFSZ Variable1,1,0      ;  k2*((k1-1) + 3*TCY)
    GOTO   Loop_Int4          ;  k2*((k1-1)*2TCY)
    DECFSZ Variable2,1,0      ;  (k2-1) + 3*TCY
    GOTO   Loop_Ext4          ;  (k2-1)*2TCY
    RETURN                    ;  2*TCY
    
    
    ;; Retardo12(50ms)
       ;T= k2*(6+4(k1))us + k2*(1us) + 6*(1us) = k2*(6+4(249))us + k2*(1us) + 6us = 50*(1ms) + 50us + 6us = 50.056ms
     
Delay_50ms:                   ;  2TCY---Call
    MOVLW  50                 ;  1TCY... k2=50
    MOVWF  Variable2,0        ;  1TCY
       ;T = (6+4k1)us = (6+4*(249))us = 1ms 
Loop_Ext5:  
    MOVLW  249                ;  k2*TCY.....k1=249
    MOVWF  Variable1,0        ;  k2*TCY
Loop_Int5:
    Nop                       ;  k2*k1*TCY
    DECFSZ Variable1,1,0      ;  k2*((k1-1) + 3*TCY)
    GOTO   Loop_Int5          ;  k2*((k1-1)*2TCY)
    DECFSZ Variable2,1,0      ;  (k2-1) + 3*TCY
    GOTO   Loop_Ext5          ;  (k2-1)*2TCY
    RETURN                    ;  2*TCY  
                                  
                                   
    ;; Retardo13(100ms)            
       ;T= k2*(6+4(k1))us + k2*(1us)+ 6*(1us)= k2*(6+4(249))us + k2*(1us) + 6us = 100*(1ms) + 100us + 6us = 100.106ms
                                      
Delay_100ms:                  ;  2TCY---Call
    MOVLW  100                ;  1TCY... k2=100
    MOVWF  Variable2,0        ;  1TCY
       ;T = (6+4k1)us = (6+4*(249))us = 1ms 
Loop_Ext6:                          
    MOVLW  249                ;  k2*TCY....k1=249
    MOVWF  Variable1,0        ;  k2*TCY
Loop_Int6:                             
    Nop                       ;  k2*k1*TCY
    DECFSZ Variable1,1,0      ;  k2*((k1-1) + 3*TCY)
    GOTO   Loop_Int6          ;  k2*((k1-1)*2TCY)
    DECFSZ Variable2,1,0      ;  (k2-1) + 3*TCY
    GOTO   Loop_Ext6          ;  (k2-1)*2TCY
    RETURN                    ;  2*TCY 
   
    
    ;; Retardo14(200ms)
       ;T= k2*(6+4(k1))us + k2*(1us) + 6*(1us)= k2*(6+4(249))us + k2*(1us) + 6us = 200*(1ms) + 200us + 6us = 200.206ms
   
Delay_200ms:                  ;  2TCY---Call
    MOVLW  200                ;  1TCY... k2=200
    MOVWF  Variable2,0        ;  1TCY
       ;T = (6+4k1)us = (6+4*(249))us = 1ms 
Loop_Ext7:  
    MOVLW  249                ;  k2*TCY.... k1=249
    MOVWF  Variable1,0        ;  k2*TCU
Loop_Int7:
    Nop                       ;  k2*k1*TCY
    DECFSZ Variable1,1,0      ;  k2*((k1-1) + 3*TCY)
    GOTO   Loop_Int7          ;  k2*((k1-1)*2TCY)
    DECFSZ Variable2,1,0      ;  (k2-1) + 3*TCY
    GOTO   Loop_Ext7          ;  (k2-1)*2TCY
    RETURN                    ;  2*TCY
    
    
    ;; Retardo15(250ms)
       ;T= k2*(6+4(k1))us + k2*(1us) + 6*(1us) = k2*(6+4(249))us + k2*(1us) + 6us = 250*(1ms) + 250us + 6us = 250.256ms
     
Delay_250ms:                  ;  2TCY---Call
    MOVLW  250                ;  1TCY... k2=250
    MOVWF  Variable2,0        ;  1TCY
       ;T = (6+4k1)us = (6+4*(249))us = 1ms 
Loop_Ext8:  
    MOVLW  249                ;  k2*TCY.... k1=249
    MOVWF  Variable1,0        ;  k2*TCY
Loop_Int8:
    Nop                       ;  k2*k1*TCY
    DECFSZ Variable1,1,0      ;  k2*((k1-1) + 3*Tcy)
    GOTO   Loop_Int8          ;  k2*((k1-1)*2TCY)
    DECFSZ Variable2,1,0      ;  (k2-1) + 3*TCY
    GOTO   Loop_Ext8          ;  (k2-1)*2TCY
    RETURN                    ;  2*TCY	
