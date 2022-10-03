def algo_Draw_Point(x1,y1,x2,y2):
    dx=x2-x1
    dy=y2-y1
    if(abs(dx)>abs(dy)):
        step=abs(dy)
    else:
        step = abs(dy)

    xinc = dx/step
    yinc = dy/step
    
    for i in range(step):
        print(x1,y1)
        x1=x1+xinc
        y1=y1+yinc
algo_Draw_Point(3,4,30,40)